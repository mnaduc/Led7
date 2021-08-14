#include <Arduino.h>
#include "Led7.h"

Led7 led7;

void setup()
{
  led7.check();
}

void loop()
{
  led7.display(-1);
  delay(500);
  for (size_t i = 0; i < 10; i++)
  {
    led7.display(i);
    delay(500);
  }
  // led7.display('A');
  // delay(500);
  // led7.display('B');
  // delay(500);
  // led7.display('C');
  // delay(500);
  // led7.display('D');
  // delay(500);
  // led7.display('E');
  // delay(500);
  // led7.display('F');
  // delay(500);
  // led7.display('H');
  // delay(500);
  // led7.display('I');
  // delay(500);
  // led7.display('J');
  // delay(500);
  // led7.display('L');
  // delay(500);
  // led7.display('N');
  // delay(500);
  // led7.display('O');
  // delay(500);
  // led7.display('P');
  // delay(500);
  // led7.display('R');
  // delay(500);
  // led7.display('S');
  // delay(500);
  // led7.display('U');
  // delay(500);
  // led7.display('Y');
  // delay(500);
  // led7.display('Z');
  // delay(500);
}
