#include "coap-common.h"
#include "battery-sensor-resource.h"

#if REST_RES_BATTERY
#if REST_RES_BATTERY_PERIODIC
#define REST_RES_BATTERY_RESOURCE REST_PERIODIC_RESOURCE
#else
#define REST_RES_BATTERY_RESOURCE REST_RESOURCE
#endif
#else
#define REST_RES_BATTERY_RESOURCE(...)
#endif

#if REST_RES_BATTERY_RAW
#define REST_REST_BATTERY_VALUE REST_FORMAT_ONE_INT("v", battery_sensor.value(0))
#else
#define REST_REST_BATTERY_VALUE REST_FORMAT_ONE_DECIMAL("v", battery_sensor.value(0), value / 819, (10 * value / 819) % 10)
#endif

REST_RES_BATTERY_RESOURCE(battery,
    REST_RES_BATTERY_PERIOD,
    IF_SENSOR,
    DEVICE_POWER_SUPPLY_VOLTAGE_RT,
    REST_REST_BATTERY_VALUE)