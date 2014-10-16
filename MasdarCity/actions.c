#ifndef ACTIONS_H
#define ACTIONS_H

include "actions.h"

/*************** DIREKTIVEN ***************/
#define MOTOR_LINKS 0                    // Motor linkes Rad, Port 1
#define MOTOR_RECHTS 2                   // Motor rechtes Rad, Port2
#define MOTOR_RICHTUNG_VORWAERTS 1       // Zahlen können umgekehrt sein
#define MOTOR_RICHTUNG_RUECKWAERTS 0
#define SPEED 10                         // Standardgeschwindigkeit
#define STOP 0                           // Geschwindigkeit auf 0 setzen
#define Startpoint_A 64                  // Startpunkt A ist der 64.te Punkt auf dem Gitternetz
#define Startpoint_B 68                  // Startpunkt B ist der 68.te Punkt auf dem Gitternetz
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

/*****************************************************************************/
/******************** Ab hier erfolgt die Implementierung ********************/
/*****************************************************************************/
void drive()
{
    //Linker und rechter Motor muessen sich entgegengesetzt drehen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
    return 0;
}

void stop()
{
    //linkes und rechtes Rad stoppen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, STOP);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, STOP);
    return 0;
}

void back()
{
    //Wie drive nur umgekehrt
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
    return 0;
}

void change_direction_left()
{
    //linkes Rad stoppen, rechtes Rad drehen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, STOP);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
    return 0;
}

void change_direction_right()
{
    //linkes Rad drehen, rechtes Rad stoppen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, STOP);
    return 0;
}

void change_direction()
{
    /* Momentan Pseudocode!!

    //if (linker Optokoppler schwarz => Wert > 150 && rechter Optokoppler weiß => Wert < 150)
    //{
    //  change_direction_right();
    //}
    else if(wie davor nur umgekehrt)
    //{
    //  change_direction_left();
    //}
    //else
    //{
    //  drive();
    //}*/
}

void spin_around()
{
    //linkes Rad und rechtes Rad in gleiche Richtung drehen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
    return 0;
}

