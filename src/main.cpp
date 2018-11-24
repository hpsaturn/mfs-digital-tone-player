#include <TimerOne.h>
#include <Wire.h>
#include <EEPROMex.h>
#include <MultiFuncShield.h>



void checkStopConditions(byte btn) {

  if (btn == BUTTON_1_PRESSED || btn == BUTTON_1_LONG_PRESSED ) {
    MFS.beep(6, 2, 3);  // beep 3 times, 600 milliseconds on / 200 off
  }
  else if (btn == BUTTON_2_PRESSED || btn == BUTTON_2_LONG_PRESSED) {
    MFS.beep(1, 1, 3, 3, 1);  
  }
  else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED) {
    MFS.beep(8, 10, 3, 3, 10);  // beep 1 times, 800 milliseconds on / 1000 off
  }

  int x = (int)(analogRead(POT_PIN)/10);
  MFS.write(analogRead(x));
  //MFS.beep(1, x, 1);  // beep 1 times, 800 milliseconds on / 1000 off

}

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multifunction shield library
  MFS.write(0);
}

void loop() {

  byte btn = MFS.getButton();
  checkStopConditions(btn);

}
