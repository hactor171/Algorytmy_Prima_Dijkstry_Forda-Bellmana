#ifndef MacierzIncydencji_
#define MacierzIncydencji_

#include "Krawedz.h"
#include "ListaKrawedziPoczKon.h"
#include "main.h"

class MacierzIncydencji {

	friend ifstream& operator>>(ifstream& stream, MacierzIncydencji& obj);
public:
	Krawedz*** macierz;
	Krawedz*** macierz1;
	int ile_wierz;
	int ile_kraw;
	float gestosc;
	void usun();

	ListaKrawedziPoczKon* kruskal;


	MacierzIncydencji(int ile_wierzcholkow, int ile_krawedzi);
	MacierzIncydencji();
	~MacierzIncydencji();

	MacierzIncydencji(float gestosc, int ile_w, bool losowanie);

	void wypisz();
	void wypiszNieskierowany();

	double MDRkruskal();
	double MDRprim();

	double sciezkaDijkstra();
	double sciezkaBellmana();
	
};

#endif

