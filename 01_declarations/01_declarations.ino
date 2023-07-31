#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial DFPlayerSerial(1, 0); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

//constantes-------------------------------------------------------------------
const int PIN_LATCH        = 2;
const int PIN_CLOCK        = 3;
const int PIN_DATA         = 4;
const int PIN_SECONDS      = 6;

const int PIN_ROUTINE1      = 12;
const int PIN_ROUTINE2      = 11;
const int PIN_ROUTINE3      = 10;
const int PIN_ROUTINE4      = 9;
const int PIN_WORK          = 8;
const int PIN_REST          = 7;

const int STATE_WAIT       = 0;
const int STATE_INCREASE   = 1;
const int STATE_DECREASE   = 2;
const int STATE_STOP       = 3;
const int STATE_NEXT       = 4;

const int INPUT_INCREASE   = 0;
const int INPUT_DECREASE   = 1;
const int INPUT_NEXT       = 2;
const int INPUT_PLAY       = 3;
const int INPUT_PAUSE      = 4;
const int INPUT_STOP       = 5;
const int INPUT_WAIT       = 6;

const int INPUTS_READING_PERIOD = 130;
const int ONE_SECOND            = 1000;
const int TOTAL_ROUTINES        = 4;
const int SERIES                = 3;

//0,1,2,3,4,5,6,7,8,9,BARRA,NONE
const int SEVEN_SEGMENTS_CODES[12] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 115, 1, 0};

//variables--------------------------------------------------------------------
//En el encendido del equipo no se deben encender los segmentos, por eso se incializa
//indicesToDisplay con el elemento 11 (NONE)
/*
int indicesToDisplay[2][4] = {
  {SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11]},
  {SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11]}
};*/

int workModes[8][4] = {{0,0,2,0},//work 1
                       {0,0,2,5},
                       {0,0,4,0},//work 2
                       {0,0,1,5},
                       {0,0,3,0},//work 3
                       {0,0,2,0},
                       {0,0,0,0},//work 4
                       {0,0,0,0}};


unsigned long currentMillis                      = 0;
unsigned long lastTimeColonStatusBlink           = 0;
unsigned long lastTimeButtonsChecked             = 0;
unsigned long lastTimePlayPauseStatusChanged     = 0;
unsigned long lastSecondMark                     = 0;
unsigned long countdownFinishedMark              = 0;

String        stringText                         = "";
String        stringMsg                          = "";

bool          playPauseSwitchStatus              = false;
bool          workRoutine                        = true; //true means work, false means routine 1(rest)
int           colonStatus                        = LOW;

int           indexTenthOfAMinuteOfWorkRoutine   = workModes[0][0];
int           indexMinuteOfWorkRoutine           = workModes[0][1];
int           indexTenthOfASecondOfWorkRoutine   = workModes[0][2];
int           indexSecondOfWorkRoutine           = workModes[0][3];

int           indexTenthOfAMinuteOfRestRoutine   = workModes[0][0];
int           indexMinuteOfRestRoutine           = workModes[0][1];
int           indexTenthOfASecondOfRestRoutine   = workModes[0][2];
int           indexSecondOfRestRoutine           = workModes[0][3];

int           indexTenthOfAMinute                = 11;
int           indexMinute                        = 11;
int           indexTenthOfASecond                = 11;
int           indexSecond                        = 11;


int           series                             = SERIES;
int           freeSeries                         = SERIES;
//int           indexLEDsRoutines                  = 0;
int           indexRoutine                       = 0;
int           subIndexRoutine                    = 0;
int           counterOfSeconds                   = 0;

bool          firstSoundPlayed                   = false;
bool          secondSoundPlayed                  = false;
bool          thirdSoundPlayed                   = false;
