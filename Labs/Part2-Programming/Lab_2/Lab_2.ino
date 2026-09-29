int speedCount = 0;
int buttonState = 1;
int lastButtonState = 0;

void setup() {
  pinMode(13, OUTPUT); // DP (for later)
  pinMode(12, OUTPUT); // G
  pinMode(11, OUTPUT); // F
  pinMode(10, OUTPUT); // E
  pinMode(9, OUTPUT); // D
  pinMode(8, OUTPUT); // C
  pinMode(7, OUTPUT); // B
  pinMode(6, OUTPUT); // A
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  set7SegmentValue(speedCount);
}

void set7SegmentValue(uint8_t value) {
  switch (value) {
    case 0:
      digitalWrite7Segment(1, 1, 1, 1, 1, 1, 0);
      break;
    case 1:
      digitalWrite7Segment(0, 1, 1, 0, 0, 0, 0); // 0 is LOW, 1 is HIGH
      break;
    case 2:
      digitalWrite7Segment(1, 1, 0, 1, 1, 0, 1);
      break;
    case 3:
      digitalWrite7Segment(1, 1, 1, 1, 0, 0, 1);
      break;
    case 4:
      digitalWrite7Segment(0, 1, 1, 0, 0, 1, 1);
      break;
    case 5:
      digitalWrite7Segment(1, 0, 1, 1, 0, 1, 1);
      break;
    case 6:
      digitalWrite7Segment(1, 0, 1, 1, 1, 1, 1);
      break;
    case 7:
      digitalWrite7Segment(1, 1, 1, 0, 0, 0, 0);
      break;
    case 8:
      digitalWrite7Segment(1, 1, 1, 1, 1, 1, 1);
      break;
    case 9:
      digitalWrite7Segment(1, 1, 1, 1, 0, 1, 1);
      break;
    case 10:
      digitalWrite7Segment(1, 1, 1, 0, 1, 1, 1); // A (A = 10 in hex)
      break;
    default:
      digitalWrite7Segment(0, 0, 0, 0, 0, 0, 0);
      break;

    }
  }


void digitalWrite7Segment(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g) {
  digitalWrite(6, a);
  digitalWrite(7, b);
  digitalWrite(8, c);
  digitalWrite(9, d);
  digitalWrite(10, e);
  digitalWrite(11, f);
  digitalWrite(12, g);
}


void loop() {
  buttonState = digitalRead(2);
  if (speedCount < 5) {    
    if (buttonState != lastButtonState) {
      if (buttonState == 0) { 
        speedCount++;
        set7SegmentValue(speedCount);
      }
    delay(50);
    lastButtonState = buttonState;
    } 
  }
  if (digitalRead(4) == 0) {
      speedCount = 0;
      set7SegmentValue(speedCount);
  }
}
