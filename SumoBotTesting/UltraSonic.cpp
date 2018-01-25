#include "UltraSonic.h"

double UltraSonic::ping()
{
	pinMode(pin,OUTPUT);
	digitalWrite(pin, LOW);
	delayMicroseconds(10);
	digitalWrite(pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pin,LOW);
	
	
	pinMode(pin, INPUT);
	time = pulseIn(pin, HIGH);
	cm = microSecondsToCentimeters(time);
	delay(10);
	return cm;
}
UltraSonic::UltraSonic(int pinNumber)
{
	this->pin = pinNumber;
}
UltraSonic::UltraSonic()
{
	this-> pin = -1;
}

double UltraSonic::microSecondsToCentimeters(double microseconds)
{
	double cent;	
	cent = microseconds / 58;
	return cent;
}

int UltraSonic::setPin(int pinNumber)
{
	pin = pinNumber;	
}




