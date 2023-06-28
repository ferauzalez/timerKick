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