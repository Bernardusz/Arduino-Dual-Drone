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
        case 'L': addSpeedLeft(); break;
        case 'R': addSpeedRight(); break;
        case 'W': moveForward(); break;
        case 'A': turnLeft(); break;
        case 'D': turnRight(); break;
        case 'V': stopMotors(); break;
    }
}

void initializeDrone(){
    motorLeft.attach(6);
    motorRight.attach(5);

    motorLeft.writeMicroseconds(1000);
    motorRight.writeMicroseconds(1000);
}
static void moveForward(){
    motorLeft.writeMicroseconds(1500);
    motorRight.writeMicroseconds(1500);
}
static void turnLeft(){
    motorLeft.writeMicroseconds(1200);
    motorRight.writeMicroseconds(1500);
}
static void turnRight(){
    motorLeft.writeMicroseconds(1500);
    motorRight.writeMicroseconds(1200);
}
static void stopMotors(){
    motorLeft.writeMicroseconds(1000);
    motorRight.writeMicroseconds(1000);
}
static void addSpeedLeft(){
    motorLeft.writeMicroseconds(1600);
}
static void addSpeedRight(){
    motorRight.writeMicroseconds(1600);
}