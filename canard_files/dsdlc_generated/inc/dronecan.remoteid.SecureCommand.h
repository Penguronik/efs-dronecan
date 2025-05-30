

#pragma once
#include "../inc/dronecan.remoteid.SecureCommand_req.h"
#include "../inc/dronecan.remoteid.SecureCommand_res.h"

#define DRONECAN_REMOTEID_SECURECOMMAND_ID 64
#define DRONECAN_REMOTEID_SECURECOMMAND_SIGNATURE (0x126A47C9C17A8BD7ULL)


#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
#include <canard/cxx_wrappers.h>
SERVICE_MESSAGE_CXX_IFACE(dronecan_remoteid_SecureCommand, DRONECAN_REMOTEID_SECURECOMMAND_ID, DRONECAN_REMOTEID_SECURECOMMAND_SIGNATURE, DRONECAN_REMOTEID_SECURECOMMAND_REQUEST_MAX_SIZE, DRONECAN_REMOTEID_SECURECOMMAND_RESPONSE_MAX_SIZE);
#endif
