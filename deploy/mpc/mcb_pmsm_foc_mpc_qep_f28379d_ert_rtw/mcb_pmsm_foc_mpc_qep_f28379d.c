/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_mpc_qep_f28379d.c
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

#include "mcb_pmsm_foc_mpc_qep_f28379d.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_mpc_qep_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Named constants for MATLAB Function: '<S47>/optimizer' */
#define mcb_pmsm_foc_mpc_qep_f28379d_ny (2L)
#define mcb_pmsm_foc_mpc_qep_f2_degrees (3L)

/* Block signals (default storage) */
B_mcb_pmsm_foc_mpc_qep_f28379_T mcb_pmsm_foc_mpc_qep_f28379d_B;

/* Block states (default storage) */
DW_mcb_pmsm_foc_mpc_qep_f2837_T mcb_pmsm_foc_mpc_qep_f28379d_DW;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_mpc_qep_T mcb_pmsm_foc_mpc_qep_f28379d_M_;
RT_MODEL_mcb_pmsm_foc_mpc_qep_T *const mcb_pmsm_foc_mpc_qep_f28379d_M =
  &mcb_pmsm_foc_mpc_qep_f28379d_M_;

/* Forward declaration for local functions */
static void mcb_pmsm_foc_mpc__Unconstrained(const real32_T b_Hinv[9], const
  real32_T f[3], real32_T x[3], int32_T n);
static real32_T mcb_pmsm_foc_mpc_qep_f2837_norm(const real32_T x[3]);
static real32_T mcb_pmsm_foc_mpc_qep_f2_maximum(const real32_T x[3]);
static real32_T mcb_pmsm_foc_mpc_qep_f283_xnrm2(int16_T n, const real32_T x[9],
  int16_T ix0);
static void mcb_pmsm_foc_mpc_qep_f283_xgemv(int16_T b_m, int16_T n, const
  real32_T b_A[9], int16_T ia0, const real32_T x[9], int16_T ix0, real32_T y[3]);
static void mcb_pmsm_foc_mpc_qep_f283_xgerc(int16_T b_m, int16_T n, real32_T
  alpha1, int16_T ix0, const real32_T y[3], real32_T b_A[9], int16_T ia0);
static real32_T mcb_pmsm_foc_mpc_qep_KWIKfactor(const real32_T b_Ac[126], const
  int32_T iC[42], int32_T nA, const real32_T b_Linv[9], real32_T RLinv[9],
  real32_T D[9], real32_T b_H[9], int32_T n);
static real32_T mcb_pmsm_foc_mpc_qep_f28_mtimes(const real32_T b_A[3], const
  real32_T B[3]);
static void mcb_pmsm_foc_mpc_DropConstraint(int32_T kDrop, boolean_T iA[42],
  int32_T *nA, int32_T iC[42]);
static void mcb_pmsm_foc_mpc_qep_f28_qpkwik(const real32_T b_Linv[9], const
  real32_T b_Hinv[9], const real32_T f[3], const real32_T b_Ac[126], const
  real32_T b[42], boolean_T iA[42], int32_T maxiter, real32_T FeasTol, real32_T
  x[3], real32_T lambda[42], int32_T *status);
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

int16_T div_nde_s16_floor(int16_T numerator, int16_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_mpc_qep_f28379d_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_mpc_qep_f28379d_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_mpc_qep_f28379d_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.001s, 0.0s] */
    mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[2]) > 2499) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_mpc_qep_f28379d_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S19>/Two inputs CRL'
 *    '<S72>/Two inputs CRL'
 */
void mcb_pmsm_foc_m_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, real32_T *rty_Alpha, real32_T *rty_Beta)
{
  /* Sum: '<S49>/sum_beta' incorporates:
   *  Product: '<S49>/dsin'
   *  Product: '<S49>/qcos'
   */
  *rty_Beta = rtu_Qs * rtu_cos + rtu_Ds * rtu_sin;

  /* Sum: '<S49>/sum_alpha' incorporates:
   *  Product: '<S49>/dcos'
   *  Product: '<S49>/qsin'
   */
  *rty_Alpha = rtu_Ds * rtu_cos - rtu_Qs * rtu_sin;
}

/*
 * Output and update for action system:
 *    '<S55>/If Action Subsystem'
 *    '<S79>/If Action Subsystem'
 */
void mcb_pmsm__IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S58>/Sum' incorporates:
   *  DataTypeConversion: '<S58>/Convert_back'
   *  DataTypeConversion: '<S58>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(int16_T)(real32_T)floor(rtu_In1);
}

/*
 * Output and update for action system:
 *    '<S55>/If Action Subsystem1'
 *    '<S79>/If Action Subsystem1'
 */
void mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S59>/Sum' incorporates:
   *  DataTypeConversion: '<S59>/Convert_back'
   *  DataTypeConversion: '<S59>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(int16_T)rtu_In1;
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static void mcb_pmsm_foc_mpc__Unconstrained(const real32_T b_Hinv[9], const
  real32_T f[3], real32_T x[3], int32_T n)
{
  int32_T i;
  for (i = 1L; i <= n; i++) {
    x[(int16_T)i - 1] = (-b_Hinv[(int16_T)i - 1] * f[0] + -b_Hinv[(int16_T)i + 2]
                         * f[1]) + -b_Hinv[(int16_T)i + 5] * f[2];
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (fabsf(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static real32_T mcb_pmsm_foc_mpc_qep_f2837_norm(const real32_T x[3])
{
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabsf(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * (real32_T)sqrt(y);
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static real32_T mcb_pmsm_foc_mpc_qep_f2_maximum(const real32_T x[3])
{
  real32_T ex;
  real32_T x_0;
  int16_T idx;
  int16_T k;
  boolean_T exitg1;
  if (!rtIsNaNF(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaNF(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 4; k++) {
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static real32_T mcb_pmsm_foc_mpc_qep_f283_xnrm2(int16_T n, const real32_T x[9],
  int16_T ix0)
{
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  int16_T k;
  int16_T kend;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = fabsf(x[ix0 - 1]);
    } else {
      scale = 1.29246971E-26F;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        absxk = fabsf(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * (real32_T)sqrt(y);
    }
  }

  return y;
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = fabsf(u0);
  b = fabsf(u1);
  if (a < b) {
    a /= b;
    y = (real32_T)sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = (real32_T)sqrt(b * b + 1.0F) * a;
  } else if (rtIsNaNF(b)) {
    y = (rtNaNF);
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static void mcb_pmsm_foc_mpc_qep_f283_xgemv(int16_T b_m, int16_T n, const
  real32_T b_A[9], int16_T ia0, const real32_T x[9], int16_T ix0, real32_T y[3])
{
  real32_T c;
  int16_T b;
  int16_T b_iy;
  int16_T d;
  int16_T ia;
  if ((b_m != 0) && (n != 0)) {
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint16_T)n * sizeof(real32_T));
    }

    b = (n - 1) * 3 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 3) {
      c = 0.0F;
      d = (b_iy + b_m) - 1;
      for (ia = b_iy; ia <= d; ia++) {
        c += x[((ix0 + ia) - b_iy) - 1] * b_A[ia - 1];
      }

      ia = div_nde_s16_floor(b_iy - ia0, 3);
      y[ia] += c;
    }
  }
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static void mcb_pmsm_foc_mpc_qep_f283_xgerc(int16_T b_m, int16_T n, real32_T
  alpha1, int16_T ix0, const real32_T y[3], real32_T b_A[9], int16_T ia0)
{
  real32_T temp;
  int16_T b;
  int16_T ijA;
  int16_T j;
  int16_T jA;
  if (!(alpha1 == 0.0F)) {
    jA = ia0;
    for (j = 0; j < n; j++) {
      temp = y[j];
      if (temp != 0.0F) {
        temp *= alpha1;
        b = (b_m + jA) - 1;
        for (ijA = jA; ijA <= b; ijA++) {
          b_A[ijA - 1] += b_A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 3;
    }
  }
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static real32_T mcb_pmsm_foc_mpc_qep_KWIKfactor(const real32_T b_Ac[126], const
  int32_T iC[42], int32_T nA, const real32_T b_Linv[9], real32_T RLinv[9],
  real32_T D[9], real32_T b_H[9], int32_T n)
{
  int32_T d_k;
  int32_T exitg1;
  int32_T f_i;
  int32_T i;
  real32_T Q[9];
  real32_T R[9];
  real32_T TL[9];
  real32_T b_A[9];
  real32_T tau[3];
  real32_T work[3];
  real32_T Status;
  real32_T atmp;
  real32_T b_A_0;
  real32_T beta1;
  int16_T b_coltop;
  int16_T b_lastv;
  int16_T coltop;
  int16_T ii;
  int16_T j_i;
  int16_T knt;
  boolean_T exitg2;
  Status = 1.0F;
  for (j_i = 0; j_i < 9; j_i++) {
    RLinv[j_i] = 0.0F;
  }

  for (i = 1L; i <= nA; i++) {
    b_coltop = (int16_T)iC[(int16_T)i - 1];
    for (j_i = 0; j_i < 3; j_i++) {
      b_lastv = ((int16_T)i - 1) * 3 + j_i;
      RLinv[b_lastv] = 0.0F;
      RLinv[b_lastv] += b_Ac[b_coltop - 1] * b_Linv[j_i];
      RLinv[b_lastv] += b_Linv[j_i + 3] * b_Ac[b_coltop + 41];
      RLinv[b_lastv] += b_Linv[j_i + 6] * b_Ac[b_coltop + 83];
    }
  }

  for (j_i = 0; j_i < 9; j_i++) {
    b_A[j_i] = RLinv[j_i];
  }

  tau[0] = 0.0F;
  work[0] = 0.0F;
  tau[1] = 0.0F;
  work[1] = 0.0F;
  tau[2] = 0.0F;
  work[2] = 0.0F;
  for (j_i = 0; j_i < 3; j_i++) {
    ii = j_i * 3 + j_i;
    if (j_i + 1 < 3) {
      atmp = b_A[ii];
      b_lastv = ii + 2;
      tau[j_i] = 0.0F;
      beta1 = mcb_pmsm_foc_mpc_qep_f283_xnrm2(2 - j_i, b_A, ii + 2);
      if (beta1 != 0.0F) {
        b_A_0 = b_A[ii];
        beta1 = rt_hypotf_snf(b_A_0, beta1);
        if (b_A_0 >= 0.0F) {
          beta1 = -beta1;
        }

        if (fabsf(beta1) < 9.86076132E-32F) {
          knt = 0;
          do {
            knt++;
            coltop = (ii - j_i) + 3;
            for (b_coltop = b_lastv; b_coltop <= coltop; b_coltop++) {
              b_A[b_coltop - 1] *= 1.01412048E+31F;
            }

            beta1 *= 1.01412048E+31F;
            atmp *= 1.01412048E+31F;
          } while ((fabsf(beta1) < 9.86076132E-32F) && (knt < 20));

          beta1 = rt_hypotf_snf(atmp, mcb_pmsm_foc_mpc_qep_f283_xnrm2(2 - j_i,
            b_A, ii + 2));
          if (atmp >= 0.0F) {
            beta1 = -beta1;
          }

          tau[j_i] = (beta1 - atmp) / beta1;
          atmp = 1.0F / (atmp - beta1);
          for (b_coltop = b_lastv; b_coltop <= coltop; b_coltop++) {
            b_A[b_coltop - 1] *= atmp;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            beta1 *= 9.86076132E-32F;
          }

          atmp = beta1;
        } else {
          tau[j_i] = (beta1 - b_A_0) / beta1;
          atmp = 1.0F / (b_A_0 - beta1);
          b_coltop = (ii - j_i) + 3;
          for (knt = b_lastv; knt <= b_coltop; knt++) {
            b_A[knt - 1] *= atmp;
          }

          atmp = beta1;
        }
      }

      b_A[ii] = 1.0F;
      if (tau[j_i] != 0.0F) {
        b_lastv = 3 - j_i;
        knt = (ii - j_i) + 2;
        while ((b_lastv > 0) && (b_A[knt] == 0.0F)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - j_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 3 + ii) + 3;
          coltop = b_coltop;
          do {
            exitg1 = 0L;
            if (coltop + 1 <= b_coltop + b_lastv) {
              if (b_A[coltop] != 0.0F) {
                exitg1 = 1L;
              } else {
                coltop++;
              }
            } else {
              knt--;
              exitg1 = 2L;
            }
          } while (exitg1 == 0L);

          if (exitg1 == 1L) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        mcb_pmsm_foc_mpc_qep_f283_xgemv(b_lastv, knt, b_A, ii + 4, b_A, ii + 1,
          work);
        mcb_pmsm_foc_mpc_qep_f283_xgerc(b_lastv, knt, -tau[j_i], ii + 1, work,
          b_A, ii + 4);
      }

      b_A[ii] = atmp;
    } else {
      tau[2] = 0.0F;
    }
  }

  for (j_i = 0; j_i < 3; j_i++) {
    for (ii = 0; ii <= j_i; ii++) {
      R[ii + 3 * j_i] = b_A[3 * j_i + ii];
    }

    for (ii = j_i + 2; ii < 4; ii++) {
      R[(ii + 3 * j_i) - 1] = 0.0F;
    }

    work[j_i] = 0.0F;
  }

  for (j_i = 2; j_i >= 0; j_i--) {
    b_lastv = (j_i * 3 + j_i) + 4;
    if (j_i + 1 < 3) {
      b_A[b_lastv - 4] = 1.0F;
      if (tau[j_i] != 0.0F) {
        knt = 3 - j_i;
        b_coltop = b_lastv - j_i;
        while ((knt > 0) && (b_A[b_coltop - 2] == 0.0F)) {
          knt--;
          b_coltop--;
        }

        b_coltop = 2 - j_i;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = (b_coltop - 1) * 3 + b_lastv;
          ii = coltop;
          do {
            exitg1 = 0L;
            if (ii <= (coltop + knt) - 1) {
              if (b_A[ii - 1] != 0.0F) {
                exitg1 = 1L;
              } else {
                ii++;
              }
            } else {
              b_coltop--;
              exitg1 = 2L;
            }
          } while (exitg1 == 0L);

          if (exitg1 == 1L) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        b_coltop = 0;
      }

      if (knt > 0) {
        mcb_pmsm_foc_mpc_qep_f283_xgemv(knt, b_coltop, b_A, b_lastv, b_A,
          b_lastv - 3, work);
        mcb_pmsm_foc_mpc_qep_f283_xgerc(knt, b_coltop, -tau[j_i], b_lastv - 3,
          work, b_A, b_lastv);
      }

      b_coltop = b_lastv - j_i;
      for (knt = b_lastv - 2; knt < b_coltop; knt++) {
        b_A[knt - 1] *= -tau[j_i];
      }
    }

    b_A[b_lastv - 4] = 1.0F - tau[j_i];
    for (knt = 0; knt < j_i; knt++) {
      b_A[(b_lastv - knt) - 5] = 0.0F;
    }
  }

  b_lastv = 0;
  for (j_i = 0; j_i < 3; j_i++) {
    Q[b_lastv] = b_A[b_lastv];
    Q[b_lastv + 1] = b_A[b_lastv + 1];
    Q[b_lastv + 2] = b_A[b_lastv + 2];
    b_lastv += 3;
  }

  i = 1L;
  do {
    exitg1 = 0L;
    if (i <= nA) {
      if (fabsf(R[(((int16_T)i - 1) * 3 + (int16_T)i) - 1]) < 1.0E-12F) {
        Status = -2.0F;
        exitg1 = 1L;
      } else {
        i++;
      }
    } else {
      for (i = 1L; i <= n; i++) {
        for (f_i = 1L; f_i <= n; f_i++) {
          j_i = ((int16_T)i - 1) * 3;
          b_lastv = ((int16_T)f_i - 1) * 3;
          TL[((int16_T)i + b_lastv) - 1] = (b_Linv[j_i + 1] * Q[b_lastv + 1] +
            b_Linv[j_i] * Q[b_lastv]) + b_Linv[j_i + 2] * Q[b_lastv + 2];
        }
      }

      for (j_i = 0; j_i < 9; j_i++) {
        RLinv[j_i] = 0.0F;
      }

      for (i = nA; i > 0L; i--) {
        j_i = ((int16_T)i - 1) * 3;
        b_lastv = ((int16_T)i + j_i) - 1;
        RLinv[b_lastv] = 1.0F;
        for (f_i = i; f_i <= nA; f_i++) {
          b_coltop = (((int16_T)f_i - 1) * 3 + (int16_T)i) - 1;
          RLinv[b_coltop] /= R[b_lastv];
        }

        if (i > 1L) {
          for (f_i = 1L; f_i < i; f_i++) {
            for (d_k = i; d_k <= nA; d_k++) {
              b_lastv = ((int16_T)d_k - 1) * 3;
              b_coltop = (b_lastv + (int16_T)f_i) - 1;
              RLinv[b_coltop] -= R[(j_i + (int16_T)f_i) - 1] * RLinv[(b_lastv +
                (int16_T)i) - 1];
            }
          }
        }
      }

      for (i = 1L; i <= n; i++) {
        for (f_i = i; f_i <= n; f_i++) {
          j_i = (((int16_T)f_i - 1) * 3 + (int16_T)i) - 1;
          b_H[j_i] = 0.0F;
          for (d_k = nA + 1L; d_k <= n; d_k++) {
            b_lastv = ((int16_T)d_k - 1) * 3;
            b_H[j_i] -= TL[(b_lastv + (int16_T)i) - 1] * TL[(b_lastv + (int16_T)
              f_i) - 1];
          }

          b_H[((int16_T)f_i + 3 * ((int16_T)i - 1)) - 1] = b_H[j_i];
        }
      }

      for (i = 1L; i <= nA; i++) {
        for (f_i = 1L; f_i <= n; f_i++) {
          j_i = (((int16_T)i - 1) * 3 + (int16_T)f_i) - 1;
          D[j_i] = 0.0F;
          for (d_k = i; d_k <= nA; d_k++) {
            b_lastv = ((int16_T)d_k - 1) * 3;
            D[j_i] += TL[(b_lastv + (int16_T)f_i) - 1] * RLinv[(b_lastv +
              (int16_T)i) - 1];
          }
        }
      }

      exitg1 = 1L;
    }
  } while (exitg1 == 0L);

  return Status;
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static real32_T mcb_pmsm_foc_mpc_qep_f28_mtimes(const real32_T b_A[3], const
  real32_T B[3])
{
  return (b_A[0] * B[0] + b_A[1] * B[1]) + b_A[2] * B[2];
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static void mcb_pmsm_foc_mpc_DropConstraint(int32_T kDrop, boolean_T iA[42],
  int32_T *nA, int32_T iC[42])
{
  int32_T i;
  if (kDrop > 0L) {
    iA[(int16_T)iC[(int16_T)kDrop - 1] - 1] = false;
    if (kDrop < *nA) {
      for (i = kDrop; i < *nA; i++) {
        iC[(int16_T)i - 1] = iC[(int16_T)(i + 1L) - 1];
      }
    }

    iC[(int16_T)*nA - 1] = 0L;
    (*nA)--;
  }
}

/* Function for MATLAB Function: '<S47>/optimizer' */
static void mcb_pmsm_foc_mpc_qep_f28_qpkwik(const real32_T b_Linv[9], const
  real32_T b_Hinv[9], const real32_T f[3], const real32_T b_Ac[126], const
  real32_T b[42], boolean_T iA[42], int32_T maxiter, real32_T FeasTol, real32_T
  x[3], real32_T lambda[42], int32_T *status)
{
  int32_T iC[42];
  int32_T exitg1;
  int32_T exitg3;
  int32_T iSave;
  int32_T kDrop;
  int32_T lambda_tmp_tmp;
  int32_T nA;
  real32_T D[9];
  real32_T RLinv[9];
  real32_T U[9];
  real32_T b_H[9];
  real32_T Opt[6];
  real32_T Rhs[6];
  real32_T b_Ac_0[3];
  real32_T r[3];
  real32_T z[3];
  real32_T Xnorm0;
  real32_T b_Ac_tmp;
  real32_T cMin;
  real32_T cVal;
  real32_T rMin;
  real32_T t;
  int16_T U_tmp;
  int16_T b_exponent;
  int16_T exponent;
  int16_T i;
  int16_T tmp;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1;
  boolean_T guard2;
  x[0] = 0.0F;
  x[1] = 0.0F;
  x[2] = 0.0F;
  *status = 1L;
  r[0] = 0.0F;
  r[1] = 0.0F;
  r[2] = 0.0F;
  rMin = 0.0F;
  cTolComputed = false;
  for (i = 0; i < 42; i++) {
    lambda[i] = 0.0F;
    mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i] = 1.0F;
    iC[i] = 0L;
  }

  nA = 0L;
  for (i = 0; i < 42; i++) {
    if (iA[i]) {
      nA = (int16_T)nA + 1;
      iC[(int16_T)nA - 1] = i + 1;
    }
  }

  guard1 = false;
  if ((int16_T)nA > 0) {
    for (i = 0; i < 6; i++) {
      Opt[i] = 0.0F;
    }

    Rhs[0] = f[0];
    Rhs[3] = 0.0F;
    Rhs[1] = f[1];
    Rhs[4] = 0.0F;
    Rhs[2] = f[2];
    Rhs[5] = 0.0F;
    DualFeasible = false;
    tmp = (int16_T)rt_roundf_snf(0.3F * (real32_T)nA);
    ColdReset = false;
    do {
      exitg3 = 0L;
      if ((!DualFeasible) && (nA > 0L) && (*status <= maxiter)) {
        Xnorm0 = mcb_pmsm_foc_mpc_qep_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D,
          b_H, mcb_pmsm_foc_mpc_qep_f2_degrees);
        if (Xnorm0 < 0.0F) {
          if (ColdReset) {
            *status = -2L;
            exitg3 = 2L;
          } else {
            nA = 0L;
            memset(&iC[0], 0, 42U * sizeof(int32_T));
            for (i = 0; i < 42; i++) {
              iA[i] = false;
            }

            ColdReset = true;
          }
        } else {
          for (kDrop = 1L; kDrop <= nA; kDrop++) {
            Rhs[(int16_T)(kDrop + 3L) - 1] = b[(int16_T)iC[(int16_T)kDrop - 1] -
              1];
            for (iSave = kDrop; iSave <= nA; iSave++) {
              i = (((int16_T)kDrop - 1) * 3 + (int16_T)iSave) - 1;
              U[i] = 0.0F;
              for (lambda_tmp_tmp = 1L; lambda_tmp_tmp <= nA; lambda_tmp_tmp++)
              {
                U_tmp = ((int16_T)lambda_tmp_tmp - 1) * 3;
                U[i] += RLinv[(U_tmp + (int16_T)iSave) - 1] * RLinv[(U_tmp +
                  (int16_T)kDrop) - 1];
              }

              U[((int16_T)kDrop + 3 * ((int16_T)iSave - 1)) - 1] = U[i];
            }
          }

          for (i = 0; i < 3; i++) {
            Opt[i] = (b_H[i + 3] * Rhs[1] + b_H[i] * Rhs[0]) + b_H[i + 6] * Rhs
              [2];
            for (kDrop = 1L; kDrop <= nA; kDrop++) {
              Opt[i] += D[((int16_T)kDrop - 1) * 3 + i] * Rhs[(int16_T)(kDrop +
                3L) - 1];
            }
          }

          for (kDrop = 1L; kDrop <= nA; kDrop++) {
            i = ((int16_T)kDrop - 1) * 3;
            Opt[(int16_T)(kDrop + 3L) - 1] = (D[i + 1] * Rhs[1] + D[i] * Rhs[0])
              + D[i + 2] * Rhs[2];
            for (iSave = 1L; iSave <= nA; iSave++) {
              Opt[(int16_T)(kDrop + 3L) - 1] += U[(((int16_T)iSave - 1) * 3 +
                (int16_T)kDrop) - 1] * Rhs[(int16_T)(iSave + 3L) - 1];
            }
          }

          Xnorm0 = -1.0E-12F;
          kDrop = 0L;
          for (iSave = 1L; iSave <= nA; iSave++) {
            cMin = Opt[(int16_T)(iSave + 3L) - 1];
            lambda[(int16_T)iC[(int16_T)iSave - 1] - 1] = cMin;
            if ((cMin < Xnorm0) && (iSave <= nA)) {
              kDrop = iSave;
              Xnorm0 = cMin;
            }
          }

          if (kDrop <= 0L) {
            DualFeasible = true;
            x[0] = Opt[0];
            x[1] = Opt[1];
            x[2] = Opt[2];
          } else {
            (*status)++;
            if (tmp <= 5) {
              i = 5;
            } else {
              i = tmp;
            }

            if (*status > i) {
              nA = 0L;
              memset(&iC[0], 0, 42U * sizeof(int32_T));
              for (i = 0; i < 42; i++) {
                iA[i] = false;
              }

              ColdReset = true;
            } else {
              lambda[(int16_T)iC[(int16_T)kDrop - 1] - 1] = 0.0F;
              mcb_pmsm_foc_mpc_DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0L) {
          memset(&lambda[0], 0, 42U * sizeof(real32_T));
          mcb_pmsm_foc_mpc__Unconstrained(b_Hinv, f, x,
            mcb_pmsm_foc_mpc_qep_f2_degrees);
        }

        exitg3 = 1L;
      }
    } while (exitg3 == 0L);

    if (exitg3 == 1L) {
      guard1 = true;
    }
  } else {
    x[0] = 0.0F;
    x[1] = 0.0F;
    x[2] = 0.0F;
    mcb_pmsm_foc_mpc__Unconstrained(b_Hinv, f, x,
      mcb_pmsm_foc_mpc_qep_f2_degrees);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = mcb_pmsm_foc_mpc_qep_f2837_norm(x);
    exitg2 = false;
    while ((!exitg2) && (*status <= maxiter)) {
      cMin = -FeasTol;
      tmp = -1;
      for (i = 0; i < 42; i++) {
        if (!cTolComputed) {
          z[0] = fabsf(b_Ac[i] * x[0]);
          z[1] = fabsf(b_Ac[i + 42] * x[1]);
          z[2] = fabsf(b_Ac[i + 84] * x[2]);
          cVal = mcb_pmsm_foc_mpc_qep_f2_maximum(z);
          if ((mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i] >= cVal) || rtIsNaNF(cVal))
          {
          } else {
            mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i] = cVal;
          }
        }

        if (!iA[i]) {
          cVal = (((b_Ac[i + 42] * x[1] + b_Ac[i] * x[0]) + b_Ac[i + 84] * x[2])
                  - b[i]) / mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i];
          if (cVal < cMin) {
            cMin = cVal;
            tmp = i;
          }
        }
      }

      cTolComputed = true;
      if (tmp + 1 <= 0) {
        exitg2 = true;
      } else if (*status == maxiter) {
        *status = 0L;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0L;
          if ((tmp + 1 > 0) && (*status <= maxiter)) {
            guard2 = false;
            if (nA == 0L) {
              for (i = 0; i < 3; i++) {
                z[i] = (b_Hinv[i + 3] * b_Ac[tmp + 42] + b_Hinv[i] * b_Ac[tmp])
                  + b_Hinv[i + 6] * b_Ac[tmp + 84];
              }

              guard2 = true;
            } else {
              cMin = mcb_pmsm_foc_mpc_qep_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv,
                D, b_H, mcb_pmsm_foc_mpc_qep_f2_degrees);
              if (cMin <= 0.0F) {
                *status = -2L;
                exitg1 = 1L;
              } else {
                for (i = 0; i < 9; i++) {
                  U[i] = -b_H[i];
                }

                for (i = 0; i < 3; i++) {
                  z[i] = (U[i + 3] * b_Ac[tmp + 42] + U[i] * b_Ac[tmp]) + U[i +
                    6] * b_Ac[tmp + 84];
                }

                for (kDrop = 1L; kDrop <= nA; kDrop++) {
                  i = ((int16_T)kDrop - 1) * 3;
                  r[(int16_T)kDrop - 1] = (D[i + 1] * b_Ac[tmp + 42] + D[i] *
                    b_Ac[tmp]) + D[i + 2] * b_Ac[tmp + 84];
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0L;
              cMin = 0.0F;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0L) {
                iSave = 1L;
                exitg4 = false;
                while ((!exitg4) && (iSave <= nA)) {
                  if (r[(int16_T)iSave - 1] >= 1.0E-12F) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    iSave++;
                  }
                }
              }

              if ((nA != 0L) && (!ColdReset)) {
                for (iSave = 1L; iSave <= nA; iSave++) {
                  cVal = r[(int16_T)iSave - 1];
                  if (cVal > 1.0E-12F) {
                    cVal = lambda[(int16_T)iC[(int16_T)iSave - 1] - 1] / cVal;
                    if ((kDrop == 0L) || (cVal < rMin)) {
                      rMin = cVal;
                      kDrop = iSave;
                    }
                  }
                }

                if (kDrop > 0L) {
                  cMin = rMin;
                  DualFeasible = false;
                }
              }

              b_Ac_0[0] = b_Ac[tmp];
              t = b_Ac[tmp + 42];
              b_Ac_0[1] = t;
              b_Ac_tmp = b_Ac[tmp + 84];
              b_Ac_0[2] = b_Ac_tmp;
              cVal = mcb_pmsm_foc_mpc_qep_f28_mtimes(z, b_Ac_0);
              if (cVal <= 0.0F) {
                cVal = 0.0F;
                ColdReset = true;
              } else {
                cVal = (b[tmp] - ((t * x[1] + b_Ac[tmp] * x[0]) + b_Ac_tmp * x[2]))
                  / cVal;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1L;
                exitg1 = 1L;
              } else {
                if (ColdReset) {
                  t = cMin;
                } else if (DualFeasible) {
                  t = cVal;
                } else if (cMin < cVal) {
                  t = cMin;
                } else {
                  t = cVal;
                }

                for (iSave = 1L; iSave <= nA; iSave++) {
                  lambda_tmp_tmp = iC[(int16_T)iSave - 1];
                  lambda[(int16_T)lambda_tmp_tmp - 1] -= r[(int16_T)iSave - 1] *
                    t;
                  if ((lambda_tmp_tmp <= 42L) && (lambda[(int16_T)lambda_tmp_tmp
                       - 1] < 0.0F)) {
                    lambda[(int16_T)lambda_tmp_tmp - 1] = 0.0F;
                  }
                }

                lambda[tmp] += t;
                frexp(1.0, &exponent);
                if (fabsf(t - cMin) < 1.1920929E-7F) {
                  mcb_pmsm_foc_mpc_DropConstraint(kDrop, iA, &nA, iC);
                }

                if (!ColdReset) {
                  x[0] += t * z[0];
                  x[1] += t * z[1];
                  x[2] += t * z[2];
                  frexp(1.0, &b_exponent);
                  if (fabsf(t - cVal) < 1.1920929E-7F) {
                    if (nA == mcb_pmsm_foc_mpc_qep_f2_degrees) {
                      *status = -1L;
                      exitg1 = 1L;
                    } else {
                      nA++;
                      iC[(int16_T)nA - 1] = tmp + 1;
                      kDrop = nA;
                      exitg4 = false;
                      while ((!exitg4) && (kDrop > 1L)) {
                        iSave = iC[(int16_T)kDrop - 1];
                        lambda_tmp_tmp = iC[(int16_T)(kDrop - 1L) - 1];
                        if (iSave > lambda_tmp_tmp) {
                          exitg4 = true;
                        } else {
                          iC[(int16_T)kDrop - 1] = lambda_tmp_tmp;
                          iC[(int16_T)(kDrop - 1L) - 1] = iSave;
                          kDrop--;
                        }
                      }

                      iA[tmp] = true;
                      tmp = -1;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = mcb_pmsm_foc_mpc_qep_f2837_norm(x);
            if (fabsf(cMin - Xnorm0) > 0.001F) {
              Xnorm0 = cMin;
              for (i = 0; i < 42; i++) {
                cMin = fabsf(b[i]);
                if (cMin >= 1.0F) {
                  mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i] = cMin;
                } else {
                  mcb_pmsm_foc_mpc_qep_f28379d_B.cTol[i] = 1.0F;
                }
              }

              cTolComputed = false;
            }

            exitg1 = 2L;
          }
        } while (exitg1 == 0L);

        if (exitg1 == 1L) {
          exitg2 = true;
        }
      }
    }
  }
}

/* System initialize for atomic system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* Start for S-Function (c280xqep): '<S87>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xadc): '<S87>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S87>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c280xgpio_do): '<S120>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S120>/ePWM1' */
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

  /* Start for S-Function (c2802xpwm): '<S120>/ePWM2' */
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

  /* Start for S-Function (c2802xpwm): '<S120>/ePWM3' */
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

  /* InitializeConditions for Delay: '<S94>/Delay' */
  mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx = 0U;
}

/* Output and update for atomic system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

void mcb_pmsm_foc_CurrentControl(void)
{
  /* local block i/o variables */
  uint32_T rtb_BytePack[2];
  int32_T statusINT;
  real32_T tmp[9];
  real32_T rseq[4];
  real32_T rtb_xest[4];
  real32_T xk[4];
  real32_T f[3];
  real32_T zopt[3];
  real32_T rtb_Selector[2];
  real32_T tmp_0[2];
  real32_T y_innov[2];
  real32_T rtb_Add2;
  real32_T rtb_Add3;
  real32_T rtb_Add_j;
  real32_T rtb_PU_Conversion_idx_0;
  real32_T rtb_PU_Conversion_idx_1;
  real32_T rtb_Product;
  real32_T rtb_Product_l;
  real32_T rtb_Selector_0;
  real32_T rtb_Selector_1;
  real32_T rtb_algDD_o1_c;
  real32_T rtb_u_idx_0;
  real32_T rtb_u_idx_1;
  real32_T xk_0;
  real32_T xk_1;
  real32_T y_innov_0;
  real32_T y_innov_1;
  uint32_T rtb_SCI_Tx_Data[3];
  uint32_T rtb_Add;
  uint32_T rtb_PositionToCount;
  int16_T i;
  int16_T rtb_SCI_Tx_Iteration;
  int16_T s124_iter;
  uint16_T rtb_Switch1[3];
  uint16_T rtb_FixPtSum1;
  uint16_T rtb_MultiportSwitch_idx_1;
  boolean_T rtb_iAout[42];
  boolean_T tmp_1;
  static const real32_T a[8] = { 2.36032772F, 0.0F, 0.0F, 0.0F, 0.0F,
    2.36032772F, 0.0F, 0.0F };

  static const real32_T b_a[8] = { 1.0F, 0.0F, 0.0F, 1.0F, 0.2F, 0.0F, 0.0F,
    0.2F };

  static const real32_T c_a[8] = { 0.831443191F, 4.03316558E-17F, 0.0965792909F,
    -1.85636905E-16F, -1.08291963E-18F, 0.831443191F, 4.81671969E-17F,
    0.0965792909F };

  static const real32_T b_Kx[8] = { 0.0F, 0.0F, 0.944131F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.944131F };

  static const real32_T b_Kr[8] = { -2.36032772F, -0.0F, -2.36032772F, -0.0F,
    -0.0F, -2.36032772F, -0.0F, -2.36032772F };

  static const real32_T b_Ku1[4] = { 11.142293F, 0.0F, 0.0F, 11.142293F };

  static const real32_T b_Linv[9] = { 0.299578577F, 0.0F, 0.0F, 0.0F,
    0.299578577F, 0.0F, 0.0F, 0.0F, 0.00316227763F };

  static const real32_T b_Hinv[9] = { 0.089747332F, 0.0F, 0.0F, 0.0F,
    0.089747332F, 0.0F, 0.0F, 0.0F, 1.0E-5F };

  static const real32_T b_Ac[126] = { -2.36032772F, -0.0F, -2.36032772F, -0.0F,
    2.36032772F, 0.0F, 2.36032772F, 0.0F, -1.0F, -0.0F, 1.0F, 0.0F, -1.3032254F,
    3.03318581E-16F, 1.3032254F, 1.3032254F, -0.0F, -1.3032254F, -0.0F, -0.0F,
    -0.0F, -0.0F, -1.3032254F, 3.03318581E-16F, 1.3032254F, 1.3032254F, -0.0F,
    -1.3032254F, 0.977679729F, 5.69833517F, 5.69833517F, 0.977679729F,
    -1.3032254F, 3.03318581E-16F, 1.3032254F, 1.3032254F, -0.0F, -1.3032254F,
    0.977679729F, 5.69833517F, 5.69833517F, 0.977679729F, -0.0F, -2.36032772F,
    -0.0F, -2.36032772F, 0.0F, 2.36032772F, 0.0F, 2.36032772F, -0.0F, -1.0F,
    0.0F, 1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, -0.0F, -0.0F, -0.0F,
    -0.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, -2.36032772F, -2.36032772F,
    2.36032772F, 2.36032772F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F,
    -2.36032772F, -2.36032772F, 2.36032772F, 2.36032772F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
    0.1F, 1.0F, 1.0F, 1.0F, 1.0F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 1.0F, 1.0F,
    1.0F, 1.0F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 1.0F, 1.0F, 1.0F, 1.0F };

  static const real32_T b_Mx[168] = { -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.414213568F, 2.41421366F, 2.41421366F, 0.414213568F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -1.0F, -1.0F, 1.0F,
    1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.2F, -0.0F, -0.2F,
    -0.0F, 0.2F, 0.0F, 0.2F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0828427151F, 0.482842714F, 0.482842714F, 0.0828427151F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0828427151F, 0.482842714F,
    0.482842714F, 0.0828427151F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0828427151F, 0.482842714F, 0.482842714F, 0.0828427151F, -0.0F, -0.2F,
    -0.0F, -0.2F, 0.0F, 0.2F, 0.0F, 0.2F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, -0.2F, -0.2F, 0.2F, 0.2F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.2F, -0.2F, 0.2F, 0.2F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.2F, -0.2F, 0.2F, 0.2F };

  static const real32_T b_Mlim[42] = { 0.1F, 1.0F, 0.1F, 1.0F, 0.1F, 1.0F, 0.1F,
    1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.3032254F, 0.965925813F, 1.3032254F,
    1.3032254F, 0.965925813F, 1.3032254F, 1.0F, 2.41421366F, 2.41421366F, 1.0F,
    1.3032254F, 0.965925813F, 1.3032254F, 1.3032254F, 0.965925813F, 1.3032254F,
    1.0F, 2.41421366F, 2.41421366F, 1.0F, 1.3032254F, 0.965925813F, 1.3032254F,
    1.3032254F, 0.965925813F, 1.3032254F, 1.0F, 2.41421366F, 2.41421366F, 1.0F };

  static const real32_T b_Mu1[84] = { -2.36032772F, -0.0F, -2.36032772F, -0.0F,
    2.36032772F, 0.0F, 2.36032772F, 0.0F, -1.0F, -0.0F, 1.0F, 0.0F, -1.3032254F,
    3.03318581E-16F, 1.3032254F, 1.3032254F, 0.0F, -1.3032254F, 0.0F, 0.0F, 0.0F,
    0.0F, -1.3032254F, 3.03318581E-16F, 1.3032254F, 1.3032254F, 0.0F,
    -1.3032254F, 0.977679729F, 5.69833517F, 5.69833517F, 0.977679729F,
    -1.3032254F, 3.03318581E-16F, 1.3032254F, 1.3032254F, 0.0F, -1.3032254F,
    0.977679729F, 5.69833517F, 5.69833517F, 0.977679729F, -0.0F, -2.36032772F,
    -0.0F, -2.36032772F, 0.0F, 2.36032772F, 0.0F, 2.36032772F, -0.0F, -1.0F,
    0.0F, 1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, -2.36032772F, -2.36032772F,
    2.36032772F, 2.36032772F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F,
    -2.36032772F, -2.36032772F, 2.36032772F, 2.36032772F };

  static const int16_T d_a[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    1 };

  static const real32_T e_a[8] = { 2.35924236E-17F, -5.201808E-19F,
    0.0965792909F, -1.88962291E-16F, -8.24278449E-19F, 5.89810589E-18F,
    5.27676314E-17F, 0.0965792909F };

  /* S-Function (c280xqep): '<S87>/eQEP' */
  {
    mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o2 = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Outputs for Enabled SubSystem: '<S88>/IndexFinder' incorporates:
   *  EnablePort: '<S91>/Enable'
   */
  /* Logic: '<S88>/NOT' incorporates:
   *  Delay: '<S88>/Delay'
   */
  if (!mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
    /* Logic: '<S91>/AND' incorporates:
     *  Constant: '<S98>/Constant'
     *  Constant: '<S99>/Constant'
     *  Delay: '<S91>/Delay3'
     *  RelationalOperator: '<S98>/Compare'
     *  RelationalOperator: '<S99>/Compare'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.AND =
      ((mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay3_DSTATE == 0U) &&
       (mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o2 > 0U));

    /* Update for Delay: '<S91>/Delay3' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay3_DSTATE =
      mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o2;
  }

  /* End of Logic: '<S88>/NOT' */
  /* End of Outputs for SubSystem: '<S88>/IndexFinder' */

  /* DataStoreWrite: '<S8>/Data Store Write' */
  mcb_pmsm_foc_mpc_qep_f28379d_DW.EnClosedLoop =
    mcb_pmsm_foc_mpc_qep_f28379d_B.AND;

  /* S-Function (c2802xadc): '<S87>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S87>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* Gain: '<S119>/PU_Conversion' incorporates:
   *  DataStoreRead: '<S89>/Data Store Read1'
   *  DataStoreRead: '<S89>/Data Store Read2'
   *  DataTypeConversion: '<S89>/Data Type Conversion'
   *  Gain: '<S119>/Get ADC Voltage'
   *  Gain: '<S119>/Get Currents'
   *  Sum: '<S89>/Add'
   */
  rtb_PU_Conversion_idx_0 = (real32_T)((int32_T)
    mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_C_IN2 -
    mcb_pmsm_foc_mpc_qep_f28379d_DW.IaOffset) * 0.000732600747F * 14.2857141F *
    0.0466666669F;
  rtb_PU_Conversion_idx_1 = (real32_T)((int32_T)
    mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_B_IN2 -
    mcb_pmsm_foc_mpc_qep_f28379d_DW.IbOffset) * 0.000732600747F * 14.2857141F *
    0.0466666669F;

  /* Outputs for IfAction SubSystem: '<S93>/PositionNoReset' incorporates:
   *  ActionPort: '<S109>/Action Port'
   */
  /* If: '<S93>/If1' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S115>/Constant'
   *  DataTypeConversion: '<S112>/DTC'
   *  MinMax: '<S109>/MinMax'
   *  Product: '<S93>/Product'
   *  Sum: '<S109>/Sum3'
   *  Sum: '<S109>/Sum7'
   */
  rtb_FixPtSum1 = mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o1 -
    mcb_pmsm_foc_mpc_qep_f28379d_B.eQEP_o2;
  if (rtb_FixPtSum1 > rtb_FixPtSum1 + 4000U) {
    rtb_FixPtSum1 += 4000U;
  }

  rtb_Product = (real32_T)rtb_FixPtSum1 * 0.00025F;

  /* End of If: '<S93>/If1' */
  /* End of Outputs for SubSystem: '<S93>/PositionNoReset' */

  /* If: '<S102>/If' incorporates:
   *  Constant: '<S104>/Constant'
   *  Constant: '<S11>/IndexOffset'
   *  Gain: '<S107>/Number of pole pairs'
   *  Product: '<S93>/Product'
   *  Sum: '<S104>/Add'
   *  Sum: '<S105>/Add'
   *  Switch: '<S101>/Switch'
   */
  if (rtb_Product <= 0.0755F) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    rtb_Product_l = (rtb_Product + 1.0F) - 0.0755F;

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    rtb_Product_l = rtb_Product - 0.0755F;

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem1' */
  }

  rtb_Product_l *= 4.0F;

  /* End of If: '<S102>/If' */

  /* Sum: '<S103>/Add' incorporates:
   *  Rounding: '<S103>/Floor'
   */
  rtb_Add_j = rtb_Product_l - (real32_T)floor(rtb_Product_l);

  /* Outputs for Enabled SubSystem: '<S8>/Closed Loop Control' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
    /* Outputs for Atomic SubSystem: '<S23>/Two phase CRL wrap' */
    /* Gain: '<S24>/one_by_sqrt3' incorporates:
     *  Sum: '<S24>/a_plus_2b'
     */
    rtb_algDD_o1_c = ((rtb_PU_Conversion_idx_0 + rtb_PU_Conversion_idx_1) +
                      rtb_PU_Conversion_idx_1) * 0.577350259F;

    /* End of Outputs for SubSystem: '<S23>/Two phase CRL wrap' */

    /* If: '<S55>/If' incorporates:
     *  Constant: '<S57>/Constant'
     *  RelationalOperator: '<S57>/Compare'
     */
    if (rtb_Add_j < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S55>/If Action Subsystem' incorporates:
       *  ActionPort: '<S58>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(rtb_Add_j, &rtb_Add2);

      /* End of Outputs for SubSystem: '<S55>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S55>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S59>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(rtb_Add_j, &rtb_Add2);

      /* End of Outputs for SubSystem: '<S55>/If Action Subsystem1' */
    }

    /* End of If: '<S55>/If' */

    /* Gain: '<S53>/indexing' */
    rtb_Add2 *= 800.0F;

    /* DataTypeConversion: '<S53>/Get_Integer' */
    rtb_FixPtSum1 = (uint16_T)rtb_Add2;

    /* Sum: '<S53>/Sum2' incorporates:
     *  DataTypeConversion: '<S53>/Data Type Conversion1'
     *  DataTypeConversion: '<S53>/Get_Integer'
     */
    rtb_Product_l = rtb_Add2 - (real32_T)(uint16_T)rtb_Add2;

    /* Selector: '<S53>/Lookup' incorporates:
     *  Constant: '<S53>/sine_table_values'
     *  DataTypeConversion: '<S53>/Get_Integer'
     *  Sum: '<S54>/Sum3'
     */
    rtb_u_idx_0 = mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)(uint16_T)
      rtb_Add2];

    /* Sum: '<S54>/Sum4' incorporates:
     *  Constant: '<S53>/offset'
     *  Constant: '<S53>/sine_table_values'
     *  DataTypeConversion: '<S53>/Get_Integer'
     *  Product: '<S54>/Product'
     *  Selector: '<S53>/Lookup'
     *  Sum: '<S53>/Sum'
     *  Sum: '<S54>/Sum3'
     */
    rtb_Add2 = (mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)((uint16_T)
      rtb_Add2 + 1UL)] - rtb_u_idx_0) * rtb_Product_l + rtb_u_idx_0;

    /* Selector: '<S53>/Lookup' incorporates:
     *  Constant: '<S53>/offset'
     *  Constant: '<S53>/sine_table_values'
     *  DataTypeConversion: '<S53>/Get_Integer'
     *  Sum: '<S53>/Sum'
     *  Sum: '<S54>/Sum5'
     */
    rtb_u_idx_0 = mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)
      (rtb_FixPtSum1 + 200UL)];

    /* Sum: '<S54>/Sum6' incorporates:
     *  Constant: '<S53>/offset'
     *  Constant: '<S53>/sine_table_values'
     *  DataTypeConversion: '<S53>/Get_Integer'
     *  Product: '<S54>/Product1'
     *  Selector: '<S53>/Lookup'
     *  Sum: '<S53>/Sum'
     *  Sum: '<S54>/Sum5'
     */
    rtb_Product_l = (mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)
                     (rtb_FixPtSum1 + 201UL)] - rtb_u_idx_0) * rtb_Product_l +
      rtb_u_idx_0;

    /* Outputs for Atomic SubSystem: '<S20>/Two inputs CRL' */
    /* Outputs for Atomic SubSystem: '<S23>/Two phase CRL wrap' */
    /* AlgorithmDescriptorDelegate generated from: '<S51>/a16' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S24>/a16'
     *  Product: '<S51>/acos'
     *  Product: '<S51>/bsin'
     *  Sum: '<S51>/sum_Ds'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o1 = rtb_PU_Conversion_idx_0 *
      rtb_Product_l + rtb_algDD_o1_c * rtb_Add2;

    /* AlgorithmDescriptorDelegate generated from: '<S51>/a16' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S24>/a16'
     *  Product: '<S51>/asin'
     *  Product: '<S51>/bcos'
     *  Sum: '<S51>/sum_Qs'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o2 = rtb_algDD_o1_c * rtb_Product_l -
      rtb_PU_Conversion_idx_0 * rtb_Add2;

    /* End of Outputs for SubSystem: '<S23>/Two phase CRL wrap' */
    /* End of Outputs for SubSystem: '<S20>/Two inputs CRL' */

    /* SignalConversion generated from: '<S15>/Idq_ref_PU' */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[0] =
      mcb_pmsm_foc_mpc_qep_f28379d_B.RT2[0];
    mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[1] =
      mcb_pmsm_foc_mpc_qep_f28379d_B.RT2[1];

    /* MATLAB Function: '<S47>/optimizer' */
    /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S48>:1' */
    /* '<S48>:1:128' */
    /* '<S48>:1:153' */
    /* '<S48>:1:155' */
    /* '<S48>:1:157' */
    /* '<S48>:1:218' */
    /* '<S48>:1:219' */
    /* '<S48>:1:223' */
    /* '<S48>:1:242' */
    /* '<S48>:1:23' */
    /* '<S48>:1:260' */
    /* '<S48>:1:25' */
    /* '<S48>:1:260' */
    /* '<S48>:1:27' */
    /* '<S48>:1:260' */
    /* '<S48>:1:29' */
    /* '<S48>:1:260' */
    /* '<S48>:1:49' */
    /* '<S48>:1:51' */
    /* '<S48>:1:262' */
    /* '<S48>:1:128' */
    rseq[2] = 0.0F;
    rseq[0] = mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[0];
    rseq[1] = mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[1];
    rseq[(int16_T)mcb_pmsm_foc_mpc_qep_f28379d_ny] =
      mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[0];

    /* Switch: '<S25>/Switch' incorporates:
     *  DataStoreRead: '<S25>/Data Store Read'
     */
    /* '<S48>:1:133' */
    /* '<S48>:1:137' */
    if (mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable) {
      /* MATLAB Function: '<S47>/optimizer' incorporates:
       *  Delay: '<S25>/Delay'
       */
      rtb_Selector[0] = mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE[0];
      rtb_Selector[1] = mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE[1];
    } else {
      /* MATLAB Function: '<S47>/optimizer' incorporates:
       *  Constant: '<S25>/Constant'
       */
      rtb_Selector[0] = 0.0F;
      rtb_Selector[1] = 0.0F;
    }

    /* End of Switch: '<S25>/Switch' */

    /* MATLAB Function: '<S47>/optimizer' incorporates:
     *  Memory: '<S27>/last_x'
     *  UnitDelay: '<S27>/last_mv'
     */
    /* '<S48>:1:138' */
    /* '<S48>:1:143' */
    /* '<S48>:1:150' */
    /* '<S48>:1:153' */
    rtb_u_idx_0 = rtb_Selector[0] -
      mcb_pmsm_foc_mpc_qep_f28379d_DW.last_mv_DSTATE[0];
    rtb_u_idx_1 = rtb_Selector[1] -
      mcb_pmsm_foc_mpc_qep_f28379d_DW.last_mv_DSTATE[1];
    for (i = 0; i < 4; i++) {
      xk[i] = (a[i + 4] * rtb_u_idx_1 + a[i] * rtb_u_idx_0) +
        mcb_pmsm_foc_mpc_qep_f28379d_DW.last_x_PreviousInput[i];
    }

    /* SignalConversion generated from: '<S48>/ SFunction ' incorporates:
     *  MATLAB Function: '<S47>/optimizer'
     */
    /* '<S48>:1:155' */
    /* '<S48>:1:156' */
    tmp_0[0] = mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o1;
    tmp_0[1] = mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o2;

    /* MATLAB Function: '<S47>/optimizer' incorporates:
     *  DataStoreRead: '<S25>/Data Store Read'
     *  Logic: '<S25>/Logical Operator'
     *  Memory: '<S27>/Memory'
     */
    rtb_algDD_o1_c = xk[1];
    rtb_Add3 = xk[0];
    xk_0 = xk[2];
    xk_1 = xk[3];
    for (i = 0; i < 2; i++) {
      y_innov[i] = tmp_0[i] - (((b_a[i + 2] * rtb_algDD_o1_c + b_a[i] * rtb_Add3)
        + b_a[i + 4] * xk_0) + b_a[i + 6] * xk_1);
    }

    /* '<S48>:1:157' */
    y_innov_0 = y_innov[1];
    y_innov_1 = y_innov[0];
    for (i = 0; i < 4; i++) {
      rtb_xest[i] = (c_a[i + 4] * y_innov_0 + c_a[i] * y_innov_1) + xk[i];
    }

    /* '<S48>:1:216' */
    for (i = 0; i < 42; i++) {
      rtb_iAout[i] = false;
    }

    if (!mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable) {
      rtb_u_idx_0 = rtb_Selector[0];
      rtb_u_idx_1 = rtb_Selector[1];
    } else {
      f[0] = 0.0F;
      f[1] = 0.0F;
      f[2] = 0.0F;
      rtb_u_idx_0 = rtb_xest[1];
      rtb_u_idx_1 = rtb_xest[0];
      rtb_algDD_o1_c = rtb_xest[2];
      rtb_Add3 = rtb_xest[3];
      xk_0 = rseq[1];
      xk_1 = rseq[0];
      y_innov_0 = rseq[2];
      y_innov_1 = mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[1];
      rtb_Selector_0 = rtb_Selector[1];
      rtb_Selector_1 = rtb_Selector[0];

      /* Outputs for Iterator SubSystem: '<S121>/While Iterator Subsystem' incorporates:
       *  WhileIterator: '<S124>/While Iterator'
       */
      rtb_SCI_Tx_Iteration = 0;
      s124_iter = 0;

      /* End of Outputs for SubSystem: '<S121>/While Iterator Subsystem' */
      for (i = 0; i < 2; i++) {
        /* Outputs for Iterator SubSystem: '<S121>/While Iterator Subsystem' incorporates:
         *  WhileIterator: '<S124>/While Iterator'
         */
        f[i] = ((((b_Kx[rtb_SCI_Tx_Iteration + 1] * rtb_u_idx_0 +
                   b_Kx[rtb_SCI_Tx_Iteration] * rtb_u_idx_1) +
                  b_Kx[rtb_SCI_Tx_Iteration + 2] * rtb_algDD_o1_c) +
                 b_Kx[rtb_SCI_Tx_Iteration + 3] * rtb_Add3) +
                (((b_Kr[rtb_SCI_Tx_Iteration + 1] * xk_0 +
                   b_Kr[rtb_SCI_Tx_Iteration] * xk_1) +
                  b_Kr[rtb_SCI_Tx_Iteration + 2] * y_innov_0) +
                 b_Kr[rtb_SCI_Tx_Iteration + 3] * y_innov_1)) + (b_Ku1[s124_iter
          + 1] * rtb_Selector_0 + b_Ku1[s124_iter] * rtb_Selector_1);
        rtb_SCI_Tx_Iteration += 4;
        s124_iter += 2;

        /* End of Outputs for SubSystem: '<S121>/While Iterator Subsystem' */
      }

      rtb_u_idx_0 = rtb_xest[1];
      rtb_u_idx_1 = rtb_xest[0];
      rtb_algDD_o1_c = rtb_xest[2];
      rtb_Add3 = rtb_xest[3];
      rtb_Selector_0 = rtb_Selector[1];
      rtb_Selector_1 = rtb_Selector[0];
      for (i = 0; i < 42; i++) {
        rtb_iAout[i] = mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory_PreviousInput_k[i];
        mcb_pmsm_foc_mpc_qep_f28379d_B.b_Mlim[i] = -(((((b_Mx[i + 42] *
          rtb_u_idx_0 + b_Mx[i] * rtb_u_idx_1) + b_Mx[i + 84] * rtb_algDD_o1_c)
          + b_Mx[i + 126] * rtb_Add3) + b_Mlim[i]) + (b_Mu1[i + 42] *
          rtb_Selector_0 + b_Mu1[i] * rtb_Selector_1));
      }

      mcb_pmsm_foc_mpc_qep_f28_qpkwik(b_Linv, b_Hinv, f, b_Ac,
        mcb_pmsm_foc_mpc_qep_f28379d_B.b_Mlim, rtb_iAout, 180L, 1.0E-6F, zopt,
        mcb_pmsm_foc_mpc_qep_f28379d_B.a__1, &statusINT);
      if (((int32_T)(real32_T)statusINT < 0L) || ((int32_T)(real32_T)statusINT ==
           0L)) {
        zopt[0] = 0.0F;
        zopt[1] = 0.0F;
      }

      rtb_u_idx_0 = rtb_Selector[0] + zopt[0];
      rtb_u_idx_1 = rtb_Selector[1] + zopt[1];
    }

    /* Outputs for Atomic SubSystem: '<S19>/Two inputs CRL' */
    /* '<S48>:1:216' */
    /* '<S48>:1:234' */
    /* '<S48>:1:235' */
    /* '<S48>:1:242' */
    /* '<S48>:1:244' */
    /* '<S48>:1:247' */
    mcb_pmsm_foc_m_TwoinputsCRL(rtb_u_idx_0, rtb_u_idx_1, rtb_Add2,
      rtb_Product_l, &rtb_algDD_o1_c, &rtb_Add3);

    /* End of Outputs for SubSystem: '<S19>/Two inputs CRL' */

    /* Gain: '<S67>/one_by_two' */
    rtb_Add2 = 0.5F * rtb_algDD_o1_c;

    /* Gain: '<S67>/sqrt3_by_two' */
    rtb_Add3 *= 0.866025388F;

    /* Sum: '<S67>/add_b' */
    rtb_Product_l = rtb_Add3 - rtb_Add2;

    /* Sum: '<S67>/add_c' */
    rtb_Add2 = (0.0F - rtb_Add2) - rtb_Add3;

    /* MinMax: '<S64>/Max' incorporates:
     *  MinMax: '<S64>/Min'
     */
    tmp_1 = rtIsNaNF(rtb_Product_l);
    if ((rtb_algDD_o1_c >= rtb_Product_l) || tmp_1) {
      rtb_Add3 = rtb_algDD_o1_c;
    } else {
      rtb_Add3 = rtb_Product_l;
    }

    /* MinMax: '<S64>/Min' */
    if ((rtb_algDD_o1_c <= rtb_Product_l) || tmp_1) {
      xk_0 = rtb_algDD_o1_c;
    } else {
      xk_0 = rtb_Product_l;
    }

    /* MinMax: '<S64>/Max' incorporates:
     *  MinMax: '<S64>/Min'
     */
    tmp_1 = !rtIsNaNF(rtb_Add2);
    if ((!(rtb_Add3 >= rtb_Add2)) && tmp_1) {
      rtb_Add3 = rtb_Add2;
    }

    /* MinMax: '<S64>/Min' */
    if ((!(xk_0 <= rtb_Add2)) && tmp_1) {
      xk_0 = rtb_Add2;
    }

    /* Gain: '<S64>/one_by_two' incorporates:
     *  MinMax: '<S64>/Max'
     *  MinMax: '<S64>/Min'
     *  Sum: '<S64>/Add'
     */
    rtb_Add3 = (rtb_Add3 + xk_0) * -0.5F;

    /* Gain: '<S63>/Gain' incorporates:
     *  Sum: '<S63>/Add1'
     *  Sum: '<S63>/Add2'
     *  Sum: '<S63>/Add3'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[0] = (rtb_algDD_o1_c + rtb_Add3) *
      1.15470052F;
    mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[1] = (rtb_Product_l + rtb_Add3) *
      1.15470052F;
    mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[2] = (rtb_Add3 + rtb_Add2) * 1.15470052F;

    /* Update for Delay: '<S25>/Delay' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE[0] = rtb_u_idx_0;
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE[1] = rtb_u_idx_1;

    /* Update for Memory: '<S27>/Memory' */
    for (i = 0; i < 42; i++) {
      mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory_PreviousInput_k[i] = rtb_iAout[i];
    }

    /* End of Update for Memory: '<S27>/Memory' */

    /* Update for UnitDelay: '<S27>/last_mv' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.last_mv_DSTATE[0] = rtb_u_idx_0;
    mcb_pmsm_foc_mpc_qep_f28379d_DW.last_mv_DSTATE[1] = rtb_u_idx_1;

    /* MATLAB Function: '<S47>/optimizer' */
    rtb_algDD_o1_c = xk[1];
    rtb_Add3 = xk[0];
    xk_0 = xk[2];
    xk_1 = xk[3];
    y_innov_0 = y_innov[1];
    y_innov_1 = y_innov[0];
    for (i = 0; i < 4; i++) {
      /* Update for Memory: '<S27>/last_x' */
      mcb_pmsm_foc_mpc_qep_f28379d_DW.last_x_PreviousInput[i] = (((((real32_T)
        d_a[i + 4] * rtb_algDD_o1_c + (real32_T)d_a[i] * rtb_Add3) + (real32_T)
        d_a[i + 8] * xk_0) + (real32_T)d_a[i + 12] * xk_1) + (a[i + 4] *
        rtb_u_idx_1 + a[i] * rtb_u_idx_0)) + (e_a[i + 4] * y_innov_0 + e_a[i] *
        y_innov_1);
    }
  }

  /* End of Outputs for SubSystem: '<S8>/Closed Loop Control' */

  /* Outputs for Enabled SubSystem: '<S8>/Open Loop Start-Up' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  /* Logic: '<S8>/NOT' incorporates:
   *  Constant: '<S68>/Constant'
   *  Constant: '<S77>/offset'
   *  Constant: '<S77>/sine_table_values'
   *  DataTypeConversion: '<S77>/Get_Integer'
   *  Delay: '<S85>/Delay'
   *  Saturate: '<S16>/Saturation'
   *  Selector: '<S77>/Lookup'
   *  Sum: '<S77>/Sum'
   *  Sum: '<S78>/Sum4'
   *  Sum: '<S78>/Sum5'
   *  Sum: '<S78>/Sum6'
   *  UnaryMinus: '<S68>/Unary Minus'
   */
  if (!mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
    mcb_pmsm_foc_mpc_qep_f28379d_DW.OpenLoopStartUp_MODE = true;

    /* DiscreteIntegrator: '<S70>/Ramp Generator' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read1'
     *  Logic: '<S70>/NOT'
     */
    if (!mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable) {
      mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* DiscreteIntegrator: '<S70>/Ramp Generator' */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Eps =
      mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE;

    /* Product: '<S16>/Product' incorporates:
     *  Constant: '<S16>/Speed_ref(rpm)'
     *  Gain: '<S16>/rpm2freq'
     */
    rtb_Add3 = 52.7866669F * mcb_pmsm_foc_mpc_qep_f28379d_B.Eps;

    /* Gain: '<S16>/V-by-f' incorporates:
     *  Abs: '<S16>/Abs'
     */
    rtb_algDD_o1_c = 0.0037888356F * fabsf(rtb_Add3);

    /* Outputs for Enabled SubSystem: '<S69>/Accumulate' incorporates:
     *  EnablePort: '<S85>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S85>/Subsystem' incorporates:
     *  EnablePort: '<S86>/Enable'
     */
    if (mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE_j) {
      /* SignalConversion generated from: '<S86>/Input' incorporates:
       *  Gain: '<S16>/position_increment'
       *  Gain: '<S69>/scaleIn'
       */
      mcb_pmsm_foc_mpc_qep_f28379d_B.Input = 0.000314159261F * rtb_Add3 *
        0.159154937F;
    }

    /* End of Outputs for SubSystem: '<S85>/Subsystem' */

    /* Sum: '<S85>/Add' incorporates:
     *  Delay: '<S85>/Delay'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Input +
      mcb_pmsm_foc_mpc_qep_f28379d_B.Add1_c;

    /* Sum: '<S85>/Add1' incorporates:
     *  DataTypeConversion: '<S85>/Data Type Conversion'
     *  DataTypeConversion: '<S85>/Data Type Conversion1'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Add1_c = rtb_Product_l - (real32_T)(int16_T)
      (real32_T)floor(rtb_Product_l);

    /* Update for Delay: '<S85>/Delay' incorporates:
     *  Constant: '<S85>/Constant'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE_j = true;

    /* End of Outputs for SubSystem: '<S69>/Accumulate' */

    /* Gain: '<S79>/convert_pu' incorporates:
     *  Gain: '<S69>/scaleOut'
     */
    rtb_Add3 = 6.28318548F * mcb_pmsm_foc_mpc_qep_f28379d_B.Add1_c *
      0.159154937F;

    /* If: '<S79>/If' incorporates:
     *  Constant: '<S81>/Constant'
     *  RelationalOperator: '<S81>/Compare'
     */
    if (rtb_Add3 < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      mcb_pmsm__IfActionSubsystem(rtb_Add3, &rtb_Product_l);

      /* End of Outputs for SubSystem: '<S79>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      mcb_pmsm_IfActionSubsystem1(rtb_Add3, &rtb_Product_l);

      /* End of Outputs for SubSystem: '<S79>/If Action Subsystem1' */
    }

    /* End of If: '<S79>/If' */

    /* Gain: '<S77>/indexing' */
    rtb_Product_l *= 800.0F;

    /* DataTypeConversion: '<S77>/Get_Integer' */
    rtb_FixPtSum1 = (uint16_T)rtb_Product_l;

    /* Sum: '<S77>/Sum2' incorporates:
     *  DataTypeConversion: '<S77>/Data Type Conversion1'
     *  DataTypeConversion: '<S77>/Get_Integer'
     */
    rtb_Product_l -= (real32_T)(uint16_T)rtb_Product_l;

    /* Product: '<S78>/Product' incorporates:
     *  Constant: '<S77>/offset'
     *  Constant: '<S77>/sine_table_values'
     *  DataTypeConversion: '<S77>/Get_Integer'
     *  Selector: '<S77>/Lookup'
     *  Sum: '<S77>/Sum'
     *  Sum: '<S78>/Sum3'
     */
    rtb_Add3 = (mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)(rtb_FixPtSum1
      + 1UL)] - mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)rtb_FixPtSum1])
      * rtb_Product_l;

    /* Product: '<S78>/Product1' incorporates:
     *  Constant: '<S77>/offset'
     *  Constant: '<S77>/sine_table_values'
     *  DataTypeConversion: '<S77>/Get_Integer'
     *  Selector: '<S77>/Lookup'
     *  Sum: '<S77>/Sum'
     *  Sum: '<S78>/Sum5'
     */
    rtb_Product_l *= mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)
      (rtb_FixPtSum1 + 201UL)] - mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14
      [(int16_T)(rtb_FixPtSum1 + 200UL)];

    /* Gain: '<S16>/Correction_Factor_sinePWM' */
    rtb_Add2 = 1.15470052F * rtb_algDD_o1_c;

    /* Saturate: '<S16>/Saturation' */
    if (rtb_Add2 > 0.95F) {
      rtb_Add2 = 0.95F;
    } else if (rtb_Add2 < 0.15F) {
      rtb_Add2 = 0.15F;
    }

    /* Outputs for Atomic SubSystem: '<S72>/Two inputs CRL' */
    mcb_pmsm_foc_m_TwoinputsCRL(0.0F, -rtb_Add2, rtb_Add3 +
      mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)rtb_FixPtSum1],
      rtb_Product_l + mcb_pmsm_foc_mpc_qep_f28_ConstP.pooled14[(int16_T)
      (rtb_FixPtSum1 + 200UL)], &rtb_Product_l, &rtb_Add3);

    /* End of Outputs for SubSystem: '<S72>/Two inputs CRL' */

    /* Gain: '<S74>/Ka' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S77>/offset'
     *  Constant: '<S77>/sine_table_values'
     *  DataTypeConversion: '<S77>/Get_Integer'
     *  Saturate: '<S16>/Saturation'
     *  Selector: '<S77>/Lookup'
     *  Sum: '<S77>/Sum'
     *  Sum: '<S78>/Sum4'
     *  Sum: '<S78>/Sum5'
     *  Sum: '<S78>/Sum6'
     *  UnaryMinus: '<S68>/Unary Minus'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Ka = rtb_Product_l;

    /* Gain: '<S74>/one_by_two' */
    rtb_Product_l *= 0.5F;

    /* Gain: '<S74>/sqrt3_by_two' */
    rtb_Add3 *= 0.866025388F;

    /* Gain: '<S74>/Kb' incorporates:
     *  Sum: '<S74>/add_b'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Kb = rtb_Add3 - rtb_Product_l;

    /* Gain: '<S74>/Kc' incorporates:
     *  Sum: '<S74>/add_c'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Kc = (0.0F - rtb_Product_l) - rtb_Add3;

    /* Update for DiscreteIntegrator: '<S70>/Ramp Generator' incorporates:
     *  Constant: '<S16>/Ramp_Time (sec)'
     *  Constant: '<S70>/One'
     *  Gain: '<S70>/Sample_Time'
     *  Product: '<S70>/Divide'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE += 1.66666669E-5F;
    if (mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE > 1.0F) {
      mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE = 1.0F;
    } else if (mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE < 0.0F) {
      mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* End of Update for DiscreteIntegrator: '<S70>/Ramp Generator' */
  } else if (mcb_pmsm_foc_mpc_qep_f28379d_DW.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S70>/Ramp Generator' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RampGenerator_DSTATE =
      mcb_pmsm_foc_mpc_qep_f28379d_B.Eps;
    mcb_pmsm_foc_mpc_qep_f28379d_DW.OpenLoopStartUp_MODE = false;
  }

  /* End of Logic: '<S8>/NOT' */
  /* End of Outputs for SubSystem: '<S8>/Open Loop Start-Up' */

  /* Gain: '<S94>/PositionToCount' incorporates:
   *  Product: '<S93>/Product'
   */
  rtb_PositionToCount = (uint32_T)(4.2949673E+9F * rtb_Product);

  /* Sum: '<S97>/Add1' incorporates:
   *  DataTypeConversion: '<S117>/DTC'
   *  Delay: '<S94>/Delay'
   *  Gain: '<S94>/SpeedGain'
   *  Product: '<S97>/Product'
   *  Product: '<S97>/Product1'
   *  Sum: '<S94>/SpeedCount'
   *  UnitDelay: '<S97>/Unit Delay'
   */
  mcb_pmsm_foc_mpc_qep_f28379d_B.Add1 = (real32_T)((int32_T)rtb_PositionToCount
    - (int32_T)
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE_p[mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx])
    * 8.82157E-10F * 0.01F + 0.99F * mcb_pmsm_foc_mpc_qep_f28379d_B.Add1;

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Ia_Pos'
   *  Constant: '<S9>/Iab'
   *  Constant: '<S9>/Id_control'
   *  Constant: '<S9>/Iq_control'
   *  Constant: '<S9>/speed_control'
   *  DataStoreRead: '<S9>/Data Store Read'
   */
  switch (mcb_pmsm_foc_mpc_qep_f28379d_DW.Debug_signals) {
   case 1:
    rtb_FixPtSum1 = 1U;
    rtb_MultiportSwitch_idx_1 = 2U;
    break;

   case 2:
    rtb_FixPtSum1 = 5U;
    rtb_MultiportSwitch_idx_1 = 6U;
    break;

   case 3:
    rtb_FixPtSum1 = 7U;
    rtb_MultiportSwitch_idx_1 = 8U;
    break;

   case 4:
    rtb_FixPtSum1 = 3U;
    rtb_MultiportSwitch_idx_1 = 4U;
    break;

   default:
    rtb_FixPtSum1 = 3U;
    rtb_MultiportSwitch_idx_1 = 9U;
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* SignalConversion generated from: '<S9>/Selector' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  tmp[0] = mcb_pmsm_foc_mpc_qep_f28379d_DW.SpeedRef;
  tmp[1] = mcb_pmsm_foc_mpc_qep_f28379d_B.Add1;
  tmp[2] = rtb_PU_Conversion_idx_0;
  tmp[3] = rtb_PU_Conversion_idx_1;
  tmp[4] = mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[0];
  tmp[5] = mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o1;
  tmp[6] = mcb_pmsm_foc_mpc_qep_f28379d_B.Idq_ref_PU[1];
  tmp[7] = mcb_pmsm_foc_mpc_qep_f28379d_B.algDD_o2;
  tmp[8] = rtb_Add_j;

  /* Selector: '<S9>/Selector' */
  rtb_Selector[0] = tmp[(int16_T)rtb_FixPtSum1 - 1];
  rtb_Selector[1] = tmp[(int16_T)rtb_MultiportSwitch_idx_1 - 1];

  /* S-Function (any2byte_svd): '<S125>/Byte Pack' */

  /* Pack: <S125>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &rtb_BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 2 */
    {
      MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &rtb_Selector[0], MW_inputPortWidth);
    }
  }

  /* If: '<S123>/If' incorporates:
   *  UnitDelay: '<S126>/Output'
   */
  if (mcb_pmsm_foc_mpc_qep_f28379d_DW.Output_DSTATE == 0U) {
    /* Outputs for IfAction SubSystem: '<S123>/Start' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* SignalConversion generated from: '<S129>/Data_out' incorporates:
     *  Constant: '<S129>/Start'
     *  SignalConversion generated from: '<S129>/Data'
     */
    rtb_SCI_Tx_Data[0] = 1397969747UL;
    rtb_SCI_Tx_Data[1] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[2] = rtb_BytePack[1];

    /* Bias: '<S129>/Bias' */
    rtb_SCI_Tx_Iteration = 3;

    /* End of Outputs for SubSystem: '<S123>/Start' */
  } else if (mcb_pmsm_foc_mpc_qep_f28379d_DW.Output_DSTATE == 599U) {
    /* Outputs for IfAction SubSystem: '<S123>/End' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    /* SignalConversion generated from: '<S128>/Data_out' incorporates:
     *  Constant: '<S128>/End'
     *  SignalConversion generated from: '<S128>/Data'
     */
    rtb_SCI_Tx_Data[0] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[1] = rtb_BytePack[1];
    rtb_SCI_Tx_Data[2] = 1162167621UL;

    /* Bias: '<S128>/Bias' */
    rtb_SCI_Tx_Iteration = 3;

    /* End of Outputs for SubSystem: '<S123>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S123>/Data' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    /* SignalConversion generated from: '<S127>/Data_out' incorporates:
     *  Constant: '<S127>/Dummy'
     *  SignalConversion generated from: '<S127>/Data'
     */
    rtb_SCI_Tx_Data[0] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[1] = rtb_BytePack[1];
    rtb_SCI_Tx_Data[2] = 0UL;

    /* SignalConversion generated from: '<S127>/Data_width' */
    rtb_SCI_Tx_Iteration = 2;

    /* End of Outputs for SubSystem: '<S123>/Data' */
  }

  /* End of If: '<S123>/If' */

  /* Outputs for Iterator SubSystem: '<S121>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S124>/While Iterator'
   */
  /* MultiPortSwitch: '<S124>/Index Vector' */
  i = 0;
  do {
    mcb_pmsm_foc_mpc_qep_f28379d_B.IndexVector = rtb_SCI_Tx_Data[i];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_mpc_qep_f28379d_B.IndexVector, 4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    rtb_Add = (uint32_T)rtb_SCI_Tx_Iteration - (uint32_T)(i + 1);
    i++;
  } while (rtb_Add != 0UL);

  /* End of Outputs for SubSystem: '<S121>/While Iterator Subsystem' */

  /* Switch: '<S120>/Switch' incorporates:
   *  DataStoreRead: '<S13>/Enable'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  mcb_pmsm_foc_mpc_qep_f28379d_B.Switch = mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable;

  /* S-Function (c280xgpio_do): '<S120>/DRV830x Enable' */
  {
    if (mcb_pmsm_foc_mpc_qep_f28379d_B.Switch) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S120>/Switch1' incorporates:
   *  Constant: '<S120>/stop'
   *  Constant: '<S13>/Constant'
   *  DataStoreRead: '<S13>/Enable'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  Gain: '<S120>/Scale_to_PWM_Counter_PRD'
   *  Gain: '<S13>/One_by_Two'
   *  Sum: '<S13>/Sum'
   *  Switch: '<S8>/Switch'
   */
  if ((real32_T)mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable >= 0.5F) {
    /* Switch: '<S8>/Switch' */
    if (mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[0];
    } else {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Ka;
    }

    rtb_Switch1[0] = (uint16_T)((0.5F * rtb_Product_l + 0.5F) * 5000.0F);

    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S13>/Constant'
     *  Gain: '<S120>/Scale_to_PWM_Counter_PRD'
     *  Gain: '<S13>/One_by_Two'
     *  Sum: '<S13>/Sum'
     */
    if (mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[1];
    } else {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Kb;
    }

    rtb_Switch1[1] = (uint16_T)((0.5F * rtb_Product_l + 0.5F) * 5000.0F);

    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S13>/Constant'
     *  Gain: '<S120>/Scale_to_PWM_Counter_PRD'
     *  Gain: '<S13>/One_by_Two'
     *  Sum: '<S13>/Sum'
     */
    if (mcb_pmsm_foc_mpc_qep_f28379d_B.AND) {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Gain[2];
    } else {
      rtb_Product_l = mcb_pmsm_foc_mpc_qep_f28379d_B.Kc;
    }

    rtb_Switch1[2] = (uint16_T)((0.5F * rtb_Product_l + 0.5F) * 5000.0F);
  } else {
    rtb_Switch1[0] = 0U;
    rtb_Switch1[1] = 0U;
    rtb_Switch1[2] = 0U;
  }

  /* End of Switch: '<S120>/Switch1' */

  /* S-Function (c2802xpwm): '<S120>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1[0]);
  }

  /* S-Function (c2802xpwm): '<S120>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1[1]);
  }

  /* S-Function (c2802xpwm): '<S120>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1[2]);
  }

  /* Switch: '<S131>/FixPt Switch' incorporates:
   *  Constant: '<S130>/FixPt Constant'
   *  Sum: '<S130>/FixPt Sum1'
   *  UnitDelay: '<S126>/Output'
   */
  if (mcb_pmsm_foc_mpc_qep_f28379d_DW.Output_DSTATE + 1U > 599U) {
    /* Update for UnitDelay: '<S126>/Output' incorporates:
     *  Constant: '<S131>/Constant'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S126>/Output' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S131>/FixPt Switch' */

  /* Update for Delay: '<S94>/Delay' */
  mcb_pmsm_foc_mpc_qep_f28379d_DW.Delay_DSTATE_p[mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx]
    = rtb_PositionToCount;
  if (mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx < 19U) {
    mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx++;
  } else {
    mcb_pmsm_foc_mpc_qep_f28379d_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S94>/Delay' */
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S147>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_pmsm__SPIMasterTransfer(uint16_T rtu_0, DW_SPIMasterTransfer_mcb_pmsm_T
  *localDW)
{
  uint16_T rdDataRaw;

  /* MATLABSystem: '<S147>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  rdDataRaw = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (rdDataRaw == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* End of MATLABSystem: '<S147>/SPI Master Transfer' */
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S147>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S147>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Constant: '<S157>/Ki2'
   */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_m_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, real32_T *rty_IdqRef_PU, real32_T *rty_IdqRef_PU_h, const
  boolean_T *rtd_EnClosedLoop, const boolean_T *rtd_Enable,
  DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  real32_T rtb_Add1;
  real32_T rtb_DeadZone;
  real32_T rtb_IProdOut;
  real32_T rtb_Sum_e;
  int16_T tmp;
  int16_T tmp_0;
  boolean_T rtb_LogicalOperator_d;

  /* Constant: '<S7>/Id_ref' */
  *rty_IdqRef_PU = 0.0F;

  /* Switch: '<S158>/Switch' incorporates:
   *  DataStoreRead: '<S158>/Data Store Read'
   *  DataStoreRead: '<S158>/Data Store Read1'
   *  Logic: '<S158>/AND'
   */
  if ((*rtd_EnClosedLoop) && (*rtd_Enable)) {
    rtb_Add1 = rtu_Speed_Ref_PU;
  } else {
    rtb_Add1 = rtu_Speed_Meas_PU;
  }

  /* Sum: '<S217>/Add1' incorporates:
   *  Product: '<S217>/Product'
   *  Product: '<S217>/Product1'
   *  Switch: '<S158>/Switch'
   *  UnitDelay: '<S217>/Unit Delay'
   */
  rtb_Add1 = rtb_Add1 * 0.2F + 0.8F * localDW->UnitDelay_DSTATE;

  /* Sum: '<S157>/Sum' */
  rtb_IProdOut = rtb_Add1 - rtu_Speed_Meas_PU;

  /* Logic: '<S157>/Logical Operator' incorporates:
   *  DataStoreRead: '<S157>/Data Store Read1'
   */
  rtb_LogicalOperator_d = !*rtd_Enable;

  /* DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Constant: '<S157>/Ki2'
   */
  if (rtb_LogicalOperator_d || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* Sum: '<S206>/Sum' incorporates:
   *  Constant: '<S157>/Kp1'
   *  DiscreteIntegrator: '<S197>/Integrator'
   *  Product: '<S202>/PProd Out'
   */
  rtb_Sum_e = rtb_IProdOut * 0.114279762F + localDW->Integrator_DSTATE;

  /* DeadZone: '<S189>/DeadZone' incorporates:
   *  Saturate: '<S204>/Saturation'
   */
  if (rtb_Sum_e > 1.0F) {
    rtb_DeadZone = rtb_Sum_e - 1.0F;
    *rty_IdqRef_PU_h = 1.0F;
  } else {
    if (rtb_Sum_e >= -1.0F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rtb_Sum_e - -1.0F;
    }

    if (rtb_Sum_e < -1.0F) {
      *rty_IdqRef_PU_h = -1.0F;
    } else {
      *rty_IdqRef_PU_h = rtb_Sum_e;
    }
  }

  /* End of DeadZone: '<S189>/DeadZone' */

  /* Product: '<S194>/IProd Out' incorporates:
   *  Constant: '<S157>/Ki1'
   */
  rtb_IProdOut *= 0.00253549335F;

  /* Update for UnitDelay: '<S217>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtb_Add1;

  /* Switch: '<S187>/Switch1' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S187>/Constant2'
   *  RelationalOperator: '<S187>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   *  Constant: '<S187>/Constant3'
   *  Constant: '<S187>/Constant4'
   *  RelationalOperator: '<S187>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   *  Constant: '<S187>/Constant1'
   *  Logic: '<S187>/AND3'
   *  RelationalOperator: '<S187>/Equal1'
   *  RelationalOperator: '<S187>/Relational Operator'
   *  Switch: '<S187>/Switch1'
   *  Switch: '<S187>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Switch: '<S187>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int16_T)rtb_LogicalOperator_d;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_mpc_qep_f28379d_step0(void) /* Sample time: [0.0002s, 0.0s] */
{
  int16_T tmp;

  {                                    /* Sample time: [0.0002s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT2' */
  tmp = mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_ActiveBufIdx << 1U;
  mcb_pmsm_foc_mpc_qep_f28379d_B.RT2[0] =
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_Buffer[tmp];
  mcb_pmsm_foc_mpc_qep_f28379d_B.RT2[1] =
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_Buffer[tmp + 1];

  /* Outputs for Atomic SubSystem: '<Root>/Current Control' */
  mcb_pmsm_foc_CurrentControl();

  /* End of Outputs for SubSystem: '<Root>/Current Control' */

  /* RateTransition: '<Root>/RT1' */
  if (mcb_pmsm_foc_mpc_qep_f28379d_DW.RT1_semaphoreTaken == 0) {
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RT1_Buffer0 =
      mcb_pmsm_foc_mpc_qep_f28379d_B.Add1;
  }

  /* End of RateTransition: '<Root>/RT1' */
}

/* Model step function for TID1 */
void mcb_pmsm_foc_mpc_qep_f28379d_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  real32_T rtb_Id_ref;
  real32_T rtb_RT1;
  real32_T rtb_RT3;
  real32_T rtb_Saturation;

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_mpc_qep_f28379d_DW.RT1_semaphoreTaken = 1;
  rtb_RT1 = mcb_pmsm_foc_mpc_qep_f28379d_DW.RT1_Buffer0;
  mcb_pmsm_foc_mpc_qep_f28379d_DW.RT1_semaphoreTaken = 0;

  /* RateTransition: '<Root>/RT3' */
  rtb_RT3 =
    mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_Buffer[mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm_foc_m_SpeedControl(rtb_RT3, rtb_RT1, &rtb_Id_ref, &rtb_Saturation,
    &mcb_pmsm_foc_mpc_qep_f28379d_DW.EnClosedLoop,
    &mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable,
    &mcb_pmsm_foc_mpc_qep_f28379d_DW.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_Buffer
    [(mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_ActiveBufIdx == 0) << 1U] = rtb_Id_ref;
  mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_Buffer[1 +
    ((mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_ActiveBufIdx == 0) << 1U)] =
    rtb_Saturation;
  mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_mpc_qep_f28379d_DW.RT2_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void mcb_pmsm_foc_mpc_qep_f28379d_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S149>/Digital Output' incorporates:
   *  Constant: '<S4>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_mpc_qep_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_mpc_qep_f28379d_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_mpc_qep_T));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_mpc_qep_f28379d_B), 0,
                sizeof(B_mcb_pmsm_foc_mpc_qep_f28379_T));

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_mpc_qep_f28379d_DW, 0,
                sizeof(DW_mcb_pmsm_foc_mpc_qep_f2837_T));

  {
    uint16_T s141_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.IaOffset = 2295U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.IbOffset = 2286U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_mpc_qep_f28379d_DW.Debug_signals = 5U;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Current Control' */
    mcb_pms_CurrentControl_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Current Control' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S156>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[0] = (real32_T)0.0;
      mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[1] = (real32_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_mpc_qep_f28379d_DW.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S149>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S139>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S139>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x400000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S139>/ADC Gain setting' */
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer);
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<S139>/ADC Gain setting' */

    /* SystemInitialize for Enabled SubSystem: '<S137>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S138>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S141>/ADC_A_IN0' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC2 ();

    /* Start for S-Function (c2802xadc): '<S141>/ADC_B_IN0' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC2 ();

    /* End of SystemInitialize for SubSystem: '<S138>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S137>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Enabled SubSystem: '<S139>/ADC Gain setting' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    /* Constant: '<S3>/6PWM_Mode' */
    mcb_pmsm__SPIMasterTransfer(14870U,
      &mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    mcb_pmsm__SPIMasterTransfer(20480U,
      &mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer1);

    /* End of Outputs for SubSystem: '<S139>/ADC Gain setting' */

    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S139>/Inverter Enable'
     */
    mcb_pmsm_foc_mpc_qep_f28379d_B.Switch_c = 1U;

    /* S-Function (c280xgpio_do): '<S139>/Digital Output' */
    {
      if (mcb_pmsm_foc_mpc_qep_f28379d_B.Switch_c) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* S-Function (c280xgpio_do): '<S139>/Digital Output1' incorporates:
     *  Constant: '<S139>/RunTimeMeasurement'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO22 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S137>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S138>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S138>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S141>/For Iterator'
     */
    for (s141_iter = 1U; s141_iter < 17U; s141_iter++) {
      /* S-Function (c2802xadc): '<S141>/ADC_A_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S141>/ADC_B_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S141>/If' */
      if (s141_iter > 8U) {
        /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        /* Sum: '<S146>/Sum' incorporates:
         *  Memory: '<S146>/Memory'
         */
        mcb_pmsm_foc_mpc_qep_f28379d_B.Sum =
          mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_A_IN0 +
          mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory_PreviousInput;

        /* Sum: '<S146>/Sum1' incorporates:
         *  Memory: '<S146>/Memory1'
         */
        mcb_pmsm_foc_mpc_qep_f28379d_B.Sum1 =
          mcb_pmsm_foc_mpc_qep_f28379d_B.ADC_B_IN0 +
          mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory1_PreviousInput;

        /* Update for Memory: '<S146>/Memory' */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory_PreviousInput =
          mcb_pmsm_foc_mpc_qep_f28379d_B.Sum;

        /* Update for Memory: '<S146>/Memory1' */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.Memory1_PreviousInput =
          mcb_pmsm_foc_mpc_qep_f28379d_B.Sum1;

        /* End of Outputs for SubSystem: '<S141>/If Action Subsystem' */
      }

      /* End of If: '<S141>/If' */
    }

    /* End of Outputs for SubSystem: '<S138>/For Iterator Subsystem' */

    /* Product: '<S138>/Divide' incorporates:
     *  Constant: '<S138>/Constant'
     */
    s141_iter = (uint16_T)((real_T)mcb_pmsm_foc_mpc_qep_f28379d_B.Sum / 8.0);

    /* If: '<S138>/If' incorporates:
     *  Constant: '<S138>/Constant1'
     *  Constant: '<S138>/Constant2'
     */
    if ((s141_iter > 1500U) && (s141_iter < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem' incorporates:
       *  ActionPort: '<S142>/Action Port'
       */
      /* DataStoreWrite: '<S142>/Data Store Write1' */
      mcb_pmsm_foc_mpc_qep_f28379d_DW.IaOffset = s141_iter;

      /* End of Outputs for SubSystem: '<S138>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S143>/Action Port'
       */
      /* DataStoreWrite: '<S143>/Data Store Write1' incorporates:
       *  Constant: '<S143>/Constant'
       */
      mcb_pmsm_foc_mpc_qep_f28379d_DW.IaOffset = 2295U;

      /* End of Outputs for SubSystem: '<S138>/If Action Subsystem1' */
    }

    /* End of If: '<S138>/If' */

    /* Product: '<S138>/Divide1' incorporates:
     *  Constant: '<S138>/Constant'
     */
    s141_iter = (uint16_T)((real_T)mcb_pmsm_foc_mpc_qep_f28379d_B.Sum1 / 8.0);

    /* If: '<S138>/If1' incorporates:
     *  Constant: '<S138>/Constant1'
     *  Constant: '<S138>/Constant2'
     */
    if ((s141_iter > 1500U) && (s141_iter < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S144>/Action Port'
       */
      /* DataStoreWrite: '<S144>/Data Store Write2' */
      mcb_pmsm_foc_mpc_qep_f28379d_DW.IbOffset = s141_iter;

      /* End of Outputs for SubSystem: '<S138>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S145>/Action Port'
       */
      /* DataStoreWrite: '<S145>/Data Store Write2' incorporates:
       *  Constant: '<S145>/Constant1'
       */
      mcb_pmsm_foc_mpc_qep_f28379d_DW.IbOffset = 2286U;

      /* End of Outputs for SubSystem: '<S138>/If Action Subsystem3' */
    }

    /* End of If: '<S138>/If1' */
    /* End of Outputs for SubSystem: '<S137>/Calculate ADC Offset ' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_mpc_qep_f28379d_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Enabled SubSystem: '<S139>/ADC Gain setting' */
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer);
  mcb__SPIMasterTransfer_Term
    (&mcb_pmsm_foc_mpc_qep_f28379d_DW.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<S139>/ADC Gain setting' */
  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_pmsm_foc_mpc_qep_f28379d_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,1);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S135>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Rx FIFO complete */
  /* Check event Rx FIFO complete occurred */
  if (0 != (SciaRegs.SCIFFRX.bit.RXFFINT==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Serial Receive' */

        /* S-Function (c28xsci_rx): '<S156>/SCI Receive' */
        {
          int16_T i;
          int16_T errFlg = NOERROR;
          uint16_T isHeadReceived = 1U;

          //get data as uint16 in recBuff
          uint16_T recbuff[4];
          for (i = 0; i < 4; i++) {
            recbuff[i] = 0U;
          }

          errFlg = NOERROR;

          /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
          if (isHeadReceived) {
            errFlg = scia_rcv(recbuff, 8, 4);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[0], recbuff,4);
            }
          }
        }

        /* DataTypeConversion: '<S153>/Data Type Conversion3' incorporates:
         *  DataStoreWrite: '<S6>/Data Store Write'
         *  DataTypeConversion: '<S154>/Data Type Conversion2'
         *  S-Function (sfix_bitop): '<S153>/Bitwise Operator'
         */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.Enable = (((uint16_T)
          mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[1] & 1U) != 0U);

        /* DataStoreWrite: '<S6>/Data Store Write1' */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.SpeedRef =
          mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[0];

        /* ArithShift: '<S153>/Shift Arithmetic1' incorporates:
         *  DataStoreWrite: '<S6>/Data Store Write2'
         *  DataTypeConversion: '<S154>/Data Type Conversion2'
         *  S-Function (sfix_bitop): '<S153>/Bitwise Operator1'
         */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.Debug_signals = ((uint16_T)
          mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[1] & 240U) >> 4U;

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

        /* RateTransition: '<Root>/RT3' */
        mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_Buffer[mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_ActiveBufIdx
          == 0] = mcb_pmsm_foc_mpc_qep_f28379d_B.SCIReceive[0];
        mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_ActiveBufIdx =
          (mcb_pmsm_foc_mpc_qep_f28379d_DW.RT3_ActiveBufIdx == 0);
      }
    }

    /* Clear occurred Rx FIFO complete event */
    EALLOW;
    SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
    EDIS;
  }

  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_mpc_qep_f28379d_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
