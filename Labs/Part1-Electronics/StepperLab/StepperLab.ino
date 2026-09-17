#include <Stepper.h>

//const int stepsPerRevolution = 2048;  // 32 steps * 64:1 gearhead
const int stepsPerRevolution = 2048;  // Tell a lie for now!
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Order is important!

void setup() {
  // myStepper.setSpeed(5); // For later
  // set the speed at 1 rpm:
  myStepper.setSpeed(5);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  // step one revolution  in one direction:
  //myStepper.step(stepsPerRevolution);
  //delay(500);

  // step one revolution in the other direction:
  //myStepper.step(-stepsPerRevolution);
  //delay(500);

  if (!digitalRead(2)) {
    step90(1);
  }
  if (!digitalRead(3)) {
    step90(-1);
  }
}

void step90(int n) {
  myStepper.step(n * stepsPerRevolution/4);
  delay(500);
}