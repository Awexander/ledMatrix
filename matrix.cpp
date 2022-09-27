#include "matrix.h"
#include "characters.h"

ledmatrix::ledmatrix(uint8_t row, uint8_t col)
{
  _numRow = row;
  _numCol = col;
  _leds = new char[_numRow * _numCol];
  _rowValue = new char[_numRow];
}

void ledmatrix::begin(uint8_t m_rowPin, uint8_t m_colPin, uint8_t m_latchPin, uint8_t m_clockPin)
{
  _rowPin = m_rowPin;
  _colPin = m_colPin;
  _latchPin = m_latchPin;
  _clockPin = m_clockPin;

  pinMode(_rowPin, OUTPUT);
  pinMode(_colPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  memset(_leds, 0, sizeof(_leds));
}

void ledmatrix::setCursor(uint8_t col, uint8_t row)
{
  if(col > _numCol) _colCursor = _numCol;
  else _colCursor = col;
  if(row > _numRow) _rowCursor = _numRow;
  else _rowCursor = row;
}

inline size_t ledmatrix::write(uint8_t value)
{
  uint8_t _col = _colCursor;
  _rowCursor = 0;

  for(int i = 0; i < 8; i++)
  {
    uint8_t data = pgm_read_byte_near(ascii[value] + i);
    for(int j = 5; j >= 0; j--)
    {
      char d = bitRead(data, j);
      *(_leds + i * _numCol + _col) = d;

      _col++;
      if(_col / _numCol > _numCol) break;
    }
    *(_leds + i * _numCol + _col) = 0;
    _col = _colCursor;
  }
  _colCursor += 6;
  
  return 1;
}

void ledmatrix::display()
{
  for(int a = 0; a < _numRow; a++)
  {
    Serial.print("Row");Serial.print(a);Serial.print(" : ");
    for(int i = 0; i < _numCol; i++)
    {
      Serial.print(" ");
      if(i > _colCursor) break;

      if(*(_leds + a * _numCol + i) == 1)
      {
        Serial.print('#');
      }
      else Serial.print('.');
    }
    Serial.println();
  }

  delete []_leds;
}
