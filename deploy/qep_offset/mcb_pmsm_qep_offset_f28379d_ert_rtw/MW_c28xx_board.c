#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_qep_offset_f28379d.h"
#include "mcb_pmsm_qep_offset_f28379d_private.h"

void init_board (void)
{
  DisableDog();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.DMA = 1U;
  CpuSysRegs.PCLKCR6.bit.SD1 = 1U;
  CpuSysRegs.PCLKCR6.bit.SD2 = 1U;
  EDIS;

#ifdef CPU1

  EALLOW;

  //enable pull-ups on unbonded IOs as soon as possible to reduce power consumption.
  GPIO_EnableUnbondedIOPullups();
  CpuSysRegs.PCLKCR13.bit.ADC_A = 1U;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 1U;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 1U;
  CpuSysRegs.PCLKCR13.bit.ADC_D = 1U;

  //check if device is trimmed
  if (*((Uint16 *)0x5D1B6) == 0x0000U) {
    //device is not trimmed, apply static calibration values
    AnalogSubsysRegs.ANAREFTRIMA.all = 31709U;
    AnalogSubsysRegs.ANAREFTRIMB.all = 31709U;
    AnalogSubsysRegs.ANAREFTRIMC.all = 31709U;
    AnalogSubsysRegs.ANAREFTRIMD.all = 31709U;
  }

  CpuSysRegs.PCLKCR13.bit.ADC_A = 0U;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 0U;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 0U;
  CpuSysRegs.PCLKCR13.bit.ADC_D = 0U;
  EDIS;
  InitSysPll(XTAL_OSC,40,0,1);

  //Turn on all peripherals
  //InitPeripheralClocks();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1U;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1U;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1U;
  CpuSysRegs.PCLKCR0.bit.HRPWM = 1U;
  CpuSysRegs.PCLKCR1.bit.EMIF1 = 1U;
  CpuSysRegs.PCLKCR1.bit.EMIF2 = 1U;

  /* Assign all Peripherals to CPU2 */
  DevCfgRegs.CPUSEL11.all = 0x0000000FU;
  DevCfgRegs.CPUSEL5.all = 0x0000000FU;
  DevCfgRegs.CPUSEL14.all = 0x00070000U;
  DevCfgRegs.CPUSEL7.all = 0x00000003U;
  DevCfgRegs.CPUSEL0.all = 0x00000FFFU;
  DevCfgRegs.CPUSEL1.all = 0x0000003FU;
  DevCfgRegs.CPUSEL2.all = 0x00000007U;
  DevCfgRegs.CPUSEL4.all = 0x00000003U;
  DevCfgRegs.CPUSEL6.all = 0x00000007U;
  DevCfgRegs.CPUSEL8.all = 0x00000003U;
  DevCfgRegs.CPUSEL12.all = 0x000000FFU;
  EDIS;

#endif                                 // #ifdef CPU1

  EALLOW;

  /* Configure low speed peripheral clocks */
  ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0U;
  EDIS;

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000U;
  IFR = 0x0000U;
  InitPieCtrl();
  InitPieVectTable();
  initSetGPIOIPC();
  InitCpuTimers();

#ifdef CPU1

  EALLOW;

  /* Assign used ADC modules to CPU1 */
  DevCfgRegs.CPUSEL11.bit.ADC_B = 0U;
  DevCfgRegs.CPUSEL11.bit.ADC_C = 0U;

#ifdef MW_DAC_CHANNEL_A

  DevCfgRegs.CPUSEL14.bit.DAC_A = 0U;

#endif

#ifdef MW_DAC_CHANNEL_B

  DevCfgRegs.CPUSEL14.bit.DAC_B = 0U;

#endif

#ifdef MW_DAC_CHANNEL_C

  DevCfgRegs.CPUSEL14.bit.DAC_C = 0U;

#endif

  /* Assign SDFM modules to CPU1 */
#ifdef MW_SDFM_1

  DevCfgRegs.CPUSEL4.bit.SD1 = 0U;

#endif

#ifdef MW_SDFM_2

  DevCfgRegs.CPUSEL4.bit.SD2 = 0U;

#endif

#ifdef MW_SDFM_3

  DevCfgRegs.CPUSEL4.bit.SD3 = 0U;

#endif

#ifdef MW_SDFM_4

  DevCfgRegs.CPUSEL4.bit.SD4 = 0U;

#endif

  /* Assign used PWM modules to CPU1 */
  DevCfgRegs.CPUSEL0.bit.EPWM1 = 0U;
  DevCfgRegs.CPUSEL0.bit.EPWM2 = 0U;
  DevCfgRegs.CPUSEL0.bit.EPWM3 = 0U;

  /* Assign used eQEP modules to CPU1 */
  DevCfgRegs.CPUSEL2.bit.EQEP1 = 0U;

  /* Assign used SCI modules to CPU1 */
  DevCfgRegs.CPUSEL5.bit.SCI_A = 0U;

  /* Assign used SPI modules to CPU1 */
#ifdef MW_SPI_A

  DevCfgRegs.CPUSEL6.bit.SPI_A = 0U;

#endif

#ifdef MW_SPI_B

  DevCfgRegs.CPUSEL6.bit.SPI_B = 0U;

#endif

#ifdef MW_SPI_C

  DevCfgRegs.CPUSEL6.bit.SPI_C = 0U;

#endif

#ifdef MW_SPI_D

  DevCfgRegs.CPUSEL6.bit.SPI_D = 0U;

#endif

#if defined MW_CMPSS1_COMPH || defined MW_CMPSS1_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS1 = 0U;

#endif

#if defined MW_CMPSS2_COMPH || defined MW_CMPSS2_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS2 = 0U;

#endif

#if defined MW_CMPSS3_COMPH || defined MW_CMPSS3_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS3 = 0U;

#endif

#if defined MW_CMPSS4_COMPH || defined MW_CMPSS4_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS4 = 0U;

#endif

#if defined MW_CMPSS5_COMPH || defined MW_CMPSS5_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS5 = 0U;

#endif

#if defined MW_CMPSS6_COMPH || defined MW_CMPSS6_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS6 = 0U;

#endif

#if defined MW_CMPSS7_COMPH || defined MW_CMPSS7_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS7 = 0U;

#endif

#if defined MW_CMPSS8_COMPH || defined MW_CMPSS8_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS8 = 0U;

#endif

#if defined MW_CMPSS9_COMPH || defined MW_CMPSS9_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS9 = 0U;

#endif

#if defined MW_CMPSS10_COMPH || defined MW_CMPSS10_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS10 = 0U;

#endif

#if defined MW_CMPSS11_COMPH || defined MW_CMPSS11_COMPL

  DevCfgRegs.CPUSEL12.bit.CMPSS11 = 0U;

#endif

  EDIS;

#endif                                 // #ifdef CPU1

  init_SCI();
  init_SCI_GPIO();
  init_SCIFrame();

  /* initial ePWM GPIO assignment... */
  config_ePWM_GPIO();
  EALLOW;

  /* Enable clock to ePWM */
  CpuSysRegs.PCLKCR2.bit.EPWM1 = 1U;
  CpuSysRegs.PCLKCR2.bit.EPWM2 = 1U;
  CpuSysRegs.PCLKCR2.bit.EPWM3 = 1U;

  /* Disable TBCLK within ePWM before module configuration */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0U;
  EDIS;
  config_ePWMSyncSource();

#ifdef CPU1

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0x0U;
  GpioCtrlRegs.GPAQSEL2.all = 0x0U;
  GpioCtrlRegs.GPBQSEL1.all = 0x0U;
  GpioCtrlRegs.GPBQSEL2.all = 0x0U;
  GpioCtrlRegs.GPCQSEL1.all = 0x0U;
  GpioCtrlRegs.GPCQSEL2.all = 0x0U;
  GpioCtrlRegs.GPDQSEL1.all = 0x0U;
  GpioCtrlRegs.GPDQSEL2.all = 0x0U;
  GpioCtrlRegs.GPEQSEL1.all = 0x0U;
  GpioCtrlRegs.GPEQSEL2.all = 0x0U;
  GpioCtrlRegs.GPFQSEL1.all = 0x0U;
  EDIS;

#endif                                 // #ifdef CPU1

}
