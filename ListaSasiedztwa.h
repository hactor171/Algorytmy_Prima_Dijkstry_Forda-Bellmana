#ifndef LS_
#define LS_

#include "ListaKrawedzi.h"
#include "Krawedz.h"
#include "ListaKrawedziPoczKon.h"
#include "main.h"

class ListaSasiedztwa {

	friend ifstream& operator>>(ifstream& stream, ListaSasiedztwa & obj);
	public:
	ListaKrawedzi* listaKrawedzi;
	ListaKrawedzi* listaKrawedzi1;
	int ile_wierz;
	int ile_kraw;
	int gestosc;

	
	ListaSasiedztwa(int wierzcholki, int krawedzie);
	ListaSasiedztwa();
	ListaSasiedztwa(float gestosc, int ile_w, bool losowanie);
	~ListaSasiedztwa();

	void wypiszNieSkierowany();
	void wypisz();
	void ZapiszDoPlikuiEndTimer(double, string);
	void CzasPlik(string,string, double);
	

	double MDRprim();
	double MDRkruskal();

	double sciezkaDijkstra();
	double sciezkaBellmana();
	double FordaFulkersona();

};

#endif

