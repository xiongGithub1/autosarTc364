/**********************************************************************************************************************
 * Local include-path adapter for the Vector CAN stack.
 *
 * The project also contains MCAL364/Platform/Can_GeneralTypes.h. Because the
 * generated include path lists MCAL before BSW364/_Common, Can_Cfg.h can pick
 * the MCAL header and miss AUTOSAR 4.4 CAN driver types required by Vector Can.h.
 *********************************************************************************************************************/

#ifndef CAN_GENERALTYPES_ADAPTER_H
#define CAN_GENERALTYPES_ADAPTER_H

#include "../../BSW364/_Common/Implementation/Can_GeneralTypes.h"

#endif /* CAN_GENERALTYPES_ADAPTER_H */
