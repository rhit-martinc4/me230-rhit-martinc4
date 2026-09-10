void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, INPUT_PULLUP);
}

void loop()
{
  /*
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  */
  
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  
  if (digitalRead(5) == LOW) {
    digitalWrite(10, LOW);
  	digitalWrite(9, LOW);
  	digitalWrite(8, HIGH);
    	delay(1500);
    
    digitalWrite(10, LOW);
  	digitalWrite(9, HIGH);
  	digitalWrite(8, LOW);
    	delay(1000);
  }
}