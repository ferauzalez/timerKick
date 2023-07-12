void activateStopStateOutputs() {
  playPauseSwitchStatus = false;
  countdownStarted();
}

void activateDecreaseStateOutputs() {
  decreaseTime();
  switchColonMode(1);
}

void activateIncreaseStateOutputs() {
  increaseTime();
  switchColonMode(1);
}

void activateWaitStateOutputs() {
  display();
  if (playPauseSwitchStatus) {
    switchColonMode(1);
  } else {
    switchColonMode(2);
  }
}
