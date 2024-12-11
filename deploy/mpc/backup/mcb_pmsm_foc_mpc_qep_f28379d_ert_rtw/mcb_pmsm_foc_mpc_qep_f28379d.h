/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_mpc_qep_f28379d.h
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

#ifndef mcb_pmsm_foc_mpc_qep_f28379d_h_
#define mcb_pmsm_foc_mpc_qep_f28379d_h_
#ifndef mcb_pmsm_foc_mpc_qep_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_mpc_qep_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                       /* mcb_pmsm_foc_mpc_qep_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_mpc_qep_f28379d_types.h"
#include "rtGetNaN.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<S147>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SP_T obj; /* '<S147>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S147>/SPI Master Transfer' */
} DW_SPIMasterTransfer_mcb_pmsm_T;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S217>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S197>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S197>/Integrator' */
} DW_SpeedControl_mcb_pmsm_foc__T;

/* Block signals (default storage) */
typedef struct {
  real32_T a__1[42];
  real32_T b_Mlim[42];
  real32_T cTol[42];
  uint32_T IndexVector;                /* '<S124>/Index Vector' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SCIReceive[2];              /* '<S156>/SCI Receive' */
  real32_T Add1;                       /* '<S97>/Add1' */
  real32_T Eps;                        /* '<S70>/Ramp Generator' */
  real32_T Ka;                         /* '<S74>/Ka' */
  real32_T Kb;                         /* '<S74>/Kb' */
  real32_T Kc;                         /* '<S74>/Kc' */
  real32_T Add1_c;                     /* '<S85>/Add1' */
  real32_T Input;                      /* '<S86>/Input' */
  real32_T Idq_ref_PU[2];              /* '<S15>/Idq_ref_PU' */
  real32_T Gain[3];                    /* '<S63>/Gain' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Switch;                     /* '<S120>/Switch' */
  uint16_T ADC_A_IN0;                  /* '<S141>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S141>/ADC_B_IN0' */
  uint16_T Sum;                        /* '<S146>/Sum' */
  uint16_T Sum1;                       /* '<S146>/Sum1' */
  uint16_T eQEP_o1;                    /* '<S87>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S87>/eQEP' */
  uint16_T ADC_C_IN2;                  /* '<S87>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S87>/ADC_B_IN2' */
  uint16_T Switch_c;                   /* '<S139>/Switch' */
  boolean_T AND;                       /* '<S91>/AND' */
} B_mcb_pmsm_foc_mpc_qep_f28379_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T RampGenerator_DSTATE;       /* '<S70>/Ramp Generator' */
  real32_T Delay_DSTATE[2];            /* '<S25>/Delay' */
  real32_T last_mv_DSTATE[2];          /* '<S27>/last_mv' */
  uint32_T Delay_DSTATE_p[20];         /* '<S94>/Delay' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  volatile real32_T RT1_Buffer0;       /* '<Root>/RT1' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  real32_T last_x_PreviousInput[4];    /* '<S27>/last_x' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S149>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_e;    /* '<S139>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S139>/Digital Output1' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S120>/DRV830x Enable' */
  uint16_T Output_DSTATE;              /* '<S126>/Output' */
  uint16_T Delay3_DSTATE;              /* '<S91>/Delay3' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory6' */
  uint16_T Memory_PreviousInput;       /* '<S146>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S146>/Memory1' */
  uint16_T CircBufIdx;                 /* '<S94>/Delay' */
  boolean_T Delay_DSTATE_j;            /* '<S85>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T Memory_PreviousInput_k[42];/* '<S27>/Memory' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S8>/Open Loop Start-Up' */
  DW_SpeedControl_mcb_pmsm_foc__T SpeedControl;/* '<Root>/Speed Control' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer1;/* '<S147>/SPI Master Transfer' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer;/* '<S147>/SPI Master Transfer' */
} DW_mcb_pmsm_foc_mpc_qep_f2837_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S53>/sine_table_values'
   *   '<S77>/sine_table_values'
   */
  real32_T pooled14[1002];
} ConstP_mcb_pmsm_foc_mpc_qep_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_mpc_qep__T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_mcb_pmsm_foc_mpc_qep_f28379_T mcb_pmsm_foc_mpc_qep_f28379d_B;

/* Block states (default storage) */
extern DW_mcb_pmsm_foc_mpc_qep_f2837_T mcb_pmsm_foc_mpc_qep_f28379d_DW;

/* Constant parameters (default storage) */
extern const ConstP_mcb_pmsm_foc_mpc_qep_f_T mcb_pmsm_foc_mpc_qep_f28_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_mpc_qep_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_mpc_qep_f28379d_initialize(void);
extern void mcb_pmsm_foc_mpc_qep_f28379d_step0(void);/* Sample time: [0.0002s, 0.0s] */
extern void mcb_pmsm_foc_mpc_qep_f28379d_step1(void);/* Sample time: [0.001s, 0.0s] */
extern void mcb_pmsm_foc_mpc_qep_f28379d_step2(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_mpc_qep_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_mpc_qep_T *const mcb_pmsm_foc_mpc_qep_f28379d_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_mpc_qep_f28379d_configure_interrupts (void);
  void mcb_pmsm_foc_mpc_qep_f28379d_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mcb_pmsm_foc_mpc_qep_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/HW Interrupt'
 * '<S3>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Inverter and Motor - Plant Model'
 * '<S6>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive'
 * '<S7>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control'
 * '<S8>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System'
 * '<S9>'   : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Debug_signals'
 * '<S10>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/HW_Inputs'
 * '<S11>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling'
 * '<S12>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Inverter'
 * '<S13>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Output Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx'
 * '<S15>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control'
 * '<S16>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up'
 * '<S17>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform'
 * '<S18>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers'
 * '<S19>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S20>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S22>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator'
 * '<S23>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform/Two phase input'
 * '<S24>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S25>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC'
 * '<S26>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller'
 * '<S27>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC'
 * '<S28>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S29>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S30>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S31>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check'
 * '<S32>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S33>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check2'
 * '<S34>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S35>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S36>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check5'
 * '<S37>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check6'
 * '<S38>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check7'
 * '<S39>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Preview Signal Check8'
 * '<S40>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S41>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S42>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S43>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Vector Signal Check'
 * '<S44>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S45>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S46>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/moorx'
 * '<S47>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/optimizer'
 * '<S48>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/Current_ControllerMPC/MPC Controller/MPC/optimizer/optimizer'
 * '<S49>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL'
 * '<S50>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S51>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform/Two inputs CRL'
 * '<S52>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S53>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S54>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S55>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S56>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S57>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S58>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S59>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S60>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S61>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S62>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S63>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S64>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S65>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S66>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S67>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S68>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S69>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator'
 * '<S70>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Ramp Generator'
 * '<S71>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S72>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S73>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S74>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Two phase input'
 * '<S75>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL'
 * '<S76>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S77>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S78>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S79>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S80>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S81>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S82>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S83>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S84>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S85>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator/Accumulate'
 * '<S86>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator/Accumulate/Subsystem'
 * '<S87>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S88>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed'
 * '<S89>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S90>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S91>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder'
 * '<S92>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S93>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S94>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S95>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S96>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S97>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S98>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant'
 * '<S99>'  : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant1'
 * '<S100>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S101>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S102>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S103>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S104>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S105>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S106>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S107>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S108>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S109>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S110>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S111>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S112>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S113>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S114>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S115>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S116>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S117>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S118>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S119>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S120>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/Inverter/Code Generation'
 * '<S121>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation'
 * '<S122>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx'
 * '<S123>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging'
 * '<S124>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S125>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx/Data_Type_Float'
 * '<S126>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited'
 * '<S127>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Data'
 * '<S128>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/End'
 * '<S129>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Start'
 * '<S130>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Increment Real World'
 * '<S131>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S132>' : 'mcb_pmsm_foc_mpc_qep_f28379d/HW Interrupt/Code generation'
 * '<S133>' : 'mcb_pmsm_foc_mpc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT'
 * '<S134>' : 'mcb_pmsm_foc_mpc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S135>' : 'mcb_pmsm_foc_mpc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S136>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem'
 * '<S137>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation'
 * '<S138>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S139>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S140>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S141>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S142>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S143>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S144>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S145>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S146>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S147>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable/ADC Gain setting'
 * '<S148>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Heartbeat LED/Heartbeat LED'
 * '<S149>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S150>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Inverter and Motor - Plant Model/Codegeneration'
 * '<S151>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/Data_Conditioning_Rx'
 * '<S152>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/SCI_Rx'
 * '<S153>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/unParse'
 * '<S154>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 * '<S155>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/SCI_Rx/Code Generation'
 * '<S156>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Serial Receive/SCI_Rx/Code Generation/Data_Type_Float'
 * '<S157>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed'
 * '<S158>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/Speed_Ref_Selector'
 * '<S159>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S160>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S161>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S162>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S163>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S164>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S165>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S166>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S167>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S168>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S169>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S170>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S171>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S172>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S173>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S174>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S175>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S176>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S177>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S178>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S179>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S180>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S181>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S182>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S183>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S184>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S185>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S186>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S187>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S188>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S189>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S190>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S191>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S192>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S193>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S194>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S195>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S196>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S197>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S198>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S199>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S200>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S201>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S202>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S203>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S204>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S205>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S206>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S207>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S208>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S209>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S210>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S211>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S212>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S213>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S214>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S215>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S216>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S217>' : 'mcb_pmsm_foc_mpc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* mcb_pmsm_foc_mpc_qep_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
