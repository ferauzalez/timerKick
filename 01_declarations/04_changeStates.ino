void changeState(int newState) {
  stringText = "currentState: ";
  stringMsg = stringText + currentState;
  Serial.println(stringMsg);

  stringText = "newState: ";
  stringMsg = stringText + newState;
  Serial.println(stringMsg);

  currentState = newState;

  switch (currentState) {
    default:
      activateWaitStateOutputs();  //Nunca deberia entrar acá
      break;
  }
}

void activateWaitStateOutputs() {
  Serial.println("activateWaitStateOutputs");
  display(0);
  colonMode = 2;
}
