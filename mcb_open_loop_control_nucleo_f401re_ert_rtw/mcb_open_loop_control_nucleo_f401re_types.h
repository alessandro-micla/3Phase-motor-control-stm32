/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_open_loop_control_nucleo_f401re_types.h
 *
 * Code generated for Simulink model 'mcb_open_loop_control_nucleo_f401re'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Feb  5 17:10:38 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_open_loop_control_nucleo_f401re_types_h_
#define mcb_open_loop_control_nucleo_f401re_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#include "stm_can_hal.h"
#ifndef DEFINED_TYPEDEF_FOR_CANMsg_
#define DEFINED_TYPEDEF_FOR_CANMsg_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CANMsg;

#endif

/* Custom Type definition for MATLABSystem: '<S18>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_tsKyPuhWUdS8zBSeRGR2aC
#define struct_tag_tsKyPuhWUdS8zBSeRGR2aC

struct tag_tsKyPuhWUdS8zBSeRGR2aC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_tsKyPuhWUdS8zBSeRGR2aC */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_tsKyPuhWUdS8zBSeRGR2aC stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Custom Type definition for MATLABSystem: '<S26>/PWM Output' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_0RzKA0TA5eXyA1b3sjyvMG
#define struct_tag_0RzKA0TA5eXyA1b3sjyvMG

struct tag_0RzKA0TA5eXyA1b3sjyvMG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_0RzKA0TA5eXyA1b3sjyvMG */

#ifndef typedef_stm32cube_blocks_PWMOutput_mc_T
#define typedef_stm32cube_blocks_PWMOutput_mc_T

typedef struct tag_0RzKA0TA5eXyA1b3sjyvMG stm32cube_blocks_PWMOutput_mc_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_mc_T */

#ifndef struct_tag_UjrdchBSJr9uXrLnGNh2HB
#define struct_tag_UjrdchBSJr9uXrLnGNh2HB

struct tag_UjrdchBSJr9uXrLnGNh2HB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
};

#endif                                 /* struct_tag_UjrdchBSJr9uXrLnGNh2HB */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_UjrdchBSJr9uXrLnGNh2HB stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

/* Custom Type definition for MATLABSystem: '<S2>/CAN Write' */
#include "stm_can_hal.h"
#ifndef struct_tag_SnSgtQYxxl9kKF1a4KngUE
#define struct_tag_SnSgtQYxxl9kKF1a4KngUE

struct tag_SnSgtQYxxl9kKF1a4KngUE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  CAN_Type_T * MW_CAN_HANDLE;
};

#endif                                 /* struct_tag_SnSgtQYxxl9kKF1a4KngUE */

#ifndef typedef_stm32cube_blocks_CANRead_mcb__T
#define typedef_stm32cube_blocks_CANRead_mcb__T

typedef struct tag_SnSgtQYxxl9kKF1a4KngUE stm32cube_blocks_CANRead_mcb__T;

#endif                             /* typedef_stm32cube_blocks_CANRead_mcb__T */

#ifndef struct_tag_PntCqqci1qldtb9wcAzzPH
#define struct_tag_PntCqqci1qldtb9wcAzzPH

struct tag_PntCqqci1qldtb9wcAzzPH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  CAN_Type_T * MW_CAN_HANDLE;
};

#endif                                 /* struct_tag_PntCqqci1qldtb9wcAzzPH */

#ifndef typedef_stm32cube_blocks_CANWrite_mcb_T
#define typedef_stm32cube_blocks_CANWrite_mcb_T

typedef struct tag_PntCqqci1qldtb9wcAzzPH stm32cube_blocks_CANWrite_mcb_T;

#endif                             /* typedef_stm32cube_blocks_CANWrite_mcb_T */

/* Parameters (default storage) */
typedef struct P_mcb_open_loop_control_nucle_T_ P_mcb_open_loop_control_nucle_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_mcb_open_loop_control_T RT_MODEL_mcb_open_loop_contro_T;

#endif                        /* mcb_open_loop_control_nucleo_f401re_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
