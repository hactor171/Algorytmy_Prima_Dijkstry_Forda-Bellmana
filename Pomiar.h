#include "main.h"

#ifndef _POMIAR_
#define _POMIAR_


class Pomiar {

	friend ostream& operator<<(ostream& stream, Pomiar& pom); //zaprzyja�nienie przeladowania operatora<< z klasy ostream aby wyswietlac dane na ekranie
	friend ofstream& operator<<(ofstream& stream, Pomiar& pom); //zaprzyja�nienie przeladowania operatora << z klasy ofstream aby zapisac dane do pliku


public:

	enum Kontener { MacierzIncydencji, ListaSasiedztwa };

	Pomiar();

	void show(void); //Wypisanie pomiaru

	void save(string pathToFileWithName); //Zapisuje pomiar do pliku o zadanej �cie�ce np.: C:/folder/plik.txt

	Kontener kontener;
	double									//zmienne do przechowywania odpowiednich czas�w z pomiar�w
		MSTprim,		// Na ko�cu nazwy:
		MSTkruskal,				// TL -> dotyczy tablicy albo listy 
		NSdijkstra,
		NSford_bellman;				// -> r�wnie� dotyczy wszystkich

	long ilosc_wierzcholkow;
	float gestosc;

};


#endif