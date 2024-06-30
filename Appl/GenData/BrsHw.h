#ifndef BRSHW_H
#define BRSHW_H

/*
 * The generated vBrs_Lcfg files only need this macro to decide whether
 * BRS startup-core descriptors must be emitted. In this project the
 * startup path is handled by EcuM + OS, so keep the legacy BRS branch off.
 */
#define BRSHW_SOURCECODE_TEMPLATE_VERSION 0x0000u

#endif /* BRSHW_H */
