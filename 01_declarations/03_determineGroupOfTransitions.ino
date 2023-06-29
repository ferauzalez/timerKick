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
    case INPUT_INCREASE:
      changeState(STATE_INCREASE);
      break;
    default:
      changeState(STATE_WAIT);
      break;
  }
}
