#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define SALT 9
#define PEPPER 11

#define GREEN 4
#define RED 6
#define BLUE 8

#define OFF 0
#define ON 1

int state = 0;
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  Serial.begin(9600);
  alpha4.begin(0x70);  // pass in the address

  pinMode(SALT, INPUT);
  pinMode(PEPPER, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  int sVal = digitalRead(SALT);
  int pVal = digitalRead(PEPPER);

  Serial.print(sVal);
  Serial.print("  ");
  Serial.print(pVal);
  Serial.print("\t");
  
  if (sVal == 1 || pVal == 1) {
    if (state == OFF) {
      displayWord("    START   ", 5, 0,1,0);
    }
    else {
      if (sVal == 1) {
        displayWord("    SALT   ", 4, 0,0,1);
      }
      if (pVal == 1) {
        displayWord("    PEPPER   ", 6, 0,0,1);
      } 
    }
    state = ON;
  }
  else {
    if (state == ON) {
      displayWord("    STOP   ", 4, 1,0,0);
    }
    else {
      displayWord("       ", 0, 0,0,0);
    }
    state = OFF;
  }
  Serial.println("");
}

void displayWord(char* c, int n, int r, int g, int b) {
  Serial.print(r);
  Serial.print("  ");
  Serial.print(g);
  Serial.print("  ");
  Serial.print(b);
  Serial.print("  ");
  
  digitalWrite(RED, 1-r);
  digitalWrite(GREEN, 1-g);
  digitalWrite(BLUE, 1-b);
  
  for (int i = 0; i < n + 4; i++) {
    alpha4.writeDigitAscii(0, c[i]);
    alpha4.writeDigitAscii(1, c[i+1]);
    alpha4.writeDigitAscii(2, c[i+2]);
    alpha4.writeDigitAscii(3, c[i+3]);

    alpha4.writeDisplay();
    delay(200);
  }
}

