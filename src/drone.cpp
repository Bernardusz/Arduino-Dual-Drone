#include "drone.h"
#include <Arduino.h>
#include <Servo.h>

Servo motorLeft;
Servo motorRight;

int lowSpeed = 1300;
int mediumSpeed = 1500;
int highSpeed = 1700;
int maxSpeed = 2000;

int normalSpeed = 1000;

int currentSpeedLeft = 1000;
int currentSpeedRight = 1000;

static void moveForward();
static void turnLeft();
static void turnRight();
static void stopMotors();
static void addSpeedLeft();
static void addSpeedRight();
static void gradualThrottle(int &currentSpeed, int target);

void droneController(char command){
    switch (command){
        case 'A': addSpeedLeft(); break;
        case 'D': addSpeedRight(); break;
        case 'F': moveForward(); break;
        case 'L': turnLeft(); break;
        case 'R': turnRight(); break;
        case 'B': stopMotors(); break;

        case '0':
        case '1':
        case '2':
            gradualThrottle(currentSpeedLeft, lowSpeed);
            gradualThrottle(currentSpeedRight, lowSpeed);
            normalSpeed = lowSpeed;
            break;

        case '3':
        case '4':
        case '5':
            gradualThrottle(currentSpeedLeft, mediumSpeed);
            gradualThrottle(currentSpeedRight, mediumSpeed);
            normalSpeed = mediumSpeed;
            break;

        case '6':
        case '7':
        case '8':
            gradualThrottle(currentSpeedLeft, highSpeed);
            gradualThrottle(currentSpeedRight, highSpeed);
            normalSpeed = highSpeed;
            break;

        case '9':
            gradualThrottle(currentSpeedLeft, maxSpeed);
            gradualThrottle(currentSpeedRight, maxSpeed);
            normalSpeed = maxSpeed;
            break;
    }
}


void initializeDrone(){
    motorLeft.attach(5);
    motorRight.attach(6);

    motorLeft.writeMicroseconds(currentSpeedLeft);
    motorRight.writeMicroseconds(currentSpeedRight);
}
static void moveForward(){
    gradualThrottle(currentSpeedLeft, normalSpeed);
    gradualThrottle(currentSpeedRight, normalSpeed);

    motorLeft.writeMicroseconds(currentSpeedLeft);
    motorRight.writeMicroseconds(currentSpeedRight);
}
static void turnLeft(){
    gradualThrottle(currentSpeedRight, normalSpeed);
    gradualThrottle(currentSpeedRight, normalSpeed + 300);

    motorLeft.writeMicroseconds(currentSpeedLeft);
    motorRight.writeMicroseconds(currentSpeedRight);
}
static void turnRight(){
    gradualThrottle(currentSpeedLeft, normalSpeed + 300);
    gradualThrottle(currentSpeedRight, normalSpeed);

    motorLeft.writeMicroseconds(currentSpeedLeft);
    motorRight.writeMicroseconds(currentSpeedRight);
}
static void stopMotors(){
    normalSpeed = 1000;

    gradualThrottle(currentSpeedLeft, normalSpeed);
    gradualThrottle(currentSpeedRight, normalSpeed);

    motorLeft.writeMicroseconds(1000);
    motorRight.writeMicroseconds(1000);
}
static void addSpeedLeft(){ // For when it's too tilted to the left
    gradualThrottle(currentSpeedLeft, normalSpeed + 100);
    motorLeft.writeMicroseconds(currentSpeedLeft);
}
static void addSpeedRight(){ // For when it's too tilted to the right
    gradualThrottle(currentSpeedRight, normalSpeed + 100);
    motorRight.writeMicroseconds(currentSpeedRight);
}
static void gradualThrottle(int &currentSpeed, int target){
    float steps = 100;
    
    if (target > 2000) target = 2000;
    if (target < 1000) target = 1000;

    float stepSize = (target - currentSpeed) / (float)steps;

    for(int i = 0; i <= steps; i++){
        currentSpeed += stepSize;
        delay(10);
    }
    currentSpeed = target;
}