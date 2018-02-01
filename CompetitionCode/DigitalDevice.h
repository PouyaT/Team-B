/*
 * Represents a digital device. Could use an int* array for
 * more pins. Default sets pin to -1, which could cause
 * arduino error, idk
 */

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
