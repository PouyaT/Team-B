#include "AnalogDevice.h"

// Constructor
AnalogDevice::AnalogDevice(int pinNum)
{
    pin = pinNum;
}

// Default Constructor
AnalogDevice::AnalogDevice()
{
  pin = -1;
}

// Destructor
AnalogDevice::~AnalogDevice()
{

}

// Reads analog pin
int AnalogDevice::read()
{
  return analogRead(pin);
}

// Writes analog pin
void AnalogDevice::write(int value)
{
  analogWrite(pin, value);
}
