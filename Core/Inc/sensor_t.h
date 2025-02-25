/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software< /span>
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Update by K. Townsend (Adafruit Industries) for lighter typedefs, and
 * extended sensor support to include color, voltage and current */

 #ifndef __SENSOR_T_H__
 #define __SENSOR_T_H__
 
 #include <stdint.h>
 #include <stdbool.h>
 
 /* Constants */
 #define SENSORS_GRAVITY_EARTH (9.80665F)
 #define SENSORS_GRAVITY_MOON (1.6F)
 #define SENSORS_GRAVITY_SUN (275.0F)
 #define SENSORS_GRAVITY_STANDARD (SENSORS_GRAVITY_EARTH)
 #define SENSORS_MAGFIELD_EARTH_MAX (60.0F)
 #define SENSORS_MAGFIELD_EARTH_MIN (30.0F)
 #define SENSORS_PRESSURE_SEALEVELHPA (1013.25F)
 #define SENSORS_DPS_TO_RADS (0.017453293F)
 #define SENSORS_RADS_TO_DPS (57.29577793F)
 #define SENSORS_GAUSS_TO_MICROTESLA (100)
 
 /* Sensor types */
 typedef enum {
     SENSOR_TYPE_ACCELEROMETER = 1,
     SENSOR_TYPE_MAGNETIC_FIELD,
     SENSOR_TYPE_ORIENTATION,
     SENSOR_TYPE_GYROSCOPE,
     SENSOR_TYPE_LIGHT,
     SENSOR_TYPE_PRESSURE,
     SENSOR_TYPE_PROXIMITY = 8,
     SENSOR_TYPE_GRAVITY,
     SENSOR_TYPE_LINEAR_ACCELERATION,
     SENSOR_TYPE_ROTATION_VECTOR,
     SENSOR_TYPE_RELATIVE_HUMIDITY,
     SENSOR_TYPE_AMBIENT_TEMPERATURE,
     SENSOR_TYPE_OBJECT_TEMPERATURE,
     SENSOR_TYPE_VOLTAGE,
     SENSOR_TYPE_CURRENT,
     SENSOR_TYPE_COLOR,
     SENSOR_TYPE_TVOC,
     SENSOR_TYPE_VOC_INDEX,
     SENSOR_TYPE_NOX_INDEX,
     SENSOR_TYPE_CO2,
     SENSOR_TYPE_ECO2,
     SENSOR_TYPE_PM10_STD,
     SENSOR_TYPE_PM25_STD,
     SENSOR_TYPE_PM100_STD,
     SENSOR_TYPE_PM10_ENV,
     SENSOR_TYPE_PM25_ENV,
     SENSOR_TYPE_PM100_ENV,
     SENSOR_TYPE_GAS_RESISTANCE,
     SENSOR_TYPE_UNITLESS_PERCENT,
     SENSOR_TYPE_ALTITUDE
 } sensors_type_t;
 
 /* Vector structure */
 typedef struct {
     float x, y, z;
     int8_t status;
     uint8_t reserved[3];
 } sensors_vec_t;
 
 /* Color structure */
 typedef struct {
     float r, g, b;
     uint32_t rgba;
 } sensors_color_t;
 
 /* Sensor event structure */
 typedef struct {
     int32_t version;
     int32_t sensor_id;
     int32_t type;
     int32_t reserved0;
     int32_t timestamp;
     union {
         float data[4];
         sensors_vec_t acceleration;
         sensors_vec_t magnetic;
         sensors_vec_t orientation;
         sensors_vec_t gyro;
         float temperature;
         float distance;
         float light;
         float pressure;
         float relative_humidity;
         float current;
         float voltage;
         float tvoc;
         float voc_index;
         float nox_index;
         float CO2;
         float eCO2;
         float pm10_std;
         float pm25_std;
         float pm100_std;
         float pm10_env;
         float pm25_env;
         float pm100_env;
         float gas_resistance;
         float unitless_percent;
         sensors_color_t color;
         float altitude;
     } data;
 } sensors_event_t;
 
 /* Sensor details structure */
 typedef struct {
     char name[12];
     int32_t version;
     int32_t sensor_id;
     int32_t type;
     float max_value;
     float min_value;
     float resolution;
     int32_t min_delay;
 } sensor_t;
 
 /* Sensor interface structure */
 typedef struct {
     void (*enableAutoRange)(bool enabled);
     bool (*getEvent)(sensors_event_t *event);
     void (*getSensor)(sensor_t *sensor);
 } Adafruit_Sensor;
 
 #endif  // __SENSOR_T_H__