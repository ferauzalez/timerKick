void activateWaitStateOutputs() {
  display(0);
  switchColonMode(2);
}

void activateIncreaseStateOutputs() {
  increaseTime();
  assignDataToPrintOut(0);
  switchColonMode(1);
}
