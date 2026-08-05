/*
 * tle5012b.c - TLE5012B register access via AUTOSAR Spi MCAL
 */
#include "tle5012b.h"
#include "Tle5012bd_Spi.h"
#include "McalLib.h"

TLE5012_SFR tle5012_sfr;

void tle5012b_delay_us(uint32 delayUs)
{
  uint32 resolution = Mcal_DelayTickResolution();

  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 i;

    for (i = 0U; i < (delayUs * 200U); i++)
    {
      /* fallback */
    }
  }
  else
  {
    uint32 targetTicks;
    uint32 startTick;

    /* Resolution is ns/tick ??ticks = (?s * 1000) / ns */
    targetTicks = (delayUs * 1000UL) / resolution;
    if (targetTicks == 0U)
    {
      targetTicks = 1U;
    }
    startTick = Mcal_DelayGetTick();
    while ((Mcal_DelayGetTick() - startTick) < targetTicks)
    {
      /* wait */
    }
  }
}

static uint32 tle5012b_build_tx(uint16 address, uint16 data, boolean isWrite)
{
  uint32 pTx;

  if (isWrite == TRUE)
  {
    pTx = (uint32)address << 4;
    if ((address >= 0x5U) && (address <= 0x11U))
    {
      pTx = 0x5000U | ((uint32)address << 4);
    }
    pTx = (pTx << 16) | (uint32)data;
  }
  else
  {
    pTx = 0x8000U | ((uint32)address << 4);
    if ((address >= 0x5U) && (address <= 0x11U))
    {
      pTx = 0xD000U | ((uint32)address << 4);
    }
    pTx = (pTx << 16) | 0xFFFFU;
  }

  return pTx;
}

static uint16 tle5012b_spi_transfer(uint32 txWord)
{
  uint32 rxWord = 0U;

  if (Tle5012bd_SpiExchangeU32(txWord, &rxWord) != E_OK)
  {
    return 0U;
  }

  return (uint16)(rxWord & 0xFFFFU);
}

void tle5012b_write_fast(uint16 address, uint16 data)
{
  (void)tle5012b_spi_transfer(tle5012b_build_tx(address, data, TRUE));
}

uint16 tle5012b_read_fast(uint8 address)
{
  return tle5012b_spi_transfer(tle5012b_build_tx(address, 0U, FALSE));
}


Std_ReturnType tle5012b_process_angle_raw(Tle5012 *tle5012, uint16 avalRaw)
{
  uint16 angle;
  float32 angleOldPi;
  float32 error;

  if (tle5012 == NULL_PTR) { return E_NOT_OK; }
  tle5012_sfr.AVAL_Type.U = avalRaw;

  /* RD_AV=bit15, ANG_VAL=bits14:0. Never use :15 bitfield — TASKING treats it
   * as signed, so ANG_VAL>=16384 becomes negative / uint16 0xCxxx, Angle locks
   * into 4096..8191 and the old delta>2048 filter then rejects half the circle. */
  if (avalRaw == 0xFFFFU)
  {
    /* All-ones frame: real communication failure. */
    tle5012->SafetyBit++;
    return E_NOT_OK;
  }

  if ((avalRaw & 0x8000U) == 0U)
  {
    /* RD_AV=0: no new angle since the last read. Normal when reading faster
       than the sensor update rate; keep the current angle. */
    return E_OK;
  }

  angle = (uint16)(avalRaw & 0x7FFFU); /* 0..32767 full mechanical circle */
  tle5012->Original_Angle = (float32)angle;
  /* 15-bit mechanical -> 13-bit electrical angle index: v % 8192 (IPB convention). */
  angle = (uint16)(angle % 8192U);
  tle5012->Angle = (float32)angle;
  angleOldPi = tle5012->anglePi;
  tle5012->anglePi = tle5012->Angle * 7.6699039394287e-4F; /* 2*pi/8192 */
  error = tle5012->anglePi - angleOldPi;
  if (error > M_PI) { error -= M_TWOPI; }
  else if (error < -M_PI) { error += M_TWOPI; }

  if (tle5012->DisTimer > 0.0F)
  {
    tle5012->AngleSpeed = error / tle5012->DisTimer;
    tle5012->AngleSpeedFilter = (tle5012->AngleSpeedFilter * 0.9F) + (tle5012->AngleSpeed * 0.1F);
    /* anglePi is now the electrical angle: divide by pole pairs for RPM. */
    tle5012->RPM = tle5012->AngleSpeedFilter * 9.5493F /
                   (float32)((tle5012->polePairs != 0U) ? tle5012->polePairs : 1U);
  }
  return E_OK;
}


boolean tle5012b_ChangeAngleDirection(boolean Dir)
{
  tle5012_sfr.MOD_2_Type.U = tle5012b_read_fast(MOD_2) & 0x7FFCU;

  if ((tle5012_sfr.MOD_2_Type.B.ANG_DIR == counterclockwise) && (Dir == clockwise))
  {
    tle5012b_write_fast(MOD_2, 0x0808U);
    tle5012b_delay_us(150U);
    tle5012b_write_fast(MOD_2, 0x0809U);
  }
  else if ((tle5012_sfr.MOD_2_Type.B.ANG_DIR == clockwise) && (Dir == counterclockwise))
  {
    tle5012b_write_fast(MOD_2, 0x0800U);
    tle5012b_delay_us(150U);
    tle5012b_write_fast(MOD_2, 0x0801U);
  }

  tle5012b_delay_us(150U);
  tle5012_sfr.STAT_Type.U = tle5012b_read_fast(STAT);
  tle5012_sfr.MOD_2_Type.U = tle5012b_read_fast(MOD_2);
  (void)tle5012b_spi_transfer(0x8020FFFFU);
  tle5012b_delay_us(2U);

  return (boolean)tle5012_sfr.MOD_2_Type.B.ANG_DIR;
}

void tle5012b_ChangeAngleBasic(Tle5012 *tle5012, uint16 angleBasic)
{
  sint32 mod_2_t;
  sint32 mod_3_t;
  sint32 angle;

  if (tle5012 == NULL_PTR)
  {
    return;
  }

  mod_2_t = (sint32)tle5012b_read_fast(MOD_2);
  tle5012b_delay_us(2U);
  mod_2_t &= 0x7FFC;
  tle5012b_write_fast(MOD_2, (uint16)mod_2_t);
  tle5012b_delay_us(2U);

  angle = (sint32)((angleBasic >> 3) & 0xFFFU);
  mod_3_t = (sint32)tle5012b_read_fast(MOD_3);
  tle5012b_delay_us(2U);

  {
    const uint16 lowbit_4 = (uint16)(mod_3_t & 0xFU);
    mod_3_t = (mod_3_t >> 4) & 0xFFF;

    if (tle5012_sfr.MOD_2_Type.B.ANG_DIR == 0U)
    {
      mod_3_t = mod_3_t - angle;
    }
    else
    {
      mod_3_t = mod_3_t + angle;
    }

    mod_3_t = (mod_3_t << 4) | (sint32)lowbit_4;
    tle5012->ANG_BASE = (uint16)mod_3_t;
    tle5012b_write_fast(MOD_3, (uint16)mod_3_t);
  }

  tle5012b_delay_us(2U);
  mod_2_t |= 0x1;
  tle5012b_write_fast(MOD_2, (uint16)mod_2_t);
  tle5012b_delay_us(2U);

  tle5012_sfr.MOD_2_Type.U = tle5012b_read_fast(MOD_2);
  tle5012b_delay_us(2U);
  tle5012_sfr.MOD_3_Type.U = tle5012b_read_fast(MOD_3);
  tle5012b_delay_us(2U);

  (void)tle5012b_spi_transfer(0x8020FFFFU);
  tle5012b_delay_us(2U);
}

void tle5012b_read_all(void)
{
  tle5012_sfr.STAT_Type.U = tle5012b_read_fast(STAT);
  tle5012_sfr.ACSTAT_Type.U = tle5012b_read_fast(ACSTAT);
  tle5012_sfr.AVAL_Type.U = tle5012b_read_fast(AVAL);
  tle5012_sfr.ASPD_Type.U = tle5012b_read_fast(ASPD);
  tle5012_sfr.AREV_Type.U = tle5012b_read_fast(AREV);
  tle5012_sfr.FSYNC_Type.U = tle5012b_read_fast(FSYNC);
  tle5012_sfr.MOD_1_Type.U = tle5012b_read_fast(MOD_1);
  tle5012_sfr.SIL_Type.U = tle5012b_read_fast(SIL);
  tle5012_sfr.MOD_2_Type.U = tle5012b_read_fast(MOD_2);
  tle5012_sfr.MOD_3_Type.U = tle5012b_read_fast(MOD_3);
  tle5012_sfr.OFFX_Type.U = tle5012b_read_fast(OFFX);
  tle5012_sfr.OFFY_Type.U = tle5012b_read_fast(OFFY);
  tle5012_sfr.SYNCH_Type.U = tle5012b_read_fast(SYNCH);
  tle5012_sfr.IFAB_Type.U = tle5012b_read_fast(IFAB);
  tle5012_sfr.MOD_4_Type.U = tle5012b_read_fast(MOD_4);
  tle5012_sfr.TCO_Y_Type.U = tle5012b_read_fast(TCO_Y);
  tle5012_sfr.ADC_X_Type.U = tle5012b_read_fast(ADC_X);
  tle5012_sfr.ADC_Y_Type.U = tle5012b_read_fast(ADC_Y);
  tle5012_sfr.D_MAG_Type.U = tle5012b_read_fast(D_MAG);
  tle5012_sfr.T_RAW_Type.U = tle5012b_read_fast(T_RAW);
  tle5012_sfr.IIF_CNT_Type.U = tle5012b_read_fast(IIF_CNT);
  tle5012_sfr.T25O_Type.U = tle5012b_read_fast(T25O);
}

