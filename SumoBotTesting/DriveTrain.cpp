#include "DriveTrain.h"

DriveTrain::DriveTrain() {
	pinMode(left1, OUTPUT);
	pinMode(left2, OUTPUT);
	pinMode(right1, OUTPUT);
	pinMode(right2, OUTPUT);
}

float DriveTrain::coerce(float value) {
	if(abs(value) > 1.0) {
		return 1.0;
	}
	else {
		return abs(value);
	}
}

void DriveTrain::setRawOutput(float left, float right) {
	
	direction leftDirection = idle;
	leftDirection = left > 0 ? forward : leftDirection;
	leftDirection = left < 0 ? backward : leftDirection;
	
	direction rightDirection = idle;
	rightDirection = right > 0 ? forward : rightDirection;
	rightDirection = right < 0 ? backward : rightDirection;
	
	left = coerce(left) * 255;
	right = coerce(right) * 255;


}

void DriveTrain::spin() {

}