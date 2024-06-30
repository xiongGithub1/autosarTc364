/**********************************************************************************************************************
 *  MemMap.h
 *
 *  AUTOSAR MemMap header for MCAL modules (Mcu, Port, ...).
 *  Must be included repeatedly (START/STOP pairs). Do NOT use an include guard here.
 **********************************************************************************************************************/

#ifndef MICROSAR_DISABLE_MEMMAP

#define MEMMAP_ERROR

#include "_MemMap.h"

#ifdef MEMMAP_ERROR
# error "No MemMap section found. Check your section define for validity."
#endif

#endif /* MICROSAR_DISABLE_MEMMAP */
