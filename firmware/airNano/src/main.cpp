#include "Arduino.h"
#include "jobsMints.h"
#include "devicesMints.h"

bool BME680Online;
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */

bool SCD30Online;
SCD30 scd;

Adafruit_SGP30 sgp;
bool SGP30Online;

GAS_GMXXX<TwoWire> gas;
bool MGSV2Online;

DFRobot_OzoneSensor Ozone;
bool SEN0321Online;

Adafruit_PM25AQI aqi = Adafruit_PM25AQI();
bool PMSA003IOnline; 

bool MQ136Online; 



uint16_t sensingPeriod = 1000;
uint16_t initPeriod = 1500;

unsigned long startTime;

void setup() {

  delay(initPeriod);
  initializeSerialMints();

  delay(initPeriod);
  SCD30Online = initializeSCD30Mints();

  delay(initPeriod);
  BME680Online = initializeBME680Mints();

  delay(initPeriod);
  SGP30Online = initializeSGP30Mints();
  
  delay(initPeriod);
  MGSV2Online = initializeMGSV2Mints();

  delay(initPeriod);
  SEN0321Online = initializeSEN0321Mints();

  delay(initPeriod);
  PMSA003IOnline = initializePMSA003IMints();

  delay(initPeriod);
  MQ136Online = initializeMQ136Mints();
}

// the loop routine runs over and over again forever:
int counter = 0;
void loop() {

    startTime  = millis();

   
    if(SCD30Online)
    {
      readSCD30Mints();
    }

    delay(sensingPeriod);
    if(BME680Online)
    {
      readBME680Mints();
    }
   

     delay(sensingPeriod);
       if(SGP30Online)
    {
      readSGP30Mints();
    }
    if (counter == 30) {
    counter = 0;
    uint16_t TVOC_base, eCO2_base;
    sgp.getIAQBaseline(&eCO2_base, &TVOC_base);
    }


    delay(sensingPeriod);
    if(MGSV2Online)
    {
      readMGSV2Mints();
    }


   delay(sensingPeriod);
    if(SEN0321Online)
    {
      readSEN0321Mints();
    }

    delay(sensingPeriod);
    if(PMSA003IOnline)
    {
      readPMSA003IMints();
    }

    delay(sensingPeriod);
    if(MQ136Online)
    {
      readMQ136Mints();
    }


    delayMints(millis() - startTime,10000);

}