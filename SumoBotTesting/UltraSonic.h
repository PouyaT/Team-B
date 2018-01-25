#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#inlcude <Arduino.h>

class UltraSonic{
	public:
		UltraSonic(int pinNumber);
		UltraSonic();
		double microSecondsToCentimeter(double time);
		double cm;
		double microseconds;
		double ping();
		int setPin(int pinNumber);
};


#endif