#ifndef _BL0492_H_
#define _BL0492_H_

#include <Arduino.h>

struct ElectricData {
  uint32_t I_FAST_RMS;
  uint32_t I_RMS;
  uint32_t V_RMS;
  uint32_t WATT;
  uint32_t CF_CNT;
  uint32_t FREQ;
  uint32_t STATUS;
};

struct ElectricDataSend {
  double current;
  double volt;
  double active_power;
  double FQ;
  double kwh;
};

class BL0492 {
public:
  BL0492(HardwareSerial& serial);
  BL0492(SoftwareSerial& serial);
  void begin();
  void sendCommand();
  void blDelay(unsigned long ms);
  void encodeData();
  void clearSerial();
  void printElectricData(const ElectricData& electricData);

private:
  void convertToStruct(ElectricData& electricData);
  bool calculateChecksum();

  HardwareSerial* hardwareSerial;
  SoftwareSerial* softwareSerial;
};

#endif
