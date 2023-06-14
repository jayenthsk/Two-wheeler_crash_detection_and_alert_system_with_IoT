
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <RCSwitch.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <MPU6050.h>

MPU6050 mpu;

RCSwitch mySwitch = RCSwitch();

const char *ssid =  "En unta net ilaya?";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mnbvcxz0987654321"; 

WiFiClient client;

TinyGPSPlus gps;  

SoftwareSerial ss(D7, D8);

String url= "http://192.168.43.158:3000/notify";


void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
     
  mySwitch.enableReceive(D6); // Connect the DATA pin of the RF receiver module to NodeMCU digital pin D1 (GPIO5)
  mySwitch.setProtocol(1);
   ss.begin(9600);

   Wire.begin();
   Serial.begin(9600); // Initialize serial communication for debugging

  mpu.initialize();   // Initialize the MPU6050 sensor

  // Calibrate the sensor
  mpu.CalibrateGyro();
  mpu.setDLPFMode(3);
  }


float val = 0 ; 

void loop() {

  delay(500);
  
  gyro() ;
 // location();

    if (mySwitch.available()) {
    unsigned long value = mySwitch.getReceivedValue();
    if (value != 0) {
      Serial.print("Received value: ");
      Serial.println(value);
      if(val>=20000)
        sendRequest();
      else 
        Serial.println("No Accident detected");
    }
    mySwitch.resetAvailable();
  }
}


void sendRequest(){

  Serial.println("Accident Detected");

  if(WiFi.status()== WL_CONNECTED){

        WiFiClient client;
        HTTPClient http;

        http.begin(client,url);

        int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();

    }

    delay(2000);
}

int16_t ax, ay, az, gx, gy, gz , prevGx,prevGy,prevGz;

void gyro(){

  // Read accelerometer and gyroscope data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Display the sensor data
  // Serial.print("Accelerometer (raw): ");
  // Serial.print(ax);
  // Serial.print(" ");
  // Serial.print(ay);
  // Serial.print(" ");
  // Serial.println(az);

  Serial.print("Gyroscope (raw): ");
  Serial.print(gx);
  Serial.print(" ");
  Serial.print(gy);
  Serial.print(" ");
  Serial.println(gz);

  val =sqrt( pow(abs(prevGx-gx),2) + pow(abs(prevGy-gy),2) + pow(abs(prevGz-gz),2) ) ; 

  if(val>=40000){
     location();
  }

  prevGx = gx;
  prevGy = gy ;
  prevGz = gz ;

}

float latitude , longitude;

void location(){

  while (ss.available() > 0)

    if (gps.encode(ss.read())){

      if (gps.location.isValid())

      {

        latitude = gps.location.lat();

        //lat_str = String(latitude , 6);

        longitude = gps.location.lng();

        //lng_str = String(longitude , 6);

        Serial.println(latitude);

        Serial.println(longitude);


      }
    }
}



