#include <stdint.h>
#include "input.h"
BleKeyboard bleKeyboard("MD Con","NERII",100);

boolean btnGnd1 = false;
boolean btnGnd2 = false;
boolean btnAir1 = false;
boolean btnAir2 = false;

void gnd1Detected(){
    btnGnd1 = true;
}

void gnd2Detected(){
    btnGnd2 = true;
}

void air1Detected(){
    btnAir1 = true;
}

void air2Detected(){
    btnAir2 = true;
}

void buttons(){
        if(btnGnd1 == true && touchRead(BTN_GND_1) <= SENSITIVITY){
        bleKeyboard.press(KEY_GND_1);
    } else {
        bleKeyboard.release(KEY_GND_1);
        btnGnd1 = false;
    }
    if(btnGnd2 == true && touchRead(BTN_GND_2) <= SENSITIVITY){
        bleKeyboard.press(KEY_GND_2);
    } else {
        bleKeyboard.release(KEY_GND_2);
        btnGnd2 = false;
    }
    if(btnAir1 == true && touchRead(BTN_AIR_1) <= SENSITIVITY){
        bleKeyboard.press(KEY_AIR_1);
    } else {
        bleKeyboard.release(KEY_AIR_1);
        btnAir1 = false;
    }
    if(btnAir2 == true && touchRead(BTN_AIR_2) <= SENSITIVITY){
        bleKeyboard.press(KEY_AIR_2);
    } else {
        bleKeyboard.release(KEY_AIR_2);
        btnAir2 = false;
    }
}
void start(){
  Serial.begin(115200);
  bleKeyboard.begin();
  bleKeyboard.releaseAll();
  touchAttachInterrupt(BTN_GND_1, gnd1Detected, SENSITIVITY);
  touchAttachInterrupt(BTN_GND_2, gnd2Detected, SENSITIVITY);
  touchAttachInterrupt(BTN_AIR_1, air1Detected, SENSITIVITY);
  touchAttachInterrupt(BTN_AIR_2, air2Detected, SENSITIVITY);
}

void inputLoop(){
    if(bleKeyboard.isConnected()){
        buttons();
    }
}