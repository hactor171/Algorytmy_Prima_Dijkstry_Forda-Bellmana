#ifndef ListaSasiedztwaSkierowana_
#define ListaSasiedztwaSkierowana_

#include "ListaKrawedzi.h"

class ListaSasiedztwaSkierowana {
	ListaKrawedzi* listaKrawedzi;

	
	int ile_wierz;
	int ile_kraw;

public:

	ListaSasiedztwaSkierowana(int wierzcholki, int krawedzie);
	~ListaSasiedztwaSkierowana();

	void wypisz();

};

#endif
