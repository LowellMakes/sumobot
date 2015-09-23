// Sumobot.ino
// Super simple Sumobot starter code
// Written by Brian Bailey
// brian@bunedoggle.com
// This code released under a Beerware license
// free for all to use, modify and share

/*******************************************************
* Include statements - include extra code we need
*******************************************************/
// This line includes the code we need to control servos
#include <Servo.h>
// This line includes the code we need to use the ultrasonic range finder
#include <NewPing.h>

/*******************************************************
* Define statements - Define constants we will use later
*******************************************************/
#define TRIGGER_PIN  A2      // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A3      // Arduino pin tied to echo pin on the ultrasonic sensor.
#define LEFT_WHEEL_PIN  A0   // Arduino pin tied to the left servo wheel motor
#define RIGHT_WHEEL_PIN A1   // Arduino pin tied to the right servo wheel motor
#define FLIPPER_PIN A4       // Flipper pin
#define MAX_DISTANCE 200     // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define FRONT_EDGE_SENSOR 3  // Pin connected to the front edge IR sensor
#define REAR_EDGE_SENSOR 2   // Pin connected to the rear edge IR sensor
#define LIGHT_COLOR_VALUE 2900 // This is a value returned from the edge sensors when they see a lighter color, may need tweaking

/********************************************************
* Class object instances - These will help us control the
* sensors and motors.
********************************************************/
// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Servo motor control objects
// Up to twelve servo objects can be created and controlled
Servo rightWheel;
Servo leftWheel;
Servo flipper;

/********************************************************
* Setup code runs one time at the very beginning after we
* power up (or reset)
********************************************************/
void setup()
{
	// Open serial monitor so we can print out debug information
	// When connected to a USB port
	Serial.begin(115200);
	
	// Tell the servo objects which pins the servos are connected to
	leftWheel.attach(LEFT_WHEEL_PIN);
	rightWheel.attach(RIGHT_WHEEL_PIN);
	flipper.attach(FLIPPER_PIN);

	flipper.write(0);
	
	leftWheel.write(180);
	rightWheel.write(0);
	delay(300);
	
}

/********************************************************
* Loop code runs over and over, forever while powered on
********************************************************/
void loop()
{
	// Variables we will need in the loop code
	int distInCentimeters;  // We'll store the ultrasonic range distance here
	int frontEdgeValue;     // This will be a reading from the IR edge sensor in the front
	int rearEdgeValue;      // This will be a reading from the IR edge sensor in the back
	

	/*******************************
	* IR Edge finder code
	********************************/
	// Check front and back edge sensors for edge of the ring
	// Lower numbers mean more reflective colors
	// 3000 or more means nothing was reflected.
	frontEdgeValue = readQD(FRONT_EDGE_SENSOR);
	// Print front edge value for debug
	Serial.print("Front Edge: ");
	Serial.println(frontEdgeValue);
	// Less than 1000 means we see white-ish
	// This number can be tweaked if the IR sensor is closer to the ground
	if(frontEdgeValue > LIGHT_COLOR_VALUE)
	{
		// Better back up!!
		leftWheel.write(180);
		rightWheel.write(0);
		delay(1000);
	}
	// Now check the back edge
	int backEdgeValue = readQD(REAR_EDGE_SENSOR);
	Serial.print("Back Edge: ");
	Serial.println(backEdgeValue);
	if(backEdgeValue > LIGHT_COLOR_VALUE)
	{
		// Better go forward!!
		leftWheel.write(0);
		rightWheel.write(180);
		delay(1000);
	}

	/*******************************
	* Ultrasonic Range Finder Code
	********************************/
	// This code takes a distance reading from the range finder
	distInCentimeters = sonar.ping_cm();

	// Print distance for debug (0 = outside set distance range)
	Serial.print("Ping: ");
	Serial.print(distInCentimeters);
	Serial.println("cm");

	// Flip time?
	if(distInCentimeters <= 5 && distInCentimeters != 0)
	{
		leftWheel.write(0);
		rightWheel.write(180);
		flipper.write(180);
	}
	// If don't see opponent, spin to look around
	else if(distInCentimeters > 39 || distInCentimeters == 0){
		leftWheel.write(180);
		rightWheel.write(180);
		flipper.write(0);
	}
	// Otherwise attack!
	else {
		leftWheel.write(0);
		rightWheel.write(180);
		flipper.write(0);
	}
	
	delay(50);
}



int readQD(int pin){
	//Returns value from the QRE1113
	//Lower numbers mean more refleacive
	//More than 3000 means nothing was reflected.
	pinMode( pin, OUTPUT );
	digitalWrite( pin, HIGH );
	delayMicroseconds(10);
	pinMode( pin, INPUT );

	long time = micros();

	//time how long the input is HIGH, but quit after 3ms as nothing happens after that
	while (digitalRead(pin) == HIGH && micros() - time < 3000);
	int diff = micros() - time;

	return diff;
}