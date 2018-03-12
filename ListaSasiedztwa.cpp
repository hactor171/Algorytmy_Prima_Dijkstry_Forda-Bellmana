#include "main.h"
#include "ListaSasiedztwa.h"



ListaSasiedztwa::ListaSasiedztwa(int wierzcholki, int krawedzie) {
	this->ile_wierz = wierzcholki;
	this->ile_kraw = krawedzie;

	this->gestosc = 0;

	listaKrawedzi = new ListaKrawedzi[ile_wierz]();
	listaKrawedzi1 = new ListaKrawedzi[ile_wierz]();

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
			listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);
		}
		else {
			listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
			//listaKrawedzi[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
			listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
			listaKrawedzi1[wierz_kon].dodaj_sasiada(wierz_pocz, waga);

		}
	}
}

void ListaSasiedztwa::wypiszNieSkierowany()
{
for (int i = 0; i < ile_wierz; i++)
	{
		cout << i << ") ";
		for (int j = 0; j < listaKrawedzi1[i].dostan_ilosc_sasiadow(); j++)
		{
			cout << listaKrawedzi1[i].dostan_sasiada(j) << "|" << listaKrawedzi1[i].dostan_wage(j) << " ";
		}
		cout << endl;

	}	
}
ListaSasiedztwa::ListaSasiedztwa(float gest, int ile_w, bool losowanie) {
	if (losowanie == true)
		this->ile_kraw = gest*ile_w*(ile_w - 1)/2; ///2;
	else
		this->ile_kraw = gest*ile_w*(ile_w - 1);


	this->ile_wierz = ile_w;
	this->gestosc = gest;

	listaKrawedzi = new ListaKrawedzi[ile_wierz]();
	listaKrawedzi1 = new ListaKrawedzi[ile_wierz]();

	
	int wierz_pocz, wierz_kon, waga;

	for (int i = 0; i < ile_wierz-1 ; i++)
	{
		
		
		wierz_pocz = rand() % ile_wierz;
		wierz_kon = rand() % ile_wierz ;
		waga = (rand() % 9) + 1;
		

		if (wierz_pocz == wierz_kon) {
			listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);
			listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);

		}
		else {
			listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
			//listaKrawedzi[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
			listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
			listaKrawedzi1[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
		}
	}

	waga = (rand() % 9) + 1;

	//listaKrawedzi[ile_wierz - 1].dodaj_sasiada(0, waga);
	//listaKrawedzi[0].dodaj_sasiada(ile_wierz-1, waga);
	//listaKrawedzi[0].dodaj_sasiada(ile_wierz - 1, waga);

	for (int j = ile_wierz ; j < ile_kraw; ++j)
	{
		do {
			wierz_pocz = rand() % ile_wierz;
			wierz_kon = rand() % ile_wierz;
			waga = (rand() % 9) + 1;
		} while (wierz_pocz == wierz_kon);

		listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
		listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
		listaKrawedzi1[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
		//listaKrawedzi[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
		
	}
}

ListaSasiedztwa::ListaSasiedztwa() {
	this->ile_kraw = -1;
	this->ile_wierz = -1;
	this->listaKrawedzi = NULL;
}

ifstream& operator>>(ifstream& stream, ListaSasiedztwa & obj) {

	if (stream.good()) {
		stream >> obj.ile_kraw;
		stream >> obj.ile_wierz;

		if (obj.listaKrawedzi != NULL) {
			delete[] obj.listaKrawedzi;
		}
		/*if (obj.listaKrawedzi1 != NULL) {
			delete[] obj.listaKrawedzi1;
		}*/

		obj.listaKrawedzi = new ListaKrawedzi[obj.ile_wierz]();
		obj.listaKrawedzi1 = new ListaKrawedzi[obj.ile_wierz]();



		for (int j = 0; j < obj.ile_kraw; ++j)
		{
			int wierz_pocz, wierz_kon, waga;


			stream >> wierz_pocz;
			stream >> wierz_kon;
			stream >> waga;

			cout << "Dodaje " << wierz_pocz << " " << wierz_kon << " " << waga << endl;

			if (wierz_pocz == wierz_kon) {
				obj.listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);
				obj.listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_pocz, waga);
			}
			else {
				obj.listaKrawedzi[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
				obj.listaKrawedzi1[wierz_pocz].dodaj_sasiada(wierz_kon, waga);
		        obj.listaKrawedzi1[wierz_kon].dodaj_sasiada(wierz_pocz, waga);
			}
		}

	}

	return stream;
}


ListaSasiedztwa::~ListaSasiedztwa() {
	delete[]listaKrawedzi;
}

void ListaSasiedztwa::wypisz() {
	for (int i = 0; i < ile_wierz; i++)
	{
		cout << i << ") ";
		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			cout << listaKrawedzi[i].dostan_sasiada(j) << "|" << listaKrawedzi[i].dostan_wage(j) << " ";
		}
		cout << endl;

	}
}
