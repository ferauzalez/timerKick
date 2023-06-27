void determineGroupOfTransitions(){
  switch (currentState) {    
    default:
      determineTransitionFromWaitState();
      break;
    }
}

void determineTransitionFromWaitState(){
  switch (currentInput) {
    default:
      changeState(STATE_WAIT);
      break;
  }
}
