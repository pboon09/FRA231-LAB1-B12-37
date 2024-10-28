/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Read_Encoder.h
 *
 * Code generated for Simulink model 'Read_Encoder'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 17 01:07:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Read_Encoder_h_
#define Read_Encoder_h_
#ifndef Read_Encoder_COMMON_INCLUDES_
#define Read_Encoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* Read_Encoder_COMMON_INCLUDES_ */

#include "Read_Encoder_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>/Change Unit' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Change Unit' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/Change Unit' */
} DW_ChangeUnit_Read_Encoder_T;

/* Block signals (default storage) */
typedef struct {
  real_T radps;                        /* '<Root>/Change Unit5' */
  real_T rad;                          /* '<Root>/Change Unit5' */
  real_T radps_c;                      /* '<Root>/Change Unit4' */
  real_T rad_g;                        /* '<Root>/Change Unit4' */
  real_T radps_d;                      /* '<Root>/Change Unit3' */
  real_T rad_e;                        /* '<Root>/Change Unit3' */
  real_T radps_k;                      /* '<Root>/Change Unit2' */
  real_T rad_m;                        /* '<Root>/Change Unit2' */
  real_T radps_n;                      /* '<Root>/Change Unit1' */
  real_T rad_h;                        /* '<Root>/Change Unit1' */
  real_T radps_p;                      /* '<Root>/Change Unit' */
  real_T rad_f;                        /* '<Root>/Change Unit' */
} B_Read_Encoder_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder 3' */
  stm32cube_blocks_EncoderBlock_T obj_e;/* '<Root>/Encoder 2' */
  stm32cube_blocks_EncoderBlock_T obj_o;/* '<Root>/Encoder 1' */
  real_T prev_count;                   /* '<Root>/qei_x4' */
  real_T pulses_accum;                 /* '<Root>/qei_x4' */
  real_T prev_count_m;                 /* '<Root>/qei_x2' */
  real_T pulses_accum_i;               /* '<Root>/qei_x2' */
  real_T prev_count_o;                 /* '<Root>/qei_x1' */
  real_T pulses_accum_n;               /* '<Root>/qei_x1' */
  real_T prev_A;                       /* '<Root>/encoder_x4' */
  real_T prev_B;                       /* '<Root>/encoder_x4' */
  real_T count;                        /* '<Root>/encoder_x4' */
  real_T prev_count_k;                 /* '<Root>/encoder_x4' */
  real_T prev_A_m;                     /* '<Root>/encoder_x2' */
  real_T count_l;                      /* '<Root>/encoder_x2' */
  real_T prev_count_kd;                /* '<Root>/encoder_x2' */
  real_T prev_A_d;                     /* '<Root>/encoder_x1' */
  real_T count_lf;                     /* '<Root>/encoder_x1' */
  real_T prev_count_mm;                /* '<Root>/encoder_x1' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit5;/* '<Root>/Change Unit5' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit4;/* '<Root>/Change Unit4' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit3;/* '<Root>/Change Unit3' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit2;/* '<Root>/Change Unit2' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit1;/* '<Root>/Change Unit1' */
  DW_ChangeUnit_Read_Encoder_T sf_ChangeUnit;/* '<Root>/Change Unit' */
} DW_Read_Encoder_T;

/* Real-time Model Data Structure */
struct tag_RTM_Read_Encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_Read_Encoder_T Read_Encoder_B;

/* Block states (default storage) */
extern DW_Read_Encoder_T Read_Encoder_DW;

/* Model entry point functions */
extern void Read_Encoder_initialize(void);
extern void Read_Encoder_step(void);
extern void Read_Encoder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Read_Encoder_T *const Read_Encoder_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Read_Encoder'
 * '<S1>'   : 'Read_Encoder/Change Unit'
 * '<S2>'   : 'Read_Encoder/Change Unit1'
 * '<S3>'   : 'Read_Encoder/Change Unit2'
 * '<S4>'   : 'Read_Encoder/Change Unit3'
 * '<S5>'   : 'Read_Encoder/Change Unit4'
 * '<S6>'   : 'Read_Encoder/Change Unit5'
 * '<S7>'   : 'Read_Encoder/Digital Port Read 1'
 * '<S8>'   : 'Read_Encoder/Digital Port Read 2'
 * '<S9>'   : 'Read_Encoder/encoder_x1'
 * '<S10>'  : 'Read_Encoder/encoder_x2'
 * '<S11>'  : 'Read_Encoder/encoder_x4'
 * '<S12>'  : 'Read_Encoder/qei_x1'
 * '<S13>'  : 'Read_Encoder/qei_x2'
 * '<S14>'  : 'Read_Encoder/qei_x4'
 * '<S15>'  : 'Read_Encoder/Digital Port Read 1/ECSoC'
 * '<S16>'  : 'Read_Encoder/Digital Port Read 1/ECSoC/ECSimCodegen'
 * '<S17>'  : 'Read_Encoder/Digital Port Read 2/ECSoC'
 * '<S18>'  : 'Read_Encoder/Digital Port Read 2/ECSoC/ECSimCodegen'
 */
#endif                                 /* Read_Encoder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
