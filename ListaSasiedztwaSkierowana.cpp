#include "ListaSasiedztwaSkierowana.h"
#include "main.h"


ListaSasiedztwaSkierowana::ListaSasiedztwaSkierowana(int wierzcholki, int krawedzie) {
	this->ile_wierz = wierzcholki;
	this->ile_kraw = krawedzie;

	listaKrawedzi = new ListaKrawedzi[ile_wierz]();

	for (int j = 0; j < ile_kraw; ++j)
	{
		int wierz_pocz, wierz_kon, waga;


		do {
			cout << "\n\tKrawedz nr.: " << j << endl;
			cout << "Podaj wierzcholek poczatkowy: ";
			cin >> wierz_pocz;
			cout << "Podaj wierzcholek koncowy: ";
			cin >> wierz_kon;
			cout << "Podaj wage krawedzi: ";
			cin >> waga;
		} while (wierz_pocz >= ile_wierz || wierz_kon >= ile_wierz || wierz_pocz < 0 || wierz_kon < 0);

		if (wierz_pocz == wierz_kon) {
			listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);
		}
		else {
			listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
		}
	}
}


ListaSasiedztwaSkierowana::~ListaSasiedztwaSkierowana() {
	delete[]listaKrawedzi;
}

void ListaSasiedztwaSkierowana::wypisz() {
	for (int i = 0; i < ile_wierz; i++)
	{
		cout << i << ") ";
		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			cout << setw(6) << listaKrawedzi[i].dostan_sasiada(j) << "|" << listaKrawedzi[i].dostan_wage(j) << " ";
		}
		cout << endl;

	}
}