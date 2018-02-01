#include "UltraSonic.h"
#include "DriveTrain.h"
#include "DigitalDevice.h"
#include "AnalogDevice.h"

#define U1_PIN 1
#define U2_PIN 2
#define U3_PIN 3
#define U4_PIN 4

#define ML1_PIN 5
#define ML2_PIN 6
#define MR1_PIN 7
#define MR2_PIN 8

#define DISABLED 0
#define ENABLED 1

DriveTrain driveTrain = DriveTrain(ML1_PIN, ML2_PIN, MR1_PIN, MR2_PIN) ;
UltraSonic upFront(U1_PIN);
UltraSonic upBack(U2_PIN);
UltraSonic downFront(U3_PIN);
UltraSonic downBack(U4_PIN);


void setup()
{

}

void loop()
{
	
}
