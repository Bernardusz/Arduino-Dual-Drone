#include "drone.h"
#include <Arduino.h>
#include <Servo.h>

Servo motorLeft;
Servo motorRight;

static void moveForward();
static void turnLeft();
static void turnRight();
static void stopMotors();
static void addSpeedLeft();
static void addSpeedRight();

void droneController(char command){
    switch (command){
        case 'N': addSpeedLeft(); break;
        case 'M': addSpeedRight(); break;
        case 'F': moveForward(); break;
        case 'L': turnLeft(); break;
        case 'R': turnRight(); break;
        case 'B': stopMotors(); break;
    }
}

void initializeDrone(){
    motorLeft.attach(6);
    motorRight.attach(5);

    motorLeft.writeMicroseconds(1000);
    motorRight.writeMicroseconds(1000);
}
static void moveForward(){
    motorLeft.writeMicroseconds(1700);
    motorRight.writeMicroseconds(1700);
}
static void turnLeft(){
    motorLeft.writeMicroseconds(1700);
    motorRight.writeMicroseconds(1800);
}
static void turnRight(){
    motorLeft.writeMicroseconds(1800);
    motorRight.writeMicroseconds(1700);
}
static void stopMotors(){
    motorLeft.writeMicroseconds(1000);
    motorRight.writeMicroseconds(1000);
}
static void addSpeedLeft(){
    motorLeft.writeMicroseconds(1900);
}
static void addSpeedRight(){
    motorRight.writeMicroseconds(1900);
}