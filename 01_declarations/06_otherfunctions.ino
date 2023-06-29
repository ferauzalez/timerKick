void display(int index) {
  digitalWrite(PIN_LATCH, LOW);

  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][0]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][1]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][2]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][3]);

  digitalWrite(PIN_LATCH, HIGH);
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
    increaseTenthOfASecond();
  }
}

void increaseTenthOfAMinute() {
  if (digitTenthOfAMinute < 9) {
    digitTenthOfAMinute++;
  } else {
    digitTenthOfAMinute = 0;
  }
}

void assignDataToPrintOut(int index) {

  indicesToDisplay[index][0] = SEVEN_SEGMENTS_CODES[digitSecond];
  indicesToDisplay[index][1] = SEVEN_SEGMENTS_CODES[digitTenthOfASecond];
  indicesToDisplay[index][2] = SEVEN_SEGMENTS_CODES[digitMinute];
  indicesToDisplay[index][3] = SEVEN_SEGMENTS_CODES[digitTenthOfAMinute];
}

void togglePlayPauseSwitchStatus() {
  if (playPauseSwitchStatus == true) {
    playPauseSwitchStatus = false;
  } else {
    playPauseSwitchStatus = true;
  }
}

void switchColonMode(int colonMode) {
    switch (colonMode) { //0: OFF, 1: ON, 2: blink
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