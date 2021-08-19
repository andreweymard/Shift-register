int latchPin = 2;
int dataPin = 3;
int clockPin = 4;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    shiftDataOut(i);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    digitalWrite(latchPin, LOW);
  }
}

void shiftDataOut(byte dataOut) {
  boolean pinState;
  for (int i=0; i<=3; i++) { 
    if ( dataOut & (1<<i) ) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    delay(1000);
    digitalWrite(clockPin, LOW); 
    delay(1000);
  }
  digitalWrite(clockPin, LOW); 
}
