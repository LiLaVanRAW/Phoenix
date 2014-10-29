#ifndef ACTIONS_H
#define ACTIONS_H

/*************** INCLUDES ****************/
#include <stdio.h>
#include <regc515c.h>
#include "stub.h"
/*************** INCLUDES ****************/

/*************** DIREKTIVEN ***************/
#define PHOTOSENSOR (analog(14))
#define SCHWARZ 18
#define MOTOR_LINKS 0                    // Motor linkes Rad, Port 1
#define MOTOR_RECHTS 2                   // Motor rechtes Rad, Port2
#define MOTOR_RICHTUNG_VORWAERTS 1       // 
#define MOTOR_RICHTUNG_RUECKWAERTS 0
#define SPEED 7                         // Standardgeschwindigkeit
#define MINSPEED 2  
#define STOP 0                           // Geschwindigkeit auf 0 setzen
#define Startpoint_A 64                  // Startpunkt A ist der 64.te Punkt auf dem Gitternetz
#define Startpoint_B 68                  // Startpunkt B ist der 68.te Punkt auf dem Gitternetz
#define OPTOKOPPLER_MITTE_LINKS (analog(4))
#define OPTOKOPPLER_MITTE_RECHTS (analog(6))
#define OPTOKOPPLER_VORNE_LINKS (analog(7))
#define OPTOKOPPLER_VORNE_RECHTS (analog(8))
#define OPTOKOPPLER_VORNE (analog(0))
#define GREIFER_OFFEN 0
#define GREIFER_GESCHLOSSEN 1
/*************** DIREKTIVEN ***************/


/****** GITTERNETZ ******/           // Wobei die Ecken 0, 6, 63, 69 nicht beruecksichtigt werden
/*  0  1  2  3  4  5  6 */
/*  7  8  9 10 11 12 13 */
/* 14 15 16 17 18 19 20 */
/* 21 22 23 24 25 26 27 */
/* 28 29 30 31 32 33 34 */
/* 35 36 37 38 39 40 41 */
/* 42 43 44 45 46 47 48 */
/* 49 50 51 52 53 54 55 */
/* 56 57 58 59 60 61 62 */
/* 63  A 65 66 67  B 69 */
/****** GITTERNETZ ******/

/*************** FUNKTIONSDEKLARATIONEN ****************/
// Startpunkt pruefen
char checkStartPoint();

// Fahrplan
void check_plan(char plan);                         //Anweisung lesen und Pointer an naechste Stelle
char read_plan(short start);						// l,r,g aus array auslesen

//Start pruefen - Licht aus?
void checkStart();

// Kontrolle der Fahrt -> Spur, Kreuzung
void navigate();									//

// Beschleunigen Vorwaerts, Rueckwaerts, Stoppen
void drive();
void stop();
void back();

// Spurassistent - Links und Rechts steuern
void steerLeft();
void steerRight();

// Richtungswechsel inkl. 180 Grad Drehung
void spin_around();
void biegeLinksAb();
void biegeRechtsAb();

// Kreuzung abarbeiten
void crossroads();

// Kundenservice
void fetch_guest();

/*************** FUNKTIONSDEKLARATIONEN ****************/

#endif
