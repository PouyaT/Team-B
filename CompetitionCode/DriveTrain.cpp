#include "DriveTrain.h"

#define DEF_MOTPIN -1

// Default Constructor: initializes 4 motor pins,
// 2 for each motor
DriveTrain::DriveTrain() {
	pinMode(DEF_MOTPIN, OUTPUT);
}

// Constructor for directly assigning the pins, this should be the
// one that is called
DriveTrain::DriveTrain(int left1, int left2, int right1, int right2)
{
  _left1 = left1;
  _left2 = left2;
  _right1 = right1;
  _right2 = right2;

  pinMode(_left1, OUTPUT);
  pinMode(_left2, OUTPUT);
  pinMode(_right1, OUTPUT);
  pinMode(_right2, OUTPUT);
}

// gives the magnitude of "value," from 0-1
float DriveTrain::coerce(float value) {
	if(abs(value) > 1.0) {
		return 1.0;
	}
	else {
		return abs(value);
	}
}

// takes in right and left wheel inputs, decides the
// direction of the wheel based on sign, and uses
// coerce to determine the magnitude
void DriveTrain::setRawOutput(float left, float right) {
	
	direction leftDirection = idle;
	leftDirection = left > 0 ? forward : leftDirection;
	leftDirection = left < 0 ? backward : leftDirection;
	
	direction rightDirection = idle;
	rightDirection = right > 0 ? forward : rightDirection;
	rightDirection = right < 0 ? backward : rightDirection;
	
	left = coerce(left) * 255;
	right = coerce(right) * 255;

	if ( leftDirection == forward ) {
	  analogWrite( _left1, left );
	  analogWrite( _left2, 0 );
	}
	else if ( leftDirection == backward ) {
	  analogWrite( _left2, left);
	  analogWrite( _left1, 0);
	}
	else {
	  analogWrite ( _left2, 0 );
	  analogWrite ( _left1, 0);
	}
	
	if ( rightDirection == forward ) {
	  analogWrite( _right1, right );
	  analogWrite( _right2, 0 );
	}
	else if ( rightDirection == backward ) {
	  analogWrite( _right2, right );
	  analogWrite( _right1, 0 );
	}
	else {
	  analogWrite( _right2, 0 );
	  analogWrite( _right1, 0 );
	}
}

// to rotate bot
void DriveTrain::rotation(int deg) {
  
  // figure out raw output strength/length for rotations

}

// the ultimate move
void DriveTrain::ultimate() {
  
}
