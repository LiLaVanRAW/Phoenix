/***************************/
/* project: phoenix v1_0 */
/* authors: alexandra, steven   */
/* date:    02.10.2014     */
/***************************/

//Standard Inlcude Dateien
#include <regc515c.h>

//Aksen-Bibliothek
#include <stub.h>

//Eigene Inludes
#include "actions.h"
#include "mind.h"

#define GREIFER_OFFEN 0
#define GREIFER_GESCHLOSSEN 1


void AksenMain(void)
{
byte current_startpoint = 0;
//char check = 99; //Variable zum Pruefen ob Fahrgast vorhanden und Route absolvierbar ist

// Startposition A oder B eventuell mit seitlichen Dipschaltern ueberpruefen => if...

// Initialisierung Suchverfahren
while(1)
{
  lcd_setxy(0,0);
  lcd_ubyte(analog(8));
    //breitensuche(current_startpoint);

// Fahrplan laden

// Fahrplan auslesen -> iterativer Prozess abhängig von der Anzahl der Fahrgaeste
    //check = read_plan(current_startpoint);

// transportierte Fahrgaeste auf Karte mit x etc. markieren aber nicht mit 'F'

// Codeanzeige auf Display, ob Fahrgast vorhanden, Route passierbar ist -> lcd_puts("0, -1 oder -2")

...

//Start wenn Licht aus ist -> drive();
}

/*
void breitensuche(byte start)
{
    byte aktPosition = start;
    byte kosten = 0;
    byte kostenKarte[] = 99;

    kostenKarte[aktPosition] = 0;
    putANummer(aktPosition);

    while(aktPosition != 0)
    {
        kosten++;
        if(_fa[aktPosition+1] == '.')
        {
            putANummer(aktPosition+1);
            kostenKarte[aktPosition+1] = kosten;
        }
        if(_fa[aktPosition+7] == '.')
        {
            putANummer(aktPosition+7);
            kostenKarte[aktPosition+7] = kosten;
        }
        if(_fa[aktPosition-1] == '.')
        {
            putANummer(aktPosition-1);
            kostenKarte[aktPosition-1] = kosten;
        }
        if(_fa[aktPosition-7] == '.')
        {
            putANummer(aktPosition-7);
            kostenKarte[aktPosition-7] = kosten;
        }
    }  */
}
}
