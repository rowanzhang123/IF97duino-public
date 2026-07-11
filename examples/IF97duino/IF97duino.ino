/*
    Original code
    Copyright (C) 2015 Ian H. Bell

    Modified version
    Copyright (C) 2026 Rowan Zhang

    CoolProp IF97 backend ported to the Arduino ecosystem as a meme
    The base example with some functions

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
  Serial.print("Density: ");                            Serial.println(IF97::rhomass_Tp(temp,  pressure));
  Serial.print("Enthalpy: ");                           Serial.println(IF97::hmass_Tp(temp,  pressure));
  Serial.print("Entropy: ");                            Serial.println(IF97::smass_Tp(temp,  pressure));
  Serial.print("Internal Energy: ");                    Serial.println(IF97::umass_Tp(temp,  pressure));
  Serial.print("Constant Pressure Specific Heat: ");    Serial.println(IF97::cpmass_Tp(temp, pressure));
  Serial.print("Constant Volume Specific Heat: ");      Serial.println(IF97::cvmass_Tp(temp, pressure));

  double enthalpy = 0;
  double entropy  = 0;
  enthalpy = IF97::hmass_Tp(temp,  pressure);
  entropy  = IF97::smass_Tp(temp,  pressure);
  Serial.print("Temp from pressure and enthalpy: ");       Serial.println(IF97::T_phmass(pressure, enthalpy));
  Serial.print("Temp from pressure and entropy: ");        Serial.println(IF97::T_psmass(pressure, entropy));
  Serial.print("Pressure from enthalpy and entropy: ");    Serial.println(IF97::p_hsmass(enthalpy, entropy));
  Serial.print("Temp from enthalpy and entropy: ");        Serial.println(IF97::T_hsmass(enthalpy, entropy));

  Serial.println(IF97duino_error);

  digitalWrite(PC13, 1);
  delay(500);
  digitalWrite(PC13, 0);
  delay(500);
}
