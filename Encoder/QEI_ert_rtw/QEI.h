/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI.h
 *
 * Code generated for Simulink model 'QEI'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 16 21:59:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QEI_h_
#define QEI_h_
#ifndef QEI_COMMON_INCLUDES_
#define QEI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* QEI_COMMON_INCLUDES_ */

#include "QEI_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T diff_count;                   /* '<Root>/x4' */
  real_T pulses;                       /* '<Root>/x4' */
  real_T diff_count_g;                 /* '<Root>/x2' */
  real_T pulses_b;                     /* '<Root>/x2' */
  real_T diff_count_m;                 /* '<Root>/x1' */
  real_T pulses_l;                     /* '<Root>/x1' */
  real_T pps;                          /* '<Root>/x1' */
  real_T encoder_count;                /* '<Root>/encoder_x1' */
  uint32_T qei1;                       /* '<Root>/Encoder2' */
  uint32_T qei2;                       /* '<Root>/Encoder1' */
  uint32_T qei4;                       /* '<Root>/Encoder' */
  int32_T encoder_count_p;             /* '<Root>/encoder_x3' */
  int32_T encoder_count_h;             /* '<Root>/encoder_x2' */
  boolean_T dir1;                      /* '<Root>/Encoder2' */
  boolean_T dir2;                      /* '<Root>/Encoder1' */
  boolean_T dir4;                      /* '<Root>/Encoder' */
  boolean_T DigitalPortRead;           /* '<S12>/Digital Port Read' */
  boolean_T DigitalPortRead_k;         /* '<S10>/Digital Port Read' */
} B_QEI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_e;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_l;/* '<Root>/Encoder' */
  real_T prev_count;                   /* '<Root>/x4' */
  real_T pulses_accum;                 /* '<Root>/x4' */
  real_T prev_count_p;                 /* '<Root>/x2' */
  real_T pulses_accum_p;               /* '<Root>/x2' */
  real_T prev_count_o;                 /* '<Root>/x1' */
  real_T pulses_accum_n;               /* '<Root>/x1' */
  real_T prev_A;                       /* '<Root>/encoder_x2' */
  real_T prev_A_d;                     /* '<Root>/encoder_x1' */
  real_T encoder_count_value;          /* '<Root>/encoder_x1' */
  int32_T encoder_count_value_o;       /* '<Root>/encoder_x3' */
  int32_T encoder_count_value_j;       /* '<Root>/encoder_x2' */
  uint8_T prev_state;                  /* '<Root>/encoder_x3' */
} DW_QEI_T;

/* Real-time Model Data Structure */
struct tag_RTM_QEI_T {
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
extern B_QEI_T QEI_B;

/* Block states (default storage) */
extern DW_QEI_T QEI_DW;

/* Model entry point functions */
extern void QEI_initialize(void);
extern void QEI_step(void);
extern void QEI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_QEI_T *const QEI_M;
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
 * '<Root>' : 'QEI'
 * '<S1>'   : 'QEI/Digital Port Read2'
 * '<S2>'   : 'QEI/Digital Port Read3'
 * '<S3>'   : 'QEI/encoder_x1'
 * '<S4>'   : 'QEI/encoder_x2'
 * '<S5>'   : 'QEI/encoder_x3'
 * '<S6>'   : 'QEI/x1'
 * '<S7>'   : 'QEI/x2'
 * '<S8>'   : 'QEI/x4'
 * '<S9>'   : 'QEI/Digital Port Read2/ECSoC'
 * '<S10>'  : 'QEI/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S11>'  : 'QEI/Digital Port Read3/ECSoC'
 * '<S12>'  : 'QEI/Digital Port Read3/ECSoC/ECSimCodegen'
 */
#endif                                 /* QEI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
