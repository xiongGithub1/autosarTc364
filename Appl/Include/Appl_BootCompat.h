/**********************************************************************************************************************
 * Appl_BootCompat.h — APP header @ 0x80020000 + handshake back to Boot
 *********************************************************************************************************************/
#ifndef APPL_BOOTCOMPAT_H
#define APPL_BOOTCOMPAT_H

#include "Boot_Mem.h"

/* Linked at BOOT_FLASH_APP_START (see vLinkGen App_BootHeader group / LSL). */
extern const Boot_AppHdrType Appl_BootHeader;

/* Write REQUEST_BOOT into shared RAM then software-reset into Boot. */
void Appl_RequestBoot(void);

#endif /* APPL_BOOTCOMPAT_H */
