//written by alex & steven

#include <stdio.h>


void breitensuche(int startPunkt);
void pushKnoten(int aktKnoten);
int getKnoten();
void display(char a);

const int MAX = 70;
int n = 0;
char _FA[] = "xxFxFxxx..x..xF.x.x.Fx.x...xx.x..xxx..x..xx...x.xxx..x.xF..x..Fx..x..x";
int positionsKarte[70];

int main(void)
{
	int startPunkt = 68; //Startpunkt B oder 64 == A

	printf("Fahrplanmatrix\n\n");
	display('c');

	breitensuche(startPunkt);

	printf("Kostenmatrix\n\n");
	display('n');               //Alle erreichbaren '.' wurde konvertiert mit Hilfe der BFS in Zahlen(Kosten)
                                //jedes 'F' ist immer die Zahl 70, jedes 'x' die Zahl 120 und alle nichterreichbaren
                                //'.' sind die Zahl 46. D.h. jede Zahl die < als 'F' und != 46 ist neben ein 'F' ist ein
                                //erlaubter Pfad
	return 0;
}

void display(char a)
{
	int j;
	for (j = 1; j < 71; j++)
	{
		if(a == 'c')	//map display as character
		{
			printf("%c \t",_FA[j-1]);
		}
		else if(a == 'n')	//map display as costs
		{
			printf("%d \t",_FA[j-1]);
		}
		if((j % 7)== 0)
		{
			printf("\n");
		}
	}
	printf("\n\n\n");
}

void pushKnoten(int aktKnoten)
{
	if(n < MAX)
	{
		positionsKarte[n] = aktKnoten;
		n++;
	}
}

int getKnoten()
{
	if(n > 0)
	{
		n--;
		return positionsKarte[n];
	}
}

//Die BFS wandelt alle erreichbaren Punkte in seine Kosten ausgehend vom Startpunkt 64 oder 68 um
void breitensuche(int startPunkt)
{
	int kosten = 0;
	int aktKnoten = startPunkt;
	pushKnoten(aktKnoten);
	_FA[aktKnoten] = kosten;

	do
	{
		kosten++;
		aktKnoten = getKnoten();
		if(_FA[aktKnoten-1] == '.')
		{
			pushKnoten(aktKnoten-1);
			_FA[aktKnoten-1] = kosten;
		}
		if(_FA[aktKnoten-7] =='.')
		{
			pushKnoten(aktKnoten-7);
			_FA[aktKnoten-7] = kosten;
		}
		if(_FA[aktKnoten+1] == '.')
		{
			pushKnoten(aktKnoten+1);
			_FA[aktKnoten+1] = kosten;
		}
		if(_FA[aktKnoten+7] == '.')
		{
			pushKnoten(aktKnoten+7);
			_FA[aktKnoten+7] = kosten;
		}
	}while(aktKnoten != 0);
}

