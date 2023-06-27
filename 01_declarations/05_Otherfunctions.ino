void display(int index) {
  digitalWrite(PIN_LATCH, LOW);

  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][0]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][1]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][2]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][3]);

  digitalWrite(PIN_LATCH, HIGH);
}

void blinkSeconds() {
  Serial.println("llamada");
  if (markSeconds){
    digitalWrite(PIN_SECONDS, HIGH);
    Serial.println("blink");
  } else {
    digitalWrite(PIN_SECONDS, LOW);
  }
}
