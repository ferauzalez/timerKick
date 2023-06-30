void activateDecreaseStateOutputs() {
  decreaseTime();
  switchColonMode(1);
}

void activateIncreaseStateOutputs() {
  increaseTime();
  switchColonMode(1);
}

void activateWaitStateOutputs() {
  switchColonMode(2);
  assignDataToPrintOut(0);
  display(0);
}
