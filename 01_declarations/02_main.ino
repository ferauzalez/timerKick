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
}

void loop() {
  currentMillis = millis();

  if (currentMillis - lastTimeButtonsChecked >= INPUTS_READING_PERIOD) {

    lastTimeButtonsChecked = currentMillis;

    if (digitalRead(A0)) {  //PIN_BUTTON_PLUS
      //Serial.println("MAS");
      transition(INPUT_INCREASE);
    } else if (digitalRead(A1)) {  //PIN_BUTTON_MINUS
      //Serial.println("MINUS");
      transition(INPUT_DECREASE);
    } else if (digitalRead(A2)) {  //PIN_BUTTON_NEXT
      //Serial.println("NEXT");
    } else if (digitalRead(A3)) {  //PIN_BUTTON_PLAY_PAUSE
      if (togglesDurationGreaterThanTimeWindow()){
        togglePlayPauseSwitchStatus();        
        countdownStarted();
        delay(1000);
      }
    } else if (digitalRead(A4)) {  //PIN_BUTTON_STOP
      //Serial.println("STOP");
    } else if (playPauseSwitchStatus == true) {  //means play is active
      makeACountDown();
    }
  }

  transition(INPUT_WAIT);
}
