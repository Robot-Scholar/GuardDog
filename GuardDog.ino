/********************************************************************
  Guard Dog - Make an audible beep when someone enters the range.
  Author - Eric Ryan Harrison <me@ericharrison.info>
  http://github.com/

  Originally Taken from:

  https://www.arduino.cc/en/Tutorial/ToneMelody?action=sourceblock&num=2
********************************************************************/

#include "Pitches.h"

/************************/

/** PIN CONFIGURATIONS **/

/************************/

#define led 13
#define buzzer 3
#define echoPin A0
#define pingPin 10

// roughly 2.6 feet
#define detectionDistance 80 

void setup() {
  //Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  delay(50);
  // See if an object is in front of us
  int distance = msToCm(ping());
    
  //Serial.println(distance);
  if ( distance < detectionDistance ) {
    // get a random song
    playNote(NOTE_G5, 100, .1);
  }
}
 
/**********************/

/** Helper Functions **/

/**********************/
// Note-playing buzzer helper function.
void playNote(int note, int duration, float rest) {
  digitalWrite(led, HIGH);
  tone(buzzer, note, duration);
  delay((duration * rest)/2);
  digitalWrite(led, LOW);
  delay((duration * rest)/2);
}

// Helper function to manage our ultrasonic sensor.
long ping() {
  
  long duration;
  
  // clear ping pin
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  return duration;
}

// Helper function to return the distance to an object
// detected by the ultrasonic sensor in centimeters.
long msToCm(long microseconds) {
  return microseconds * .034 / 2;
}

void blink(int blinks) {
    for ( int i = 0; i <= blinks; i++ ) {
        digitalWrite(led, HIGH);
        delay(250);
        digitalWrite(led, LOW);
        delay(250);
    }
}
