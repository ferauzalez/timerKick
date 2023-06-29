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

    if (colonStatus == HIGH){
      colonStatus = LOW;
    } else {
      colonStatus = HIGH;
    }
    
    digitalWrite(PIN_SECONDS, colonStatus);
  }
}

void increaseTime(){
  increaseSeconds();
}

void increaseSeconds(){
  if (digitSecond < 9) {
    digitSecond++;
  } else {
    digitSecond = 0;
    increaseTenthOfASecond();
  }
}

void increaseTenthOfASecond(){
  if (digitTenthOfASecond < 5) {
    digitTenthOfASecond++;
  } else {
    digitTenthOfASecond = 0;
    increaseMinutes();
  }
}

void increaseMinutes(){
  if (digitMinute < 9) {
    digitMinute++;
  } else {
    digitMinute = 0;
    increaseTenthOfASecond();
  }
}

void increaseTenthOfAMinute(){
  if (digitTenthOfAMinute < 9){
    digitTenthOfAMinute++;
  } else {
    digitTenthOfAMinute = 0;
  }   
}
