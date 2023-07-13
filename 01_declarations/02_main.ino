void setup() {
  //Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  myDFPlayer.begin(DFPlayerSerial);
  

  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_SECONDS, OUTPUT);

  pinMode(A0, INPUT);  //PIN_BUTTON_PLUS
  pinMode(A1, INPUT);  //PIN_BUTTON_MINUS
  pinMode(A2, INPUT);  //PIN_BUTTON_NEXT
  pinMode(A3, INPUT);  //PIN_BUTTON_PLAY
  pinMode(A4, INPUT);  //PIN_BUTTON_STOP

  assignDigitsForCountdown();
}

void loop() {
  currentMillis = millis();

  if (currentMillis - lastTimeButtonsChecked >= INPUTS_READING_PERIOD) {

    lastTimeButtonsChecked = currentMillis;

    if (digitalRead(A0)) {  //PIN_BUTTON_PLUS
      transition(INPUT_INCREASE);
      return;
    }
    
    if (digitalRead(A1)) {  //PIN_BUTTON_MINUS
      transition(INPUT_DECREASE);
      return;
    }
    
    if (digitalRead(A2)) {  //PIN_BUTTON_NEXT
      return;
    }
    
    if (digitalRead(A3)) {  //PIN_BUTTON_PLAY_PAUSE
      if (!togglesDurationGreaterThanTimeWindow()){
        return;
      }

      togglePlayPauseSwitchStatus();
      return;
    }
    
    if (digitalRead(A4)) {  //PIN_BUTTON_STOP
      transition(INPUT_STOP);
      return;
    }

  }

  if (playPauseSwitchStatus == true) {  //means play is active
    if (countdownFinished()) {//prepare the next routine
      if (nextRoutineIsReady() == false) {
        return;
      }
    }

      checkForSounds();
      makeACountDown();
  }

  transition(INPUT_WAIT);
}
