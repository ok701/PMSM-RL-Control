/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_mpc_qep_f28379d'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 12:39:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DSP28xx_SciUtil.h"

// to prevent re-entrancy in SCI transmit function
uint16_T checkSCITransmitInProgressA;
uint32_T frameA1Count;
uint16_T frameA1Transmitted;

/* Transmit character(s) from the SCIa*/
int16_T scia_xmit(uchar_T* pmsg, int16_T msglen, int16_T typeLen)
/*Blocking mode*/
{
  int16_T i,j;
  if (typeLen==1) {
    for (i = 0; i < msglen; i++) {
      while (SciaRegs.SCIFFTX.bit.TXFFST == 16U) {
      }                                /* The buffer is full;*/

      SciaRegs.SCITXBUF.bit.TXDT = pmsg[i];
    }
  } else {
    for (i = 0; i < (msglen/2); i++) {
      for (j = 0; j<=1; j++) {
        while (SciaRegs.SCIFFTX.bit.TXFFST == 16U) {
        }                              /* The buffer is full;*/

        SciaRegs.SCITXBUF.bit.TXDT = pmsg[i]>>(8*j);
      }
    }
  }

  return 0;
}

/*
 * Receive character(s) from the SCIa
 * Received character(s) will be write to rcvBuff.
 * Return 0 if characters are received with no error.
 * Return 1 if waiting timeout.
 * Return 2 if data error.(receiving timeout or checksum error)
 * Return 3 if a parity error occurred.
 * Return 4 if a frame error occurred.
 */
int16_T scia_rcv(uint16_T *rcvBuff, int16_T buffLen, int16_T typeLen)
{
  int16_T i;
  int16_T errorVal = NOERROR;
  uint16_T byte_cnt = 0;
  Uint32 elapsedTimeCnt, startTimeCnt, currentTimeCnt;
  uint32_T BlockingModeTimeoutCnt = 1.7500000000000002E+6;
  for (i = 0; i<buffLen; i++) {
    startTimeCnt = ReadCpuTimer2Counter();
    elapsedTimeCnt = 0U;
    while (SciaRegs.SCIFFRX.bit.RXFFST == 0U) {
      /* wait until data received */
      currentTimeCnt = (ReadCpuTimer2Counter());
      if (currentTimeCnt <= startTimeCnt) {
        elapsedTimeCnt = (Uint32)(startTimeCnt - currentTimeCnt);
      } else {
        elapsedTimeCnt = (Uint32)(0xFFFFFFFFU + startTimeCnt - currentTimeCnt);
      }

      if (elapsedTimeCnt >= BlockingModeTimeoutCnt) {
        return TIMEOUT;
      }
    }

    if (typeLen > 1) {
      if (byte_cnt == 0U) {
        rcvBuff[i/2] = (SciaRegs.SCIRXBUF.all & 0x00FFU);
        byte_cnt = 1U;
      } else {
        rcvBuff[i/2] |= SciaRegs.SCIRXBUF.all << 8;
        byte_cnt = 0U;
      }
    } else {
      rcvBuff[i] = SciaRegs.SCIRXBUF.all;
    }

    //check flags
    if (SciaRegs.SCIFFRX.bit.RXFFOVF == 1U)/* detect FIFO overflow*/
    {
      SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1U;

      /*SciaRegs.SCIFFRX.bit.RXFIFORESET = 0U;    Reset the FIFO pointer to zero.
       * SciaRegs.SCIFFRX.bit.RXFIFORESET = 1U;   Re-enable receive FIFO operation.
       */
    }

    if (SciaRegs.SCIRXST.bit.FE) {
      errorVal = FRAMERR;
    }

    if (SciaRegs.SCIRXST.bit.PE) {
      errorVal = PRTYERR;
    }

    if (SciaRegs.SCIRXST.bit.OE) {
      errorVal = OVRNERR;
    }

    if (SciaRegs.SCIRXST.bit.BRKDT) {
      errorVal = BRKDTERR;
    }

    if (SciaRegs.SCIRXST.bit.RXERROR == 1U) {
      SciaRegs.SCICTL1.bit.SWRESET = 1U;
      SciaRegs.SCICTL1.bit.SWRESET = 0U;
      SciaRegs.SCICTL1.bit.SWRESET = 1U;
    }
  }

  return errorVal;
}

/*
 * Receive character(s) from the SCIa
 * Received character(s) will be write to rcvBuff.
 * Receive data until tail is received.
 * Once first byte of tail matches with received byte start tailCount
 * If in between tail byte is not matching with received byte then reset tailCount
 * When tailCount becomes equal to tailSize then update rcvBufferLen with received number of bytes, check forFlags and exit.
 *
 *
 * Return 0 if characters are received with no error.
 * Return 1 if waiting timeout.
 * Return 2 if data error.(receiving timeout or checksum error)
 * Return 3 if a parity error occurred.
 * Return 4 if a frame error occurred.
 */
int16_T scia_rcv_varsize(uint16_T *rcvBuff, int16_T buffLen, int16_T typeLen,
  uchar_T *expTail, int16_T tailsize, int16_T *rcvBufferLen)
{
  int16_T i = 0;
  int16_T errorVal = NOERROR;
  uint16_T byte_cnt = 0;
  int16_T tailCount = 0;
  int16_T totalLen = buffLen + tailsize;
  *rcvBufferLen = 0;
  while (i < totalLen) {
    if (SciaRegs.SCIFFRX.bit.RXFFST > 0U) {/*Check if receive FIFO has data*/
      if (typeLen > 1) {
        int_T tempData = 0;
        tempData = SciaRegs.SCIRXBUF.all;
        if (byte_cnt == 0U) {
          rcvBuff[i/2] = (tempData & 0x00FFU);
          byte_cnt = 1U;
        } else {
          rcvBuff[i/2] |= tempData << 8;
          byte_cnt = 0U;
        }

        if (tailsize != 0) {
          // Do not check tail if tail is not provided
          if (tempData == expTail[tailCount]) {
            tailCount++;
            if (tailCount == tailsize) {
              *rcvBufferLen = i - tailsize + 1;
              break;
            }
          } else {
            tailCount = 0;
          }
        }
      } else {
        // for (typeLen<=1)
        rcvBuff[i] = SciaRegs.SCIRXBUF.all;
        if (tailsize != 0) {
          // Do not check tail if tail is not provided
          if (rcvBuff[i] == expTail[tailCount]) {
            tailCount++;
            if (tailCount == tailsize) {
              *rcvBufferLen = i - tailsize + 1;
              break;
            }
          }
        } else {
          tailCount = 0;
        }
      }
    } else {
      // If data is not available in FIFO i.e RXFFST == 0
      if (i == 0) {
        return DATANOTAVAILABLE;
      } else {
        *rcvBufferLen = i;
        if (*rcvBufferLen > buffLen) {
          *rcvBufferLen = buffLen;
        }

        errorVal = PARTIALDATA;
        break;
      }
    }

    i = i+1;

    //Check flags
    if (SciaRegs.SCIFFRX.bit.RXFFOVF == 1U)/* detect FIFO overflow*/
    {
      SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1U;

      /*SciaRegs.SCIFFRX.bit.RXFIFORESET = 0U;    Reset the FIFO pointer to zero.
       * SciaRegs.SCIFFRX.bit.RXFIFORESET = 1U;   Re-enable receive FIFO operation.
       */
    }

    if (SciaRegs.SCIRXST.bit.FE) {
      errorVal = FRAMERR;
    }

    if (SciaRegs.SCIRXST.bit.PE) {
      errorVal = PRTYERR;
    }

    if (SciaRegs.SCIRXST.bit.OE) {
      errorVal = OVRNERR;
    }

    if (SciaRegs.SCIRXST.bit.BRKDT) {
      errorVal = BRKDTERR;
    }

    if (SciaRegs.SCIRXST.bit.RXERROR == 1U) {
      SciaRegs.SCICTL1.bit.SWRESET = 1U;
      SciaRegs.SCICTL1.bit.SWRESET = 0U;
      SciaRegs.SCICTL1.bit.SWRESET = 1U;
    }
  }

  if (0 == tailsize) {
    if (errorVal != PARTIALDATA) {
      //In case of tail not provided, error flag will NOERROR if data received is of max length
      *rcvBufferLen = totalLen;
    }
  } else {
    // error out as partial data received if tail is provided and not found till maximum length and output the length as max length
    if (*rcvBufferLen == 0) {
      if (tailCount != (i+1)) {
        *rcvBufferLen = i-1;
        errorVal = PARTIALDATA;
      } else {
        errorVal = DATANOTAVAILABLE;
      }

      if (*rcvBufferLen > buffLen) {
        *rcvBufferLen = buffLen;
      }

      if (*rcvBufferLen < 0) {
        *rcvBufferLen = 0;
      }
    }
  }

  return errorVal;
}

void init_SCIFrame(void)
{
  // to prevent re-entrancy in SCI transmit function
  checkSCITransmitInProgressA = 0;
  frameA1Count = 0U;
  frameA1Transmitted = 1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
