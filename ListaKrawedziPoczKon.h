#ifndef LKPK_
#define LKPK_

#include "KrawedzPoczKon.h"

class ListaKrawedziPoczKon{
	struct node {
		KrawedzPoczKon kr;
		node* next;
	};
	node* head;
	int size;
public:
	ListaKrawedziPoczKon();
	~ListaKrawedziPoczKon();
	KrawedzPoczKon dostan_krawedz(int nr);
	int dostan_ilosc_krawedzi();
	void dodaj_krawedz(int wp,int wk, int waga);
	void sortuj();

	void wypisz();
};

#endif
