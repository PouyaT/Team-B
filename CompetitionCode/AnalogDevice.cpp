#include "AnalogDevice.h"

AnalogDevice::AnalogDevice(int pinNum)
{
    pin = pinNum;

}

AnalogDevice::~AnalogDevice()
{
    delete pin;
}

int AnalogDevice::read(int readPin)
{
    return analogRead(readPin);
}

void AnalogDevice::write(int writePin, int value)
{
    return analogWrite(value);
}
