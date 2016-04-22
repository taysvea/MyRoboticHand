#include <Servo.h>

//thumb button pin
const int buttonPin1 = 2;

//index button pin
const int buttonPin2 = 3;

//majure button pin
const int buttonPin3 = 4;
//

//ring button pin
const int buttonPin4 = 5;

//pinky button pin
const int buttonPin5 = 6;

//all button pin
const int buttonPin6 = 7;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;

//Assigns the servos
Servo servothumb;
Servo servoindex;
Servo servomajure;
Servo servoring;
Servo servopinky;

//Position open
int posthumb = 180;
int posindex = 180;
int posmajure = 180;
int posring = 180;
int pospinky = 180;
int posall = 180;

//Time
long tthumb = 0;
long tindex = 0;
long tmajure = 0;
long tring = 0;
long tpinky = 0;
long tall = 0;

void setup() {

  servothumb.attach(9);  // The number value changes the pins.

  servoindex.attach(10);

  servomajure.attach(11);

  servoring.attach(12);

  servopinky.attach(13);


  servothumb.write(posthumb);
  servoindex.write(posindex);
  servomajure.write(posmajure);
  servoring.write(posring);
  servopinky.write(pospinky);

  //thumb
  pinMode(buttonPin1, INPUT_PULLUP);

  //index
  pinMode(buttonPin2, INPUT_PULLUP);

  //majure
  pinMode(buttonPin3, INPUT_PULLUP);

  //ring
  pinMode(buttonPin4, INPUT_PULLUP);

  //pinky
  pinMode(buttonPin5, INPUT_PULLUP);

  //all
  pinMode(buttonPin6, INPUT_PULLUP);

  delay(1000);
}

void loop() {
  long now = millis();

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);

  //Thumb
  if (buttonState1 == LOW && now - tthumb > 1000) {
    if (posthumb > 0) {
      posthumb = 0;
    }
    else {
      posthumb = 180;
    }
    servothumb.write(posthumb);
    tthumb = now;
  }


  //Index

  if (buttonState2 == LOW && now - tindex > 1000) {
    if (posindex > 0) {
      posindex = 0;
    }
    else {
      posindex = 180;
    }
    servoindex.write(posindex);
    tindex = now;
  }

  //Majure

  if (buttonState3 == LOW && now - tmajure > 1000) {
    if (posmajure > 0) {
      posmajure = 0;
    }
    else {
      posmajure = 180;
    }
    servomajure.write(posmajure);
    tmajure = now;
  }

  //Ring

  if (buttonState4 == LOW && now - tring > 1000) {
    if (posring > 0) {
      posring = 0;
    }
    else {
      posring = 180;
    }
    servoring.write(posring);
    tring = now;
  }

  //Pinky

  if (buttonState5 == LOW && now - tpinky > 1000) {
    if (pospinky > 0) {
      pospinky = 0;
    }
    else {
      pospinky = 180;
    }
    servopinky.write(pospinky);
    tpinky = now;
  }

  //all
  if (buttonState6 == LOW && now - tall > 1000) {
    if (posall > 0) {
      posall = 0;
    }
    else {
      posall = 180;
    }
    servothumb.write(posall);
    servoindex.write(posall);
    servomajure.write(posall);
    servoring.write(posall);
    servopinky.write(posall);
    
    tall = now;
  }
}

