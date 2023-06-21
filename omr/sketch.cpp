#include <Arduino.h>

int f;
int b;
int a;
int n;
void setup()
{
Serial.begin(9600);

}

void loop()
{
  while(Serial.available())
  {
    n = Serial.read();
    move(n);
  }

}
void move(int i)
{
  if(i >= 189)
  {i = i-189;
  f = 5;
  b = 4;
  }
  else if (i >= 126)
  {i = i - 126;
  f = 9;
  b = 8;
  }
  else if (i >= 63)
  { i = i - 63;
  f = 6;
  b = 7;
  }
  else
  { f = 3;
    b = 2;
  }
  if(i == 31)
  {
    analogWrite(f,0);
    digitalWrite(b,0);
  }
  else if(i > 31)
  {
    a = 8 * (i -30) - 1;
    analogWrite(f,a);
    digitalWrite(b,0);
  }
  else
  {
    a = 255 + (8 * (i - 32) + 1);
    analogWrite(f,a);
    digitalWrite(b,1);
  }
}
