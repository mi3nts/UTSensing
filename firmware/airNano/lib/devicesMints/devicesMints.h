#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H
//
#include <Arduino.h>

#include "SparkFun_SCD30_Arduino_Library.h"

#include "seeed_bme680.h"
#include "Adafruit_SGP30.h"

#include <Multichannel_Gas_GMXXX.h>

#include "DFRobot_OzoneSensor.h"

#include "Adafruit_PM25AQI.h"

#include "jobsMints.h"

// For SGP30  
#define LOOP_TIME_INTERVAL_MS  1000
#define BASELINE_IS_STORED_FLAG  (0X55)


#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10


#define IIC_ADDR  uint8_t(0x76)

//  DF Robot Ozone Sensor 
#define COLLECT_NUMBER   20              // collect number, the collection range is 1-100
#define Ozone_IICAddress ADDRESS_3


//
extern SCD30 scd;
bool initializeSCD30Mints();
void readSCD30Mints();

extern Seeed_BME680 bme680;
bool initializeBME680Mints();
void readBME680Mints();

extern Adafruit_SGP30 sgp;
bool initializeSGP30Mints();
void readSGP30Mints();

extern GAS_GMXXX<TwoWire> gas;
bool initializeMGSV2Mints();
void readMGSV2Mints();

extern DFRobot_OzoneSensor Ozone;
bool initializeSEN0321Mints();
void readSEN0321Mints();

extern Adafruit_PM25AQI aqi;
bool initializePMSA003IMints();
void readPMSA003IMints();

bool initializeMQ136Mints();
void readMQ136Mints();

#endif
