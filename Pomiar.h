#include "main.h"

#ifndef _POMIAR_
#define _POMIAR_


class Pomiar {

	friend ostream& operator<<(ostream& stream, Pomiar& pom); //zaprzyjaŸnienie przeladowania operatora<< z klasy ostream aby wyswietlac dane na ekranie
	friend ofstream& operator<<(ofstream& stream, Pomiar& pom); //zaprzyjaŸnienie przeladowania operatora << z klasy ofstream aby zapisac dane do pliku


public:

	enum Kontener { MacierzIncydencji, ListaSasiedztwa };

	Pomiar();

	void show(void); //Wypisanie pomiaru

	void save(string pathToFileWithName); //Zapisuje pomiar do pliku o zadanej œcie¿ce np.: C:/folder/plik.txt

	Kontener kontener;
	double									//zmienne do przechowywania odpowiednich czasów z pomiarów
		MSTprim,		// Na koñcu nazwy:
		MSTkruskal,				// TL -> dotyczy tablicy albo listy 
		NSdijkstra,
		NSford_bellman;				// -> równie¿ dotyczy wszystkich

	long ilosc_wierzcholkow;
	float gestosc;

};


#endif