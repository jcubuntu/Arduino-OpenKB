#ifndef OPEN_KB_BOARD

#define OPEN_KB_BOARD   1
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack_KB.h"

Adafruit_8x16minimatrix _matrix = Adafruit_8x16minimatrix();

void startMatrix(void){
    _matrix.begin(0x70);
    _matrix.setRotation(1);
    _matrix.setTextSize(1);
    _matrix.setTextWrap(false);  
    _matrix.setTextColor(LED_ON);
}

void matrixPrint(int8_t _startPos, char *_inputText, uint8_t _displaySpeed, bool _warper = false) {
  _matrix.setTextWrap(_warper);
  _displaySpeed = 150 - _displaySpeed;
  int _textLenght = strlen(_inputText);
  int _endPos = (_startPos - ((_textLenght * 6)+_startPos))+16;
    _matrix.clear();
    _matrix.setCursor(_startPos, 0);
    _matrix.print(_inputText);
    _matrix.writeDisplay();
    delay(_displaySpeed*2);
  for (int _x = _startPos; _x >= _endPos ; _x--) {
    _matrix.clear();
    _matrix.setCursor(_x, 0);
    _matrix.print(_inputText);
    _matrix.writeDisplay();
    delay(_displaySpeed);
  }
}




#endif