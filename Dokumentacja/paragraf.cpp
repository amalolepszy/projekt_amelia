#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<conio.h>
#include<algorithm>
#include<Windows.h>
#include"paragraf.h"

using namespace std;

void Paragraf::setup()
{
	HWND console = GetConsoleWindow();		//deklaracja uchwytu konsoli
	RECT ConsoleRect;		//definicja lewego górnego i prawego dolnego narożnika okienka
	GetWindowRect(console, &ConsoleRect);		//pobranie prostokąta określającego wymiary i położenie okna
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 500, TRUE); //zmiana położenia okienka tak, aby miało wymiary 1100x500 pikseli
}

void Paragraf::wczytajtresc() //ok!
{
	fstream pliktresc; //wczytywanie tresci z pliku z treścią

	string nazwa_pliku_tresc = to_string(numer_paragrafu);	//utworzenie nazwy otwieranego pliku z numeru paragrafu
	nazwa_pliku_tresc += "-nopl.txt";	//dodanie przyrostka do stringa, by zgadzała się nazwa pliku
	nazwa_pliku_tresc = "pliki_amelia/" + nazwa_pliku_tresc; //dodanie przedrostka ścieżki pliku
	pliktresc.open(nazwa_pliku_tresc.c_str(), ios::in);		//zmiana typu nazwy pliku na char, otwieranie danego pliku
	
	if (pliktresc.good()==false)
	{
		cout << "Blad z wczytaniem pliku tresci!" << endl;
		cin.get();
		exit(0);
	}
	
	
	string bufor; //utworzenie bufora, którzy będzie przechowywał linijkę tekstu z pliku
	while (true)
	{
		getline(pliktresc, bufor);	//przekazanie tresci z pliku do stringa "bufor"
		tresc += bufor;	//treść składa się z linijki tekstu wczytanego z pliku...
		tresc += "\n";	//... oraz po każdej linijce jest znak nowego wiersza
		if (pliktresc.eof()) //jeżeli koniec pliku, przerwij
		{
			break;
		}
	}
	
	pliktresc.close(); //zamknięcie pliku

}

void Paragraf::wczytajitem()
{
	fstream plikitem; //wczytywanie tresci z pliku z treścią
	string nazwa_pliku_item = to_string(numer_paragrafu);	//utworzenie nazwy otwieranego pliku z numeru paragrafu
	nazwa_pliku_item += "-item.txt";	//dodanie przyrostka do stringa, by zgadzała się nazwa pliku
	nazwa_pliku_item = "pliki_amelia/" + nazwa_pliku_item;
	plikitem.open(nazwa_pliku_item.c_str(), ios::in);		//zmiana typu nazwy pliku na char, otwieranie danego pliku

	if (plikitem.good() == false)	//jeśli pliku nie da się otworzyć
	{
		cout << "Blad z wczytaniem pliku itemu!" << endl;
		cin.get();
		exit(0);
	}

	plikitem >> item; //przekazanie itemu do składowej klasy paragrafu

	if (item != 0)
	{
		if(find(itemygracza.begin(),itemygracza.end(),item)==itemygracza.end()) // jeżeli nie ma itemu w zbiorze itemów gracza
		itemygracza.push_back(item);	//dodanie do itemów gracza
	}
}


void Paragraf::wczytajnumerypytan()
{
	
	fstream plik_numerypytan;
	string nazwa_pliku_numerypytan = to_string(numer_paragrafu);	
	nazwa_pliku_numerypytan += "-odp.txt";
	nazwa_pliku_numerypytan = "pliki_amelia/" + nazwa_pliku_numerypytan;
	plik_numerypytan.open(nazwa_pliku_numerypytan.c_str(), ios::in);		//zmiana typu nazwy pliku na char, otwieranie danego pliku

	if (plik_numerypytan.good() == false)	//jeśli pliku nie da się otworzyć
	{
		cout << "Blad z wczytaniem pliku numeru pytan!" << endl;
		cin.get();
		exit(0);
	}
	int bufor;
	while (true)
	{
		plik_numerypytan >> bufor;		//prześlij do bufora
		numery_pytan.push_back(bufor);		//dodaj do wektora numery_pytan
		if (plik_numerypytan.eof()) //jeżeli koniec pliku, przerwij
		{
			break;
		}
	}

	plik_numerypytan.close(); //zamknięcie pliku

}

void Paragraf::wczytajtrescpytan()
{

	fstream plik_pytanie;
	string nazwa_pliku_pytanie = to_string(numer_paragrafu);
	nazwa_pliku_pytanie += "-mozliwe.txt";
	nazwa_pliku_pytanie = "pliki_amelia/" + nazwa_pliku_pytanie;
	plik_pytanie.open(nazwa_pliku_pytanie.c_str(), ios::in);		//zmiana typu nazwy pliku na char, otwieranie danego pliku

	if (plik_pytanie.good() == false)	//jeśli pliku nie da się otworzyć
	{
		cout << "Blad z wczytaniem pliku tresci pytan!" << endl;
		cin.get();
		exit(0);
	}
	string bufor;
	while (true)
	{
		getline(plik_pytanie, bufor);	//linijke tekstu prześlij do bufora
		pytania_tresc.push_back(bufor);		//dodaj wektor do wektora pytania_tresc
		if (plik_pytanie.eof()) //jeżeli koniec pliku, przerwij
		{
			break;
		}
	}

	plik_pytanie.close(); //zamknięcie pliku

}


void Paragraf::wczytaj()
{
	wczytajtresc();
	wczytajitem();
	wczytajnumerypytan();
	wczytajtrescpytan();
}

void Paragraf::wyswietl()
{
	int x, y;		//zmienne przechowujące wartości funkcji _getch()
	int czy_strzalka = 0;		//numer wektora przy którym ma być pokazana strzałka:
	string strzalka = "\t<-";		//deklaracja zmiennej strzałka, przechowującej strzałkę
	system("cls");	//wyczyść ekran po poprzednim paragrafie
	do    //rozpoczęcie pętli do while
	{
		
		cout << "Paragraf " << numer_paragrafu << "\t \t \t \t \t \t \t \t";
		cout << "Znane informacje: ";
		for (int i = 0; i < itemygracza.size(); i++)
		{
			cout << "#" << itemygracza[i] << "\t";		//wypisanie itemów gracza
		}

		cout << endl << "################################################################################################################################################" << endl;
		cout << tresc << endl;		//wypisanie treści paragrafu
		cout << "################################################################################################################################################" << endl;

		
			for (int i = 0; i < pytania_tresc.size(); i++)		//wyświetlenie pytań do wyboru
			{
				if (i == czy_strzalka)		//jeżeli i-te pytanie ma mieć postawioną strzałkę
				{
					cout << pytania_tresc[i] << strzalka << endl;		//wypisanie i-tego pytania ze strzałką
				}
				else
				{
					cout << pytania_tresc[i] << endl;		//reszta pytań bez strzałek
				}
			}
			
			x = _getch();		//wyłapanie getcha
			if (x == 224)		//jeśli górna/dolna strzałka
			{
				y = _getch();	//wyłapanie drugiego getcha
				if (y == 72) //do góry
				{
					if (czy_strzalka != 0)		//jeżeli strzałka nie jest na pierwszej pozycji
					{
						czy_strzalka--;		//zmniejsz wartość o jeden
					}
				}
				if (y == 80)//w dół
				{
					if (czy_strzalka != pytania_tresc.size() - 1)		//jeżeli nie jest na ostatniej pozycji
					{
						czy_strzalka++;		//zwiększ o jeden

					}

				}
			}
		
		 if (numery_pytan[0] == 0)		//jeżeli wektor numery_pytan wczytal wartość 0 z pliku
		{
			koniec = 1;		//zakończ grę
		}
		system("cls");	//wyczyść ekran
	}
	while (x != 13);	//dopóki użytkownik nie wciśnie klawisza Enter

	odpowiedz = numery_pytan[czy_strzalka];		//odpowiedz gracza = pytanie, przy którym stała strzałka kiedy gracz nacisnął Enter
}


void Paragraf::sprawdz()
	{
	numer_paragrafu = odpowiedz;
	}

void Paragraf::pozamiataj()
{
	numery_pytan.clear();
	pytania_tresc.clear();
	tresc = "";

}
	 
void Paragraf::odnowa()
{
	numer_paragrafu = 0;
	itemygracza.clear();
	numery_pytan.clear();
	pytania_tresc.clear();
	tresc = "";
	koniec = 0;

}

bool Paragraf::koniecgry()
{
	if (koniec == 1)
		return true;
	return false;
}

Paragraf::Paragraf(int nr, string tr, int it, int kon)
{
	numer_paragrafu = nr;
	tresc = tr;
	item =it;
	
	koniec = kon;
}

Paragraf::~Paragraf()
{
	system("cls");
}