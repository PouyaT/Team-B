#ifndef ANALOGDEVICE_H
#define ANALOGDEVICE_H
#include <Arduino.h>

class AnalogDevice
{
 public:
  AnalogDevice(int pinNum);
  AnalogDevice();
  virtual ~AnalogDevice();
  int read();
  void write(int value);
  
 protected:
  int pin;
};

#endif // ANALOGDEVICE_H
