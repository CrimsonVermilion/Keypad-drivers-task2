#include "tm4c123gh6pm.h"

#ifndef DIO_H
#define DIO_H

void DIOInt(char port,char pins, char direction);
void DIOWritePin(char port,char pin, char value);
void DIOWritePort(char port,char value);
char DIOReadPin(char port,char pin);
char DIOReadPort(char port);
void DIOTogPin(char port,char pin);
void delay(int n);

#define pin0 0b00001
#define pin1 0b00010
#define pin2 0b00100
#define pin3 0b01000
#define pin4 0b10000

#endif