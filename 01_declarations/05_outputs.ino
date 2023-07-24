void activateNextStateOutputs() {
  if (indexRoutine <= TOTAL_ROUTINES * 2) {
    indexRoutine = indexRoutine + 2;
  } // conflicto entre 8 y 10, no estoy del todo seguro de que deba poner <=

  ledsIndicatorsControl();

  if (indexRoutine == 8) {
    freeRoutine();    
  }

  if (indexRoutine == 10) {
    setSeries();
    indexRoutine = 0;
  }
}

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
  
  ledsWorkAndRestControl();
  display();
  
  if (playPauseSwitchStatus) {
    switchColonMode(1);
  } else {
    switchColonMode(2);
  }
}
