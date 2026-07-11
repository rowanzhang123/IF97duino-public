/*
    Original code
    Copyright (C) 2015 Ian H. Bell

    Modified version
    Copyright (C) 2026 Rowan Zhang

    CoolProp IF97 backend ported to the Arduino ecosystem as a meme
    Produce a T-H saturation curve, using a backward calculation function

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "IF97.h"

void setup() {
  Serial.begin(115200);
  pinMode(PC13, OUTPUT);
  while (!Serial.available()) {}
}

#define temp     300 // K
#define pressure 1000000 // Pa

void loop() {
  // Initializating H, and T
  double my_enthalpy = IF97::hmass_Tp(temp,pressure);
  double my_temp     = temp;
  
  while (my_temp < 600) {
    my_enthalpy = my_enthalpy + 50000;
    my_temp     = IF97::T_phmass(pressure, my_enthalpy);
    Serial.println(String(my_enthalpy,4) + "," + String(my_temp,4));
  }

  Serial.println(IF97duino_error);  

  digitalWrite(PC13, 1);
  delay(500);
  digitalWrite(PC13, 0);
  delay(500);
}
