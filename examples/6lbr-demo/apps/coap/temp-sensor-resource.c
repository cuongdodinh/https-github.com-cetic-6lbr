#include "coap-common.h"
#include "temp-sensor-resource.h"

#if REST_RES_TEMP
#if REST_RES_TEMP_PERIODIC
#define REST_RES_TEMP_RESOURCE REST_PERIODIC_RESOURCE
#else
#define REST_RES_TEMP_RESOURCE REST_RESOURCE
#endif
#else
#define REST_RES_TEMP_RESOURCE(...)
#endif

#if REST_RES_TEMP_RAW
#define REST_REST_TEMP_VALUE REST_FORMAT_ONE_INT("temp", sht11_sensor.value(SHT11_SENSOR_TEMP))
#else
#define REST_REST_TEMP_VALUE REST_FORMAT_ONE_DECIMAL("temp", sht11_sensor.value(SHT11_SENSOR_TEMP), (value / 10 - 396) / 10, (value / 10 - 396) % 10)
#endif

REST_RES_TEMP_RESOURCE(temp,
    REST_RES_TEMP_PERIOD,
    IF_SENSOR,
    TEMPERATURE_SENSOR_RT,
    REST_REST_TEMP_VALUE)