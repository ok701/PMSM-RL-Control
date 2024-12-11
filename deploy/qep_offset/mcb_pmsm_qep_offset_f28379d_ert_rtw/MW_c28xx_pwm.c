#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_qep_offset_f28379d.h"
#include "mcb_pmsm_qep_offset_f28379d_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 0U;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1U; /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1U; /* Configure GPIOGPIO1 as EPWM1B*/

  /*-- Configure pin assignments for ePWM2 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO2 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1U; /* Configure GPIOGPIO2 as EPWM2A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO3 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1U; /* Configure GPIOGPIO3 as EPWM2B*/

  /*-- Configure pin assignments for ePWM3 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO4 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1U; /* Configure GPIOGPIO4 as EPWM3A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO5 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1U; /* Configure GPIOGPIO5 as EPWM3B*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;

  /* Enable TBCLK after the ePWM configurations */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
  /* Configuring EXTSYNCOUT source selection */
  EALLOW;
  SyncSocRegs.SYNCSELECT.bit.SYNCOUT = 0U;

  /* Configuring ePWM Sync in source selection */
  SyncSocRegs.SYNCSELECT.bit.EPWM4SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM7SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM10SYNCIN = 0U;
  EDIS;
}
