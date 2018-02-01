#include "AnalogDevice.h"

AnalogDevice::AnalogDevice(int pinNum)
{
    pin = pinNum;
}

AnalogDevice::AnalogDevice()
{
  pin = -1;
}

AnalogDevice::~AnalogDevice()
{

}

int AnalogDevice::read()
{
  return analogRead(pin);
}

void AnalogDevice::write(int value)
{
  analogWrite(pin, value);
}
