/*void assignDataToPrintOut(int index) {  
  if (index == 0) {
    indicesToDisplay[0][0] = SEVEN_SEGMENTS_CODES[index0Second];         //digitSecond
    indicesToDisplay[0][1] = SEVEN_SEGMENTS_CODES[index0TenthOfASecond]; //digitTenthOfASecond
    indicesToDisplay[0][2] = SEVEN_SEGMENTS_CODES[index0Minute];         //digitMinute
    indicesToDisplay[0][3] = SEVEN_SEGMENTS_CODES[index0TenthOfAMinute]; //digitTenthOfAMinute

    return;
  }

  if (index == 1) {
    indicesToDisplay[1][0] = SEVEN_SEGMENTS_CODES[index1Second];         //digitSecond
    indicesToDisplay[1][1] = SEVEN_SEGMENTS_CODES[index1TenthOfASecond]; //digitTenthOfASecond
    indicesToDisplay[1][2] = SEVEN_SEGMENTS_CODES[index1Minute];         //digitMinute
    indicesToDisplay[1][3] = SEVEN_SEGMENTS_CODES[index1TenthOfAMinute]; //digitTenthOfAMinute

    return;
  }
}*/

void assignDigitsForCountdown() {

  if (workRoutine) {
    indexSecond         = workModes[indexRoutine - 2][3];
    indexTenthOfASecond = workModes[indexRoutine - 2][2];
    indexMinute         = workModes[indexRoutine - 2][1];
    indexTenthOfAMinute = workModes[indexRoutine - 2][0];
    
    return;
  }
    indexSecond         = workModes[indexRoutine - 1][3];
    indexTenthOfASecond = workModes[indexRoutine - 1][2];
    indexMinute         = workModes[indexRoutine - 1][1];
    indexTenthOfAMinute = workModes[indexRoutine - 1][0];
}



void blinkColon() {
  if (currentMillis - lastTimeColonStatusBlink >= ONE_SECOND) {
    lastTimeColonStatusBlink = currentMillis;

    if (colonStatus == HIGH) {
      colonStatus = LOW;
    } else {
      colonStatus = HIGH;
    }

    digitalWrite(PIN_SECONDS, colonStatus);
  }
}

void checkForSounds() {
  if (!workRoutine) {
    return;    
  }

  if (indexSecond         == indexSecondOfWorkRoutine         and
      indexTenthOfASecond == indexTenthOfASecondOfWorkRoutine and
      indexMinute         == indexMinuteOfWorkRoutine         and
      indexTenthOfAMinute == indexTenthOfAMinuteOfWorkRoutine
  ) {
    playSound(1);
  }
  
  if (indexSecond == 1 and indexTenthOfASecond == 1 and indexMinute == 0 and indexTenthOfAMinute == 0) {
    playSound(3);
  }

  if (indexSecond == 1 and indexTenthOfASecond == 0 and indexMinute == 0 and indexTenthOfAMinute == 0) {
    playSound(2);
  }
}

bool countdownFinished() {
  if (indexSecond != 0 or indexTenthOfASecond != 0 or indexMinute != 0 or indexTenthOfAMinute != 0) {
    countdownFinishedMark = currentMillis;
    return false;
  }
  return true;
}

void countdownStarted(){
  /*
  if (playPauseSwitchStatus == true) {
      playSound(1);   
  }
*/
  series = 1;
  workRoutine = true;
  assignDigitsForCountdown();
}

void decreaseTime() {
  decreaseSeconds();
}

void decreaseSeconds() {
  if (indexSecond > 0) {
    indexSecond--;
  } else {
    indexSecond = 9;
    decreaseTenthOfASecond();
  }
}
void decreaseTenthOfASecond() {
  if (indexTenthOfASecond > 0) {
    indexTenthOfASecond--;
  } else {
    indexTenthOfASecond = 5;
    decreaseMinutes();
  }
}

void decreaseMinutes() {
  if (indexMinute > 0) {
    indexMinute--;
  } else {
    indexMinute = 9;
    decreaseTenthOfAMinute();
  }
}

void decreaseTenthOfAMinute() {
  if (indexTenthOfAMinute > 0) {
    indexTenthOfAMinute--;
  } else {
    indexTenthOfAMinute = 9;
  }
} 

void display() {
  digitalWrite(PIN_LATCH, LOW);
  
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, SEVEN_SEGMENTS_CODES[indexSecond]); //digitSecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, SEVEN_SEGMENTS_CODES[indexTenthOfASecond]); //digitTenthOfASecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, SEVEN_SEGMENTS_CODES[indexMinute]); //digitMinute
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, SEVEN_SEGMENTS_CODES[indexTenthOfAMinute]); //digitTenthOfAMinute

  digitalWrite(PIN_LATCH, HIGH);
}

/*
void display(int index) {
  digitalWrite(PIN_LATCH, LOW);
  
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][0]); //digitSecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][1]); //digitTenthOfASecond
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][2]); //digitMinute
  shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, indicesToDisplay[index][3]); //digitTenthOfAMinute

  digitalWrite(PIN_LATCH, HIGH);
}*/

void increaseTime() {
  increaseSeconds();
}

void increaseSeconds() {
  if (indexSecond < 9) {
    indexSecond++;
  } else {
    indexSecond = 0;
    increaseTenthOfASecond();
  }
}

void increaseTenthOfASecond() {
  if (indexTenthOfASecond < 5) {
    indexTenthOfASecond++;
  } else {
    indexTenthOfASecond = 0;
    increaseMinutes();
  }
}

void increaseMinutes() {
  if (indexMinute < 9) {
    indexMinute++;
  } else {
    indexMinute = 0;
    increaseTenthOfAMinute();
  }
}

void increaseTenthOfAMinute() {
  if (indexTenthOfAMinute < 9) {
    indexTenthOfAMinute++;
  } else {
    indexTenthOfAMinute = 0;
  }
}

void ledsIndicatorsControl(int led1, int led2, int led3, int led4, int ledWork, int ledRest) {
  digitalWrite(PIN_ROUTINE1, led1);
  digitalWrite(PIN_ROUTINE2, led2);
  digitalWrite(PIN_ROUTINE3, led3);
  digitalWrite(PIN_ROUTINE4, led4);
  digitalWrite(PIN_WORK    , ledWork);
  digitalWrite(PIN_REST    , ledRest);
}

void makeACountDown() {
  if (currentMillis - lastSecondMark >= ONE_SECOND) {
    lastSecondMark = currentMillis;
    transition(INPUT_DECREASE);
  }
}

bool nextRoutineIsReady() {

  if (currentMillis - countdownFinishedMark < 2000) {//ONE_SECOND
    return false;
  }

  if (series == 0){
    togglePlayPauseSwitchStatus();
    return false;
  }

  workRoutine = !workRoutine;
  
  if (!workRoutine) {
    series--;
  }
  
  assignDigitsForCountdown();
  lastSecondMark = currentMillis;
 
  return true;
}

void playSound(int fileNumber) {
  myDFPlayer.volume(30);
  myDFPlayer.play(fileNumber);
   // must be 1,2 or 3.
}

void switchColonMode(int colonMode) {
  switch (colonMode) {  //0: OFF, 1: ON, 2: blink
    case 0:
      digitalWrite(PIN_SECONDS, LOW);
      break;
    case 1:
      digitalWrite(PIN_SECONDS, HIGH);
      break;
    case 2:
      blinkColon();
      break;
    default:
      digitalWrite(PIN_SECONDS, LOW);
      break;
  }
}

bool togglesDurationGreaterThanTimeWindow (){
    if (currentMillis - lastTimePlayPauseStatusChanged >= ONE_SECOND) {
    lastTimePlayPauseStatusChanged = currentMillis;
    return true;
    }
    return false;
}
    
void togglePlayPauseSwitchStatus() {
  playPauseSwitchStatus = !playPauseSwitchStatus;
  lastSecondMark = currentMillis;
  if (playPauseSwitchStatus) {
    //Serial.println("PAUSE");//means input is PAUSE
  } else {
    //Serial.println("PLAY");//means input is PLAY
  }
}
