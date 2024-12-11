#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_qep_offset_f28379d.h"
#include "mcb_pmsm_qep_offset_f28379d_private.h"

void enableExtInterrupt (void);
void configureGPIOExtInterrupt(void);

#include <stdint.h>

void disableWatchdog(void)
{
  int *WatchdogWDCR = (int *)(uintptr_t)0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

void init_SCI(void)
{
  /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_A with following parameters:
   *    BaudRate              : 12500000
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   */
  CpuSysRegs.PCLKCR7.bit.SCI_A = 1U;
  asm(" NOP");
  SciaRegs.SCICCR.bit.STOPBITS = 0U;
                    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  SciaRegs.SCICCR.bit.PARITY = 0U;
                                 /*Parity mode (0: Odd parity, 1: Even parity)*/
  SciaRegs.SCICCR.bit.PARITYENA = 0U;  /*Enable Pary Mode */
  SciaRegs.SCICCR.bit.LOOPBKENA = 0U;  /*Loop Back enable*/
  SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0U;/*ADDR/IDLE Mode control*/
  SciaRegs.SCICCR.bit.SCICHAR = 7U;    /*Character length*/
  SciaRegs.SCICTL1.bit.RXERRINTENA = 0U;/*Disable receive error interrupt*/
  SciaRegs.SCICTL1.bit.SWRESET = 1U;   /*Software reset*/
  SciaRegs.SCICTL1.bit.TXENA = 1U;     /* SCI transmitter enable*/
  SciaRegs.SCICTL1.bit.RXENA = 1U;     /* SCI receiver enable*/
  SciaRegs.SCIHBAUD.bit.BAUD = 0U;
  SciaRegs.SCILBAUD.bit.BAUD = 1U;

  /*Free run, continue SCI operation regardless of suspend*/
  SciaRegs.SCIPRI.bit.FREESOFT = 3U;
  SciaRegs.SCIFFCT.bit.ABDCLR = 0U;
  SciaRegs.SCIFFCT.bit.CDC = 0U;
  SciaRegs.SCIFFTX.bit.SCIRST = 1U;    /* SCI reset rx/tx channels*/
  SciaRegs.SCIFFTX.bit.SCIFFENA = 1U;  /* SCI FIFO enhancements are enabled.*/
  SciaRegs.SCIFFTX.bit.TXFIFORESET = 1U;/* Re-enable transmit FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFIFORESET = 1U;/* Re-enable receive FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFFIENA = 1U;
  SciaRegs.SCIFFRX.bit.RXFFIL = 4U;
  SciaRegs.SCICTL1.bit.RXERRINTENA = 1U;
  /*Enable receive error interrupt by default if receive FIFO interrupt is enabled*/
  EDIS;
}

void init_SCI_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPBQSEL1.bit.GPIO43 = 3U;/*Asynch input GPIO43 SCIRXDA*/
  GpioCtrlRegs.GPBPUD.bit.GPIO43 = 0U; /*Enable pull-up for GPIO43*/
  GpioCtrlRegs.GPBGMUX1.bit.GPIO43 = 3U;
  GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3U;/*Configure GPIO43 as SCIRXDA*/
  GpioCtrlRegs.GPBPUD.bit.GPIO42 = 0U; /*Enable pull-up for GPIO42*/
  GpioCtrlRegs.GPBGMUX1.bit.GPIO42 = 3U;
  GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3U;/*Configure GPIO42 as SCITXDA*/
  EDIS;
}
