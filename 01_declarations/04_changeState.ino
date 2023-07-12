void changeState(int state) {
  if (state != STATE_WAIT) {
  stringText = "state: ";
  stringMsg = stringText + state;
  //Serial.println(stringMsg);
  }

  switch (state) {
    case STATE_DECREASE:
      activateDecreaseStateOutputs();
      break;
    case STATE_INCREASE:
      activateIncreaseStateOutputs();
      break;
    case STATE_WAIT:
      activateWaitStateOutputs();
      break;
    case STATE_STOP:
      activateStopStateOutputs();
      break;
  }
}
