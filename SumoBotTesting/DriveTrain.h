#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

#define left1 10
#define right1 5
#define left2 11
#define right2 6

#include <Arduino.h>

class DriveTrain {
	enum direction {
		forward,
		backward,
		idle
	};
	private:
		float coerce(float value);
	public:
		DriveTrain();
		void setRawOutput(float left, float right);
		void spin();
};

#endif