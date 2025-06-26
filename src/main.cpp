#include <Arduino.h>
#include <drone.h>
#include <comm.h>
float ax, ay, az, gx, gy, gz;
char command = 'B';

void setup() {
  // put your setup code here, to run once:
  initializeBluetooth();
  initializeDrone();
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    command = readBluetooth();
  }
  droneController(command);
}


