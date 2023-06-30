void assignDataToPrintOut(int index) {  
  indicesToDisplay[index][0] = SEVEN_SEGMENTS_CODES[digitSecond];
  indicesToDisplay[index][1] = SEVEN_SEGMENTS_CODES[digitTenthOfASecond];
  indicesToDisplay[index][2] = SEVEN_SEGMENTS_CODES[digitMinute];
  indicesToDisplay[index][3] = SEVEN_SEGMENTS_CODES[digitTenthOfAMinute];
}

void blinkColon() {
  if (currentMillis - lastTimeColonStatusBlink >= 100 * INTERVAL) {
    lastTimeColonStatusBlink = currentMillis;

    if (colonStatus == HIGH) {
      colonStatus = LOW;
    } else {
      colonStatus = HIGH;
    }

    digitalWrite(PIN_SECONDS, colonStatus);
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

void togglePlayPauseSwitchStatus() {
  if (playPauseSwitchStatus == true) {
    playPauseSwitchStatus = false;
  } else {
    playPauseSwitchStatus = true;
  }
}
