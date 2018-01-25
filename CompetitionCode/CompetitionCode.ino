#include "UltraSonic.h"
#include "DriveTrain.h"

#define U1_PIN 1
#define U2_PIN 2
#define U3_PIN 3
#define U4_PIN 4

#define DISABLED 0
#define ENABLED 1

DriveTrain driveTrain;
UltraSonic upFront(U1_PIN);
UltraSonic upBack(U2_PIN);
UltraSonic downFront(U3_PIN);
UltraSonic downBack(U4_PIN);

setup()
{

}

loop()
{
	
}