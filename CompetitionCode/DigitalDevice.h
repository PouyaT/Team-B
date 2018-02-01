#ifndef DIGITALDEVICE_H
#define DIGITALDEVICE_H
#include <Arduino.h>

class DigitalDevice
{
 public:
  DigitalDevice(int pinNum);
  DigitalDevice();
  virtual ~DigitalDevice();
  int read();
  void write(int value);

 protected:
  int pin;
};

#endif // DIGITALDEVICE_H
