int latchPin = 8; 
int clockPin = 12; 
int dataPin = 11; 

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    shiftDataOut(i);
    digitalWrite(latchPin, LOW);
    delay(100);
    digitalWrite(latchPin, HIGH);
  }
}

void shiftDataOut(byte dataOut) {
  boolean pinState;
  for (int i=0; i<=7; i++) { 
    digitalWrite(clockPin, LOW); 
    if ( dataOut & (1<<i) ) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(clockPin, LOW); 
}
