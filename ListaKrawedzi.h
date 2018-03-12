

#ifndef LISTA_KRAWEDZI_
#define LISTA_KRAWEDZI_


class ListaKrawedzi {
	struct node {
		int wierzcholek;
		int waga;
		node* next;
	};
	node* head;
	int size;
public:
	ListaKrawedzi();
	~ListaKrawedzi();
	int dostan_sasiada(int nr);
	int dostan_wage(int nr);
	int dostan_ilosc_sasiadow();
	void dodaj_sasiada(int nr_wierz, int waga);
};


#endif // !LISTA_KRAWEDZI_
