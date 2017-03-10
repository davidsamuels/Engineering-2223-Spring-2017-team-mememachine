#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

/* 
 *  goals reverse when front sensor gets too close to wall
 *  turn away from walls when they get too close
 *  ex turn right when the wall on the left side gets too close
 *  
*/

// works best with blue ultrasenoic sensor

RedBotMotors motors;
float distf, distr, distl, distb;
void setup() {
  // put your setup code here, to run once:
#define trigPinf 10 //we can use one echo sensor with one pin from the board 
#define echoPinf 10
#define echoPinr 9
#define trigPinr 9
#define trigPinl 3
#define echoPinl 3

  Serial.begin(9600);


}

void loop() {

  motors.drive(100);
  if ( 11.0 < distancefront() && distancefront() < 15.0) {
    motors.drive(-99);
  }

  else if ( distancefront() > 15.0) {
    motors.drive(100);
  }
  else if ( distancefront() < 11.0) {
    motors.drive(-100);
  }

  if (distanceright() < 20) {
    motors.leftMotor(99);
    motors.rightMotor(99);
  }
  else if (distanceright() > 10)
    motors.stop();
}


float distancefront() {
  long durationf, distancef;
  pinMode(trigPinf, OUTPUT);
  digitalWrite(trigPinf, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinf, HIGH);
  pinMode(echoPinf,  INPUT);
  delayMicroseconds(10);
  digitalWrite(trigPinf, LOW);
  pinMode(echoPinf,  INPUT);
  durationf = pulseIn(echoPinf, HIGH);
  distancef = (durationf / 2) / 29.1; // THIS IS IN centimeters!
  Serial.print(distancef);
  Serial.println("distance front cm ");
  Serial.println(" ");//nlt
  delay(10);
  return distancef;

}

float distanceleft() {
  long durationl, distancel;
  pinMode(trigPinl, OUTPUT);
  digitalWrite(trigPinl, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinl, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinl, LOW);
  pinMode(echoPinl,  INPUT);
  durationl = pulseIn(echoPinl, HIGH);
  distancel = (durationl / 2) / 29.1; // THIS IS IN centimeters!
  Serial.print(distancel);
  Serial.println("distance left cm ");
  Serial.println(" ");//nlt
  delay(10);
  return distancel;

}


float distanceright() {
  long durationr, distancer;
  pinMode(trigPinr, OUTPUT);
  digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  pinMode(echoPinr,  INPUT);
  durationr = pulseIn(echoPinr, HIGH);
  distancer = (durationr / 2) / 29.1; // THIS IS IN centimeters!
  Serial.print(distancer);
  Serial.println("distance right cm ");
  Serial.println(" ");//nlt
  delay(10);
  return distancer;

}

/*float distanceback() {
  long durationb, distanceb;

  digitalWrite(trigPinb, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinb, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinb, LOW);
  durationb = pulseIn(echoPinb, HIGH);
  distanceb = (durationb / 2) / 29.1; // THIS IS IN centimeters!
  Serial.print(distanceb);
  Serial.println("distance front cm ");
  Serial.println(" ");//nlt
  delay(50);
  return distanceb;
  if ( distance < 15) {
  motors.stop();
  }
*/



