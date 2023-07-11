void activateDecreaseStateOutputs() {
  decreaseTime();
  switchColonMode(1); //una sola vez deberia activarse esta instruccion
}

void activateIncreaseStateOutputs() {
  increaseTime();
  switchColonMode(1);
}

void activateWaitStateOutputs() {
  //assignDataToPrintOut(0);
  display();
  if (playPauseSwitchStatus) {
    switchColonMode(1);
  } else {
    switchColonMode(2);
  }
}
