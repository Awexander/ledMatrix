#ifndef matrix_h
#define matrix_h
#include <arduino.h>
#include <stdio.h>
#include <Print.h>


class ledmatrix : public Print
{
  public:
    ledmatrix(uint8_t rows, uint8_t cols);
    void begin(uint8_t m_rowPin, uint8_t m_colPin, uint8_t m_latchPin, uint8_t m_clockPin);
    virtual size_t write(uint8_t);
    void setCursor(uint8_t, uint8_t);
    void display();

  private:
    uint8_t _rowPin;
    uint8_t _colPin;
    uint8_t _latchPin;
    uint8_t _clockPin;

    uint8_t _numRow;
    uint8_t _numCol;
    uint8_t _rowCursor = 0;
    uint8_t _colCursor = 0;

    uint8_t * _leds;
    uint8_t * _rowValue;
};
#endif

