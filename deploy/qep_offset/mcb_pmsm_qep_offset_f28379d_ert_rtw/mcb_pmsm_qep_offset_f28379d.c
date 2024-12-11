/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_qep_offset_f28379d.c
 *
 * Code generated for Simulink model 'mcb_pmsm_qep_offset_f28379d'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 11:18:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_qep_offset_f28379d.h"
#include "mcb_pmsm_qep_offset_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_qep_offset_f28 mcb_pmsm_qep_offset_f28379d_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_qep_offset_f283 mcb_pmsm_qep_offset_f2837_DWork;

/* Real-time model */
static RT_MODEL_mcb_pmsm_qep_offset_f2 mcb_pmsm_qep_offset_f28379d_M_;
RT_MODEL_mcb_pmsm_qep_offset_f2 *const mcb_pmsm_qep_offset_f28379d_M =
  &mcb_pmsm_qep_offset_f28379d_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/* Model step function */
void mcb_pmsm_qep_offset_f28379d_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S2>/Digital Output2' incorporates:
   *  Constant: '<S2>/LED 1 Hz'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_qep_offset_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(mcb_pmsm_qep_offset_f28379d_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_qep_offset_f28379d_B), 0,
                sizeof(BlockIO_mcb_pmsm_qep_offset_f28));

  {
    mcb_pmsm_qep_offset_f28379d_B.SCIReceive = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.DTC = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Product = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Merge = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Numberofpolepairs = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Floor = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add_c = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch_k = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.TmpSignalConversionAtBytePackIn[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.TmpSignalConversionAtBytePackIn[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Merge_f = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.indexing = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Lookup[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Lookup[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Lookup[2] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Lookup[3] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum3 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum2 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Product_j = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum4 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum5 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Product1 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum6 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch4[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch4[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch4[2] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.one_by_two = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.add_c = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.add_b = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Min = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Max = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add_i = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.one_by_two_b = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add2 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add1_m = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add3 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain[2] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum_d[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum_d[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Sum_d[2] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain_h[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain_h[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Gain_h[2] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Convert_back = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Convert_back_g = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Merge_g = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.UnitDelay = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch_b = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Multiply = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add_d = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1_c = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add1_j = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Input = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Delay_f = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Add1_a = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.qcos = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.dsin = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.sum_beta = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.dcos = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.qsin = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.sum_alpha = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch_k5[0] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.Switch_k5[1] = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.algDD_o1 = 0.0F;
    mcb_pmsm_qep_offset_f28379d_B.algDD_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_qep_offset_f2837_DWork, 0,
                sizeof(D_Work_mcb_pmsm_qep_offset_f283));
  mcb_pmsm_qep_offset_f2837_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE = 0.0F;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Offset Calculation'
   */

  /* System initialize for function-call system: '<Root>/Offset Calculation' */

  /* Start for S-Function (c280xqep): '<S3>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xpwm): '<S15>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S15>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S15>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S15>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xadc): '<S3>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S3>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* SystemInitialize for Enabled SubSystem: '<S11>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
  mcb_pmsm_qep_offset_f2837_DWork.UnitDelay_DSTATE = 0.0F;

  /* SystemInitialize for Merge: '<S25>/Merge' */
  mcb_pmsm_qep_offset_f28379d_B.Merge_g = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S18>/Up Counter' */
  /* InitializeConditions for Delay: '<S26>/Delay' */
  mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_n = 0UL;

  /* End of SystemInitialize for SubSystem: '<S18>/Up Counter' */
  /* End of SystemInitialize for SubSystem: '<S11>/PosGen' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Serial Receive'
   */

  /* System initialize for function-call system: '<Root>/Serial Receive' */

  /* Start for S-Function (c28xsci_rx): '<S80>/SCI Receive' */

  /* Initialize out port */
  {
    mcb_pmsm_qep_offset_f28379d_B.SCIReceive = (real32_T)0.0;
  }

  /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
  {
    /* InitCpuTimers() - CPU Timers are also initialized in
     * MW_c28xx_board.c in the generated code.
     */
    CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
    CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
    CpuTimer2Regs.TPR.all = 0x00U;     /* no prescaler    */
    StartCpuTimer2();
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* Start for S-Function (c280xgpio_do): '<S2>/Digital Output2' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model terminate function */
void mcb_pmsm_qep_offset_f28379d_terminate(void)
{
  /* (no terminate code required) */
}

void mcb_pmsm_qep_offset_f28379d_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,0);
  HWI_TIC28x_EnableIRQ(33);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,2);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S8>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~66;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Offset Calculation' */
      {
        uint64_T tmp;
        real32_T Bias;
        real32_T u0_p;
        uint32_T Data;
        int16_T s51_iter;
        uint16_T u0;
        uint16_T u1;
        boolean_T tmp_e;
        boolean_T tmp_p;

        /* UnitDelay: '<S53>/Output' */
        mcb_pmsm_qep_offset_f28379d_B.Output =
          mcb_pmsm_qep_offset_f2837_DWork.Output_DSTATE;

        /* S-Function (c280xqep): '<S3>/eQEP' */
        {
          mcb_pmsm_qep_offset_f28379d_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
          mcb_pmsm_qep_offset_f28379d_B.eQEP_o2 = EQep1Regs.QPOSILAT;
          /* The position-counter value is latched into this register on an IEL*/
        }

        /* Outputs for IfAction SubSystem: '<S61>/PositionNoReset' incorporates:
         *  ActionPort: '<S71>/Action Port'
         */
        /* If: '<S61>/If1' incorporates:
         *  Constant: '<S76>/Constant'
         *  Merge: '<S61>/Merge'
         *  MinMax: '<S71>/MinMax'
         *  Sum: '<S71>/Sum3'
         *  Sum: '<S71>/Sum7'
         */
        mcb_pmsm_qep_offset_f28379d_B.Sum3_n =
          mcb_pmsm_qep_offset_f28379d_B.eQEP_o1 -
          mcb_pmsm_qep_offset_f28379d_B.eQEP_o2;
        mcb_pmsm_qep_offset_f28379d_B.Sum7 =
          mcb_pmsm_qep_offset_f28379d_B.Sum3_n + 4000U;
        u0 = mcb_pmsm_qep_offset_f28379d_B.Sum3_n;
        u1 = mcb_pmsm_qep_offset_f28379d_B.Sum7;
        if (u0 <= u1) {
          u1 = u0;
        }

        mcb_pmsm_qep_offset_f28379d_B.Merge_j = u1;

        /* End of If: '<S61>/If1' */
        /* End of Outputs for SubSystem: '<S61>/PositionNoReset' */

        /* DataTypeConversion: '<S74>/DTC' */
        mcb_pmsm_qep_offset_f28379d_B.DTC =
          mcb_pmsm_qep_offset_f28379d_B.Merge_j;

        /* Product: '<S61>/Product' incorporates:
         *  Constant: '<S77>/Constant'
         */
        mcb_pmsm_qep_offset_f28379d_B.Product =
          mcb_pmsm_qep_offset_f28379d_B.DTC * 0.00025F;

        /* Switch: '<S63>/Switch' incorporates:
         *  Constant: '<S63>/Constant1'
         */
        mcb_pmsm_qep_offset_f28379d_B.Switch = 0.0F;

        /* If: '<S64>/If' */
        if (mcb_pmsm_qep_offset_f28379d_B.Product <= 0.0F) {
          /* Outputs for IfAction SubSystem: '<S64>/If Action Subsystem' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Merge: '<S64>/Merge' incorporates:
           *  Sum: '<S66>/Add'
           */
          mcb_pmsm_qep_offset_f28379d_B.Merge = 1.0F;

          /* End of Outputs for SubSystem: '<S64>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S64>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S67>/Action Port'
           */
          /* Merge: '<S64>/Merge' incorporates:
           *  Sum: '<S67>/Add'
           */
          mcb_pmsm_qep_offset_f28379d_B.Merge =
            mcb_pmsm_qep_offset_f28379d_B.Product;

          /* End of Outputs for SubSystem: '<S64>/If Action Subsystem1' */
        }

        /* End of If: '<S64>/If' */

        /* Gain: '<S69>/Number of pole pairs' */
        mcb_pmsm_qep_offset_f28379d_B.Numberofpolepairs = 4.0F *
          mcb_pmsm_qep_offset_f28379d_B.Merge;

        /* Rounding: '<S65>/Floor' */
        mcb_pmsm_qep_offset_f28379d_B.Floor = (real32_T)floor
          (mcb_pmsm_qep_offset_f28379d_B.Numberofpolepairs);

        /* Sum: '<S65>/Add' */
        mcb_pmsm_qep_offset_f28379d_B.Add_c =
          mcb_pmsm_qep_offset_f28379d_B.Numberofpolepairs -
          mcb_pmsm_qep_offset_f28379d_B.Floor;

        /* DataStoreRead: '<S11>/Data Store Read' */
        mcb_pmsm_qep_offset_f28379d_B.DataStoreRead =
          mcb_pmsm_qep_offset_f2837_DWork.Enable;

        /* Outputs for Enabled SubSystem: '<S11>/PosGen' incorporates:
         *  EnablePort: '<S18>/Enable'
         */
        if (mcb_pmsm_qep_offset_f28379d_B.DataStoreRead) {
          if (!mcb_pmsm_qep_offset_f2837_DWork.PosGen_MODE) {
            /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
            mcb_pmsm_qep_offset_f2837_DWork.UnitDelay_DSTATE = 0.0F;
            mcb_pmsm_qep_offset_f2837_DWork.PosGen_MODE = true;
          }

          /* Outputs for Enabled SubSystem: '<S18>/Up Counter' incorporates:
           *  EnablePort: '<S26>/Enable'
           */
          if (!mcb_pmsm_qep_offset_f2837_DWork.UpCounter_MODE) {
            /* InitializeConditions for Delay: '<S26>/Delay' */
            mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_n = 0UL;
            mcb_pmsm_qep_offset_f2837_DWork.UpCounter_MODE = true;
          }

          /* Delay: '<S26>/Delay' */
          mcb_pmsm_qep_offset_f28379d_B.Delay =
            mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_n;

          /* Sum: '<S26>/Add1' incorporates:
           *  Constant: '<S26>/Constant'
           */
          tmp = mcb_pmsm_qep_offset_f28379d_B.Delay + 1ULL;
          if (tmp > 4294967295ULL) {
            tmp = 4294967295ULL;
          }

          /* Sum: '<S26>/Add1' */
          mcb_pmsm_qep_offset_f28379d_B.Add1 = (uint32_T)tmp;

          /* Update for Delay: '<S26>/Delay' */
          mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_n =
            mcb_pmsm_qep_offset_f28379d_B.Add1;

          /* End of Outputs for SubSystem: '<S18>/Up Counter' */

          /* RelationalOperator: '<S23>/Compare' incorporates:
           *  Constant: '<S23>/Constant'
           */
          mcb_pmsm_qep_offset_f28379d_B.Compare_b =
            (mcb_pmsm_qep_offset_f28379d_B.Add1 <= 300000UL);

          /* Logic: '<S18>/NOT' */
          mcb_pmsm_qep_offset_f28379d_B.NOT_p =
            !mcb_pmsm_qep_offset_f28379d_B.Compare_b;

          /* Outputs for Enabled SubSystem: '<S18>/Subsystem' incorporates:
           *  EnablePort: '<S24>/Enable'
           */
          if (mcb_pmsm_qep_offset_f28379d_B.NOT_p) {
            /* DataStoreWrite: '<S24>/Data Store Write' incorporates:
             *  Constant: '<S24>/Constant'
             */
            mcb_pmsm_qep_offset_f2837_DWork.Enable = false;
          }

          /* End of Outputs for SubSystem: '<S18>/Subsystem' */

          /* RelationalOperator: '<S27>/Compare' incorporates:
           *  Constant: '<S27>/Constant'
           */
          mcb_pmsm_qep_offset_f28379d_B.Compare_p =
            (mcb_pmsm_qep_offset_f28379d_B.Add1 >= 200000UL);

          /* If: '<S25>/If' incorporates:
           *  Constant: '<S25>/Count for 10 sec'
           *  Constant: '<S25>/Count for 2 sec'
           */
          if (mcb_pmsm_qep_offset_f28379d_B.Add1 < 40000UL) {
            /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem' incorporates:
             *  ActionPort: '<S28>/Action Port'
             */
            /* Merge: '<S25>/Merge' incorporates:
             *  Constant: '<S28>/Constant'
             */
            mcb_pmsm_qep_offset_f28379d_B.Merge_g = 0.0F;

            /* End of Outputs for SubSystem: '<S25>/If Action Subsystem' */
          } else if (mcb_pmsm_qep_offset_f28379d_B.Add1 < 200000UL) {
            /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S29>/Action Port'
             */
            /* Delay: '<S29>/Delay' */
            mcb_pmsm_qep_offset_f28379d_B.Delay_f =
              mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE;

            /* Sum: '<S29>/Add1' incorporates:
             *  Constant: '<S29>/Constant1'
             */
            mcb_pmsm_qep_offset_f28379d_B.Add1_a =
              mcb_pmsm_qep_offset_f28379d_B.Delay_f + 0.001F;

            /* Saturate: '<S29>/Saturate to 'motor.calibSpeed' RPM' */
            u0_p = mcb_pmsm_qep_offset_f28379d_B.Add1_a;
            if (u0_p > 4.0F) {
              /* Saturate: '<S29>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = 4.0F;
            } else if (u0_p < 0.0F) {
              /* Saturate: '<S29>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = 0.0F;
            } else {
              /* Saturate: '<S29>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = u0_p;
            }

            /* End of Saturate: '<S29>/Saturate to 'motor.calibSpeed' RPM' */

            /* Merge: '<S25>/Merge' incorporates:
             *  Gain: '<S29>/Multiply'
             */
            mcb_pmsm_qep_offset_f28379d_B.Merge_g = 5.0E-5F *
              mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM;

            /* Update for Delay: '<S29>/Delay' */
            mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE =
              mcb_pmsm_qep_offset_f28379d_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S25>/If Action Subsystem2' */
          }

          /* End of If: '<S25>/If' */

          /* UnitDelay: '<S30>/Unit Delay' */
          mcb_pmsm_qep_offset_f28379d_B.UnitDelay =
            mcb_pmsm_qep_offset_f2837_DWork.UnitDelay_DSTATE;

          /* Logic: '<S30>/NOT' incorporates:
           *  Constant: '<S30>/Constant_Reset'
           */
          mcb_pmsm_qep_offset_f28379d_B.NOT_j = true;

          /* Outputs for Enabled SubSystem: '<S30>/Accumulate' incorporates:
           *  EnablePort: '<S32>/Enable'
           */
          /* Delay: '<S32>/Delay' */
          mcb_pmsm_qep_offset_f28379d_B.Delay_i =
            mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_o;

          /* Outputs for Enabled SubSystem: '<S32>/Subsystem' incorporates:
           *  EnablePort: '<S33>/Enable'
           */
          if (mcb_pmsm_qep_offset_f28379d_B.Delay_i) {
            /* SignalConversion generated from: '<S33>/Input' */
            mcb_pmsm_qep_offset_f28379d_B.Input =
              mcb_pmsm_qep_offset_f28379d_B.Merge_g;
          }

          /* End of Outputs for SubSystem: '<S32>/Subsystem' */

          /* Sum: '<S32>/Add' */
          mcb_pmsm_qep_offset_f28379d_B.Add_d =
            mcb_pmsm_qep_offset_f28379d_B.Input +
            mcb_pmsm_qep_offset_f28379d_B.UnitDelay;

          /* DataTypeConversion: '<S32>/Data Type Conversion' */
          mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion_i = (int16_T)
            (real32_T)floor(mcb_pmsm_qep_offset_f28379d_B.Add_d);

          /* DataTypeConversion: '<S32>/Data Type Conversion1' */
          mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1_c =
            mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion_i;

          /* Sum: '<S32>/Add1' */
          mcb_pmsm_qep_offset_f28379d_B.Add1_j =
            mcb_pmsm_qep_offset_f28379d_B.Add_d -
            mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1_c;

          /* Update for Delay: '<S32>/Delay' incorporates:
           *  Constant: '<S32>/Constant'
           */
          mcb_pmsm_qep_offset_f2837_DWork.Delay_DSTATE_o = true;

          /* End of Outputs for SubSystem: '<S30>/Accumulate' */

          /* Outputs for Enabled SubSystem: '<S25>/Subsystem' incorporates:
           *  EnablePort: '<S31>/Enable'
           */
          if (mcb_pmsm_qep_offset_f28379d_B.Compare_p) {
            mcb_pmsm_qep_offset_f2837_DWork.Subsystem_MODE = true;

            /* Gain: '<S31>/Multiply' */
            mcb_pmsm_qep_offset_f28379d_B.Multiply = 0.25F *
              mcb_pmsm_qep_offset_f28379d_B.Add_c;

            /* Switch: '<S25>/Switch' incorporates:
             *  Constant: '<S25>/Constant'
             */
            mcb_pmsm_qep_offset_f28379d_B.Switch_b = 0.0F;
          } else {
            if (mcb_pmsm_qep_offset_f2837_DWork.Subsystem_MODE) {
              /* Disable for Gain: '<S31>/Multiply' incorporates:
               *  Outport: '<S31>/Offset'
               */
              mcb_pmsm_qep_offset_f28379d_B.Multiply = 0.0F;
              mcb_pmsm_qep_offset_f2837_DWork.Subsystem_MODE = false;
            }

            /* Switch: '<S25>/Switch' */
            mcb_pmsm_qep_offset_f28379d_B.Switch_b =
              mcb_pmsm_qep_offset_f28379d_B.Add1_j;
          }

          /* End of Outputs for SubSystem: '<S25>/Subsystem' */

          /* Update for UnitDelay: '<S30>/Unit Delay' */
          mcb_pmsm_qep_offset_f2837_DWork.UnitDelay_DSTATE =
            mcb_pmsm_qep_offset_f28379d_B.Add1_j;
        } else if (mcb_pmsm_qep_offset_f2837_DWork.PosGen_MODE) {
          /* Disable for Enabled SubSystem: '<S18>/Up Counter' */
          if (mcb_pmsm_qep_offset_f2837_DWork.UpCounter_MODE) {
            /* Disable for Sum: '<S26>/Add1' incorporates:
             *  Outport: '<S26>/Count'
             */
            mcb_pmsm_qep_offset_f28379d_B.Add1 = 0UL;
            mcb_pmsm_qep_offset_f2837_DWork.UpCounter_MODE = false;
          }

          /* End of Disable for SubSystem: '<S18>/Up Counter' */

          /* Disable for Enabled SubSystem: '<S25>/Subsystem' */
          if (mcb_pmsm_qep_offset_f2837_DWork.Subsystem_MODE) {
            /* Disable for Gain: '<S31>/Multiply' incorporates:
             *  Outport: '<S31>/Offset'
             */
            mcb_pmsm_qep_offset_f28379d_B.Multiply = 0.0F;
            mcb_pmsm_qep_offset_f2837_DWork.Subsystem_MODE = false;
          }

          /* End of Disable for SubSystem: '<S25>/Subsystem' */

          /* Disable for RelationalOperator: '<S23>/Compare' incorporates:
           *  Outport: '<S18>/EnPWM'
           */
          mcb_pmsm_qep_offset_f28379d_B.Compare_b = false;
          mcb_pmsm_qep_offset_f2837_DWork.PosGen_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S11>/PosGen' */

        /* Switch: '<S3>/Switch' */
        if (mcb_pmsm_qep_offset_f28379d_B.Compare_b) {
          /* Switch: '<S3>/Switch' */
          mcb_pmsm_qep_offset_f28379d_B.Switch_k =
            mcb_pmsm_qep_offset_f28379d_B.Add_c;
        } else {
          /* Switch: '<S3>/Switch' incorporates:
           *  Constant: '<S3>/Constant'
           */
          mcb_pmsm_qep_offset_f28379d_B.Switch_k = -1.0F;
        }

        /* End of Switch: '<S3>/Switch' */

        /* SignalConversion generated from: '<S52>/Byte Pack' */
        mcb_pmsm_qep_offset_f28379d_B.TmpSignalConversionAtBytePackIn[0] =
          mcb_pmsm_qep_offset_f28379d_B.Switch_k;
        mcb_pmsm_qep_offset_f28379d_B.TmpSignalConversionAtBytePackIn[1] =
          mcb_pmsm_qep_offset_f28379d_B.Multiply;

        /* S-Function (any2byte_svd): '<S52>/Byte Pack' */

        /* Pack: <S52>/Byte Pack */
        {
          uint32_T MW_outputPortOffset = 0U;
          uint16_T MW_inputPortWidth = 0U;

          /* Packed output data type - uint32_T */
          void* packData = &mcb_pmsm_qep_offset_f28379d_B.BytePack[0];

          /* Packing the values of Input 1 */
          /* Input data type - real32_T, size - 2 */
          {
            MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
            memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
                   &mcb_pmsm_qep_offset_f28379d_B.TmpSignalConversionAtBytePackIn
                   [0], MW_inputPortWidth);
          }
        }

        /* If: '<S50>/If' */
        if (mcb_pmsm_qep_offset_f28379d_B.Output == 0U) {
          /* Outputs for IfAction SubSystem: '<S50>/Start' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  Constant: '<S56>/Start'
           *  SignalConversion generated from: '<S56>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[0] = 1397969747UL;

          /* SignalConversion generated from: '<S56>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S50>/Start' */
          mcb_pmsm_qep_offset_f28379d_B.Data_fw[0] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/Start' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  SignalConversion generated from: '<S56>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[1] = Data;

          /* SignalConversion generated from: '<S56>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S50>/Start' */
          mcb_pmsm_qep_offset_f28379d_B.Data_fw[1] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/Start' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  SignalConversion generated from: '<S56>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[2] = Data;

          /* Merge: '<S50>/Merge1' incorporates:
           *  Bias: '<S56>/Bias'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_qep_offset_f283_ConstB.Width + 1UL;

          /* End of Outputs for SubSystem: '<S50>/Start' */
        } else if (mcb_pmsm_qep_offset_f28379d_B.Output == 599U) {
          /* Outputs for IfAction SubSystem: '<S50>/End' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* SignalConversion generated from: '<S55>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S50>/End' */
          mcb_pmsm_qep_offset_f28379d_B.Data_f[0] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/End' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  SignalConversion generated from: '<S55>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[0] = Data;

          /* SignalConversion generated from: '<S55>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S50>/End' */
          mcb_pmsm_qep_offset_f28379d_B.Data_f[1] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/End' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  Constant: '<S55>/End'
           *  SignalConversion generated from: '<S55>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[1] = Data;
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[2] = 1162167621UL;

          /* Merge: '<S50>/Merge1' incorporates:
           *  Bias: '<S55>/Bias'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_qep_offset_f283_ConstB.Width + 1UL;

          /* End of Outputs for SubSystem: '<S50>/End' */
        } else {
          /* Outputs for IfAction SubSystem: '<S50>/Data' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* SignalConversion generated from: '<S54>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S50>/Data' */
          mcb_pmsm_qep_offset_f28379d_B.Data[0] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/Data' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  SignalConversion generated from: '<S54>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[0] = Data;

          /* SignalConversion generated from: '<S54>/Data' */
          Data = mcb_pmsm_qep_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S50>/Data' */
          mcb_pmsm_qep_offset_f28379d_B.Data[1] = Data;

          /* Outputs for IfAction SubSystem: '<S50>/Data' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Merge: '<S50>/Merge' incorporates:
           *  Constant: '<S54>/Dummy'
           *  SignalConversion generated from: '<S54>/Data_out'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[1] = Data;
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[2] = 0UL;

          /* Merge: '<S50>/Merge1' incorporates:
           *  SignalConversion generated from: '<S54>/Data_width'
           */
          mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_qep_offset_f283_ConstB.Width;

          /* End of Outputs for SubSystem: '<S50>/Data' */
        }

        /* End of If: '<S50>/If' */

        /* Outputs for Iterator SubSystem: '<S12>/While Iterator Subsystem' incorporates:
         *  WhileIterator: '<S51>/While Iterator'
         */
        s51_iter = 1;
        do {
          mcb_pmsm_qep_offset_f28379d_B.WhileIterator = s51_iter;
          mcb_pmsm_qep_offset_f28379d_B.IndexVector =
            mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Data[mcb_pmsm_qep_offset_f28379d_B.WhileIterator
            - 1];

          {
            if (checkSCITransmitInProgressA != 1U) {
              checkSCITransmitInProgressA = 1U;
              int16_T errFlgHeader = NOERROR;
              int16_T errFlgData = NOERROR;
              int16_T errFlgTail = NOERROR;
              errFlgData = scia_xmit((uchar_T*)
                &mcb_pmsm_qep_offset_f28379d_B.IndexVector, 4, 4);
              checkSCITransmitInProgressA = 0U;
            }
          }

          mcb_pmsm_qep_offset_f28379d_B.Add =
            mcb_pmsm_qep_offset_f28379d_B.SCI_Tx_Iteration - (uint32_T)
            mcb_pmsm_qep_offset_f28379d_B.WhileIterator;
          s51_iter++;
        } while (mcb_pmsm_qep_offset_f28379d_B.Add != 0UL);

        /* End of Outputs for SubSystem: '<S12>/While Iterator Subsystem' */

        /* Sum: '<S57>/FixPt Sum1' incorporates:
         *  Constant: '<S57>/FixPt Constant'
         */
        mcb_pmsm_qep_offset_f28379d_B.FixPtSum1 =
          mcb_pmsm_qep_offset_f28379d_B.Output + 1U;

        /* Switch: '<S58>/FixPt Switch' */
        if (mcb_pmsm_qep_offset_f28379d_B.FixPtSum1 > 599U) {
          /* Switch: '<S58>/FixPt Switch' incorporates:
           *  Constant: '<S58>/Constant'
           */
          mcb_pmsm_qep_offset_f28379d_B.FixPtSwitch = 0U;
        } else {
          /* Switch: '<S58>/FixPt Switch' */
          mcb_pmsm_qep_offset_f28379d_B.FixPtSwitch =
            mcb_pmsm_qep_offset_f28379d_B.FixPtSum1;
        }

        /* End of Switch: '<S58>/FixPt Switch' */

        /* RelationalOperator: '<S38>/Compare' incorporates:
         *  Constant: '<S38>/Constant'
         */
        mcb_pmsm_qep_offset_f28379d_B.Compare =
          (mcb_pmsm_qep_offset_f28379d_B.Switch_b < 0.0F);

        /* DataTypeConversion: '<S36>/Data Type Conversion' */
        mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion =
          mcb_pmsm_qep_offset_f28379d_B.Compare;

        /* If: '<S36>/If' */
        if (mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion > 0U) {
          /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* DataTypeConversion: '<S39>/Convert_uint16' */
          mcb_pmsm_qep_offset_f28379d_B.Convert_uint16_c = (int16_T)(real32_T)
            floor(mcb_pmsm_qep_offset_f28379d_B.Switch_b);

          /* DataTypeConversion: '<S39>/Convert_back' */
          mcb_pmsm_qep_offset_f28379d_B.Convert_back_g =
            mcb_pmsm_qep_offset_f28379d_B.Convert_uint16_c;

          /* Merge: '<S36>/Merge' incorporates:
           *  Sum: '<S39>/Sum'
           */
          mcb_pmsm_qep_offset_f28379d_B.Merge_f =
            mcb_pmsm_qep_offset_f28379d_B.Switch_b -
            mcb_pmsm_qep_offset_f28379d_B.Convert_back_g;

          /* End of Outputs for SubSystem: '<S36>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* DataTypeConversion: '<S40>/Convert_uint16' */
          mcb_pmsm_qep_offset_f28379d_B.Convert_uint16 = (int16_T)
            mcb_pmsm_qep_offset_f28379d_B.Switch_b;

          /* DataTypeConversion: '<S40>/Convert_back' */
          mcb_pmsm_qep_offset_f28379d_B.Convert_back =
            mcb_pmsm_qep_offset_f28379d_B.Convert_uint16;

          /* Merge: '<S36>/Merge' incorporates:
           *  Sum: '<S40>/Sum'
           */
          mcb_pmsm_qep_offset_f28379d_B.Merge_f =
            mcb_pmsm_qep_offset_f28379d_B.Switch_b -
            mcb_pmsm_qep_offset_f28379d_B.Convert_back;

          /* End of Outputs for SubSystem: '<S36>/If Action Subsystem1' */
        }

        /* End of If: '<S36>/If' */

        /* Gain: '<S34>/indexing' */
        mcb_pmsm_qep_offset_f28379d_B.indexing = 800.0F *
          mcb_pmsm_qep_offset_f28379d_B.Merge_f;

        /* DataTypeConversion: '<S34>/Get_Integer' */
        mcb_pmsm_qep_offset_f28379d_B.Get_Integer = (uint16_T)
          mcb_pmsm_qep_offset_f28379d_B.indexing;

        /* Sum: '<S34>/Sum' incorporates:
         *  Constant: '<S34>/offset'
         */
        Data = mcb_pmsm_qep_offset_f28379d_B.Get_Integer + 1UL;
        mcb_pmsm_qep_offset_f28379d_B.Sum[0] = Data;

        /* Selector: '<S34>/Lookup' incorporates:
         *  Constant: '<S34>/sine_table_values'
         */
        mcb_pmsm_qep_offset_f28379d_B.Lookup[0] =
          mcb_pmsm_qep_offset_f283_ConstP.sine_table_values_Value[(int16_T)Data];

        /* Sum: '<S34>/Sum' */
        Data = mcb_pmsm_qep_offset_f28379d_B.Get_Integer;
        mcb_pmsm_qep_offset_f28379d_B.Sum[1] = Data;

        /* Selector: '<S34>/Lookup' incorporates:
         *  Constant: '<S34>/sine_table_values'
         */
        mcb_pmsm_qep_offset_f28379d_B.Lookup[1] =
          mcb_pmsm_qep_offset_f283_ConstP.sine_table_values_Value[(int16_T)Data];

        /* Sum: '<S34>/Sum' incorporates:
         *  Constant: '<S34>/offset'
         */
        Data = mcb_pmsm_qep_offset_f28379d_B.Get_Integer + 201UL;
        mcb_pmsm_qep_offset_f28379d_B.Sum[2] = Data;

        /* Selector: '<S34>/Lookup' incorporates:
         *  Constant: '<S34>/sine_table_values'
         */
        mcb_pmsm_qep_offset_f28379d_B.Lookup[2] =
          mcb_pmsm_qep_offset_f283_ConstP.sine_table_values_Value[(int16_T)Data];

        /* Sum: '<S34>/Sum' incorporates:
         *  Constant: '<S34>/offset'
         */
        Data = mcb_pmsm_qep_offset_f28379d_B.Get_Integer + 200UL;
        mcb_pmsm_qep_offset_f28379d_B.Sum[3] = Data;

        /* Selector: '<S34>/Lookup' incorporates:
         *  Constant: '<S34>/sine_table_values'
         */
        mcb_pmsm_qep_offset_f28379d_B.Lookup[3] =
          mcb_pmsm_qep_offset_f283_ConstP.sine_table_values_Value[(int16_T)Data];

        /* Sum: '<S35>/Sum3' */
        mcb_pmsm_qep_offset_f28379d_B.Sum3 =
          mcb_pmsm_qep_offset_f28379d_B.Lookup[0] -
          mcb_pmsm_qep_offset_f28379d_B.Lookup[1];

        /* DataTypeConversion: '<S34>/Data Type Conversion1' */
        mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1 =
          mcb_pmsm_qep_offset_f28379d_B.Get_Integer;

        /* Sum: '<S34>/Sum2' */
        mcb_pmsm_qep_offset_f28379d_B.Sum2 =
          mcb_pmsm_qep_offset_f28379d_B.indexing -
          mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion1;

        /* Product: '<S35>/Product' */
        mcb_pmsm_qep_offset_f28379d_B.Product_j =
          mcb_pmsm_qep_offset_f28379d_B.Sum3 *
          mcb_pmsm_qep_offset_f28379d_B.Sum2;

        /* Sum: '<S35>/Sum4' */
        mcb_pmsm_qep_offset_f28379d_B.Sum4 =
          mcb_pmsm_qep_offset_f28379d_B.Product_j +
          mcb_pmsm_qep_offset_f28379d_B.Lookup[1];

        /* Sum: '<S35>/Sum5' */
        mcb_pmsm_qep_offset_f28379d_B.Sum5 =
          mcb_pmsm_qep_offset_f28379d_B.Lookup[2] -
          mcb_pmsm_qep_offset_f28379d_B.Lookup[3];

        /* Product: '<S35>/Product1' */
        mcb_pmsm_qep_offset_f28379d_B.Product1 =
          mcb_pmsm_qep_offset_f28379d_B.Sum5 *
          mcb_pmsm_qep_offset_f28379d_B.Sum2;

        /* Sum: '<S35>/Sum6' */
        mcb_pmsm_qep_offset_f28379d_B.Sum6 =
          mcb_pmsm_qep_offset_f28379d_B.Product1 +
          mcb_pmsm_qep_offset_f28379d_B.Lookup[3];

        /* Outputs for Atomic SubSystem: '<S17>/Two inputs CRL' */
        /* Product: '<S21>/qcos' incorporates:
         *  Constant: '<S11>/Constant'
         */
        mcb_pmsm_qep_offset_f28379d_B.qcos = 0.0F *
          mcb_pmsm_qep_offset_f28379d_B.Sum6;

        /* Product: '<S21>/dsin' incorporates:
         *  Constant: '<S11>/Vd_Ref'
         */
        mcb_pmsm_qep_offset_f28379d_B.dsin = 0.15F *
          mcb_pmsm_qep_offset_f28379d_B.Sum4;

        /* Sum: '<S21>/sum_beta' */
        mcb_pmsm_qep_offset_f28379d_B.sum_beta =
          mcb_pmsm_qep_offset_f28379d_B.qcos +
          mcb_pmsm_qep_offset_f28379d_B.dsin;

        /* Product: '<S21>/dcos' incorporates:
         *  Constant: '<S11>/Vd_Ref'
         */
        mcb_pmsm_qep_offset_f28379d_B.dcos = 0.15F *
          mcb_pmsm_qep_offset_f28379d_B.Sum6;

        /* Product: '<S21>/qsin' incorporates:
         *  Constant: '<S11>/Constant'
         */
        mcb_pmsm_qep_offset_f28379d_B.qsin = 0.0F *
          mcb_pmsm_qep_offset_f28379d_B.Sum4;

        /* Sum: '<S21>/sum_alpha' */
        mcb_pmsm_qep_offset_f28379d_B.sum_alpha =
          mcb_pmsm_qep_offset_f28379d_B.dcos -
          mcb_pmsm_qep_offset_f28379d_B.qsin;

        /* Switch: '<S22>/Switch' */
        mcb_pmsm_qep_offset_f28379d_B.Switch_k5[0] =
          mcb_pmsm_qep_offset_f28379d_B.sum_alpha;
        mcb_pmsm_qep_offset_f28379d_B.Switch_k5[1] =
          mcb_pmsm_qep_offset_f28379d_B.sum_beta;

        /* AlgorithmDescriptorDelegate generated from: '<S21>/a16' */
        mcb_pmsm_qep_offset_f28379d_B.algDD_o1 =
          mcb_pmsm_qep_offset_f28379d_B.Switch_k5[0];

        /* AlgorithmDescriptorDelegate generated from: '<S21>/a16' */
        mcb_pmsm_qep_offset_f28379d_B.algDD_o2 =
          mcb_pmsm_qep_offset_f28379d_B.Switch_k5[1];

        /* End of Outputs for SubSystem: '<S17>/Two inputs CRL' */

        /* Switch: '<S14>/Switch4' */
        if (mcb_pmsm_qep_offset_f28379d_B.Compare_b) {
          /* Gain: '<S48>/sqrt3_by_two' */
          mcb_pmsm_qep_offset_f28379d_B.sqrt3_by_two = 0.866025388F *
            mcb_pmsm_qep_offset_f28379d_B.algDD_o2;

          /* Gain: '<S48>/one_by_two' */
          mcb_pmsm_qep_offset_f28379d_B.one_by_two = 0.5F *
            mcb_pmsm_qep_offset_f28379d_B.algDD_o1;

          /* Sum: '<S48>/add_c' */
          mcb_pmsm_qep_offset_f28379d_B.add_c = (0.0F -
            mcb_pmsm_qep_offset_f28379d_B.one_by_two) -
            mcb_pmsm_qep_offset_f28379d_B.sqrt3_by_two;

          /* Sum: '<S48>/add_b' */
          mcb_pmsm_qep_offset_f28379d_B.add_b =
            mcb_pmsm_qep_offset_f28379d_B.sqrt3_by_two -
            mcb_pmsm_qep_offset_f28379d_B.one_by_two;

          /* MinMax: '<S45>/Min' incorporates:
           *  MinMax: '<S45>/Max'
           */
          u0_p = mcb_pmsm_qep_offset_f28379d_B.algDD_o1;
          Bias = mcb_pmsm_qep_offset_f28379d_B.add_b;
          tmp_p = rtIsNaNF(Bias);
          if ((u0_p <= Bias) || tmp_p) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_qep_offset_f28379d_B.add_c;
          tmp_e = rtIsNaNF(u0_p);
          if ((!(Bias <= u0_p)) && (!tmp_e)) {
            Bias = u0_p;
          }

          /* MinMax: '<S45>/Min' */
          mcb_pmsm_qep_offset_f28379d_B.Min = Bias;

          /* MinMax: '<S45>/Max' */
          u0_p = mcb_pmsm_qep_offset_f28379d_B.algDD_o1;
          Bias = mcb_pmsm_qep_offset_f28379d_B.add_b;
          if ((u0_p >= Bias) || tmp_p) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_qep_offset_f28379d_B.add_c;
          if ((!(Bias >= u0_p)) && (!tmp_e)) {
            Bias = u0_p;
          }

          /* MinMax: '<S45>/Max' */
          mcb_pmsm_qep_offset_f28379d_B.Max = Bias;

          /* Sum: '<S45>/Add' */
          mcb_pmsm_qep_offset_f28379d_B.Add_i =
            mcb_pmsm_qep_offset_f28379d_B.Max +
            mcb_pmsm_qep_offset_f28379d_B.Min;

          /* Gain: '<S45>/one_by_two' */
          mcb_pmsm_qep_offset_f28379d_B.one_by_two_b = -0.5F *
            mcb_pmsm_qep_offset_f28379d_B.Add_i;

          /* Sum: '<S44>/Add2' */
          mcb_pmsm_qep_offset_f28379d_B.Add2 =
            mcb_pmsm_qep_offset_f28379d_B.one_by_two_b +
            mcb_pmsm_qep_offset_f28379d_B.add_c;

          /* Sum: '<S44>/Add1' */
          mcb_pmsm_qep_offset_f28379d_B.Add1_m =
            mcb_pmsm_qep_offset_f28379d_B.add_b +
            mcb_pmsm_qep_offset_f28379d_B.one_by_two_b;

          /* Sum: '<S44>/Add3' */
          mcb_pmsm_qep_offset_f28379d_B.Add3 =
            mcb_pmsm_qep_offset_f28379d_B.algDD_o1 +
            mcb_pmsm_qep_offset_f28379d_B.one_by_two_b;

          /* Gain: '<S44>/Gain' */
          mcb_pmsm_qep_offset_f28379d_B.Gain[0] = 1.15470052F *
            mcb_pmsm_qep_offset_f28379d_B.Add3;
          mcb_pmsm_qep_offset_f28379d_B.Gain[1] = 1.15470052F *
            mcb_pmsm_qep_offset_f28379d_B.Add1_m;
          mcb_pmsm_qep_offset_f28379d_B.Gain[2] = 1.15470052F *
            mcb_pmsm_qep_offset_f28379d_B.Add2;

          /* Sum: '<S14>/Sum' incorporates:
           *  Constant: '<S14>/Constant'
           */
          Bias = mcb_pmsm_qep_offset_f28379d_B.Gain[0] + 1.0F;
          mcb_pmsm_qep_offset_f28379d_B.Sum_d[0] = Bias;

          /* Gain: '<S14>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_qep_offset_f28379d_B.Gain_h[0] = Bias;

          /* Gain: '<S14>/Scale_to_PWM_Counter_PRD' */
          u0 = (uint16_T)(5000.0F * Bias);
          mcb_pmsm_qep_offset_f28379d_B.Scale_to_PWM_Counter_PRD[0] = u0;

          /* Switch: '<S14>/Switch4' */
          mcb_pmsm_qep_offset_f28379d_B.Switch4[0] = u0;

          /* Sum: '<S14>/Sum' incorporates:
           *  Constant: '<S14>/Constant'
           */
          Bias = mcb_pmsm_qep_offset_f28379d_B.Gain[1] + 1.0F;
          mcb_pmsm_qep_offset_f28379d_B.Sum_d[1] = Bias;

          /* Gain: '<S14>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_qep_offset_f28379d_B.Gain_h[1] = Bias;

          /* Gain: '<S14>/Scale_to_PWM_Counter_PRD' */
          u0 = (uint16_T)(5000.0F * Bias);
          mcb_pmsm_qep_offset_f28379d_B.Scale_to_PWM_Counter_PRD[1] = u0;

          /* Switch: '<S14>/Switch4' */
          mcb_pmsm_qep_offset_f28379d_B.Switch4[1] = u0;

          /* Sum: '<S14>/Sum' incorporates:
           *  Constant: '<S14>/Constant'
           */
          Bias = mcb_pmsm_qep_offset_f28379d_B.Gain[2] + 1.0F;
          mcb_pmsm_qep_offset_f28379d_B.Sum_d[2] = Bias;

          /* Gain: '<S14>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_qep_offset_f28379d_B.Gain_h[2] = Bias;

          /* Gain: '<S14>/Scale_to_PWM_Counter_PRD' */
          u0 = (uint16_T)(5000.0F * Bias);
          mcb_pmsm_qep_offset_f28379d_B.Scale_to_PWM_Counter_PRD[2] = u0;

          /* Switch: '<S14>/Switch4' */
          mcb_pmsm_qep_offset_f28379d_B.Switch4[2] = u0;
        } else {
          /* Switch: '<S14>/Switch4' incorporates:
           *  Constant: '<S14>/stop'
           */
          mcb_pmsm_qep_offset_f28379d_B.Switch4[0] = 0.0F;
          mcb_pmsm_qep_offset_f28379d_B.Switch4[1] = 0.0F;
          mcb_pmsm_qep_offset_f28379d_B.Switch4[2] = 0.0F;
        }

        /* End of Switch: '<S14>/Switch4' */

        /* S-Function (c2802xpwm): '<S15>/ePWM1' */
        uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_qep_offset_f28379d_B.Switch4[0]);
        }

        /* S-Function (c2802xpwm): '<S15>/ePWM2' */
        uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_qep_offset_f28379d_B.Switch4[1]);
        }

        /* S-Function (c2802xpwm): '<S15>/ePWM3' */
        uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

        /*-- Update CMPA value for ePWM3 --*/
        {
          EPwm3Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_qep_offset_f28379d_B.Switch4[2]);
        }

        /* Switch: '<S15>/Switch' */
        mcb_pmsm_qep_offset_f28379d_B.Switch_j =
          mcb_pmsm_qep_offset_f28379d_B.Compare_b;

        /* S-Function (c280xgpio_do): '<S15>/DRV830x Enable' */
        {
          if (mcb_pmsm_qep_offset_f28379d_B.Switch_j) {
            GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
          } else {
            GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
          }
        }

        /* S-Function (c2802xadc): '<S3>/ADC_B_IN2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          mcb_pmsm_qep_offset_f28379d_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
        }

        /* S-Function (c2802xadc): '<S3>/ADC_C_IN2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          mcb_pmsm_qep_offset_f28379d_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
        }

        /* Update for UnitDelay: '<S53>/Output' */
        mcb_pmsm_qep_offset_f2837_DWork.Output_DSTATE =
          mcb_pmsm_qep_offset_f28379d_B.FixPtSwitch;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */
    }
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

/* Hardware Interrupt Block: '<S10>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S80>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[2];
        for (i = 0; i < 2; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 4, 4);
          if ((errFlg != NOERROR) && (errFlg != PARTIALDATA)) {
            mcb_pmsm_qep_offset_f28379d_B.SCIReceive = 0.0;
          }

          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_qep_offset_f28379d_B.SCIReceive, recbuff,2);
          }
        }
      }

      /* DataTypeConversion: '<S4>/Data Type Conversion' */
      mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion_o =
        (mcb_pmsm_qep_offset_f28379d_B.SCIReceive != 0.0F);

      /* DataStoreWrite: '<S4>/Data Store Write' */
      mcb_pmsm_qep_offset_f2837_DWork.Enable =
        mcb_pmsm_qep_offset_f28379d_B.DataTypeConversion_o;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_qep_offset_f28379d_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
