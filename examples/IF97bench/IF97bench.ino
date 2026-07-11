/*
    Original code
    Copyright (C) 2015 Ian H. Bell

    Modified version
    Copyright (C) 2026 Rowan Zhang

    CoolProp IF97 backend ported to the Arduino ecosystem as a meme
    IF97bench is an indicative test for microcontroller compute power by performing IF97 enthalpy calculations

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
}

double temp     = 400.0;  // k
double pressure = 101325; // Pa

void loop() {
  // Some of the features, not all are shown here
  int end_time = 0;
  int start_time = micros();
  double results = 0;

  results = IF97::hmass_Tp(temp,  pressure) - IF97::hmass_Tp(300,  pressure);
  end_time = micros() - start_time;
  
  Serial.print("Time used: ");
  Serial.println(end_time);

  Serial.print("Enthalpy diff: ");
  Serial.println(results);

  digitalWrite(PC13, 1);
  delay(500);
  digitalWrite(PC13, 0);
  delay(500);
}
