#ifndef ACTIONS_H
#define ACTIONS_H

/*************** FUNKTIONSDEKLARATIONEN ****************/
// Fahrplan
void check_plan(char plan);                         //Anweisung lesen und Pointer an naechste Stelle
char read_plan(short start);

// Beschleunigen Vorwaerts, Rueckwaerts, Stoppen
void drive();
void stop();
void back();

// Spurassistent
void change_direction_left();
void change_direction_right();
void change_direction();

// Richtungswechsel inkl. 180 Grad Drehung
void spin_around();
void turn_left();
void turn_right();

// Kundenservice
void fetch_guest();

// Suchverfahren
void breitensuche(byte start);
/*************** FUNKTIONSDEKLARATIONEN ****************/

