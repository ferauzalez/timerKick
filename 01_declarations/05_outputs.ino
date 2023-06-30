void activateDecreseStateOutputs() {
  switchColonMode(1);
  decreaseTime();
  assignDataToPrintOut(0);
}

void activateIncreaseStateOutputs() {
  switchColonMode(1);
  increaseTime();
  assignDataToPrintOut(0);
}

void activateWaitStateOutputs() {
  if (playPauseSwitchStatus) {
    switchColonMode(1);
  } else {
    switchColonMode(2);
  }
  
  display(0);
}