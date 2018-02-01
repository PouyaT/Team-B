/*
 * Represents an analog device. Right now only has one
 * pin field, which honestly isn't much more useful than
 * doing a plain analogRead(). Would be more useful if
 * the field was an int* array of pins, to represent an
 * analog device with an arbitrary number of pins
 *
 * Default sets pin to -1, which could cause arduino error, idk
 */


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
