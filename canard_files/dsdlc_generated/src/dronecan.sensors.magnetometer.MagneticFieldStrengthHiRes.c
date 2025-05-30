

#define CANARD_DSDLC_INTERNAL
#include "../inc/dronecan.sensors.magnetometer.MagneticFieldStrengthHiRes.h"

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes_encode(struct dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, DRONECAN_SENSORS_MAGNETOMETER_MAGNETICFIELDSTRENGTHHIRES_MAX_SIZE);
    _dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

/*
  return true if the decode is invalid
 */
bool dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes_decode(const CanardRxTransfer* transfer, struct dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes* msg) {
#if CANARD_ENABLE_TAO_OPTION
    if (transfer->tao && (transfer->payload_len > DRONECAN_SENSORS_MAGNETOMETER_MAGNETICFIELDSTRENGTHHIRES_MAX_SIZE)) {
        return true; /* invalid payload length */
    }
#endif
    uint32_t bit_ofs = 0;
    if (_dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes_decode(transfer, &bit_ofs, msg,
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    )) {
        return true; /* invalid payload */
    }

    const uint32_t byte_len = (bit_ofs+7U)/8U;
#if CANARD_ENABLE_TAO_OPTION
    // if this could be CANFD then the dlc could indicating more bytes than
    // we actually have
    if (!transfer->tao) {
        return byte_len > transfer->payload_len;
    }
#endif
    return byte_len != transfer->payload_len;
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes sample_dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes_msg(void) {

    struct dronecan_sensors_magnetometer_MagneticFieldStrengthHiRes msg;






    msg.sensor_id = (uint8_t)random_bitlen_unsigned_val(8);







    for (size_t i=0; i < 3; i++) {




        msg.magnetic_field_ga[i] = random_float_val();



    }




    return msg;

}
#endif
