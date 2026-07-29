/**********************************************************************************************************************
 * TLE5012BD QSPI2 direct SFR transfer (bypasses Spi_SetupEB / Spi_SyncTransmit)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"
#include "IfxQspi_reg.h"
#include "IfxQspi_bf.h"
#include "IfxQspi_regdef.h"

uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;

/*
 * Matches Appl GenData SpiJob_5012BD + SpiChannel_5012BD1:
 *  - QSPI2, SLSO2, HW CS, frame-based LAST=1
 *  - 8 MHz (ECON Q/A/B/C/CPH), MSB-first, 32-bit
 *  - Idle/Lead/Trail delays from Spi_IdleLeadTrailParam(1,5,1,5,1,5,*)
 */
#define TLE5012BD_QSPI2_ECON_VAL              (0x00001404UL)
#define TLE5012BD_QSPI2_ECON_INDEX            (2U)
#define TLE5012BD_QSPI2_SSOC_VAL              (0x00040000UL)
/* Same as Spi_lHwSetJobConfig for SpiJob_5012BD (LEVEL_DELIVERED=0). */
#define TLE5012BD_QSPI2_GLOBALCON_VAL         (0x21203C00UL)
#define TLE5012BD_QSPI2_GLOBALCON1_VAL        (0x17000000UL)
#define TLE5012BD_SPI_TXF_RXFIFO_MASK         (0x00380200UL)
#define TLE5012BD_SPI_TXF_RXFIFO_1_SET        (0x00080200UL)
#define TLE5012BD_SPI_HW_ERROR_MASK           (0x0000007FUL)
#define TLE5012BD_SPI_FLAGSCLEAR_VAL          (0x00000FFFUL)
/* ~bit-time budget with margin at CPU clock (32 bit @ 8 MHz ≈ 4 us). */
#define TLE5012BD_SPI_POLL_TIMEOUT            (20000UL)

static uint32 Tle5012bd_SpiBaconLast = 0UL;
static uint8 Tle5012bd_SpiHwReady = 0U;

static uint32 Tle5012bd_SpiBuildBaconLast(void)
{
  Ifx_QSPI_BACON bacon;

  bacon.U = 0UL;
  bacon.B.LAST = 1U;
  bacon.B.IPRE = 1U;
  bacon.B.IDLE = 5U;
  bacon.B.LPRE = 1U;
  bacon.B.LEAD = 5U;
  bacon.B.TPRE = 1U;
  bacon.B.TRAIL = 5U;
  bacon.B.PARTYP = 0U;
  bacon.B.UINT = 1U;
  bacon.B.MSB = 1U;
  bacon.B.BYTE = 0U;
  bacon.B.DL = 31U; /* 32-bit frame */
  bacon.B.CS = 2U;  /* SLSO2 */
  return bacon.U;
}

void Tle5012bd_SpiHwInit(void)
{
  Tle5012bd_SpiBaconLast = Tle5012bd_SpiBuildBaconLast();

  /* Align runtime SFRs with MCAL SpiJob_5012BD (after Spi_Init CLC/PISEL). */
  MODULE_QSPI2.GLOBALCON.U = TLE5012BD_QSPI2_GLOBALCON_VAL;
  MODULE_QSPI2.GLOBALCON1.U = TLE5012BD_QSPI2_GLOBALCON1_VAL;
  MODULE_QSPI2.ECON[TLE5012BD_QSPI2_ECON_INDEX].U = TLE5012BD_QSPI2_ECON_VAL;
  MODULE_QSPI2.SSOC.U = TLE5012BD_QSPI2_SSOC_VAL;
  MODULE_QSPI2.FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;

  Tle5012bd_SpiHwReady = 1U;
}

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  uint32 timeout;
  uint32 status;
  Ifx_QSPI *qspi = &MODULE_QSPI2;

  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;

  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiHwReady == 0U))
  {
    return E_NOT_OK;
  }

  /* Drop any stale RXFIFO words. */
  timeout = 8UL;
  while ((qspi->STATUS.B.RXFIFOLEVEL != 0U) && (timeout > 0UL))
  {
    (void)qspi->RXEXIT.U;
    timeout--;
  }

  qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
  qspi->BACONENTRY.U = Tle5012bd_SpiBaconLast;
  qspi->DATAENTRY[0].U = txWord;

  timeout = TLE5012BD_SPI_POLL_TIMEOUT;
  do
  {
    status = qspi->STATUS.U;
    if ((status & TLE5012BD_SPI_HW_ERROR_MASK) != 0UL)
    {
      qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
      return E_NOT_OK;
    }
    if ((status & TLE5012BD_SPI_TXF_RXFIFO_MASK) == TLE5012BD_SPI_TXF_RXFIFO_1_SET)
    {
      break;
    }
    timeout--;
  } while (timeout > 0UL);

  if (timeout == 0UL)
  {
    qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
    return E_NOT_OK;
  }

  *rxWord = qspi->RXEXIT.U;
  Tle5012bd_SpiLastRxWord = *rxWord;

  /* Wait trail / expect wait-state so CS releases before next frame. */
  timeout = TLE5012BD_SPI_POLL_TIMEOUT;
  while ((qspi->STATUS.B.PHASE != 0U) && (timeout > 0UL))
  {
    if ((qspi->STATUS.U & TLE5012BD_SPI_HW_ERROR_MASK) != 0UL)
    {
      qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
      return E_NOT_OK;
    }
    timeout--;
  }

  Tle5012bd_SpiLastResult = E_OK;
  return E_OK;
}
