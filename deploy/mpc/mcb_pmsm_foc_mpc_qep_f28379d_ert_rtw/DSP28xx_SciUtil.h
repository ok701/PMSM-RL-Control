/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_mpc_qep_f28379d'.
 *
 * Model version                  : 9.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Dec 11 16:26:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DSP28xx_SciUtil_h_
#define DSP28xx_SciUtil_h_
#include "MW_f2837xD_includes.h"
#include "F2837xD_device.h"
#include <string.h>
#include "rtwtypes.h"
#define NOERROR                        0                         /* no error*/
#define TIMEOUT                        1                         /* waiting timeout*/
#define DATAERR                        2                         /* data error (checksum error)*/
#define PRTYERR                        3                         /* parity error*/
#define FRAMERR                        4                         /* frame error*/
#define OVRNERR                        5                         /* overrun error*/
#define BRKDTERR                       6                         /* brake-detect error*/
#define DATANOTAVAILABLE               7                         /* Data not available */
#define PARTIALDATA                    8                         /* Partial Data available */

extern uint16_T checkSCITransmitInProgressA;
extern uint32_T frameA1Count;
extern uint16_T frameA1Transmitted;
int16_T scia_xmit(uchar_T* pmsg, int16_T msglen, int16_T typeLen);
int16_T scia_rcv(uint16_T *rcvBuff, int16_T buffLen, int16_T typeLen);
int16_T scia_rcv_varsize(uint16_T *rcvBuff, int16_T buffLen, int16_T typeLen,
  uchar_T *expTail, int16_T tailsize, int16_T *rcvBufferLen);
void init_SCIFrame(void);

#endif                                 /* DSP28xx_SciUtil_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
