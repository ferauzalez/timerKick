void transition(int currentInput) {
  if (currentInput != 6) {
    stringText = "currentInput: ";
    stringMsg = stringText + currentInput;
    //Serial.println(stringMsg);
  }
  switch (currentInput) {
    case INPUT_WAIT:
      changeState(STATE_WAIT);
      break;
    case INPUT_INCREASE:
      changeState(STATE_INCREASE);
      break;
    case INPUT_DECREASE:
      changeState(STATE_DECREASE);
      break;
    case INPUT_STOP:
      changeState(STATE_STOP);
      break;
  }
}
