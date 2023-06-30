//constantes-------------------------------------------------------------------
const int PIN_LATCH        = 2;
const int PIN_CLOCK        = 3;
const int PIN_DATA         = 4;
const int PIN_SECONDS      = 12;

const int STATE_WAIT       = 0;
const int STATE_INCREASE   = 1;
const int STATE_DECREASE   = 2;

const int INPUT_INCREASE   = 0;
const int INPUT_DECREASE   = 1;
const int INPUT_NEXT       = 2;
const int INPUT_PLAY       = 3;
const int INPUT_PAUSE      = 4;
const int INPUT_STOP       = 5;
const int INPUT_WAIT       = 6;

const int INTERVAL         = 10;

//0,1,2,3,4,5,6,7,8,9,BARRA,NONE
const int SEVEN_SEGMENTS_CODES[12] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 115, 1, 0};

//variables--------------------------------------------------------------------
//En el encendido del equipo no se deben encender los segmentos, por eso se incializa
//indicesToDisplay con el elemento 11 (NONE)
int indicesToDisplay[2][4] = {
  {SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11]},
  {SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11], SEVEN_SEGMENTS_CODES[11]}
};

int                  colonStatus                = LOW;
static unsigned long currentMillis              = 0;
unsigned long        lastTimeColonStatusBlink   = 0;
unsigned long        lastTimeButtonsChecked     = 0;
unsigned long        lastSecondMark             = 0;
String               stringText                 = "";
String               stringMsg                  = "";
bool                 playPauseSwitchStatus      = false;
int                  digitTenthOfAMinute        = 0;
int                  digitMinute                = 0;
int                  digitTenthOfASecond        = 0;
int                  digitSecond                = 0;
