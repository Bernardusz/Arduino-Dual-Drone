#ifndef SENSOR_H
#define SENSOR_H
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

void initializeSensor();
void readSensor(float &ax, float &ay, float &az, float &gx, float &gy, float &gz);

#endif