#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial DFPlayerSerial(1, 0); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

//constantes-------------------------------------------------------------------
const int PIN_LATCH        = 2;
const int PIN_CLOCK        = 3;
const int PIN_DATA         = 4;
const int PIN_SECONDS      = 12;

const int STATE_WAIT       = 0;
const int STATE_INCREASE   = 1;
const int STATE_DECREASE   = 2;
const int STATE_STOP       = 3;

const int INPUT_INCREASE   = 0;
const int INPUT_DECREASE   = 1;
const int INPUT_NEXT       = 2;
const int INPUT_PLAY       = 3;
const int INPUT_PAUSE      = 4;
const int INPUT_STOP       = 5;
const int INPUT_WAIT            = 6;

const int INPUTS_READING_PERIOD = 130;
const int ONE_SECOND = 1000;

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

int workModes[6][4] = {{0,0,2,0},//work 1
                       {0,0,2,5},
                       {0,1,3,0},//work 2
                       {0,0,2,0},
                       {0,0,3,0},//work 3
                       {0,0,2,0}};

int                  colonStatus                        = LOW;
static unsigned long currentMillis                      = 0;
unsigned long        lastTimeColonStatusBlink           = 0;
unsigned long        lastTimeButtonsChecked             = 0;
unsigned long        lastTimePlayPauseStatusChanged     = 0;
unsigned long        lastSecondMark                     = 0;
unsigned long        countdownFinishedMark                     = 0;
String               stringText                         = "";
String               stringMsg                          = "";
bool                 playPauseSwitchStatus              = false;

int                  indexTenthOfAMinuteOfWorkRoutine   = workModes[4][0];
int                  indexMinuteOfWorkRoutine           = workModes[4][1];
int                  indexTenthOfASecondOfWorkRoutine   = workModes[4][2];
int                  indexSecondOfWorkRoutine           = workModes[4][3];

int                  indexTenthOfAMinuteOfRestRoutine   = workModes[5][0];
int                  indexMinuteOfRestRoutine           = workModes[5][1];
int                  indexTenthOfASecondOfRestRoutine   = workModes[5][2];
int                  indexSecondOfRestRoutine           = workModes[5][3];

int                  indexTenthOfAMinute                = 11;
int                  indexMinute                        = 11;
int                  indexTenthOfASecond                = 11;
int                  indexSecond                        = 11;

bool                 workRoutine                        = true; //true means work, false means routine 1(rest)
int                  series                             = 1;
