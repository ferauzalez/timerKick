void setup() {
  Serial.begin(9600);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_SECONDS, OUTPUT);
/*
  pinMode(PIN_BUTTON_PLUS, INPUT);
  pinMode(PIN_BUTTON_MINUS, INPUT);
  pinMode(PIN_BUTTON_NEXT, INPUT);
  pinMode(PIN_BUTTON_PLAY, INPUT);
  pinMode(PIN_BUTTON_STOP, INPUT);
*/
  determineGroupOfTransitions();  // lo ejecuto una vez para que se establezca el estado de espera
}

void loop() {
  currentMillis = millis();

  if (currentMillis - previousMillis >= 100 * INTERVAL) {
    previousMillis = currentMillis;
    markSeconds = true;
    Serial.println("mark");
  } else {
    markSeconds = false;
  }
}

/*
    stringText = "currentState: ";
    stringMsg = stringText + currentState;
    Serial.println(stringMsg);

      if (currentMillis - lastTimeButtonsChecked >= 5*INTERVAL) {
    lastTimeButtonsChecked = currentMillis;

    determineGroupOfTransitions();
  }
*/
