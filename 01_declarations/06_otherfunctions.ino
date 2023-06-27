void display(int index) {
  digitalWrite(PIN_LATCH, LOW);

  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][0]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][1]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][2]);
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][3]);

  digitalWrite(PIN_LATCH, HIGH);
}

void blinkSeconds() {
  if (markSeconds){
    digitalWrite(PIN_SECONDS, HIGH);
  } else {
    digitalWrite(PIN_SECONDS, LOW);
  }
}


/*
    stringText = "currentState: ";
    stringMsg = stringText + currentState;
    Serial.println(stringMsg);

      if (currentMillis - lastTimeButtonsChecked >= 5*INTERVAL) {
    lastTimeButtonsChecked = currentMillis;

    determineGroupOfTransitions();
  }
*/