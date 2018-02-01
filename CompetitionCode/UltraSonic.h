#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include <Arduino.h>

class UltraSonic{
public:
  UltraSonic(int echoNumber, int trigNumber);
  UltraSonic();
  double microSecondsToCentimeter(double time);
  double cm;
  double microseconds;
  double ping();
  int echoPin;
  int trigPin;
  int setEchoPin(int pinNumber);
  int setTrigPin(int pinNumber);
};


#endif
