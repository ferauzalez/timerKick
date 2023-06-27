void setup() {
  Serial.begin(9600);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_SECONDS, OUTPUT);

    // lo ejecuto una vez para que se establezca el estado de espera
}

void loop() {
  currentMillis = millis();

  if (currentMillis - previousMillis >= 100 * INTERVAL) {

    previousMillis = currentMillis;
    markSeconds = true;
  } else {
    markSeconds = false;
  }

  if (currentMillis - lastTimeButtonsChecked >= 5*INTERVAL) {

    lastTimeButtonsChecked = currentMillis;
    determineGroupOfTransitions();
  }
}