void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (digitalRead(2) == LOW){
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4,LOW);
  }
  if (digitalRead(3) == LOW){
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5,LOW);
  }  
  //Resistor size 620 Ohms connected to NPN transistor Base
  if (digitalRead(2) == LOW){
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12,LOW);
  }
  if (digitalRead(3) == LOW){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13,LOW);
  }  
  analogWrite(6, analogRead(0)/4);
  analogWrite(11, analogRead(0)/4);
  
  delay(10);
 
}