/*
 * represents the robot motors
 */

#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

#include <Arduino.h>

class DriveTrain {
  enum direction {
    forward,
    backward,
    idle
  };
 private:
  float coerce(float value);
	
 protected:
  int _left1;
  int _left2;
  int _right1;
  int _right2;

 public:
  DriveTrain();
  DriveTrain(int left1, int left2, int right1, int right2);
  void setRawOutput(float left, float right);
  void rotation(int deg);
  void ultimate();
};

#endif
