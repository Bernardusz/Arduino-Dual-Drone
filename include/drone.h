#ifndef DRONE_H
#define DRONE_H
#include <Servo.h>

extern Servo motorLeft;
extern Servo motorRight;

void droneController(char command);
void initializeDrone();

#endif