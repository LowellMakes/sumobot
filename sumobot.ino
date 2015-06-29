#include <Servo.h>

#include <NewPing.h>

#define TRIGGER_PIN  A2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


Servo rightWheel;  // create servo object to control a servo
// twelve servo objects can be created on most boards

Servo leftWheel;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup()
{
	Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
	leftWheel.attach(A0);  // attaches the servo on pin A0 to the servo object
	rightWheel.attach(A1);
}

void loop()
{
	int d = sonar.ping_cm();
	
	Serial.print("Ping: ");
	Serial.print(d); // Send ping, get distance in cm and print result (0 = outside set distance range)
	Serial.println("cm");


	// If don't see opponent, spin to seek
	if(d > 39 || d == 0){
		leftWheel.write(180);
		rightWheel.write(180);
	}
	// Otherwise attack!
	else {
		leftWheel.write(180);
		rightWheel.write(0);
	}

	delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

}
