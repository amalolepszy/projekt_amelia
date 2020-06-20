#include<iostream>
#include"paragraf.h"

using namespace std;

int main()
{
	Paragraf p1;	//deklaracja przedstawiciela klasy paragraf
	p1.setup();		//otwarcie okienka
	while(true)
	{
		
		p1.wczytaj(); //wczytaj treść paragrafu z pytaniami z plików tekstowych
		p1.wyswietl();	//wyświetl treść paragrafów, gracz wybiera następny paragraf
		p1.sprawdz();	//wybór gracza decyduje o kolejnym paragrafie
		if (p1.koniecgry())	//jeżeli paragraf kończy grę
		{
			p1.odnowa();	//zacznij od początku
		}
		p1.pozamiataj();	//wyzeruj dane z ostatniego paragrafu
	}
	cin.get();
	return 0;
}