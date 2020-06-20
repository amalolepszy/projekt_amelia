#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Gracz
{
protected:
	vector <int> itemygracza;		//przechowuje itemy zebrane przez gracza
	vector <int> numery_pytan;		//przechowuje numery pytań spośród których gracz może wybrać
	vector<string> pytania_tresc;		//przechowuje treść pytań spośród których gracz może wybrać
	int odpowiedz;		//odpowiedz udzielona na pytanie - miejsce w wektorze numery_pytan zajmowane przez wybraną odpowiedz
};


class Paragraf :protected Gracz
{
protected:
	int numer_paragrafu;		//numer wyświetlanego paragrafu
	string tresc;		//treść paragrafu
	int item;			//item do zebrania w danym paragrafie
	int koniec;			//wartość 0 lub 1, mówi o zkaończeniu gry
public:
	Paragraf(int = 0, string = "", int = 0, int = 0);		//konstruktor
	~Paragraf();		//destruktor
	
	void setup();		//otwiera okienko konsoli w określonych rozmiarach
	void wczytaj();		//zawiera metody wczytajtresc(), wczytajnumerypytan(), wczytajtrescpytan(), wczytajitem()
	void wczytajtresc();		//wczytuje treść paragrafu, przypisuje zmiennej tresc
	void wczytajnumerypytan();		//wczytuje możliwe numery paragrafu do wyboru, wrzuca do wektora numery_pytan
	void wczytajtrescpytan();		//wczytuje treści pytań do wyboru, wrzuca do wektora pytania_tresc
	void wczytajitem();		//wczytuje itemy do zebrania w paragrafie, wrzuca do wektora itemygracza
	void wyswietl();		//wyswietla numer paragrafu, jego tresc, wszystkie zdobyte itemy, możliwe pytania, oraz umożliwia wybór strzałkami
	void sprawdz();		//sprawdza odpowiedz gracza, przypisuje zmiennej numer_paragrafu odpowiedz gracza
	void pozamiataj();		//zeruje wektory numery_pytan, pytania_tresc, oraz zmienną tresc
	bool koniecgry();		//jezeli zmienna koniec =1, zakończ gre
	void odnowa();		//zeruje wszystkie wektory, zmienne tresc, koniec, oraz wróć do menu głównego
};


