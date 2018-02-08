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
#define U2_PIN 2
#define U3_PIN 3
#define U4_PIN 4

#define ML1_PIN 5
#define ML2_PIN 6
#define MR1_PIN 7
#define MR2_PIN 8

#define MIN_DISTANCE 80

#define DISABLED 0
#define ENABLED 1

DriveTrain driveTrain = DriveTrain(ML1_PIN, ML2_PIN, MR1_PIN, MR2_PIN) ;
UltraSonic front(U1_PIN);
UltraSonic back(U2_PIN);
UltraSonic left(U3_PIN);
UltraSonic right(U4_PIN);

int state = 1;
int sensors [4];

void setup()
{
	
}

void loop()
{
  attack(state);
}

// attack code
/********************/

//done
void attack(int state) {
  switch (state) {
  case 1:
    state = sense(front);
    break;
  case 2:
    state = search(driveTrain);
    break;
  case 3:
    state = charge(driveTrain, front);
    break;
  default:
    break;
  }
}

// senses stuff
// done
int sense(UltraSonic front) {
  sensors[0] = front.ping();
  
  if (sensors[0] < MIN_DISTANCE) {
    return 3;
  else {
    return 2;
  }	 
}

// Rotates a certain amount, then hands control back to sensor
// Will probably need to implement a search pattern in an independent array
// Not done
int search(DriveTrain driveTrain)
{
	driveTrain.setRawOutput(1,-1);
  // call rotation method
	
  
  return 1;
}

// charges forward to push opponent off
// Done
int charge(DriveTrain driveTrain, UltraSonic front) {
  
  driveTrain.setRawOutput(1,1);
  
  while ( front.ping() < MIN_DISTANCE ) 
  {

  }

  driveTrain.setRawOutput(0,0);

  return 1;
}
