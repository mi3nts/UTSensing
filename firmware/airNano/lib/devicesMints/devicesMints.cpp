
#include "devicesMints.h"

// SCD30 ---------------------------------------
bool initializeSCD30Mints(){
  if (scd.begin()) {
    Serial.println("SCD30 Initiated");
    delay(1);
    return true;
  }else{
    Serial.println("SCD30 not found");
    delay(1);
    return false;
  }

  delay(2000);
}

void readSCD30Mints(){

  uint16_t co2         = scd.getCO2();
  uint16_t temperature = scd.getTemperature();
  uint16_t humidity    = scd.getHumidity();

  String readings[3] = { String(co2), String(temperature) , String(humidity) };
  sensorPrintMints("SCD30",readings,3);

}


// BME680 ---------------------------------------
bool initializeBME680Mints(){
  if (bme680.init()) {
    Serial.println("BME680 Initiated");
    delay(1);
    return true;
  }else{
    Serial.println("BME680 not found");
    delay(1);
    return false;
  }

}

void readBME680Mints(){
  if (!bme680.read_sensor_data()) {
    String readings[4] = { String(bme680.sensor_result_value.temperature), 
                           String(bme680.sensor_result_value.pressure / 1000.0) ,
                           String(bme680.sensor_result_value.humidity) ,
                           String(bme680.sensor_result_value.gas / 1000.0),
                           };
  
  sensorPrintMints("BME680",readings,4);
  }


}



// SGP30 ---------------------------------------
bool initializeSGP30Mints(){
if (sgp.begin()){
    Serial.println("SGP30 Initiated");
    Serial.print("Found SGP30 serial #");
    Serial.print(sgp.serialnumber[0], HEX);
    Serial.print(sgp.serialnumber[1], HEX);
    Serial.println(sgp.serialnumber[2], HEX);
    delay(1);
    return true;
    }else{
    Serial.println("SGP30 not found");
    delay(1);
    return false;
    }
}


 void readSGP30Mints(){


   if (sgp.IAQmeasure()){
        String TVOC        = String(sgp.TVOC);
        String eCO2        = String(sgp.eCO2);
      if (sgp.IAQmeasureRaw()){
           String rawH2       = String(sgp.rawH2);
           String rawEthanol  = String(sgp.rawEthanol);
        
           String readings[4] = { 
                          TVOC, 
                           eCO2  ,
                           rawH2  ,
                           rawEthanol
                           };
          sensorPrintMints("SGP30",readings,4);
      }
 }
 }

// MGSV2 ---------------------------------------
bool initializeMGSV2Mints(){
  gas.begin(Wire, 0x08);
  Serial.println("MGSV2 Initiated");
  return true;
}


void readMGSV2Mints(){
 String readings[4] = { String(gas.measure_NO2()), 
                        String(gas.measure_C2H5OH()) ,
                        String(gas.measure_VOC()) ,
                        String(gas.measure_CO()),
                        };
  
  sensorPrintMints("MGSV2",readings,4);
 }



// SEN0321 ---------------------------------------
bool initializeSEN0321Mints(){
  if (Ozone.begin(Ozone_IICAddress)) {
    Serial.println("SEN0321 Initiated");
     delay(1000);
    return true;
  }else{
    Serial.println("SEN0321 not found");
    delay(1);
    return false;
  }

}

void readSEN0321Mints(){
    String readings[1] = { String(Ozone.ReadOzoneData(COLLECT_NUMBER))
                           };
    sensorPrintMints("SEN0321",readings,1);
}

// PMSA0031 ---------------------------------------
bool initializePMSA003IMints(){
  if (aqi.begin_I2C()) {
      Serial.println("PMSA003I Initiated");
      delay(10);
      return true;
  }else{
      Serial.println("PMSA003I not found");
      delay(10);
      return false;
  }
}


void readPMSA003IMints(){
    PM25_AQI_Data data;
    if (aqi.read(&data)) {
       String readings[12] =
                      { String(data.pm10_standard), 
                        String(data.pm25_standard) ,
                        String(data.pm100_standard) ,
                        String(data.pm10_env),
                        String(data.pm25_env), 
                        String(data.pm100_env) ,
                        String(data.particles_03um) ,
                        String(data.particles_05um),
                        String(data.particles_10um), 
                        String(data.particles_25um),
                        String(data.particles_50um),
                        String(data.particles_100um) 
                        };

    sensorPrintMints("PMSA003I",readings,12);
  }
}


// 
bool initializeMQ136Mints(){
   Serial.println("Initiating MQ136");
   delay(20000);
   Serial.println("MQ136 Initiated");
   return true;
}


void readMQ136Mints(){
       String readings[1] =
                      { String(analogRead(0)), 
                      };

    sensorPrintMints("MQ136",readings,1);
}





















