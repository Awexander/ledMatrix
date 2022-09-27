#include "variables.h"
#include "matrix.h"

ledmatrix leds(NUM_ROW, NUM_COL);
void setup() 
{
  Serial.begin(115200);
  leds.begin(rowPin, colPin, latchPin, clockPin);
  leds.setCursor(0,0);
  leds.print("awexander");
  leds.display();
  leds.setCursor(0,0);
  leds.print("12:99");
  leds.display();
}

void loop() 
{

}