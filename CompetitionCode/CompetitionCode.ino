/* pseudocode for attack state machine
*******************************
* (1) Sense
*     -> If nothing, (2) Search
*     -> If front sensor, (3) Charge
* (2) Search
*     -> Rotate to get different sensor position, then (1) Sense
* (3) Charge
*     -> Full motor forward until timeout, then (1) Sense
*/

#include "UltraSonic.h"
#include "DriveTrain.h"
#include "DigitalDevice.h"
#include "AnalogDevice.h"

#define U1_PIN 1

#define ML1_PIN 5
#define ML2_PIN 6
#define MR1_PIN 7
#define MR2_PIN 8

const int MIN_DISTANCE =  80;

#define DISABLED 0
#define ENABLED 1

DriveTrain driveTrain = DriveTrain(ML1_PIN, ML2_PIN, MR1_PIN, MR2_PIN) ;
UltraSonic front(U1_PIN);

int state = 1;

void setup()
{
	
}

void loop()
{
  attack(state, driveTrain, front);
}

// attack code
/********************/

//done
void attack(int state, DriveTrain driveTrain, UltraSonic front) {
  switch (state) {
  case 1:
    state = search(driveTrain, front);
    break;
  case 2:
    state = charge(driveTrain, front);
  default:
    break;
  }
}


// Rotates a certain amount, then hands control back to sensor
// Will probably need to implement a search pattern in an independent array
// Not done
int search(DriveTrain driveTrain, UltraSonic front)
{
	driveTrain.setRawOutput(1,-1);
  
	while ( front.ping() > MIN_DISTANCE ) {
  
	}
  
  return 2;
}

// charges forward to push opponent off
// Done
int charge(DriveTrain driveTrain, UltraSonic front) {
  
  driveTrain.setRawOutput(1,1);
  
  while ( front.ping() <= MIN_DISTANCE ) 
  {

  }

  driveTrain.setRawOutput(0,0);

  return 1;
}
