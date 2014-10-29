/*************** INCLUDES ****************/
#include "actions.h"
/*************** INCLUDES ****************/

/*****************************************************************************/
/******************** Ab hier erfolgt die Implementierung ********************/
/*****************************************************************************/
char startPoint = 0;

char routenArray[] = {'g','r','l','g','l','l','g','l','r','g','r'};
int max = 11;
int i = 0;

unsigned long delay = 0;
const int offset = 400;

char checkStartPoint()
{
    while(startPoint == 0)
	{
		if(dip_pin(0) == 1)
		{
			startPoint = 64;
			lcd_cls();
			lcd_setxy(0,0);
			lcd_ubyte(startPoint);
		}
		else if(dip_pin(3) == 1)
		{
			startPoint = 68;
			lcd_cls();
			lcd_setxy(0,0);
			lcd_ubyte(startPoint);
		}
		else
		{
			lcd_cls();
			lcd_setxy(0,0);
			lcd_puts("Kein Startpunkt");
			lcd_setxy(1,0);
			lcd_puts("vergeben");
			sleep(500);
		}
	}
	return startPoint;
}

void checkStart()
{
    while(PHOTOSENSOR < 100);
    //Wenn Photosensor bemerkt, dass Startlampe aus ist, dann beende Endlosschleife while(1);
}
void navigate()
{
    //wenn einer der beiden mittleren Optokoppler auf schwarz - Kreuzung (Hoechste Prioritaet)
    if((OPTOKOPPLER_MITTE_LINKS > 18 || OPTOKOPPLER_MITTE_RECHTS > 18) && delay <= akt_time())
    {
		led(0,1);
        crossroads();
    }
    //Linker mittlerer Optokoppler schwarz UND rechter mittlerer Optokoppler weiß
	else if(OPTOKOPPLER_VORNE_LINKS > 150)
	{
		led(0,0);
		steerLeft();
	}
    //Rechter mittlerer Optokoppler schwarz UND linker mittlerer Optokoppler weiß
	else if(OPTOKOPPLER_VORNE_RECHTS > 150)
	{
		led(0,0);
		steerRight();
	}
    //beide Optokoppler weiß
	else
	{
		led(0,0);
		drive();
	}
}
void drive()
{
    //Linker und rechter Motor muessen sich entgegengesetzt drehen -> Polung
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
}

void stop()
{
    //linkes und rechtes Rad stoppen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, STOP);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, STOP);
}

void back()
{
    //Wie drive nur umgekehrt
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
}

void steerLeft()
{
    //linkes Rad abbremsen, rechtes Rad drehen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, MINSPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
}

void steerRight()
{
    //linkes Rad drehen, rechtes Rad abbremsen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, MINSPEED);
}

void biegeRechtsAb()
{
    //Raeder drehen sich entgegengesetzt mit gleicher Staerke
	motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, STOP);
}

void biegeLinksAb()
{
    //Raeder drehen sich entgegengesetzt mit gleicher Staerke
	motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_LINKS, STOP);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_VORWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
}

void spin_around()
{
    //linkes Rad und rechtes Rad in gleiche Richtung drehen
    motor_richtung(MOTOR_LINKS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_LINKS, SPEED);
    motor_richtung(MOTOR_RECHTS, MOTOR_RICHTUNG_RUECKWAERTS);
    motor_pwm(MOTOR_RECHTS, SPEED);
}

void crossroads()
{
    //biegeRechtsAb ist nur Beispiel - ansonsten Fkt. aufrufen abarbeiten() -> Array verarbeiten
    biegeLinksAb();
	sleep(1000);			//Damit hintere Opto von schwarz runterkommt
	while(OPTOKOPPLER_VORNE < 70);			//solange weiss ->
	
	delay = akt_time() + offset;
}


