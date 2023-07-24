void activateNextStateOutputs() {
  if (indexRoutine < TOTAL_ROUTINES * 2) {
    indexRoutine = indexRoutine + 2;
  }
  

  switch (indexRoutine){
    case 2: //routine 1 (free routine)
      displayLEDsIndicators(HIGH,LOW,LOW,LOW);
      break;
    case 4: //routine 2
      displayLEDsIndicators(LOW,HIGH,LOW,LOW);
      break;
    case 6: //routine 3
      displayLEDsIndicators(LOW,LOW,HIGH,LOW);
      break;
    case 8: //routine 4
      displayLEDsIndicators(LOW,LOW,LOW,HIGH);
      freeRoutine();
      break;
    default:
      displayLEDsIndicators(LOW,LOW,LOW,LOW);
      break;
  }

  if (indexRoutine == 0) {
    indexTenthOfAMinute = 11;
    indexMinute         = 11;
    indexTenthOfASecond = 11;
    indexSecond         = 11;
  } else if (subIndexRoutine == 3) {
    indexTenthOfAMinute = 10;
    indexMinute         = 10;
    indexTenthOfASecond = freeSeries/10;
    indexSecond         = freeSeries - (indexTenthOfASecond * 10);
  } else {
    countdownStarted();
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
