#include <Arduino.h>
#include <drone.h>
#include <sensor.h>
#include <comm.h>
float ax, ay, az, gx, gy, gz;

void setup() {
  // put your setup code here, to run once:
  initializeSensor();
  initializeBluetooth();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensor(ax, ay, az, gx, gy, gz);
  char command = readBluetooth();
}

