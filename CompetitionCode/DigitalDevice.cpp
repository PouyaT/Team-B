#include "DigitalDevice.h"

// Constructor
DigitalDevice::DigitalDevice(int pinNum)
{
    pin = pinNum;

}

// Default Constructor
DigitalDevice::DigitalDevice()
{
  pin = -1;
}

// Destructor
DigitalDevice::~DigitalDevice()
{

}

// Reads the pin
int DigitalDevice::read()
{
    return digitalRead(pin);
}

// Writes the pin
void DigitalDevice::write(int value)
{
  return digitalWrite(pin, value);
}
