void assignDataToPrintOut(int index) {  
  indicesToDisplay[index][0] = SEVEN_SEGMENTS_CODES[digitSecond];
  indicesToDisplay[index][1] = SEVEN_SEGMENTS_CODES[digitTenthOfASecond];
  indicesToDisplay[index][2] = SEVEN_SEGMENTS_CODES[digitMinute];
  indicesToDisplay[index][3] = SEVEN_SEGMENTS_CODES[digitTenthOfAMinute];
}

void blinkColon() {
  if (currentMillis - lastTimeColonStatusBlink >= ONE_SECOND) {
    lastTimeColonStatusBlink = currentMillis;

    if (colonStatus == HIGH) {
      colonStatus = LOW;
    } else {
      colonStatus = HIGH;
    }

    digitalWrite(PIN_SECONDS, colonStatus);
  }
}

void countdownStarted(){
  if (playPauseSwitchStatus == true) {
      playSound(1);   
  }
}

void decreaseTime() {
  decreaseSeconds();
}

void decreaseSeconds() {
  if (digitSecond > 0) {
    digitSecond--;
  } else {
    digitSecond = 9;
    decreaseTenthOfASecond();
  }
}

void decreaseTenthOfASecond() {
  if (digitTenthOfASecond > 0) {
    digitTenthOfASecond--;
  } else {
    digitTenthOfASecond = 5;
    decreaseMinutes();
  }
}

void decreaseMinutes() {
  if (digitMinute > 0) {
    digitMinute--;
  } else {
    digitMinute = 9;
    decreaseTenthOfAMinute();
  }
}

void decreaseTenthOfAMinute() {
  if (digitTenthOfAMinute > 0) {
    digitTenthOfAMinute--;
  } else {
    digitTenthOfAMinute = 9;
  }
}

void display(int index) {
  digitalWrite(PIN_LATCH, LOW);
  
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][0]); //digitSecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][1]); //digitTenthOfASecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][2]); //digitMinute
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][3]); //digitTenthOfAMinute

  digitalWrite(PIN_LATCH, HIGH);
}

void increaseTime() {
  increaseSeconds();
}

void increaseSeconds() {
  if (digitSecond < 9) {
    digitSecond++;
  } else {
    digitSecond = 0;
    increaseTenthOfASecond();
  }
}

void increaseTenthOfASecond() {
  if (digitTenthOfASecond < 5) {
    digitTenthOfASecond++;
  } else {
    digitTenthOfASecond = 0;
    increaseMinutes();
  }
}

void increaseMinutes() {
  if (digitMinute < 9) {
    digitMinute++;
  } else {
    digitMinute = 0;
    increaseTenthOfAMinute();
  }
}

void increaseTenthOfAMinute() {
  if (digitTenthOfAMinute < 9) {
    digitTenthOfAMinute++;
  } else {
    digitTenthOfAMinute = 0;
  }
}

void makeACountDown() {
  if (currentMillis - lastSecondMark >= ONE_SECOND) {
    lastSecondMark = currentMillis;
    transition(INPUT_DECREASE);
    if (digitSecond == 1 and digitTenthOfASecond == 1 and digitMinute == 0 and digitTenthOfAMinute == 0) {
      playSound(3);
    }

    if (digitSecond == 1 and digitTenthOfASecond == 0 and digitMinute == 0 and digitTenthOfAMinute == 0) {
      playSound(2);
    }
    
    if (digitSecond == 0 and digitTenthOfASecond == 0 and digitMinute == 0 and digitTenthOfAMinute == 0) {
      togglePlayPauseSwitchStatus();
    }
  }
}

void playSound(int fileNumber) {
  myDFPlayer.volume(30);
  myDFPlayer.play(fileNumber);
   // must be 1,2 or 3.
}

void switchColonMode(int colonMode) {
  switch (colonMode) {  //0: OFF, 1: ON, 2: blink
    case 0:
      digitalWrite(PIN_SECONDS, LOW);
      break;
    case 1:
      digitalWrite(PIN_SECONDS, HIGH);
      break;
    case 2:
      blinkColon();
      break;
    default:
      digitalWrite(PIN_SECONDS, LOW);
      break;
  }
}

bool togglesDurationGreaterThanTimeWindow (){
    if (currentMillis - lastTimePlayPauseStatusChanged >= ONE_SECOND) {
    lastTimePlayPauseStatusChanged = currentMillis;
    return true;
    }
    return false;
}
    
void togglePlayPauseSwitchStatus() {
  playPauseSwitchStatus = !playPauseSwitchStatus;
  if (playPauseSwitchStatus) {
    //Serial.println("PAUSE");//means input is PAUSE
  } else {
    //Serial.println("PLAY");//means input is PLAY
  }
}
