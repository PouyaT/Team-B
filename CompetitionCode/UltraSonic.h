/*
 * Sensor class for robot. Master pin is used for both triggering
 * and receiving from the sensor, since they will never be going at the same time.
 * 
 * Use the ping() method to rangefind, only useful method for interacting objects
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include <Arduino.h>

class UltraSonic{
 protected:
  double _cm;
  double _microseconds;
  int _masterPin;
public:
  UltraSonic(int masterPin);
  UltraSonic();
  virtual ~UltraSonic();
  void microSecondsToCentimeters();
  double ping();
  void setMasterPin(int pinNumber);
  int getMasterPin();
};


#endif
