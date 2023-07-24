void setup() {
  //Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  myDFPlayer.begin(DFPlayerSerial);
  

  pinMode(PIN_LATCH,   OUTPUT);
  pinMode(PIN_CLOCK,   OUTPUT);
  pinMode(PIN_DATA,    OUTPUT);
  pinMode(PIN_SECONDS, OUTPUT);

  pinMode(PIN_ROUTINE1, OUTPUT);
  pinMode(PIN_ROUTINE2, OUTPUT);
  pinMode(PIN_ROUTINE3, OUTPUT);
  pinMode(PIN_ROUTINE4, OUTPUT);
  pinMode(PIN_WORK,     OUTPUT);
  pinMode(PIN_REST,     OUTPUT);

  pinMode(A0, INPUT);  //PIN_BUTTON_PLUS
  pinMode(A1, INPUT);  //PIN_BUTTON_MINUS
  pinMode(A2, INPUT);  //PIN_BUTTON_NEXT
  pinMode(A3, INPUT);  //PIN_BUTTON_PLAY
  pinMode(A4, INPUT);  //PIN_BUTTON_STOP

  digitalWrite(PIN_ROUTINE1, LOW);
  digitalWrite(PIN_ROUTINE2, LOW);
  digitalWrite(PIN_ROUTINE3, LOW);
  digitalWrite(PIN_ROUTINE4, LOW);
  digitalWrite(PIN_WORK    , LOW);
  digitalWrite(PIN_REST    , LOW);

  //assignDigitsForCountdown();
}

void loop() {
  transition(INPUT_WAIT);
  
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
      transition(INPUT_NEXT);
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
}
