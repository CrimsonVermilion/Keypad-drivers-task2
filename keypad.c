#include "keypad.h"

const char arr[4][4] = {{49,50,51,'-'},{52,53,54,'+'},{55,56,57,'/'},{'*',48,'#','='}};


void KeyPad_Init()
{
    // intialize port E from pins 3-0 as output
    DIOInt('E',0x0F,0x0F); 
    // intialize port C from pins 7-4 as input 
    DIOInt('C',0xF0,0x0F);  

}

unsigned char KeyPad_Read(void)
{
  DIOWritePort('E',0);
  //checks if any of the of the input pins has a zero on it
  
  if ( (DIOReadPort('C') & 0xF0) == 0xF0){
    delay(50);
    return 0;
  }
  
  for (int i = 0; i<4;i++)
  {
      DIOWritePort('E',0x0F);
      DIOWritePin('E',i,0);
      if ((DIOReadPort('C') & 0xF0) == 0xE0)
      {
        delay(50);
        if ((DIOReadPort('C') & 0xF0) == 0xE0)
        {
        while ((DIOReadPort('C') & 0xF0) == 0xE0);
        return arr[i][0];
        }
      }
      else if ((DIOReadPort('C') & 0xF0) == 0xD0)
      {
        delay(50);
        if ((DIOReadPort('C') & 0xF0) == 0xD0)
        {
        while ((DIOReadPort('C') & 0xF0) == 0xD0);
        return arr[i][1];
        }
      }
      else if ((DIOReadPort('C') & 0xF0) == 0xB0)
      {
        delay(50);
        if ((DIOReadPort('C') & 0xF0) == 0xB0)
        {
        while ((DIOReadPort('C') & 0xF0) == 0xB0);
        return arr[i][2];
        }
      }
      else if ((DIOReadPort('C') & 0xF0) == 0x70)
      {
        delay(50);
        if ((DIOReadPort('C') & 0xF0) == 0x70)
        {
        while ((DIOReadPort('C') & 0xF0) == 0x70);
        return arr[i][3];
        }
      }
   }
  return 0;
}