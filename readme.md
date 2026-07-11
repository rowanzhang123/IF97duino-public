# IF97duino
CoolProp IF97 backend ported to the Arduino (R) Development Environment as a meme\
All original IF97 C++ functions should work

## Meme origin
This project has been heavily inspired by the popular "Can it run DOOM?" internet meme, except the question we are asking here is "Can it run CoolProp?"

## Important note
Since most Arduino (R) compatible microcontrollers lacks the ability to handle exceptions, the "throw" has been replaced with an error String of "IF97duino_error", the program will not halt if an invalid parameter set was used, it is up to the user to interpret the correctness of the results. A spreasheet of PropsSI calls have been included, it calculates the same state points as the example files listed within, and should be close to the output from the library

## IF97bench
It was later realized due to the double-precision floating-point computational requirements of IF97, it has the potential to be used as a benchmark for the computational capabilities of microcontrollers by observing the time taken to perform a calculation

| Microcontroller | Time taken (IF97bench.ino, microseconds) |
| --------------- | ---------------------------------------- |
| STM32H743VIH6   | 177                                      |
| STM32H503CBT6   | 996                                      |
| STM32F405RGT6   | 809                                      |
| STSPIN32G4      | 1033                                     |
| RP2040          | 1215                                     |

## Acknowledgments
This project would not have been possible without the original CoolProp library
```
I. Bell and CoolProp team, “CoolProp/IF97: Open-source C++ implementation of the IAPWS-IF97 equations,” GitHub, https://github.com/CoolProp/IF97 (accessed Jun. 14, 2026).
```
```
CoolProp Team and I. H. Bell, “Welcome to coolprop#,” Welcome to CoolProp - CoolProp 7.2.0 documentation, https://coolprop.org/ (accessed Jun. 14, 2026). 
```