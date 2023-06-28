//TIMER KICK v0
//Etapa Nº 1
//Resultado esperable: Se prende el equipo y se observa sólo el segundero parpadeando.

//constantes-------------------------------------------------------------------
const int PIN_LATCH        = 2;
const int PIN_CLOCK        = 3;
const int PIN_DATA         = 4;
const int PIN_SECONDS      = 12;
/*
  const int PIN_BUTTON_PLUS  = 4;
  const int PIN_BUTTON_MINUS = 6;
  const int PIN_BUTTON_NEXT  = 7;
  const int PIN_BUTTON_PLAY  = 8;
  const int PIN_BUTTON_STOP  = 9;
*/

const int STATE_WAIT       = 0;

const int INTERVAL         = 10;

//0,1,2,3,4,5,6,7,8,9,BARRA, NONE
const int sevenSegmentsCodes[12] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 115, 1, 0};

//variables--------------------------------------------------------------------
//En el encendido del equipo no se deben encender los segmentos, por eso se incializa
//indicesToDisplay con el elemento 11 (NONE)
int indicesToDisplay[2][4] = {
  {sevenSegmentsCodes[11], sevenSegmentsCodes[11], sevenSegmentsCodes[11], sevenSegmentsCodes[11]},
  {sevenSegmentsCodes[11], sevenSegmentsCodes[11], sevenSegmentsCodes[11], sevenSegmentsCodes[11]}
};//chequear esta declaracion

int                  currentState               = STATE_WAIT;
int                  currentInput               = 0;
int                  colonMode                  = 0; //0 means OFF, 1 means ON, 2 means blink
static unsigned long currentMillis              = 0;
unsigned long        previousMillis             = 0;
unsigned long        lastTimeButtonsChecked     = 0;
unsigned long        lastTimeColonStatusBlink   = 0;
bool                 markSeconds                = false;
int                 colonStatus                = LOW;

String stringText = "";
String stringMsg = "";
