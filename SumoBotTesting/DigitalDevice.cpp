#include "DigitalDevice.h"
#include <Arduino.h>

DigitalDevice::DigitalDevice(int pinNum)
{
    pin = pinNum;

}

DigitalDevice::~DigitalDevice()
{
    delete pin;
}

int DigitalDevice::read(int readPin)
{
    return digitalRead(readPin);
}

void DigitalDevice::write(int writePin, int value)
{
    return digitalWrite(value);
}
