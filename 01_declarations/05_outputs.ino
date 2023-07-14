void activateNextStateOutputs() {
  if (indexLEDsRoutines < TOTAL_ROUTINES * 2) {
    indexRoutine = indexRoutine + 2;
  }

  switch (indexRoutine){
    case 2: //routine 1 (free routine)
      ledsIndicatorsControl(HIGH,LOW,LOW,LOW,LOW,LOW);
      break;
    case 4: //routine 2
      ledsIndicatorsControl(LOW,HIGH,LOW,LOW,LOW,LOW);
      break;
    case 6: //routine 3
      ledsIndicatorsControl(LOW,LOW,HIGH,LOW,LOW,LOW);
      break;
    case 8: //routine 4
      if (subIndexRoutine == 0) {
        ledsIndicatorsControl(LOW,LOW,LOW,HIGH,HIGH,LOW);
        subIndexRoutine++;
      }
      
      if (subIndexRoutine == 1) {
        ledsIndicatorsControl(LOW,LOW,LOW,HIGH,LOW,HIGH);
        subIndexRoutine = 0;
        indexRoutine = 0;
      }
      break;
    default:
      ledsIndicatorsControl(HIGH,LOW,LOW,LOW,LOW,HIGH);
      break;
  }

  assignDigitsForCountdown();
  
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
  display();
  if (playPauseSwitchStatus) {
    switchColonMode(1);
  } else {
    switchColonMode(2);
  }
}
