#include "UltraSonic.h"

// Constructor
UltraSonic::UltraSonic(int masterPin)
{
  _masterPin = masterPin;
  _microseconds = 0;
  _cm = 0;
}

// Default Constructor
UltraSonic::UltraSonic()
{
  _masterPin = -1;
  _microseconds = 0;
  _cm = 0;
}

// Destructor
UltraSonic::~UltraSonic()
{

}

// Converts microseconds to centimers, used in ping()
void UltraSonic::microSecondsToCentimeters()
{
  _cm = _microseconds / 58;
}

// Uses the sensors to find the other robot
// returns range in cm
double UltraSonic::ping()
{
  pinMode(_masterPin,OUTPUT);
  digitalWrite(_masterPin, LOW);
  delayMicroseconds(10);
  digitalWrite(_masterPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_masterPin, LOW);


  _microseconds = pulseIn(_masterPin, HIGH);
  microSecondsToCentimeters();
  delay(10);
  return _cm;
}

// sets the master pin
void UltraSonic::setMasterPin(int masterPin)
{
  _masterPin = masterPin;
}

// returns the master pin
int UltraSonic::getMasterPin()
{
  return _masterPin;
}
