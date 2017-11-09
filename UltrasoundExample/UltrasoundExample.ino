#include <Servo.h>

//These are 2 continuous rotation servo motors. Don't actually use this for your drivetrain like I did
Servo motor1;
Servo motor2;  
                                               
//Ping AND Echo pin for Ultrasonic sensor
const int pingOut=7;

long valR, valL;
float r, l, f, b;//right, left, forward, backward path distances
long cm;//cm var
//long inch; //inch var
long time;

long ping(){
  
  //PING Function
  //Send Ping
  pinMode(pingOut, OUTPUT);
  digitalWrite(pingOut, LOW);
  delayMicroseconds(2);
  digitalWrite(pingOut, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingOut, LOW);
 
  //Get input and convert to distance
  pinMode(pingOut, INPUT);
  time=pulseIn(pingOut, HIGH);
  cm=microsecondsToCentimeters(time);
  //inch=microsecondsToInchess(time);
  //Finish loop, Set delay of .1 sec.
  
  delay(10);
  return cm;
}

//PING CONVERSION functions
/*long microsecondsToInches(long microseconds)
{
 
  return microseconds / 74 / 2;
}
*/
long microsecondsToCentimeters(long microseconds)
{   
    long micro;  
    micro=microseconds / 29 / 2;
    return micro;
}
//----------------------------------------------
//MOTOR FUNCTIONS
void straight()
{
	motor1.write(0);//straight
	motor2.write(180);
	delay(1000);
}

void right(){
	motor1.write(4);//right
	motor2.write(4);
	delay(1000);
}

void left(){
	motor1.write(178);//left
	motor2.write(178);
	delay(1000);
}

void back(){
	motor1.write(178);//backwards
	motor2.write(4);
	delay (1000);
}

void wait(){
	motor1.write(90);//turnaround?
	motor2.write(90);
	delay(3000);
}
//-----------------------------------

//SETUP
void setup(){
  //Start serial communication
  Serial.begin(9600);
  motor1.attach(10);//r
  motor2.attach(11);//l
}
//MAIN
void loop()
{
	//Drive straight
	straight();

	//PING Function. I think you can use ping() instead of this garbage
	//Send Ping
	pinMode(pingOut, OUTPUT);
	digitalWrite(pingOut, LOW);
	delayMicroseconds(2);
	digitalWrite(pingOut, HIGH);
	delayMicroseconds(5);
	digitalWrite(pingOut, LOW);
	
	//Get input and convert to distance
	pinMode(pingOut, INPUT);
	time=pulseIn(pingOut, HIGH);
	cm=microsecondsToCentimeters(time);
	//inch=microsecondsToInches(time);
	
	Serial.print(cm);//Tell user the distance
	Serial.println();
	
	delay(10);//Finish loop, Set delay of .1 sec.
	f=cm;
	//END PING function
  
	//We are close to a wall, so lets turn I guess?
	if(f<20)
	{
		//I think my strategy was to turn 360 degrees to find the best (most clear) path.
		//So basically it records the 4 distances and chooses the best one
		right();
		valR=ping();
		Serial.println("Right: ");
		Serial.print(valR );
		Serial.println();
		right();
		right();
		valL=ping();
		Serial.println("Left: ");
		Serial.print(valL );
		Serial.println();
  
		if (valL>valR){
		straight();
		}
		if (valL<valR){
			right();
			right();
		}
	}
}
