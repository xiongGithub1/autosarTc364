/**********************************************************************************************************************
 * Appl_SpiDmaHwInit.c
 * Application-owned SPI/DMA/Irq post-init (survives DaVinci EcuM regen).
 **********************************************************************************************************************/
#include "Appl_SpiDmaHwInit.h"

#include "Dma.h"
#include "IfxQspi_reg.h"
#include "IfxSrc_reg.h"
#include "Irq.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

static void Appl_SpiEnableQspiDmaSrc(void)
{
  SRC_QSPI1TX.B.SRE = 1U;
  SRC_QSPI1RX.B.SRE = 1U;
  SRC_QSPI2TX.B.SRE = 1U;
  SRC_QSPI2RX.B.SRE = 1U;
  SRC_QSPI3TX.B.SRE = 1U;
  SRC_QSPI3RX.B.SRE = 1U;
}

static void Appl_SpiFlushQspiRxFifo(Ifx_QSPI *qspi)
{
  uint8 guard = 16U;

  while ((qspi->STATUS.B.RXFIFOLEVEL != 0U) && (guard > 0U))
  {
    (void)qspi->RXEXIT.U;
    guard--;
  }
}

/*
 * After Spi_Cancel the Seq becomes CANCELED but KernelStatus may stay BUSY
 * until the queue drain path runs (BusHandler via MainFunction in POLLING).
 */
static void Appl_SpiDrainAsync(void)
{
  uint32 i;

  for (i = 0U; i < 64U; i++)
  {
    Spi_MainFunction_Handling();
    if ((Spi_GetHWUnitStatus(SPI_QSPI1_INDEX) == SPI_IDLE) &&
        (Spi_GetHWUnitStatus(SPI_QSPI2_INDEX) == SPI_IDLE) &&
        (Spi_GetHWUnitStatus(SPI_QSPI3_INDEX) == SPI_IDLE))
    {
      break;
    }
  }
}

void Appl_SpiDmaHwInit(void)
{
  Dma_Init(&Dma_Config);

  IrqSpi_Init();
  IrqDma_Init();
  Appl_SpiEnableQspiDmaSrc();

  /*
   * Level-2 bring-up: keep POLLING for the whole run.
   * Toggling INTERRUPT/POLLING every exchange fails when ANY QSPI is BUSY
   * (SetAsyncMode is core-global), and leaves 9180 dead once 5012 sticks.
   */
  (void)Spi_SetAsyncMode(SPI_POLLING_MODE);
}

void Appl_SpiBusRecover(void)
{
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_9183);
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_35584);
  /* Leftover RXFIFO blocks next job / keeps Kernel busy. */
  Appl_SpiFlushQspiRxFifo(&MODULE_QSPI1);
  Appl_SpiFlushQspiRxFifo(&MODULE_QSPI2);
  Appl_SpiFlushQspiRxFifo(&MODULE_QSPI3);
  Appl_SpiEnableQspiDmaSrc();
  Appl_SpiDrainAsync();
  (void)Spi_SetAsyncMode(SPI_POLLING_MODE);
}
