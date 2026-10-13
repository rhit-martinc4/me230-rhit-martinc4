//Uno 
/*
#define REG_DDR_PUSHBUTTON_PRINT DDRD
#define REG_PORT_PUSHBUTTON_PRINT PORTD 
#define REG_PIN_PUSHBUTTON_PRINT PIND 
#define BIT_PUSHBUTTON_PRINT 3 

#define REG_DDR_PUSHBUTTON_COUNT DDRD
#define REG_PORT_PUSHBUTTON_COUNT PORTD 
#define REG_PIN_PUSHBUTTON_COUNT PIND 
#define BIT_PUSHBUTTON_COUNT 2
*/

//Mega
#define REG_DDR_PUSHBUTTON_PRINT DDRE
#define REG_PORT_PUSHBUTTON_PRINT PORTE 
#define REG_PIN_PUSHBUTTON_PRINT PINE 
#define BIT_PUSHBUTTON_PRINT 5

#define REG_DDR_PUSHBUTTON_COUNT DDRE
#define REG_PORT_PUSHBUTTON_COUNT PORTE 
#define REG_PIN_PUSHBUTTON_COUNT PINE 
#define BIT_PUSHBUTTON_COUNT 4

volatile uint16_t isrCounter = 0;

volatile uint8_t mainEventFlags = 0;
#define PUSHBUTTON_FLAG 0x01
#define PUSHBUTTON_FLAG2 0x02
#define PUSHBUTTON_FLAG3 0x04
#define PUSHBUTTON_FLAG4 0x08
#define PUSHBUTTON_FLAG5 0x10
#define PUSHBUTTON_FLAG6 0x20


void setup() { 
  Serial.begin(9600);
  REG_DDR_PUSHBUTTON_PRINT &= ~_BV(BIT_PUSHBUTTON_PRINT);
  REG_DDR_PUSHBUTTON_COUNT &= ~_BV(BIT_PUSHBUTTON_COUNT);

  REG_PORT_PUSHBUTTON_PRINT |= _BV(BIT_PUSHBUTTON_PRINT);
  REG_PORT_PUSHBUTTON_COUNT |= _BV(BIT_PUSHBUTTON_COUNT);
  
  //Uno
  /*
  EIMSK |= _BV(INT0);
  EICRA |= _BV(ISC01);
  EICRA &= ~_BV(ISC00);
  */
  
  //Mega
  EIMSK |= _BV(INT4);
  EICRB |= _BV(ISC41);
  EICRB &= ~_BV(ISC40);
  
  sei();
}

void loop() { 
  if (bit_is_clear(REG_PIN_PUSHBUTTON_PRINT, BIT_PUSHBUTTON_PRINT)) {
    Serial.println(String("Counter = ") + isrCounter);
    delay(500);
  }
  if (mainEventFlags & PUSHBUTTON_FLAG) {
    delay(30);
    if (bit_is_clear(REG_PIN_PUSHBUTTON_COUNT, BIT_PUSHBUTTON_COUNT)) { 
      isrCounter++;
    }
    //isButtonPressed = 0;
    mainEventFlags &= ~PUSHBUTTON_FLAG;
  }
}

//Uno 
/*
  ISR(INT0_vect) {
  	isrCounter++;
}
*/

//Mega
  ISR(INT4_vect) {
    //isButtonPressed = 1;
    mainEventFlags |= PUSHBUTTON_FLAG;
}