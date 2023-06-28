void determineGroupOfTransitions(){
  switch (currentState) {    
    default:
      determineTransitionFromWaitState();
      break;
    }
}

void determineTransitionFromWaitState(){

  stringText = "currentInput: ";
  stringMsg = stringText + currentInput;
  Serial.println(stringMsg);
  
  switch (currentInput) {
    default:
      changeState(STATE_WAIT);
      break;
  }
}
