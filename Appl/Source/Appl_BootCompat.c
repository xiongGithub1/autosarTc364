/**********************************************************************************************************************
 * Appl_BootCompat.c — APP image header + stay-in-boot handshake
 *
 * Header MUST sit at 0x80020000 (Boot reads it there). length/crc32 are 0 in the
 * object; Tools/patch_app_header.py fills them in last364.hex after link.
 *********************************************************************************************************************/
#include "Appl_BootCompat.h"
#include "BrsCompiler_Cfg.h"
#include "BrsHw.h"

extern void brsStartupEntry(void);
/* APP OS vector tables — Boot validates intVec/trapVec against these. */
extern uint8 osIsrLevel_0_Core0[];
extern uint8 osTrap_0_Core0[];

typedef char Appl_HdrSizeCheck[(sizeof(Boot_AppHdrType) == BOOT_APP_HDR_SIZE) ? 1 : -1];
typedef char Appl_HsSizeCheck[(sizeof(Boot_HandshakeType) == BOOT_HS_SIZE) ? 1 : -1];

/* Keep section even if nothing references the symbol (Tasking would strip it). */
#if defined (BRS_COMP_TASKING)
# pragma section farrom "AppBootHdr"
# pragma protect
#endif
#if defined (__GNUC__) || defined (__ghs__) || defined (__TASKING__)
__attribute__((used))
#endif
const Boot_AppHdrType Appl_BootHeader __at(0x80020000u) =
{
  BOOT_APP_HDR_MAGIC,
  (uint32)&brsStartupEntry,
  0u, /* length: patch_app_header.py */
  0u, /* crc32:  patch_app_header.py */
  0x00010000u,
  (uint32)&osIsrLevel_0_Core0, /* intVec  — BIV base, 8 KB aligned */
  (uint32)&osTrap_0_Core0,     /* trapVec — BTV base, 256 B aligned */
  0u
};
#if defined (BRS_COMP_TASKING)
# pragma protect restore
# pragma section farrom restore
#endif

static volatile Boot_HandshakeType* Appl_Hs(void)
{
  return (volatile Boot_HandshakeType*)BOOT_HS_BASE;
}

void Appl_ArmRequestBoot(void)
{
  volatile Boot_HandshakeType* hs = Appl_Hs();
  uint32 i;

  /* Touch header so the link cannot treat it as dead even without __attribute__((used)). */
  (void)Appl_BootHeader.magic;

  hs->magic = BOOT_HS_MAGIC;
  hs->cmd = BOOT_HS_CMD_REQUEST_BOOT;
  for (i = 0u; i < 14u; i++)
  {
    hs->reserved[i] = 0u;
  }
}

void Appl_RequestBoot(void)
{
  Appl_ArmRequestBoot();
  BrsHwSoftwareResetECU(); /* does not return */
}
