#include "comm.h"
#include <Arduino.h>

void initializeBluetooth(){
  Serial.begin(9600);
}

char readBluetooth(){
    if (Serial.available()){
        return Serial.read();
    }
}