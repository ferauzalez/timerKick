void setup() {
  Serial.begin(9600);

  pinMode(PIN_LATCH  , OUTPUT);
  pinMode(PIN_CLOCK  , OUTPUT);
  pinMode(PIN_DATA   , OUTPUT);
  pinMode(PIN_SECONDS, OUTPUT);

  determineGroupOfTransitions();
}

void loop() {
  currentMillis = millis();

  if ((colonMode == 2) and (currentMillis - lastTimeColonStatusBlink >= 100 * INTERVAL)) {
    lastTimeColonStatusBlink = currentMillis;

    if (colonStatus == HIGH){
      colonStatus = LOW;
    } else {
      colonStatus = HIGH;
    }
    
    digitalWrite(PIN_SECONDS, colonStatus);
  }
}