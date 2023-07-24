void changeState(int state) {
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
    case STATE_NEXT:
      activateNextStateOutputs();
      break;
  }
}
