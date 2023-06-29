void changeState(int state) {
  stringText = "state: ";
  stringMsg = stringText + state;
  Serial.println(stringMsg);

  //currentState = newState;

  switch (state) {
    case STATE_INCREASE:
      activateIncreaseStateOutputs();
      break;
    case STATE_WAIT:
      activateWaitStateOutputs();
      break;
  }
}
