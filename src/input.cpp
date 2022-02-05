#include <Arduino.h>
#include <BleKeyboard.h>

#define BTN_GND_1 T0
#define BTN_GND_2 T7
#define BTN_AIR_1 T8
#define BTN_AIR_2 T9
#define BTN_FEVER T3

#define SENSITIVITY 50

BleKeyboard bleKeyboard("MD Con","NERII",100);

const uint8_t KEY_GND_1 = (uint8_t)'J';
const uint8_t KEY_GND_2 = (uint8_t)'K'; 
const uint8_t KEY_AIR_1 = (uint8_t)'D';
const uint8_t KEY_AIR_2 = (uint8_t)'F';
const uint8_t KEY_FEVER = 32; //SPACE

boolean btnGnd1 = false;
boolean btnGnd2 = false;
boolean btnAir1 = false;
boolean btnAir2 = false;
boolean btnFever = false;

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

void feverDetected(){
    btnFever = true;
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

    if(btnFever == true){
        btnFever = false;
        bleKeyboard.write(KEY_FEVER);
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
  touchAttachInterrupt(BTN_FEVER, feverDetected, SENSITIVITY);
}

void inputLoop(){
    if(bleKeyboard.isConnected()){
        buttons();
    }
}