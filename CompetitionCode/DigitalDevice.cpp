#include "DigitalDevice.h"

DigitalDevice::DigitalDevice(int pinNum)
{
    pin = pinNum;

}

DigitalDevice::DigitalDevice()
{
  pin = -1;
}

DigitalDevice::~DigitalDevice()
{

}

int DigitalDevice::read()
{
    return digitalRead(pin);
}

void DigitalDevice::write(int value)
{
  return digitalWrite(pin, value);
}
