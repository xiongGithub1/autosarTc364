/**********************************************************************************************************************
 * Appl_SpiDmaHwInit.c
 * Application-owned SPI/DMA/Irq post-init (survives DaVinci EcuM regen).
 **********************************************************************************************************************/
#include "Appl_SpiDmaHwInit.h"

#include "Dma.h"
#include "IfxSrc_reg.h"
#include "Irq.h"
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

void Appl_SpiDmaHwInit(void)
{
  Dma_Init(&Dma_Config);

  IrqSpi_Init();
  IrqDma_Init();
  Appl_SpiEnableQspiDmaSrc();

  (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
}

/*
 * Soft recover only. Do NOT Spi_DeInit()/Spi_Init() at runtime from Motortask —
 * that can trigger OS/DET trap -> Os_Hal_CoreFreeze.
 */
void Appl_SpiBusRecover(void)
{
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_9183);
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_35584);
  Appl_SpiEnableQspiDmaSrc();
}
