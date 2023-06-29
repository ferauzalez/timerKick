void transition(int currentInput) {
  if (currentInput != 6) {
    stringText = "currentInput: ";
    stringMsg = stringText + currentInput;
    Serial.println(stringMsg);
  }
  switch (currentInput) {
    case INPUT_INCREASE:
      changeState(STATE_INCREASE);
      break;
    case INPUT_WAIT:
      changeState(STATE_WAIT);
      break;
  }
}
