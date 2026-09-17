#include <Servo.h>

int degrees;

Servo myservo; 

void setup(){
 pinMode(2, INPUT_PULLUP);
 pinMode(3, INPUT_PULLUP);
 myservo.attach(9);
 myservo.write(degrees);
}

void loop()
{
  if (!digitalRead(2)) {
    myservo.write(0);
  } else if (!digitalRead(3)) {
    myservo.write(180);
  } else {
    degrees = map(analogRead(0), 0, 1023, 0, 180);
    myservo.write(degrees);
  }
}
