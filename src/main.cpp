#include <Arduino.h>
#include <drone.h>
#include <sensor.h>
#include <comm.h>
float ax, ay, az, gx, gy, gz;

void setup() {
  // put your setup code here, to run once:
  initializeSensor();
  initializeBluetooth();
  initializeDrone();
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensor(ax, ay, az, gx, gy, gz);
  if (gy > 20){
    droneController('D');
  }
  else if (gy < -20){
    droneController('A');
  }
  else {
    if (Serial.available() > 0) {
      char command = readBluetooth();
      droneController(command);
    }
    else{
      droneController('B'); //Sending B as stop motor
    }
  }
}

