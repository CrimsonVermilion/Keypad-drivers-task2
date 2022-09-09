#include "keypad.h"
#include <stdio.h>


float calculator(char*digits);


char reading;
int main()
{
  KeyPad_Init();
  
  char digits[3] ;
  int i =0 ;
  while(1)
  {
    while (reading != '=')
    {
      reading = KeyPad_Read();
      if ((reading != '=') && (reading != 0))
      {
        digits[i] = reading;
        printf("%c",reading);
        i++;
        reading = 0;
      }
    }
    i=0;
    calculator(digits);
    reading = 0;
  }
}



float calculator(char*digits)
{
  float result;
  switch (digits[1])
  {
  case '+':
   result = (digits[0]-'0') + (digits[2]-'0');
    break;
  case '-':
       result = (digits[0]-'0') - (digits[2]-'0');
    break;
    case'*':
         result = (digits[0]-'0') * (digits[2]-'0');
    break;
    case'/':
        result = (float)(digits[0]-'0') / (float)(digits[2]-'0');
    break;
  }
  printf("\n the result is = %f \n",result);
  return result;
}