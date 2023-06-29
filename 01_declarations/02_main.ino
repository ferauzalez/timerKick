void setup() {
  Serial.begin(9600);

  pinMode(PIN_LATCH       , OUTPUT);
  pinMode(PIN_CLOCK       , OUTPUT);
  pinMode(PIN_DATA        , OUTPUT);
  pinMode(PIN_SECONDS     , OUTPUT);

  pinMode(A0              , INPUT); //PIN_BUTTON_PLUS
  pinMode(A1              , INPUT); //PIN_BUTTON_MINUS
  pinMode(A2              , INPUT); //PIN_BUTTON_NEXT
  pinMode(A3              , INPUT); //PIN_BUTTON_PLAY
  pinMode(A4              , INPUT); //PIN_BUTTON_STOP
}

void loop() {
  currentMillis = millis();

  if (currentMillis - lastTimeButtonsChecked >= 13 * INTERVAL) {

    lastTimeButtonsChecked = currentMillis;

    if (digitalRead(A0)) {                 //PIN_BUTTON_PLUS
      Serial.println("MAS");
      transition(INPUT_INCREASE);
    } else if (digitalRead(A1)) {          //PIN_BUTTON_MINUS
      //currentInput = INPUT_DECREASE;
      Serial.println("MINUS");
    } else if (digitalRead(A2)) {          //PIN_BUTTON_NEXT
      //currentInput = INPUT_NEXT;
      Serial.println("NEXT");
    } else if (digitalRead(A3)) {          //PIN_BUTTON_PLAY
      //currentInput = INPUT_PLAY;
      Serial.println("PLAY");
      togglePlayPauseSwitchStatus();
    } else if (digitalRead(A4)) {          //PIN_BUTTON_STOP
      //currentInput = INPUT_STOP;
      Serial.println("STOP");
    }
  }

  transition(INPUT_WAIT);
}
