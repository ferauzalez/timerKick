void setup() {
  Serial.begin(9600);

  pinMode(PIN_LATCH       , OUTPUT);
  pinMode(PIN_CLOCK       , OUTPUT);
  pinMode(PIN_DATA        , OUTPUT);
  pinMode(PIN_SECONDS     , OUTPUT);

  pinMode(PIN_BUTTON_PLUS , INPUT);
  pinMode(PIN_BUTTON_MINUS, INPUT);
  pinMode(PIN_BUTTON_NEXT , INPUT);
  pinMode(PIN_BUTTON_PLAY , INPUT);
  pinMode(PIN_BUTTON_STOP , INPUT);

  determineGroupOfTransitions();
}

void loop() {
  currentMillis = millis();

  if (colonMode == 2) {
    blinkColon();
  }

  if (currentMillis - lastTimeButtonsChecked >= 5 * INTERVAL) {
    lastTimeButtonsChecked = currentMillis;

    plusButtonValue       = digitalRead(PIN_BUTTON_PLUS)  ;
    minusButtonValue      = digitalRead(PIN_BUTTON_MINUS) ;
    nextButtonValue       = digitalRead(PIN_BUTTON_NEXT)  ;
    playPauseButtonValue  = digitalRead(PIN_BUTTON_PLAY)  ;
    stopButtonValue       = digitalRead(PIN_BUTTON_STOP)  ;

    if (plusButtonValue == HIGH) {
      currentInput = INPUT_INCREASE;
    } else if (minusButtonValue == HIGH) {
      currentInput = INPUT_DECREASE;
    } else if (nextButtonValue == HIGH) {
      seriesCounter++;
      if (seriesCounter == 5) { //las series van de 1 a 4
        seriesCounter = 0;
      }
      currentInput = INPUT_NEXT;
    }  else if (playPauseSwitch == true) {
      currentInput = INPUT_PLAY;
    }  else if (playPauseSwitch == false) {
      currentInput = INPUT_PAUSE;
    }  else if (stopButtonValue == HIGH) {
      currentInput = INPUT_STOP;
    }

    stringText = "currentInput: ";
    stringMsg = stringText + currentInput;
    Serial.println(stringMsg);
  }
}