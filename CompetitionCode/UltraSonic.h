#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include <Arduino.h>

class UltraSonic{
 protected:
  double cm;
  double microseconds;
  int echoPin;
  int trigPin;
public:
  UltraSonic(int echoNumber, int trigNumber);
  UltraSonic();
  virtual ~UltraSonic();
  double microSecondsToCentimeter(double microseconds);
  double ping();
  void setEchoPin(int pinNumber);
  void setTrigPin(int pinNumber);
  int getEchoPin();
  int getTrigPin();
};


#endif
