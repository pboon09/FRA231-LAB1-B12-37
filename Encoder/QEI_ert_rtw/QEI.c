/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI.c
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

#include "QEI.h"
#include "QEI_types.h"
#include "QEI_private.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include <math.h>

/* Block signals (default storage) */
B_QEI_T QEI_B;

/* Block states (default storage) */
DW_QEI_T QEI_DW;

/* Real-time model */
static RT_MODEL_QEI_T QEI_M_;
RT_MODEL_QEI_T *const QEI_M = &QEI_M_;

/* Forward declaration for local functions */
static void QEI_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void QEI_SystemCore_setup_l(stm32cube_blocks_EncoderBlock_T *obj);
static void QEI_SystemCore_setup_l0(stm32cube_blocks_EncoderBlock_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void QEI_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void QEI_SystemCore_setup_l(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void QEI_SystemCore_setup_l0(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void QEI_step(void)
{
  real_T tmp_0;
  int32_T q1;
  int32_T tmp;
  int32_T tmp_1;
  uint32_T pinReadLoc;
  uint8_T tmp_2;
  static const int8_T b[16] = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1,
    0 };

  /* MATLABSystem: '<Root>/Encoder' */
  QEI_B.qei4 = getTimerCounterValueForG4(QEI_DW.obj_l.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder' */
  QEI_B.dir4 = ouputDirectionOfCounter(QEI_DW.obj_l.TimerHandle);

  /* MATLAB Function: '<Root>/x4' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   */
  QEI_B.diff_count = (real_T)QEI_B.qei4 - QEI_DW.prev_count;
  if (QEI_B.diff_count > 32768.0) {
    QEI_B.diff_count -= 65536.0;
  } else if (QEI_B.diff_count < -32768.0) {
    QEI_B.diff_count += 65536.0;
  }

  QEI_DW.pulses_accum += QEI_B.diff_count;
  QEI_B.pulses = QEI_DW.pulses_accum;
  QEI_DW.prev_count = QEI_B.qei4;

  /* End of MATLAB Function: '<Root>/x4' */
  /* MATLABSystem: '<Root>/Encoder1' */
  QEI_B.qei2 = getTimerCounterValueForG4(QEI_DW.obj_e.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder1' */
  QEI_B.dir2 = ouputDirectionOfCounter(QEI_DW.obj_e.TimerHandle);

  /* MATLAB Function: '<Root>/x2' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double1'
   */
  QEI_B.diff_count_g = (real_T)QEI_B.qei2 - QEI_DW.prev_count_p;
  if (QEI_B.diff_count_g > 32768.0) {
    QEI_B.diff_count_g -= 65536.0;
  } else if (QEI_B.diff_count_g < -32768.0) {
    QEI_B.diff_count_g += 65536.0;
  }

  QEI_DW.pulses_accum_p += QEI_B.diff_count_g;
  QEI_B.pulses_b = QEI_DW.pulses_accum_p;
  QEI_DW.prev_count_p = QEI_B.qei2;

  /* End of MATLAB Function: '<Root>/x2' */
  /* MATLABSystem: '<Root>/Encoder2' */
  QEI_B.qei1 = getTimerCounterValueForG4(QEI_DW.obj.TimerHandle, false, NULL);

  /* MATLABSystem: '<Root>/Encoder2' */
  QEI_B.dir1 = ouputDirectionOfCounter(QEI_DW.obj.TimerHandle);

  /* MATLAB Function: '<Root>/x1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double2'
   */
  QEI_B.diff_count_m = (real_T)QEI_B.qei1 - QEI_DW.prev_count_o;
  if (QEI_B.diff_count_m > 32768.0) {
    QEI_B.diff_count_m -= 65536.0;
  } else if (QEI_B.diff_count_m < -32768.0) {
    QEI_B.diff_count_m += 65536.0;
  }

  QEI_DW.pulses_accum_n += QEI_B.diff_count_m;
  QEI_B.pulses_l = QEI_DW.pulses_accum_n;
  QEI_B.pps = QEI_B.diff_count_m * 100.0;
  QEI_DW.prev_count_o = QEI_B.qei1;

  /* End of MATLAB Function: '<Root>/x1' */
  /* MATLABSystem: '<S10>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S10>/Digital Port Read' */
  QEI_B.DigitalPortRead_k = ((pinReadLoc & 512U) != 0U);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  QEI_B.DataTypeConversion = QEI_B.DigitalPortRead_k;

  /* MATLABSystem: '<S12>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S12>/Digital Port Read' */
  QEI_B.DigitalPortRead = ((pinReadLoc & 128U) != 0U);

  /* MATLAB Function: '<Root>/encoder_x3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  tmp_0 = rt_roundd_snf(QEI_B.DataTypeConversion);
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      tmp_2 = (uint8_T)tmp_0;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  tmp_1 = (int32_T)((uint32_T)(uint8_T)(tmp_2 << 1) + QEI_B.DigitalPortRead);
  if (tmp_1 > 255) {
    tmp_1 = 255;
  }

  if (QEI_DW.prev_state > 63) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(QEI_DW.prev_state << 2);
  }

  q1 = (int32_T)(tmp_2 + (uint32_T)tmp_1);
  if (q1 > 255) {
    q1 = 255;
  }

  tmp = (int32_T)((uint32_T)q1 + 1U);
  if ((uint32_T)q1 + 1U > 255U) {
    tmp = 255;
  }

  q1 = b[tmp - 1];
  if ((QEI_DW.encoder_count_value_o < 0) && (q1 < MIN_int32_T
       - QEI_DW.encoder_count_value_o)) {
    QEI_DW.encoder_count_value_o = MIN_int32_T;
  } else if ((QEI_DW.encoder_count_value_o > 0) && (q1 > MAX_int32_T
              - QEI_DW.encoder_count_value_o)) {
    QEI_DW.encoder_count_value_o = MAX_int32_T;
  } else {
    QEI_DW.encoder_count_value_o += q1;
  }

  QEI_DW.prev_state = (uint8_T)tmp_1;
  QEI_B.encoder_count_p = QEI_DW.encoder_count_value_o;

  /* End of MATLAB Function: '<Root>/encoder_x3' */
  /* MATLAB Function: '<Root>/encoder_x1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  if ((QEI_DW.prev_A_d == 0.0) && (QEI_B.DataTypeConversion == 1.0)) {
    if (!QEI_B.DigitalPortRead) {
      QEI_DW.encoder_count_value++;
    } else {
      QEI_DW.encoder_count_value--;
    }
  }

  QEI_DW.prev_A_d = QEI_B.DataTypeConversion;
  QEI_B.encoder_count = QEI_DW.encoder_count_value;

  /* End of MATLAB Function: '<Root>/encoder_x1' */
  /* MATLAB Function: '<Root>/encoder_x2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  if (QEI_B.DataTypeConversion != QEI_DW.prev_A) {
    if (QEI_DW.prev_A == QEI_B.DigitalPortRead) {
      if (QEI_DW.encoder_count_value_j <= 2147483646) {
        QEI_DW.encoder_count_value_j++;
      }
    } else if (QEI_DW.encoder_count_value_j >= -2147483647) {
      QEI_DW.encoder_count_value_j--;
    }
  }

  QEI_DW.prev_A = QEI_B.DataTypeConversion;
  QEI_B.encoder_count_h = QEI_DW.encoder_count_value_j;

  /* End of MATLAB Function: '<Root>/encoder_x2' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  QEI_M->Timing.taskTime0 =
    ((time_T)(++QEI_M->Timing.clockTick0)) * QEI_M->Timing.stepSize0;
}

/* Model initialize function */
void QEI_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(QEI_M, -1);
  QEI_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  QEI_M->Sizes.checksums[0] = (2730081727U);
  QEI_M->Sizes.checksums[1] = (1895262325U);
  QEI_M->Sizes.checksums[2] = (251275695U);
  QEI_M->Sizes.checksums[3] = (4284361042U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    QEI_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QEI_M->extModeInfo,
      &QEI_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QEI_M->extModeInfo, QEI_M->Sizes.checksums);
    rteiSetTPtr(QEI_M->extModeInfo, rtmGetTPtr(QEI_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder' */
  QEI_DW.obj_l.isInitialized = 0;
  QEI_DW.obj_l.matlabCodegenIsDeleted = false;
  QEI_SystemCore_setup(&QEI_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  QEI_DW.obj_e.isInitialized = 0;
  QEI_DW.obj_e.matlabCodegenIsDeleted = false;
  QEI_SystemCore_setup_l(&QEI_DW.obj_e);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  QEI_DW.obj.isInitialized = 0;
  QEI_DW.obj.matlabCodegenIsDeleted = false;
  QEI_SystemCore_setup_l0(&QEI_DW.obj);
}

/* Model terminate function */
void QEI_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!QEI_DW.obj_l.matlabCodegenIsDeleted) {
    QEI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((QEI_DW.obj_l.isInitialized == 1) && QEI_DW.obj_l.isSetupComplete) {
      disableCounter(QEI_DW.obj_l.TimerHandle);
      disableTimerInterrupts(QEI_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_DW.obj_l.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_DW.obj_l.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!QEI_DW.obj_e.matlabCodegenIsDeleted) {
    QEI_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((QEI_DW.obj_e.isInitialized == 1) && QEI_DW.obj_e.isSetupComplete) {
      disableCounter(QEI_DW.obj_e.TimerHandle);
      disableTimerInterrupts(QEI_DW.obj_e.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_DW.obj_e.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_DW.obj_e.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!QEI_DW.obj.matlabCodegenIsDeleted) {
    QEI_DW.obj.matlabCodegenIsDeleted = true;
    if ((QEI_DW.obj.isInitialized == 1) && QEI_DW.obj.isSetupComplete) {
      disableCounter(QEI_DW.obj.TimerHandle);
      disableTimerInterrupts(QEI_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
