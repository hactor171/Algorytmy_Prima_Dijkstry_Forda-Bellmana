
#include "Krawedz.h"

Krawedz::Krawedz() {
	wierz = -100;
	waga = -1;
	czy_skierowana = false;
}

Krawedz::Krawedz(int wierz, int waga, bool czy_skierowana) {
	this->wierz = wierz;
	this->waga = waga;
	this->czy_skierowana = czy_skierowana;
}