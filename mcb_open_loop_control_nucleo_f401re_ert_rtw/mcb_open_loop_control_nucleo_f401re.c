/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_open_loop_control_nucleo_f401re.c
 *
 * Code generated for Simulink model 'mcb_open_loop_control_nucleo_f401re'.
 *
 * Model version                  : 9.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Feb 16 20:00:16 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_open_loop_control_nucleo_f401re.h"
#include "mcb_open_loop_control_nucleo_f401re_types.h"
#include "rtwtypes.h"
#include "mcb_open_loop_control_nucleo_f401re_private.h"
#include <math.h>
#include "arm_math.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include <time.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_mcb_open_loop_control_nucle_T mcb_open_loop_control_nucleo__B;

/* Block states (default storage) */
DW_mcb_open_loop_control_nucl_T mcb_open_loop_control_nucleo_DW;

/* Real-time model */
static RT_MODEL_mcb_open_loop_contro_T mcb_open_loop_control_nucleo_M_;
RT_MODEL_mcb_open_loop_contro_T *const mcb_open_loop_control_nucleo_M =
  &mcb_open_loop_control_nucleo_M_;

/* Forward declaration for local functions */
static void mcb_open_lo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mc_T *obj);
static void mcb_open_loop__SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static real_T mcb_open_loop_control_nucle_now(void);
static real_T mcb_open_loop_control_nucle_mod(real_T x);
static real_T mcb_open_loop_control_nucl_rand(void);
static void mcb_open_lo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mc_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S26>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void mcb_open_loop__SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

/* Function for MATLAB Function: '<S49>/MATLAB Function' */
static real_T mcb_open_loop_control_nucle_now(void)
{
  time_t rawtime;
  struct tm expl_temp;
  real_T dDateNum;
  int16_T cDaysMonthWise[12];
  cDaysMonthWise[0] = 0;
  cDaysMonthWise[1] = 31;
  cDaysMonthWise[2] = 59;
  cDaysMonthWise[3] = 90;
  cDaysMonthWise[4] = 120;
  cDaysMonthWise[5] = 151;
  cDaysMonthWise[6] = 181;
  cDaysMonthWise[7] = 212;
  cDaysMonthWise[8] = 243;
  cDaysMonthWise[9] = 273;
  cDaysMonthWise[10] = 304;
  cDaysMonthWise[11] = 334;
  time(&rawtime);
  expl_temp = *localtime(&rawtime);
  dDateNum = (((((real_T)(expl_temp.tm_year + 1900) * 365.0 + ceil((real_T)
    (expl_temp.tm_year + 1900) / 4.0)) - ceil((real_T)(expl_temp.tm_year + 1900)
    / 100.0)) + ceil((real_T)(expl_temp.tm_year + 1900) / 400.0)) + (real_T)
              cDaysMonthWise[expl_temp.tm_mon]) + (real_T)expl_temp.tm_mday;
  if (expl_temp.tm_mon + 1 > 2) {
    int32_T r;
    boolean_T guard1;
    if (expl_temp.tm_year + 1900 == 0) {
      r = 0;
    } else {
      r = (int32_T)fmod(expl_temp.tm_year + 1900, 4.0);
      if ((r != 0) && (r < 0)) {
        r += 4;
      }
    }

    guard1 = false;
    if (r == 0) {
      if (expl_temp.tm_year + 1900 == 0) {
        r = 0;
      } else {
        r = (int32_T)fmod(expl_temp.tm_year + 1900, 100.0);
        if ((r != 0) && (r < 0)) {
          r += 100;
        }
      }

      if (r != 0) {
        dDateNum++;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (expl_temp.tm_year + 1900 == 0) {
        r = 0;
      } else {
        r = (int32_T)fmod(expl_temp.tm_year + 1900, 400.0);
        if ((r != 0) && (r < 0)) {
          r += 400;
        }
      }

      if (r == 0) {
        dDateNum++;
      }
    }
  }

  return (((real_T)expl_temp.tm_hour * 3600.0 + (real_T)expl_temp.tm_min * 60.0)
          + (real_T)expl_temp.tm_sec) / 86400.0 + dDateNum;
}

/* Function for MATLAB Function: '<S49>/MATLAB Function' */
static real_T mcb_open_loop_control_nucle_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 2.147483647E+9);
    if (r == 0.0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 2.147483647E+9;
    }
  }

  return r;
}

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

/* Function for MATLAB Function: '<S49>/MATLAB Function' */
static real_T mcb_open_loop_control_nucl_rand(void)
{
  real_T r;
  int32_T k;
  int32_T kk;
  uint32_T b_u[2];
  switch (mcb_open_loop_control_nucleo_DW.method) {
   case 4U:
    {
      uint32_T mti;
      uint32_T y;
      k = (int32_T)(mcb_open_loop_control_nucleo_DW.state_k / 127773U);
      mti = (mcb_open_loop_control_nucleo_DW.state_k - (uint32_T)k * 127773U) *
        16807U;
      y = 2836U * (uint32_T)k;
      if (mti < y) {
        mcb_open_loop_control_nucleo_DW.state_k = ~(y - mti) & 2147483647U;
      } else {
        mcb_open_loop_control_nucleo_DW.state_k = mti - y;
      }

      r = (real_T)mcb_open_loop_control_nucleo_DW.state_k *
        4.6566128752457969E-10;
    }
    break;

   case 5U:
    {
      uint32_T mti;
      uint32_T y;
      mti = 69069U * mcb_open_loop_control_nucleo_DW.state_e[0] + 1234567U;
      y = mcb_open_loop_control_nucleo_DW.state_e[1] << 13 ^
        mcb_open_loop_control_nucleo_DW.state_e[1];
      y ^= y >> 17;
      y ^= y << 5;
      mcb_open_loop_control_nucleo_DW.state_e[0] = mti;
      mcb_open_loop_control_nucleo_DW.state_e[1] = y;
      r = (real_T)(mti + y) * 2.328306436538696E-10;
    }
    break;

   default:
    {
      uint32_T mti;
      uint32_T y;

      /* ========================= COPYRIGHT NOTICE ============================ */
      /*  This is a uniform (0,1) pseudorandom number generator based on: */
      /*  */
      /*  A C-program for MT19937, with initialization improved 2002/1/26. */
      /*  Coded by Takuji Nishimura and Makoto Matsumoto. */
      /*  */
      /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
      /*  All rights reserved. */
      /*  */
      /*  Redistribution and use in source and binary forms, with or without */
      /*  modification, are permitted provided that the following conditions */
      /*  are met: */
      /*  */
      /*    1. Redistributions of source code must retain the above copyright */
      /*       notice, this list of conditions and the following disclaimer. */
      /*  */
      /*    2. Redistributions in binary form must reproduce the above copyright */
      /*       notice, this list of conditions and the following disclaimer */
      /*       in the documentation and/or other materials provided with the */
      /*       distribution. */
      /*  */
      /*    3. The names of its contributors may not be used to endorse or */
      /*       promote products derived from this software without specific */
      /*       prior written permission. */
      /*  */
      /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
      /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
      /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
      /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT */
      /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, */
      /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
      /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, */
      /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY */
      /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT */
      /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
      /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
      /*  */
      /* =============================   END   ================================= */
      int32_T exitg1;
      do {
        exitg1 = 0;
        for (k = 0; k < 2; k++) {
          mti = mcb_open_loop_control_nucleo_DW.state[624] + 1U;
          if (mcb_open_loop_control_nucleo_DW.state[624] + 1U >= 625U) {
            for (kk = 0; kk < 227; kk++) {
              mti = (mcb_open_loop_control_nucleo_DW.state[kk + 1] & 2147483647U)
                | (mcb_open_loop_control_nucleo_DW.state[kk] & 2147483648U);
              if ((mti & 1U) == 0U) {
                mti >>= 1U;
              } else {
                mti = mti >> 1U ^ 2567483615U;
              }

              mcb_open_loop_control_nucleo_DW.state[kk] =
                mcb_open_loop_control_nucleo_DW.state[kk + 397] ^ mti;
            }

            for (kk = 0; kk < 396; kk++) {
              mti = (mcb_open_loop_control_nucleo_DW.state[kk + 227] &
                     2147483648U) | (mcb_open_loop_control_nucleo_DW.state[kk +
                228] & 2147483647U);
              if ((mti & 1U) == 0U) {
                mti >>= 1U;
              } else {
                mti = mti >> 1U ^ 2567483615U;
              }

              mcb_open_loop_control_nucleo_DW.state[kk + 227] =
                mcb_open_loop_control_nucleo_DW.state[kk] ^ mti;
            }

            mti = (mcb_open_loop_control_nucleo_DW.state[623] & 2147483648U) |
              (mcb_open_loop_control_nucleo_DW.state[0] & 2147483647U);
            if ((mti & 1U) == 0U) {
              mti >>= 1U;
            } else {
              mti = mti >> 1U ^ 2567483615U;
            }

            mcb_open_loop_control_nucleo_DW.state[623] =
              mcb_open_loop_control_nucleo_DW.state[396] ^ mti;
            mti = 1U;
          }

          y = mcb_open_loop_control_nucleo_DW.state[(int32_T)mti - 1];
          mcb_open_loop_control_nucleo_DW.state[624] = mti;
          y ^= y >> 11U;
          y ^= y << 7U & 2636928640U;
          y ^= y << 15U & 4022730752U;
          b_u[k] = y >> 18U ^ y;
        }

        mti = b_u[0] >> 5U;
        y = b_u[1] >> 6U;
        if ((mti == 0U) && (y == 0U)) {
          boolean_T b_isvalid;
          b_isvalid = ((mcb_open_loop_control_nucleo_DW.state[624] >= 1U) &&
                       (mcb_open_loop_control_nucleo_DW.state[624] < 625U));
          if (b_isvalid) {
            boolean_T exitg2;
            b_isvalid = false;
            k = 1;
            exitg2 = false;
            while ((!exitg2) && (k < 625)) {
              if (mcb_open_loop_control_nucleo_DW.state[k - 1] == 0U) {
                k++;
              } else {
                b_isvalid = true;
                exitg2 = true;
              }
            }
          }

          if (!b_isvalid) {
            mti = 5489U;
            mcb_open_loop_control_nucleo_DW.state[0] = 5489U;
            for (k = 0; k < 623; k++) {
              mti = ((mti >> 30U ^ mti) * 1812433253U + (uint32_T)k) + 1U;
              mcb_open_loop_control_nucleo_DW.state[k + 1] = mti;
            }

            mcb_open_loop_control_nucleo_DW.state[624] = 624U;
          }
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      r = ((real_T)mti * 6.7108864E+7 + (real_T)y) * 1.1102230246251565E-16;
    }
    break;
  }

  return r;
}

/* Model step function */
void mcb_open_loop_control_nucleo_f401re_step(void)
{
  time_t b_eTime;
  time_t eTime;
  real_T b_y;
  real_T y;
  int32_T b_r;
  int32_T exitg1;
  int32_T t;
  uint32_T r;
  int16_T rtb_Switch_a;
  uint8_T rtb_TmpSignalConversionAtCANWri[4];
  uint8_T rtb_ByteUnpack;
  uint8_T rtb_ByteUnpack1;
  uint8_T rtb_ByteUnpack2;
  uint8_T rtb_ByteUnpack3;
  boolean_T rtb_DataTypeConversion1_d;

  /* MATLABSystem: '<S1>/CAN Read' */
  MW_CAN_ReceiveMessage(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE, 0,
                        &mcb_open_loop_control_nucleo__B.CANRead.Data[0],
                        &mcb_open_loop_control_nucleo__B.CANRead.ID,
                        &mcb_open_loop_control_nucleo__B.CANRead.Extended,
                        &mcb_open_loop_control_nucleo__B.CANRead.Remote,
                        &mcb_open_loop_control_nucleo__B.CANRead.Length, 1U, &r);
  mcb_open_loop_control_nucleo__B.CANRead.Error = 0U;
  mcb_open_loop_control_nucleo__B.CANRead.Timestamp = 0.0;

  /* S-Function (scanunpack): '<S1>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack' */
    if ((4 == mcb_open_loop_control_nucleo__B.CANRead.Length) &&
        (mcb_open_loop_control_nucleo__B.CANRead.ID != INVALID_CAN_ID) ) {
      if ((544 == mcb_open_loop_control_nucleo__B.CANRead.ID) && (0U ==
           mcb_open_loop_control_nucleo__B.CANRead.Extended) ) {
        (void) memcpy(&mcb_open_loop_control_nucleo__B.CANUnpack[0],
                      mcb_open_loop_control_nucleo__B.CANRead.Data,
                      4 * sizeof(uint8_T));
      }
    }
  }

  /* SignalConversion generated from: '<S2>/CAN Write' incorporates:
   *  ArithShift: '<S6>/Shift Arithmetic'
   *  Constant: '<Root>/Number ID ECU1'
   *  DataTypeConversion: '<S6>/Data Type Conversion3'
   */
  rtb_TmpSignalConversionAtCANWri[0] = (uint8_T)
    (mcb_open_loop_control_nucleo__P.NumberIDECU1_Value >> 8);

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack1' */

  /* Unpack: <S1>/Byte Unpack1 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[1];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack1, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack3' */

  /* Unpack: <S1>/Byte Unpack3 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[2];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack3, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack' */

  /* Unpack: <S1>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[0];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack2' */

  /* Unpack: <S1>/Byte Unpack2 */
  {
    uint32_T MW_inputPortOffset = 0U;
    uint16_T MW_outputPortWidth = 0U;

    /* Packed input data type - uint8_T */
    void* unpackData = &mcb_open_loop_control_nucleo__B.CANUnpack[3];

    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = sizeof(uint8_T);
      memcpy((void*)&rtb_ByteUnpack2, (void *)&(((uint8_T *)unpackData)
              [MW_inputPortOffset]), MW_outputPortWidth);
    }
  }

  /* MATLAB Function: '<S49>/MATLAB Function' */
  if (!mcb_open_loop_control_nucleo_DW.r_not_empty) {
    y = mcb_open_loop_control_nucle_now() * 8.64E+6;
    y = mcb_open_loop_control_nucle_mod(floor(y));
    eTime = time(NULL);
    do {
      exitg1 = 0;
      b_eTime = time(NULL);
      if ((int32_T)b_eTime <= (int32_T)eTime + 1) {
        b_y = mcb_open_loop_control_nucle_now() * 8.64E+6;
        b_y = floor(b_y);
        if (y != mcb_open_loop_control_nucle_mod(b_y)) {
          exitg1 = 1;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    y = rt_roundd_snf(y);
    if (y < 4.294967296E+9) {
      if (y >= 0.0) {
        r = (uint32_T)y;
      } else {
        r = 0U;
      }
    } else {
      r = MAX_uint32_T;
    }

    switch (mcb_open_loop_control_nucleo_DW.method) {
     case 7U:
      mcb_open_loop_control_nucleo_DW.state[0] = r;
      for (b_r = 0; b_r < 623; b_r++) {
        r = ((r >> 30U ^ r) * 1812433253U + (uint32_T)b_r) + 1U;
        mcb_open_loop_control_nucleo_DW.state[b_r + 1] = r;
      }

      mcb_open_loop_control_nucleo_DW.state[624] = 624U;
      break;

     case 5U:
      mcb_open_loop_control_nucleo_DW.state_e[0] = 362436069U;
      mcb_open_loop_control_nucleo_DW.state_e[1] = r;
      if (mcb_open_loop_control_nucleo_DW.state_e[1] == 0U) {
        mcb_open_loop_control_nucleo_DW.state_e[1] = 521288629U;
      }
      break;

     case 4U:
      b_r = (int32_T)(r >> 16U);
      t = (int32_T)(r & 32768U);
      mcb_open_loop_control_nucleo_DW.state_k = (uint32_T)b_r << 16U;
      mcb_open_loop_control_nucleo_DW.state_k = r -
        mcb_open_loop_control_nucleo_DW.state_k;
      mcb_open_loop_control_nucleo_DW.state_k -= (uint32_T)t;
      mcb_open_loop_control_nucleo_DW.state_k <<= 16U;
      mcb_open_loop_control_nucleo_DW.state_k += (uint32_T)t;
      mcb_open_loop_control_nucleo_DW.state_k += (uint32_T)b_r;
      if (mcb_open_loop_control_nucleo_DW.state_k < 1U) {
        mcb_open_loop_control_nucleo_DW.state_k = 1144108930U;
      } else if (mcb_open_loop_control_nucleo_DW.state_k > 2147483646U) {
        mcb_open_loop_control_nucleo_DW.state_k = 2147483646U;
      }
      break;
    }

    y = mcb_open_loop_control_nucl_rand();
    mcb_open_loop_control_nucleo_DW.r = floor(y * 201.0);
    mcb_open_loop_control_nucleo_DW.r_not_empty = true;
  }

  /* SignalConversion generated from: '<S2>/CAN Write' incorporates:
   *  Constant: '<Root>/Number Control Safety'
   *  Constant: '<Root>/Number ID ECU1'
   *  DataTypeConversion: '<S49>/Data Type Conversion'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  MATLAB Function: '<S49>/MATLAB Function'
   *  S-Function (sfix_bitop): '<S6>/Bitwise OR'
   *  Sum: '<S49>/Sum'
   */
  rtb_TmpSignalConversionAtCANWri[1] = (uint8_T)((uint32_T)
    mcb_open_loop_control_nucleo__P.NumberIDECU1_Value &
    mcb_open_loop_control_nucleo__P.BitwiseOR_BitMask);
  rtb_TmpSignalConversionAtCANWri[2] = (uint8_T)
    mcb_open_loop_control_nucleo_DW.r;
  rtb_TmpSignalConversionAtCANWri[3] = (uint8_T)((uint8_T)
    mcb_open_loop_control_nucleo_DW.r +
    mcb_open_loop_control_nucleo__P.NumberControlSafety_Value);

  /* MATLABSystem: '<S2>/CAN Write' */
  MW_CAN_TransmitMessage(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE,
    &rtb_TmpSignalConversionAtCANWri[0], 545U, 0, 0, 4, 100U, &r);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S8>/Extract Desired Bits'
   */
  rtb_DataTypeConversion1_d = ((rtb_ByteUnpack & 1U) != 0U);

  /* RateTransition generated from: '<S1>/Data Type Conversion1' */
  mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp =
    rtb_DataTypeConversion1_d;

  /* Switch: '<S3>/Switch' incorporates:
   *  BitConcat: '<S7>/BitConcat2'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Extract Desired Bits'
   *  Gain: '<S3>/Gain'
   */
  if ((rtb_ByteUnpack2 & 1U) != 0U) {
    rtb_Switch_a = (int16_T)(rtb_ByteUnpack1 << 8 | rtb_ByteUnpack3);
  } else {
    rtb_Switch_a = (int16_T)((uint16_T)(rtb_ByteUnpack1 << 8 | rtb_ByteUnpack3) *
      mcb_open_loop_control_nucleo__P.Gain_Gain_m);
  }

  /* End of Switch: '<S3>/Switch' */

  /* RateTransition generated from: '<Root>/Open Loop Control' */
  mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_ = rtb_Switch_a;
}

/* Model initialize function */
void mcb_open_loop_control_nucleo_f401re_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(mcb_open_loop_control_nucleo_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &mcb_open_loop_control_nucleo__B), 0,
                sizeof(B_mcb_open_loop_control_nucle_T));

  /* states (dwork) */
  (void) memset((void *)&mcb_open_loop_control_nucleo_DW, 0,
                sizeof(DW_mcb_open_loop_control_nucl_T));

  {
    static const uint32_T tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack' */

    /*-----------S-Function Block: <S1>/CAN Unpack -----------------*/

    /* InitializeConditions for RateTransition generated from: '<S1>/Data Type Conversion1' */
    mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp =
      mcb_open_loop_control_nucleo__P.TmpRTBAtDataTypeConversion1Outp;

    /* InitializeConditions for RateTransition generated from: '<Root>/Open Loop Control' */
    mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_ =
      mcb_open_loop_control_nucleo__P.TmpRTBAtOpenLoopControlInport2_;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Open Loop Control'
     */

    /* System initialize for function-call system: '<Root>/Open Loop Control' */

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Ramp Generator' */
    mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
      mcb_open_loop_control_nucleo__P.RampGenerator_IC;

    /* SystemInitialize for Enabled SubSystem: '<S31>/Accumulate' */
    /* InitializeConditions for Delay: '<S47>/Delay' */
    mcb_open_loop_control_nucleo_DW.Delay_DSTATE =
      mcb_open_loop_control_nucleo__P.Delay_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S47>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S48>/Input' incorporates:
     *  Outport: '<S48>/Out1'
     */
    mcb_open_loop_control_nucleo__B.Input =
      mcb_open_loop_control_nucleo__P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S47>/Subsystem' */

    /* SystemInitialize for Outport: '<S47>/theta_e' incorporates:
     *  Sum: '<S47>/Add1'
     *  UnitDelay: '<S31>/Unit Delay'
     */
    mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE =
      mcb_open_loop_control_nucleo__P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S31>/Accumulate' */

    /* Start for MATLABSystem: '<S26>/PWM Output' */
    mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete = false;
    mcb_open_loop_control_nucleo_DW.obj_f.isInitialized = 1;
    mcb_open_lo_PWMOutput_setupImpl(&mcb_open_loop_control_nucleo_DW.obj_f);
    mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
    mcb_open_loop_control_nucleo_DW.obj_k.isInitialized = 0;
    mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted = false;
    mcb_open_loop__SystemCore_setup(&mcb_open_loop_control_nucleo_DW.obj_k);

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

    /* SystemInitialize for MATLAB Function: '<S49>/MATLAB Function' */
    memcpy(&mcb_open_loop_control_nucleo_DW.state[0], &tmp[0], 625U * sizeof
           (uint32_T));
    mcb_open_loop_control_nucleo_DW.r_not_empty = false;
    mcb_open_loop_control_nucleo_DW.method = 7U;
    mcb_open_loop_control_nucleo_DW.state_e[0] = 362436069U;
    mcb_open_loop_control_nucleo_DW.state_e[1] = 521288629U;
    mcb_open_loop_control_nucleo_DW.state_k = 1144108930U;

    /* Start for MATLABSystem: '<S1>/CAN Read' */
    mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj.isInitialized = 1;
    mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE = MW_CAN_Initialize(0);
    MW_configureCANFilter(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE, 0,
                          0, 0, 0, 0, 0, 0, 0, 1, 1);
    mcb_open_loop_control_nucleo_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/CAN Write' */
    mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted = false;
    mcb_open_loop_control_nucleo_DW.obj_h.isInitialized = 1;
    mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE = MW_CAN_Initialize(0);
    MW_configureCANFilter(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE, 0,
                          0, 0, 0, 0, 0, 0, 0, 1, 1);
    mcb_open_loop_control_nucleo_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void mcb_open_loop_control_nucleo_f401re_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/CAN Read' */
  if (!mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj.isSetupComplete) {
      MW_CAN_Close(mcb_open_loop_control_nucleo_DW.obj.MW_CAN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CAN Read' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Open Loop Control'
   */
  /* Termination for function-call system: '<Root>/Open Loop Control' */

  /* Terminate for MATLABSystem: '<S26>/PWM Output' */
  if (!mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_f.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_f.isSetupComplete) {
      disableCounter(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle);
      disableTimerInterrupts(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
        0);
      disableTimerChannel1(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel2(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel3(mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S26>/PWM Output' */

  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_k.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_k.isSetupComplete) {
      ADC_Handle_Deinit(mcb_open_loop_control_nucleo_DW.obj_k.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S2>/CAN Write' */
  if (!mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted) {
    mcb_open_loop_control_nucleo_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((mcb_open_loop_control_nucleo_DW.obj_h.isInitialized == 1) &&
        mcb_open_loop_control_nucleo_DW.obj_h.isSetupComplete) {
      MW_CAN_Close(mcb_open_loop_control_nucleo_DW.obj_h.MW_CAN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/CAN Write' */
}

void mcb_open_loop_control_nucleo_f401re_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S11>/Hardware Interrupt' */
void ADC_IRQHandler(void)
{
  /* Event: ADC1 Inj EoCS */
  /* Check event ADC1 Inj EoCS occurred */
  if (0 != (
#if defined(MW_ADC1_ENABLED) && (defined(MW_ADC1_INJ_IRQ_ENABLED) && (MW_ADC1_INJ_IRQ_ENABLED==1))
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 != ADC_IsActiveFlagJEOS
        (&(MW_ADC1_VAR)))
#else
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 !=
        LL_ADC_IsActiveFlag_JEOS(ADC1))
#endif
            )) {
    /* Clear occurred ADC1 Inj EoCS event */
    LL_ADC_ClearFlag_JEOS(ADC1);
    if (1 == runModel) {
      {
        /* RateTransition generated from: '<S1>/Data Type Conversion1' */
        mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp =
          mcb_open_loop_control_nucleo_DW.TmpRTBAtDataTypeConversion1Outp;

        /* RateTransition generated from: '<Root>/Open Loop Control' */
        mcb_open_loop_control_nucleo__B.TmpRTBAtOpenLoopControlInport2 =
          mcb_open_loop_control_nucleo_DW.TmpRTBAtOpenLoopControlInport2_;

        /* S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Open Loop Control' */
        {
          GPIO_TypeDef * portNameLoc;
          int32_T pinWriteLoc;
          int32_T tmp_e;
          int32_T tmp_p;
          real32_T rtb_Product1;
          real32_T rtb_Product1_d;
          real32_T rtb_Product_h;
          real32_T rtb_Switch4_idx_2;
          real32_T rtb_algDD_o2;
          real32_T rtb_sum_beta;
          real32_T tmp_m;
          uint16_T tmp[2];
          boolean_T tmp_i;

          /* MATLABSystem: '<S23>/Digital Port Write' */
          portNameLoc = GPIOC;

          /* Switch: '<S19>/Switch' incorporates:
           *  Constant: '<S19>/Constant1'
           *  Logic: '<S19>/NOT'
           */
          if (mcb_open_loop_control_nucleo__P.Constant1_Value_a >
              mcb_open_loop_control_nucleo__P.Switch_Threshold_g) {
            tmp_i =
              mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp;
          } else {
            tmp_i =
              !mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp;
          }

          /* MATLABSystem: '<S23>/Digital Port Write' incorporates:
           *  Switch: '<S19>/Switch'
           */
          if (tmp_i) {
            pinWriteLoc = 1024;
            tmp_p = 2048;
            tmp_e = 4096;
          } else {
            pinWriteLoc = 0;
            tmp_p = 0;
            tmp_e = 0;
          }

          pinWriteLoc = (int32_T)((uint32_T)pinWriteLoc | (uint32_T)tmp_p |
            (uint32_T)tmp_e);
          LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)pinWriteLoc);
          LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)pinWriteLoc & 7168U);

          /* DiscreteIntegrator: '<S29>/Ramp Generator' incorporates:
           *  Logic: '<S29>/NOT'
           */
          if (!mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp)
          {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_IC;
          }

          /* Product: '<S27>/Product' incorporates:
           *  DiscreteIntegrator: '<S29>/Ramp Generator'
           *  Gain: '<S27>/rpm2freq'
           */
          rtb_Product_h = (real32_T)
            mcb_open_loop_control_nucleo__P.rpm2freq_Gain * 3.81469727E-6F *
            (real32_T)
            mcb_open_loop_control_nucleo__B.TmpRTBAtOpenLoopControlInport2 *
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE;

          /* Gain: '<S28>/Correction_Factor_sinePWM' incorporates:
           *  Abs: '<S28>/Abs'
           *  Gain: '<S28>/V-by-f'
           */
          rtb_Product1 = mcb_open_loop_control_nucleo__P.Vbyf_Gain * fabsf
            (rtb_Product_h) *
            mcb_open_loop_control_nucleo__P.Correction_Factor_sinePWM_Gain;

          /* Switch: '<S32>/Switch' incorporates:
           *  Constant: '<S5>/Boost Voltage'
           *  RelationalOperator: '<S32>/Relational Operator'
           */
          if (rtb_Product1 > mcb_open_loop_control_nucleo__P.BoostVoltage_Value)
          {
            rtb_Product1_d = rtb_Product1;
          } else {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.BoostVoltage_Value;
          }

          /* End of Switch: '<S32>/Switch' */

          /* Outputs for Enabled SubSystem: '<S31>/Accumulate' incorporates:
           *  EnablePort: '<S47>/Enable'
           */
          /* Logic: '<S31>/NOT' incorporates:
           *  Constant: '<S31>/Constant_Reset'
           *  Delay: '<S47>/Delay'
           */
          if (!mcb_open_loop_control_nucleo__P.Constant_Reset_Value) {
            /* Outputs for Enabled SubSystem: '<S47>/Subsystem' incorporates:
             *  EnablePort: '<S48>/Enable'
             */
            if (mcb_open_loop_control_nucleo_DW.Delay_DSTATE) {
              /* SignalConversion generated from: '<S48>/Input' incorporates:
               *  Gain: '<S28>/position_increment'
               *  Gain: '<S31>/scaleIn'
               */
              mcb_open_loop_control_nucleo__B.Input =
                mcb_open_loop_control_nucleo__P.position_increment_Gain *
                rtb_Product_h * mcb_open_loop_control_nucleo__P.scaleIn_Gain;
            }

            /* End of Outputs for SubSystem: '<S47>/Subsystem' */

            /* Sum: '<S47>/Add' incorporates:
             *  Delay: '<S47>/Delay'
             *  UnitDelay: '<S31>/Unit Delay'
             */
            rtb_Product_h = mcb_open_loop_control_nucleo__B.Input +
              mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE;

            /* Sum: '<S47>/Add1' incorporates:
             *  DataTypeConversion: '<S47>/Data Type Conversion'
             *  DataTypeConversion: '<S47>/Data Type Conversion1'
             *  UnitDelay: '<S31>/Unit Delay'
             */
            mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE = rtb_Product_h -
              (real32_T)(int16_T)floorf(rtb_Product_h);

            /* Update for Delay: '<S47>/Delay' incorporates:
             *  Constant: '<S47>/Constant'
             */
            mcb_open_loop_control_nucleo_DW.Delay_DSTATE =
              mcb_open_loop_control_nucleo__P.Constant_Value_a;
          }

          /* End of Logic: '<S31>/NOT' */
          /* End of Outputs for SubSystem: '<S31>/Accumulate' */

          /* Gain: '<S41>/convert_pu' incorporates:
           *  Gain: '<S31>/scaleOut'
           *  UnitDelay: '<S31>/Unit Delay'
           */
          rtb_Product_h = mcb_open_loop_control_nucleo__P.scaleOut_Gain *
            mcb_open_loop_control_nucleo_DW.UnitDelay_DSTATE *
            mcb_open_loop_control_nucleo__P.convert_pu_Gain;

          /* If: '<S41>/If' incorporates:
           *  Constant: '<S43>/Constant'
           *  DataTypeConversion: '<S44>/Convert_back'
           *  DataTypeConversion: '<S44>/Convert_uint16'
           *  DataTypeConversion: '<S45>/Convert_back'
           *  DataTypeConversion: '<S45>/Convert_uint16'
           *  Gain: '<S39>/indexing'
           *  RelationalOperator: '<S43>/Compare'
           *  Sum: '<S44>/Sum'
           *  Sum: '<S45>/Sum'
           */
          if (rtb_Product_h < mcb_open_loop_control_nucleo__P.Constant_Value_h)
          {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            rtb_Switch4_idx_2 = rtb_Product_h - (real32_T)(int16_T)floorf
              (rtb_Product_h);

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            rtb_Switch4_idx_2 = rtb_Product_h - (real32_T)(int16_T)rtb_Product_h;

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */
          }

          rtb_Product1 = mcb_open_loop_control_nucleo__P.indexing_Gain *
            rtb_Switch4_idx_2;

          /* End of If: '<S41>/If' */

          /* Sum: '<S39>/Sum2' incorporates:
           *  DataTypeConversion: '<S39>/Data Type Conversion1'
           *  DataTypeConversion: '<S39>/Get_Integer'
           */
          rtb_sum_beta = rtb_Product1 - (real32_T)(uint16_T)rtb_Product1;

          /* Saturate: '<S32>/Saturation' */
          if (rtb_Product1_d >
              mcb_open_loop_control_nucleo__P.Saturation_UpperSat) {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.Saturation_UpperSat;
          } else if (rtb_Product1_d <
                     mcb_open_loop_control_nucleo__P.Saturation_LowerSat) {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.Saturation_LowerSat;
          }

          /* Selector: '<S39>/Lookup' incorporates:
           *  Constant: '<S39>/offset'
           *  Constant: '<S39>/sine_table_values'
           *  DataTypeConversion: '<S39>/Get_Integer'
           *  Sum: '<S39>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum5'
           */
          rtb_Switch4_idx_2 =
            mcb_open_loop_control_nucleo__P.sine_table_values_Value[(int32_T)
            ((uint32_T)mcb_open_loop_control_nucleo__P.offset_Value[1] +
             (uint16_T)rtb_Product1)];
          tmp_m = mcb_open_loop_control_nucleo__P.sine_table_values_Value
            [(int32_T)((uint32_T)mcb_open_loop_control_nucleo__P.offset_Value[3]
                       + (uint16_T)rtb_Product1)];

          /* Outputs for Atomic SubSystem: '<S34>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S37>/a16' incorporates:
           *  Constant: '<S30>/Constant'
           *  Constant: '<S39>/offset'
           *  Constant: '<S39>/sine_table_values'
           *  DataTypeConversion: '<S39>/Get_Integer'
           *  Product: '<S40>/Product'
           *  Product: '<S40>/Product1'
           *  Saturate: '<S32>/Saturation'
           *  Selector: '<S39>/Lookup'
           *  Sum: '<S39>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum4'
           *  Sum: '<S40>/Sum5'
           *  Sum: '<S40>/Sum6'
           *  UnaryMinus: '<S30>/Unary Minus'
           */
          arm_inv_park_f32(mcb_open_loop_control_nucleo__P.Constant_Value_g,
                           -rtb_Product1_d, &rtb_Product_h, &rtb_algDD_o2,
                           (mcb_open_loop_control_nucleo__P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            mcb_open_loop_control_nucleo__P.offset_Value[0] + (uint16_T)
            rtb_Product1)] - rtb_Switch4_idx_2) * rtb_sum_beta +
                           rtb_Switch4_idx_2,
                           (mcb_open_loop_control_nucleo__P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            mcb_open_loop_control_nucleo__P.offset_Value[2] + (uint16_T)
            rtb_Product1)] - tmp_m) * rtb_sum_beta + tmp_m);

          /* End of Outputs for SubSystem: '<S34>/Two inputs CRL' */

          /* Switch: '<S20>/Switch4' incorporates:
           *  Constant: '<S15>/Constant'
           *  Constant: '<S15>/Constant1'
           *  Constant: '<S20>/stop'
           *  Gain: '<S15>/Gain'
           *  Gain: '<S36>/Ka'
           *  Gain: '<S36>/Kb'
           *  Gain: '<S36>/Kc'
           *  Product: '<S15>/Product'
           *  Sum: '<S15>/Sum'
           *  Sum: '<S36>/add_b'
           *  Sum: '<S36>/add_c'
           */
          if (mcb_open_loop_control_nucleo__B.TmpRTBAtDataTypeConversion1Outp) {
            /* Gain: '<S36>/sqrt3_by_two' */
            rtb_Switch4_idx_2 =
              mcb_open_loop_control_nucleo__P.sqrt3_by_two_Gain * rtb_algDD_o2;

            /* Gain: '<S36>/one_by_two' */
            rtb_Product1 = mcb_open_loop_control_nucleo__P.one_by_two_Gain *
              rtb_Product_h;
            rtb_Product1_d = (mcb_open_loop_control_nucleo__P.Ka_Gain *
                              rtb_Product_h +
                              mcb_open_loop_control_nucleo__P.Constant_Value) *
              mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
            rtb_Product_h = ((rtb_Switch4_idx_2 - rtb_Product1) *
                             mcb_open_loop_control_nucleo__P.Kb_Gain +
                             mcb_open_loop_control_nucleo__P.Constant_Value) *
              mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
            rtb_Switch4_idx_2 = (((0.0F - rtb_Product1) - rtb_Switch4_idx_2) *
                                 mcb_open_loop_control_nucleo__P.Kc_Gain +
                                 mcb_open_loop_control_nucleo__P.Constant_Value)
              * mcb_open_loop_control_nucleo__P.Gain_Gain *
              mcb_open_loop_control_nucleo__P.Constant1_Value;
          } else {
            rtb_Product1_d = mcb_open_loop_control_nucleo__P.stop_Value;
            rtb_Product_h = mcb_open_loop_control_nucleo__P.stop_Value;
            rtb_Switch4_idx_2 = mcb_open_loop_control_nucleo__P.stop_Value;
          }

          /* End of Switch: '<S20>/Switch4' */

          /* MATLABSystem: '<S26>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle, rtb_Product1_d);
          setDutyCycleInPercentageChannel2
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle, rtb_Product_h);
          setDutyCycleInPercentageChannel3
            (mcb_open_loop_control_nucleo_DW.obj_f.TimerHandle,
             rtb_Switch4_idx_2);

          /* MATLABSystem: '<S18>/Analog to Digital Converter' */
          injectedReadADCIntr(mcb_open_loop_control_nucleo_DW.obj_k.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* Update for DiscreteIntegrator: '<S29>/Ramp Generator' incorporates:
           *  Constant: '<S27>/Ramp_Time (sec)'
           *  Constant: '<S29>/One'
           *  Gain: '<S29>/Sample_Time'
           *  Product: '<S29>/Divide'
           */
          mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE +=
            mcb_open_loop_control_nucleo__P.One_Value /
            mcb_open_loop_control_nucleo__P.Ramp_Timesec_Value *
            mcb_open_loop_control_nucleo__P.Ts *
            mcb_open_loop_control_nucleo__P.RampGenerator_gainval;
          if (mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE >
              mcb_open_loop_control_nucleo__P.RampGenerator_UpperSat) {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_UpperSat;
          } else if (mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE <
                     mcb_open_loop_control_nucleo__P.RampGenerator_LowerSat) {
            mcb_open_loop_control_nucleo_DW.RampGenerator_DSTATE =
              mcb_open_loop_control_nucleo__P.RampGenerator_LowerSat;
          }

          /* End of Update for DiscreteIntegrator: '<S29>/Ramp Generator' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S11>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void mcb_open_loop_control_nucleo_f401re_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
