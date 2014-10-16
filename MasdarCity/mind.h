#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const byte MAX = 30;
byte byte auftrag[MAX] = 0;
byte index = 0;

void putANummer(byte nummer)
{
    if(index < MAX-1)
    {
        auftrag[index] = nummer;
        if(index != MAX-1){
            index++;
        }

    }
}

byte getANummer()
{
    if(index >= 0)
    {
        byte hilf;
        hilf = auftrag[index];
        if(index > 0)
        {
           index--;
        }
        return hilf;
    }
}
