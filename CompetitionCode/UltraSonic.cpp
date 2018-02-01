#include "UltraSonic.h"

double UltraSonic::ping()
{
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
	
	
  pinMode(echoPin, INPUT);
  time = pulseIn(echoPin, HIGH);
  cm = microSecondsToCentimeters(time);
  delay(10);
  return cm;
}
UltraSonic::UltraSonic(int echoNumber, int trigNumber)
{
	this->echoPin = echoNumber;
	this->trigPin = trigNumber;
}
UltraSonic::UltraSonic()
{
  this->echoPin = -1;
  this->trigPin = -1;
}

Ultrasonic::~UltraSonic()
{

}

double UltraSonic::microSecondsToCentimeters(double microseconds)
{
  double cent;	
  cent = microseconds / 58;
  return cent;
}

void UltraSonic::setEchoPin(int pinNumber)
{
  this->echoPin = pinNumber;
}

void UltraSonic::setTrigPin(int pinNumber) 
{
  this->trigPin = trigPin
}

int UltraSonic::getEchoPin()
{
  return echoPin;
}

int UltraSonic::getTrigPin()
{
  return trigPin;
}
