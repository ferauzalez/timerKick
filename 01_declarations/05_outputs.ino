void activateDecreaseStateOutputs() {
  decreaseTime();
  switchColonMode(1);
}

void activateIncreaseStateOutputs() {
  increaseTime();
  switchColonMode(1);
}

void activateWaitStateOutputs() {
  assignDataToPrintOut(0);
  display(0);
  switchColonMode(2);
}
