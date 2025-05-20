#include "sensor.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void initializeSensor() {
    Wire.begin();
    mpu.begin();
}

void readSensor(float &ax, float &ay, float &az, float &gx, float &gy, float &gz) {

}