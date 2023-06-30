void activateDecreseStateOutputs() {
  decreaseTime();
  assignDataToPrintOut(0);
  switchColonMode(1);
}

void activateIncreaseStateOutputs() {
  increaseTime();
  assignDataToPrintOut(0);
  switchColonMode(1);
}

void activateWaitStateOutputs() {
  switchColonMode(2);
  display(0);
}