#include "BL0492.h"

BL0492::BL0492(HardwareSerial& serial) : hardwareSerial(&serial), softwareSerial(nullptr) {}

BL0492::BL0492(SoftwareSerial& serial) : hardwareSerial(nullptr), softwareSerial(&serial) {}

void BL0492::begin() {
  if (hardwareSerial) {
    hardwareSerial->begin(4800, SERIAL_8N1);
  } else if (softwareSerial) { 
    softwareSerial->begin(4800, SERIAL_8N1);
  }
}

void BL0492::sendCommand() {
  if (hardwareSerial) {
    hardwareSerial->write(BL0429_FRAME_HEAD);
    hardwareSerial->write(BL0429_COMMAND);
    hardwareSerial->flush();
  } else if (softwareSerial) {
    // Handle software serial send command
  }
}

// Other member function implementations...

