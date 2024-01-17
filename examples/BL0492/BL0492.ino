#include "BL0492.h"

// Choose one of the following based on your hardware setup
// HardwareSerial
BL0492 bl0492(Serial);

// SoftwareSerial
// #include <SoftwareSerial.h>
// SoftwareSerial mySerial(10, 11); // RX, TX
// BL0492 bl0492(mySerial);

void setup() {
  Serial.begin(9600);
  bl0492.begin();
}

void loop() {
  bl0492.sendCommand();
  bl0492.blDelay(1000);
  bl0492.encodeData();
  // Other logic or functions can be added here
}
