/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_qep_f28379d.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_qep_f28379d'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 10 10:17:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_qep_f28379d_h_
#define mcb_pmsm_foc_qep_f28379d_h_
#ifndef mcb_pmsm_foc_qep_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_qep_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                           /* mcb_pmsm_foc_qep_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_qep_f28379d_types.h"
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

/* Block signals for system '<S19>/Two inputs CRL' */
typedef struct {
  real32_T qcos;                       /* '<S152>/qcos' */
  real32_T dsin;                       /* '<S152>/dsin' */
  real32_T sum_beta;                   /* '<S152>/sum_beta' */
  real32_T dcos;                       /* '<S152>/dcos' */
  real32_T qsin;                       /* '<S152>/qsin' */
  real32_T sum_alpha;                  /* '<S152>/sum_alpha' */
  real32_T Switch[2];                  /* '<S153>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} B_TwoinputsCRL_mcb_pmsm_foc_q_T;

/* Block signals for system '<S158>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S161>/Convert_back' */
  int16_T Convert_uint16;              /* '<S161>/Convert_uint16' */
} B_IfActionSubsystem_mcb_pmsm__T;

/* Block signals for system '<S158>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S162>/Convert_back' */
  int16_T Convert_uint16;              /* '<S162>/Convert_uint16' */
} B_IfActionSubsystem1_mcb_pmsm_T;

/* Block signals for system '<S253>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S253>/SPI Master Transfer' */
} B_SPIMasterTransfer_mcb_pmsm__T;

/* Block states (default storage) for system '<S253>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SP_T obj; /* '<S253>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S253>/SPI Master Transfer' */
} DW_SPIMasterTransfer_mcb_pmsm_T;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Id_ref;                     /* '<S7>/Id_ref' */
  real32_T Switch;                     /* '<S264>/Switch' */
  real32_T Switch1[2];                 /* '<S266>/Switch1' */
  real32_T Product;                    /* '<S323>/Product' */
  real32_T UnitDelay;                  /* '<S323>/Unit Delay' */
  real32_T Product1;                   /* '<S323>/Product1' */
  real32_T Add1;                       /* '<S323>/Add1' */
  real32_T Sum;                        /* '<S263>/Sum' */
  real32_T PProdOut;                   /* '<S308>/PProd Out' */
  real32_T Ki2;                        /* '<S263>/Ki2' */
  real32_T Integrator;                 /* '<S303>/Integrator' */
  real32_T Sum_c;                      /* '<S312>/Sum' */
  real32_T DeadZone;                   /* '<S295>/DeadZone' */
  real32_T IProdOut;                   /* '<S300>/IProd Out' */
  real32_T Switch_d;                   /* '<S293>/Switch' */
  real32_T Saturation;                 /* '<S310>/Saturation' */
  int16_T Switch1_i;                   /* '<S293>/Switch1' */
  int16_T Switch2;                     /* '<S293>/Switch2' */
  boolean_T DataStoreRead1;            /* '<S263>/Data Store Read1' */
  boolean_T DataStoreRead;             /* '<S264>/Data Store Read' */
  boolean_T DataStoreRead1_k;          /* '<S264>/Data Store Read1' */
  boolean_T AND;                       /* '<S264>/AND' */
  boolean_T LogicalOperator;           /* '<S263>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S293>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S293>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S293>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S293>/Equal1' */
  boolean_T AND3;                      /* '<S293>/AND3' */
} B_SpeedControl_mcb_pmsm_foc_q_T;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S323>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S303>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S303>/Integrator' */
} DW_SpeedControl_mcb_pmsm_foc__T;

/* Block signals (default storage) */
typedef struct {
  uint32_T PositionToCount;            /* '<S197>/PositionToCount' */
  uint32_T Delay;                      /* '<S197>/Delay' */
  uint32_T BytePack[2];                /* '<S228>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S226>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S226>/Merge1' */
  uint32_T IndexVector;                /* '<S227>/Index Vector' */
  uint32_T Add;                        /* '<S227>/Add' */
  uint32_T Data[2];                    /* '<S230>/Data' */
  uint32_T Data_f[2];                  /* '<S231>/Data' */
  uint32_T Data_fw[2];                 /* '<S232>/Data' */
  uint32_T Sum[4];                     /* '<S180>/Sum' */
  uint32_T Sum_e[4];                   /* '<S156>/Sum' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SCIReceive[2];              /* '<S262>/SCI Receive' */
  real32_T GetADCVoltage[2];           /* '<S222>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S222>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S222>/PU_Conversion' */
  real32_T DTC;                        /* '<S215>/DTC' */
  real32_T Product;                    /* '<S196>/Product' */
  real32_T Switch;                     /* '<S204>/Switch' */
  real32_T Merge;                      /* '<S205>/Merge' */
  real32_T Numberofpolepairs;          /* '<S210>/Number of pole pairs' */
  real32_T Floor;                      /* '<S206>/Floor' */
  real32_T Add_c;                      /* '<S206>/Add' */
  real32_T DataStoreRead;              /* '<S1>/Data Store Read' */
  real32_T DTC_p;                      /* '<S220>/DTC' */
  real32_T SpeedGain;                  /* '<S197>/SpeedGain' */
  real32_T Switch1[2];                 /* '<S193>/Switch1' */
  real32_T Product_m;                  /* '<S200>/Product' */
  real32_T UnitDelay;                  /* '<S200>/Unit Delay' */
  real32_T Product1;                   /* '<S200>/Product1' */
  real32_T Add1;                       /* '<S200>/Add1' */
  real32_T TmpSignalConversionAtSelectorIn[9];
  real32_T Selector[2];                /* '<S9>/Selector' */
  real32_T DataTypeConversion;         /* '<S13>/Data Type Conversion' */
  real32_T Switch_g;                   /* '<S223>/Switch' */
  real32_T Switch_b[3];                /* '<S8>/Switch' */
  real32_T One_by_Two[3];              /* '<S13>/One_by_Two' */
  real32_T PWM_Duty_Cycles[3];         /* '<S13>/Sum' */
  real32_T rpm2freq;                   /* '<S16>/rpm2freq' */
  real32_T Eps;                        /* '<S173>/Ramp Generator' */
  real32_T Product_k;                  /* '<S16>/Product' */
  real32_T Frequency;                  /* '<S16>/Abs' */
  real32_T Vbyf;                       /* '<S16>/V-by-f' */
  real32_T Correction_Factor_sinePWM;  /* '<S16>/Correction_Factor_sinePWM' */
  real32_T Amplitude;                  /* '<S16>/Saturation' */
  real32_T UnaryMinus;                 /* '<S171>/Unary Minus' */
  real32_T position_increment;         /* '<S16>/position_increment' */
  real32_T scaleIn;                    /* '<S172>/scaleIn' */
  real32_T UnitDelay_d;                /* '<S172>/Unit Delay' */
  real32_T scaleOut;                   /* '<S172>/scaleOut' */
  real32_T DataStoreRead_p;            /* '<S16>/Data Store Read' */
  real32_T Eps_g;                      /* '<S16>/Direction' */
  real32_T convert_pu;                 /* '<S182>/convert_pu' */
  real32_T Merge_h;                    /* '<S182>/Merge' */
  real32_T indexing;                   /* '<S180>/indexing' */
  real32_T Lookup[4];                  /* '<S180>/Lookup' */
  real32_T Sum3;                       /* '<S181>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S180>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S180>/Sum2' */
  real32_T Product_b;                  /* '<S181>/Product' */
  real32_T Sum4;                       /* '<S181>/Sum4' */
  real32_T Sum5;                       /* '<S181>/Sum5' */
  real32_T Product1_c;                 /* '<S181>/Product1' */
  real32_T Sum6;                       /* '<S181>/Sum6' */
  real32_T Ka;                         /* '<S177>/Ka' */
  real32_T one_by_two;                 /* '<S177>/one_by_two' */
  real32_T sqrt3_by_two;               /* '<S177>/sqrt3_by_two' */
  real32_T add_b;                      /* '<S177>/add_b' */
  real32_T Kb;                         /* '<S177>/Kb' */
  real32_T add_c;                      /* '<S177>/add_c' */
  real32_T Kc;                         /* '<S177>/Kc' */
  real32_T Divide;                     /* '<S173>/Divide' */
  real32_T Sample_Time;                /* '<S173>/Sample_Time' */
  real32_T Sum_f;                      /* '<S16>/Sum' */
  real32_T Add_m;                      /* '<S188>/Add' */
  real32_T DataTypeConversion1_f;      /* '<S188>/Data Type Conversion1' */
  real32_T Add1_c;                     /* '<S188>/Add1' */
  real32_T Input;                      /* '<S189>/Input' */
  real32_T Idq_ref_PU[2];              /* '<S15>/Idq_ref_PU' */
  real32_T Merge_b;                    /* '<S158>/Merge' */
  real32_T indexing_n;                 /* '<S156>/indexing' */
  real32_T Lookup_p[4];                /* '<S156>/Lookup' */
  real32_T Sum3_p;                     /* '<S157>/Sum3' */
  real32_T DataTypeConversion1_h;      /* '<S156>/Data Type Conversion1' */
  real32_T Sum2_j;                     /* '<S156>/Sum2' */
  real32_T Product_n;                  /* '<S157>/Product' */
  real32_T Sum4_l;                     /* '<S157>/Sum4' */
  real32_T Sum5_j;                     /* '<S157>/Sum5' */
  real32_T Product1_g;                 /* '<S157>/Product1' */
  real32_T Sum6_a;                     /* '<S157>/Sum6' */
  real32_T Sum_o;                      /* '<S27>/Sum' */
  real32_T PProdOut;                   /* '<S139>/PProd Out' */
  real32_T Kp1;                        /* '<S27>/Kp1' */
  real32_T Integrator;                 /* '<S134>/Integrator' */
  real32_T Sum_m;                      /* '<S143>/Sum' */
  real32_T Saturation;                 /* '<S141>/Saturation' */
  real32_T Sum_j;                      /* '<S26>/Sum' */
  real32_T PProdOut_g;                 /* '<S84>/PProd Out' */
  real32_T Ki1;                        /* '<S26>/Ki1' */
  real32_T Integrator_f;               /* '<S79>/Integrator' */
  real32_T Sum_g;                      /* '<S88>/Sum' */
  real32_T Saturation_f;               /* '<S86>/Saturation' */
  real32_T Switch_n;                   /* '<S30>/Switch' */
  real32_T Product_j;                  /* '<S30>/Product' */
  real32_T Product_f;                  /* '<S31>/Product' */
  real32_T Product1_gr;                /* '<S31>/Product1' */
  real32_T Sum1;                       /* '<S31>/Sum1' */
  real32_T Merge_i[2];                 /* '<S25>/Merge' */
  real32_T DeadZone;                   /* '<S71>/DeadZone' */
  real32_T IProdOut;                   /* '<S76>/IProd Out' */
  real32_T Switch_f;                   /* '<S69>/Switch' */
  real32_T DeadZone_a;                 /* '<S126>/DeadZone' */
  real32_T IProdOut_b;                 /* '<S131>/IProd Out' */
  real32_T Switch_a;                   /* '<S124>/Switch' */
  real32_T one_by_two_l;               /* '<S170>/one_by_two' */
  real32_T sqrt3_by_two_l;             /* '<S170>/sqrt3_by_two' */
  real32_T add_b_e;                    /* '<S170>/add_b' */
  real32_T add_c_m;                    /* '<S170>/add_c' */
  real32_T Max;                        /* '<S167>/Max' */
  real32_T Min;                        /* '<S167>/Min' */
  real32_T Add_n;                      /* '<S167>/Add' */
  real32_T one_by_two_lh;              /* '<S167>/one_by_two' */
  real32_T Add1_d;                     /* '<S166>/Add1' */
  real32_T Add2;                       /* '<S166>/Add2' */
  real32_T Add3;                       /* '<S166>/Add3' */
  real32_T Gain[3];                    /* '<S166>/Gain' */
  real32_T acos_b;                     /* '<S154>/acos' */
  real32_T bsin;                       /* '<S154>/bsin' */
  real32_T sum_Ds;                     /* '<S154>/sum_Ds' */
  real32_T bcos;                       /* '<S154>/bcos' */
  real32_T asin_o;                     /* '<S154>/asin' */
  real32_T sum_Qs;                     /* '<S154>/sum_Qs' */
  real32_T Switch_h[2];                /* '<S155>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Product_o[2];               /* '<S32>/Product' */
  real32_T SquareRoot;                 /* '<S32>/Square Root' */
  real32_T Switch_as;                  /* '<S32>/Switch' */
  real32_T Switch_j[2];                /* '<S29>/Switch' */
  real32_T Switch2;                    /* '<S39>/Switch2' */
  real32_T Product_bf;                 /* '<S38>/Product' */
  real32_T Sum_jr;                     /* '<S38>/Sum' */
  real32_T Product2;                   /* '<S38>/Product2' */
  real32_T Merge_d;                    /* '<S38>/Merge' */
  real32_T Gain_b;                     /* '<S38>/Gain' */
  real32_T Switch_m;                   /* '<S39>/Switch' */
  real32_T Switch1_n;                  /* '<S40>/Switch1' */
  real32_T Sqrt;                       /* '<S40>/Sqrt' */
  real32_T Gain_l;                     /* '<S40>/Gain' */
  real32_T a_plus_2b;                  /* '<S24>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S24>/one_by_sqrt3' */
  real32_T algDD_o1_e;
  real32_T algDD_o2_h;
  int32_T DataTypeConversion_c[2];     /* '<S192>/Data Type Conversion' */
  int32_T Add_e[2];                    /* '<S192>/Add' */
  int32_T SpeedCount;                  /* '<S197>/SpeedCount' */
  uint16_T Switch_c;                   /* '<S245>/Switch' */
  uint16_T Divide_o;                   /* '<S244>/Divide' */
  uint16_T Divide1;                    /* '<S244>/Divide1' */
  uint16_T ForIterator;                /* '<S247>/For Iterator' */
  uint16_T ADC_A_IN0;                  /* '<S247>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S247>/ADC_B_IN0' */
  uint16_T Memory;                     /* '<S252>/Memory' */
  uint16_T Sum_h;                      /* '<S252>/Sum' */
  uint16_T Memory1;                    /* '<S252>/Memory1' */
  uint16_T Sum1_j;                     /* '<S252>/Sum1' */
  uint16_T DataTypeConversion2;        /* '<S260>/Data Type Conversion2' */
  uint16_T BitwiseOperator;            /* '<S259>/Bitwise Operator' */
  uint16_T BitwiseOperator1;           /* '<S259>/Bitwise Operator1' */
  uint16_T ShiftArithmetic1;           /* '<S259>/Shift Arithmetic1' */
  uint16_T eQEP_o1;                    /* '<S190>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S190>/eQEP' */
  uint16_T DataStoreRead1;             /* '<S192>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S192>/Data Store Read2' */
  uint16_T ADC_C_IN2;                  /* '<S190>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S190>/ADC_B_IN2' */
  uint16_T Merge_h5;                   /* '<S196>/Merge' */
  uint16_T Output;                     /* '<S229>/Output' */
  uint16_T DataStoreRead_j;            /* '<S9>/Data Store Read' */
  uint16_T MultiportSwitch[2];         /* '<S9>/Multiport Switch' */
  uint16_T FixPtSum1;                  /* '<S233>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S234>/FixPt Switch' */
  uint16_T Switch1_j[3];               /* '<S223>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S223>/Scale_to_PWM_Counter_PRD' */
  uint16_T Sum3_a;                     /* '<S212>/Sum3' */
  uint16_T Sum7;                       /* '<S212>/Sum7' */
  uint16_T Delay3;                     /* '<S194>/Delay3' */
  uint16_T DataTypeConversion_o;       /* '<S182>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S180>/Get_Integer' */
  uint16_T Switch1_jb;                 /* '<S30>/Switch1' */
  uint16_T DataTypeConversion_p;       /* '<S158>/Data Type Conversion' */
  uint16_T Get_Integer_l;              /* '<S156>/Get_Integer' */
  uint16_T DataTypeConversion_f;       /* '<S28>/Data Type Conversion' */
  uint16_T DataTypeConversion_fl;      /* '<S38>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S227>/While Iterator' */
  int16_T DataTypeConversion_flc;      /* '<S188>/Data Type Conversion' */
  int16_T Switch1_h;                   /* '<S69>/Switch1' */
  int16_T Switch2_l;                   /* '<S69>/Switch2' */
  int16_T Switch1_l;                   /* '<S124>/Switch1' */
  int16_T Switch2_c;                   /* '<S124>/Switch2' */
  boolean_T NOT;                       /* '<S243>/NOT' */
  boolean_T DataTypeConversion3;       /* '<S259>/Data Type Conversion3' */
  boolean_T Delay_p;                   /* '<S191>/Delay' */
  boolean_T NOT_m;                     /* '<S191>/NOT' */
  boolean_T NOT_p;                     /* '<S8>/NOT' */
  boolean_T PWM_En;                    /* '<S13>/Enable' */
  boolean_T Compare;                   /* '<S201>/Compare' */
  boolean_T Compare_e;                 /* '<S202>/Compare' */
  boolean_T AND;                       /* '<S194>/AND' */
  boolean_T DataStoreRead1_c;          /* '<S16>/Data Store Read1' */
  boolean_T NOT_b;                     /* '<S173>/NOT' */
  boolean_T NOT_o;                     /* '<S172>/NOT' */
  boolean_T Compare_n;                 /* '<S184>/Compare' */
  boolean_T Delay_o;                   /* '<S188>/Delay' */
  boolean_T Compare_d;                 /* '<S160>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S27>/Logical Operator' */
  boolean_T DataStoreRead1_m;          /* '<S26>/Data Store Read1' */
  boolean_T LogicalOperator_a;         /* '<S26>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S69>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S69>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S69>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S69>/Equal1' */
  boolean_T AND3;                      /* '<S69>/AND3' */
  boolean_T RelationalOperator_e;      /* '<S124>/Relational Operator' */
  boolean_T fixforDTpropagationissue_j;
                                     /* '<S124>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_o;
                                    /* '<S124>/fix for DT propagation issue1' */
  boolean_T Equal1_i;                  /* '<S124>/Equal1' */
  boolean_T AND3_n;                    /* '<S124>/AND3' */
  boolean_T RelationalOperator_k;      /* '<S28>/Relational Operator' */
  boolean_T Compare_k;                 /* '<S34>/Compare' */
  boolean_T Compare_f;                 /* '<S35>/Compare' */
  boolean_T LowerRelop1;               /* '<S39>/LowerRelop1' */
  boolean_T RelationalOperator_l;      /* '<S38>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S39>/UpperRelop' */
  B_SpeedControl_mcb_pmsm_foc_q_T SpeedControl;/* '<Root>/Speed Control' */
  B_SPIMasterTransfer_mcb_pmsm__T SPIMasterTransfer1;/* '<S253>/SPI Master Transfer' */
  B_SPIMasterTransfer_mcb_pmsm__T SPIMasterTransfer;/* '<S253>/SPI Master Transfer' */
  B_IfActionSubsystem1_mcb_pmsm_T IfActionSubsystem1_h;/* '<S182>/If Action Subsystem1' */
  B_IfActionSubsystem_mcb_pmsm__T IfActionSubsystem_o;/* '<S182>/If Action Subsystem' */
  B_TwoinputsCRL_mcb_pmsm_foc_q_T TwoinputsCRL_l;/* '<S175>/Two inputs CRL' */
  B_IfActionSubsystem1_mcb_pmsm_T IfActionSubsystem1_m;/* '<S158>/If Action Subsystem1' */
  B_IfActionSubsystem_mcb_pmsm__T IfActionSubsystem_m;/* '<S158>/If Action Subsystem' */
  B_TwoinputsCRL_mcb_pmsm_foc_q_T TwoinputsCRL;/* '<S19>/Two inputs CRL' */
} B_mcb_pmsm_foc_qep_f28379d_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S200>/Unit Delay' */
  real32_T RampGenerator_DSTATE;       /* '<S173>/Ramp Generator' */
  real32_T UnitDelay_DSTATE_h;         /* '<S172>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S134>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S79>/Integrator' */
  uint32_T Delay_DSTATE[20];           /* '<S197>/Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S255>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_e;    /* '<S245>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S245>/Digital Output1' */
  int32_T Add_DWORK1[2];               /* '<S192>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S197>/SpeedCount' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S223>/DRV830x Enable' */
  uint32_T Add_DWORK1_n;               /* '<S227>/Add' */
  uint32_T Sum_DWORK1[4];              /* '<S180>/Sum' */
  uint16_T Output_DSTATE;              /* '<S229>/Output' */
  uint16_T Delay3_DSTATE;              /* '<S194>/Delay3' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory6' */
  uint16_T Memory_PreviousInput;       /* '<S252>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S252>/Memory1' */
  uint16_T CircBufIdx;                 /* '<S197>/Delay' */
  boolean_T Delay_DSTATE_m;            /* '<S191>/Delay' */
  boolean_T Delay_DSTATE_j;            /* '<S188>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S134>/Integrator' */
  int16_T Integrator_PrevResetState_k; /* '<S79>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S8>/Open Loop Start-Up' */
  DW_SpeedControl_mcb_pmsm_foc__T SpeedControl;/* '<Root>/Speed Control' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer1;/* '<S253>/SPI Master Transfer' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer;/* '<S253>/SPI Master Transfer' */
} DW_mcb_pmsm_foc_qep_f28379d_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S226>/Width' */
} ConstB_mcb_pmsm_foc_qep_f2837_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S156>/sine_table_values'
   *   '<S180>/sine_table_values'
   */
  real32_T pooled5[1002];
} ConstP_mcb_pmsm_foc_qep_f2837_T;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_qep_f283_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_mcb_pmsm_foc_qep_f28379d_T mcb_pmsm_foc_qep_f28379d_B;

/* Block states (default storage) */
extern DW_mcb_pmsm_foc_qep_f28379d_T mcb_pmsm_foc_qep_f28379d_DW;
extern const ConstB_mcb_pmsm_foc_qep_f2837_T mcb_pmsm_foc_qep_f28379d_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_mcb_pmsm_foc_qep_f2837_T mcb_pmsm_foc_qep_f28379d_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_qep_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_qep_f28379d_initialize(void);
extern void mcb_pmsm_foc_qep_f28379d_step0(void);/* Sample time: [0.0005s, 0.0s] */
extern void mcb_pmsm_foc_qep_f28379d_step1(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_qep_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_qep_f28_T *const mcb_pmsm_foc_qep_f28379d_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_qep_f28379d_configure_interrupts (void);
  void mcb_pmsm_foc_qep_f28379d_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_qep_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_qep_f28379d/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt'
 * '<S3>'   : 'mcb_pmsm_foc_qep_f28379d/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_qep_f28379d/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_qep_f28379d/Inverter and Motor - Plant Model'
 * '<S6>'   : 'mcb_pmsm_foc_qep_f28379d/Serial Receive'
 * '<S7>'   : 'mcb_pmsm_foc_qep_f28379d/Speed Control'
 * '<S8>'   : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System'
 * '<S9>'   : 'mcb_pmsm_foc_qep_f28379d/Current Control/Debug_signals'
 * '<S10>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/HW_Inputs'
 * '<S11>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling'
 * '<S12>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Inverter'
 * '<S13>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Output Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx'
 * '<S15>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control'
 * '<S16>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up'
 * '<S17>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform'
 * '<S18>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers'
 * '<S19>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S20>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S22>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator'
 * '<S23>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform/Two phase input'
 * '<S24>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S25>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S26>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S27>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S28>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S29>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S30>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S31>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S32>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S33>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S34>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S35>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S36>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S37>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S38>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S39>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S40>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S41>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S42>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S43>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S44>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S45>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S46>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S47>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S48>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S49>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S50>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S51>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S52>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S53>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S54>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S55>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S56>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S57>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S58>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S59>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S60>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S61>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S63>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S64>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S65>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S66>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S67>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S68>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S69>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S70>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S71>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S72>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S73>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S74>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S75>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S76>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S77>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S78>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S79>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S80>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S81>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S82>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S83>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S84>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S85>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S86>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S87>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S88>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S89>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S90>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S91>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S92>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S93>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S94>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S95>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S96>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S97>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S98>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S99>'  : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S100>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S101>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S102>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S103>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S104>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S105>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S106>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S107>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S108>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S109>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S110>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S111>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S112>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S113>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S114>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S115>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S116>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S117>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S118>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S119>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S120>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S121>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S122>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S123>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S124>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S125>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S126>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S127>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S128>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S129>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S130>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S131>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S132>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S133>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S134>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S135>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S136>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S137>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S138>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S139>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S140>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S141>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S142>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S143>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S144>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S145>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S147>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S148>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S149>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S150>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S151>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S152>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL'
 * '<S153>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S154>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform/Two inputs CRL'
 * '<S155>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S156>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S157>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S158>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S159>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S160>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S161>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S162>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S163>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S164>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S165>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S166>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S167>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S168>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S169>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S170>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S171>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S172>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator1'
 * '<S173>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Ramp Generator'
 * '<S174>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S175>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S176>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S177>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Two phase input'
 * '<S178>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL'
 * '<S179>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S180>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S181>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S182>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S183>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S184>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S185>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S186>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S187>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S188>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator1/Accumulate'
 * '<S189>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Control_System/Open Loop Start-Up/Position Generator1/Accumulate/Subsystem'
 * '<S190>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S191>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed'
 * '<S192>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S193>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S194>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder'
 * '<S195>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S196>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S197>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S198>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S199>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S200>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S201>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant'
 * '<S202>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant1'
 * '<S203>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S204>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S205>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S206>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S207>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S208>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S209>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S210>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S211>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S212>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S213>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S214>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S215>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S216>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S217>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S218>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S219>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S220>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S221>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S222>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S223>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/Inverter/Code Generation'
 * '<S224>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation'
 * '<S225>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx'
 * '<S226>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging'
 * '<S227>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S228>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx/Data_Type_Float'
 * '<S229>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited'
 * '<S230>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Data'
 * '<S231>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/End'
 * '<S232>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Start'
 * '<S233>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Increment Real World'
 * '<S234>' : 'mcb_pmsm_foc_qep_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S235>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation'
 * '<S236>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_ADCB1_INT'
 * '<S237>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT'
 * '<S238>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC'
 * '<S239>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S240>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S241>' : 'mcb_pmsm_foc_qep_f28379d/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S242>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem'
 * '<S243>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation'
 * '<S244>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S245>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S246>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S247>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S248>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S249>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S250>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S251>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S252>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S253>' : 'mcb_pmsm_foc_qep_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable/ADC Gain setting'
 * '<S254>' : 'mcb_pmsm_foc_qep_f28379d/Heartbeat LED/Heartbeat LED'
 * '<S255>' : 'mcb_pmsm_foc_qep_f28379d/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S256>' : 'mcb_pmsm_foc_qep_f28379d/Inverter and Motor - Plant Model/Codegeneration'
 * '<S257>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/Data_Conditioning_Rx'
 * '<S258>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/SCI_Rx'
 * '<S259>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/unParse'
 * '<S260>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 * '<S261>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/SCI_Rx/Code Generation'
 * '<S262>' : 'mcb_pmsm_foc_qep_f28379d/Serial Receive/SCI_Rx/Code Generation/Data_Type_Float'
 * '<S263>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed'
 * '<S264>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/Speed_Ref_Selector'
 * '<S265>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S266>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S267>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S268>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S269>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S270>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S271>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S272>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S273>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S274>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S275>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S276>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S277>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S278>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S279>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S280>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S281>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S282>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S283>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S284>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S285>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S286>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S287>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S288>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S289>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S290>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S291>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S292>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S293>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S294>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S295>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S296>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S297>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S298>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S299>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S300>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S301>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S302>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S303>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S304>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S305>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S306>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S307>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S308>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S309>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S310>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S311>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S312>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S313>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S314>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S315>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S316>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S317>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S318>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S319>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S320>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S321>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S322>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S323>' : 'mcb_pmsm_foc_qep_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* mcb_pmsm_foc_qep_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
