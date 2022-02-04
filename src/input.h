#include <Arduino.h>
#include <BleKeyboard.h>

#define KEY_GND_1 'J'
#define KEY_GND_2 'K'
#define KEY_AIR_1 'D'
#define KEY_AIR_2 'F'

#define BTN_GND_1 T0
#define BTN_GND_2 T7
#define BTN_AIR_1 T8
#define BTN_AIR_2 T9

#define SENSITIVITY 50

void start();
void inputLoop();