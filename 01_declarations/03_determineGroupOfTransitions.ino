void determineGroupOfTransitions() {
  switch (currentState) {
    case STATE_INCREASE:
      determineTransitionFromIncreaseState();
      break;
    default:
      determineTransitionFromWaitState();
      break;
  }
}

void transition(int currentInput) {
  stringText = "currentInput: ";
  stringMsg = stringText + currentInput;
  Serial.println(stringMsg);

  switch (currentInput) {
    case INPUT_INCREASE:
      changeState(STATE_INCREASE);
      break;
  }
}

void determineTransitionFromWaitState() {

  stringText = "currentInput: ";
  stringMsg = stringText + currentInput;
  Serial.println(stringMsg);

  switch (currentInput) {
    case INPUT_INCREASE:
      changeState(STATE_INCREASE);
      break;
  }
}

void determineTransitionFromIncreaseState() {
  switch (currentInput) {
    default:
      changeState(STATE_WAIT);
      break;
  }
}