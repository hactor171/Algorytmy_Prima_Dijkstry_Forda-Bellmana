#include "MacierzIncydencji.h"

MacierzIncydencji::MacierzIncydencji(int ile_wierzcholkow, int ile_krawedzi) {
	this->ile_kraw = ile_krawedzi;
	this->ile_wierz = ile_wierzcholkow;
	this->gestosc = 0;

	macierz = new Krawedz**[ile_wierz];
	macierz1 = new Krawedz**[ile_wierz];
	
	for (int i = 0; i < ile_wierz; ++i)
	{
		macierz[i] = new Krawedz*[ile_kraw];
		macierz1[i] = new Krawedz*[ile_kraw];
	}

	for (int i = 0; i < ile_wierz; ++i)
	{
		for (int j = 0; j < ile_kraw; ++j)
		{
			macierz[i][j] = NULL;
			macierz1[i][j] = NULL;
		}
	}

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
			macierz[wierz_pocz][j] = new Krawedz(0, waga, true);
			macierz1[wierz_pocz][j] = new Krawedz(0, waga, true);

		}
		else {
			macierz[wierz_pocz][j] = new Krawedz(1, waga, true);
			macierz[wierz_kon][j] = new Krawedz(-1, waga, true);
			macierz1[wierz_pocz][j] = new Krawedz(1, waga, true);
			macierz1[wierz_kon][j] = new Krawedz(1, waga, true);
		}
	}
}

MacierzIncydencji::MacierzIncydencji(float gestosc, int ile_w, bool losowanie) {
	if (losowanie == true)
		this->ile_kraw = gestosc*ile_w*(ile_w - 1) / 2;
	else
		this->ile_kraw = gestosc*ile_w*(ile_w - 1);


	this->ile_wierz = ile_w;
	this->gestosc = gestosc;

	cout << "Wierz: " << ile_wierz << "   krawedzie: " << ile_kraw << endl;


	macierz = new Krawedz**[ile_wierz];
	for (int i = 0; i < ile_wierz; ++i)
	{
		macierz[i] = new Krawedz*[ile_kraw];
	}

	for (int i = 0; i < ile_wierz; ++i)
	{
		for (int j = 0; j < ile_kraw; ++j)
		{
			macierz[i][j] = NULL;
		}
	}




	
	int wierz_pocz, wierz_kon, waga;

	for (int i = 0; i < ile_wierz-1; i++)
	{
		

		wierz_pocz = rand() % ile_wierz;
		wierz_kon = rand() % ile_wierz;

		waga = (rand() % 9) + 1;

		if (wierz_pocz == wierz_kon) {
			macierz[wierz_pocz][i] = new Krawedz(0, waga, true);
		}
		else {
			macierz[wierz_pocz][i] = new Krawedz(1, waga, true);
			macierz[wierz_kon][i] = new Krawedz(-1, waga, true);
		}
	}

	waga = (rand() % 9) + 1;

	macierz[ile_wierz-1][ile_wierz - 1] = new Krawedz(1, waga, true);
	macierz[0][ile_wierz - 1] = new Krawedz(-1, waga, true);
	


	for (int j = ile_wierz; j < ile_kraw; ++j)
	{

		do {
			wierz_pocz = rand() % ile_wierz;
			wierz_kon = rand() % ile_wierz;
			waga = (rand() % 9) + 1;
		}
		while (wierz_pocz == wierz_kon);


		macierz[wierz_pocz][j] = new Krawedz(1, waga, true);
		macierz[wierz_kon][j] = new Krawedz(-1, waga, true);
		
	}
	
}

MacierzIncydencji::MacierzIncydencji() {
	this->ile_kraw = 0;
	this->ile_wierz = 0;

	macierz = NULL;
}

void MacierzIncydencji::usun() {
	for (int i = 0; i < ile_wierz; i++)
	{
		for (int j = 0; j < ile_kraw; j++)
		{
			delete macierz[i][j];
			macierz[i][j] = NULL;

		}
	}

	for (int i = 0; i < ile_wierz; i++)
	{
		delete[]macierz[i];
		macierz[i] = NULL;
	}

	delete[]macierz;
	macierz = NULL;
}

MacierzIncydencji::~MacierzIncydencji() {
	usun();
}

void MacierzIncydencji::wypiszNieskierowany() {
	for (int i = 0; i < ile_wierz; i++)
	{
		cout << i << ") ";
		for (int j = 0; j < ile_kraw; j++)
		{
			if (macierz[i][j])
				cout << setw(3) << macierz1[i][j]->wierz<<setw(1)<< "|" << macierz1[i][j]->waga;
			else
				cout << setw(3) << "0"<<setw(1)<<"|"<<"0";
		}
		cout << endl;

	}
}

void MacierzIncydencji::wypisz() {
	cout << endl;
	for (int i = 0; i < ile_wierz; i++)
	{
		cout << i << ") ";
		for (int j = 0; j < ile_kraw; j++)
		{
			if (macierz[i][j])
				cout  <<setw(3)<<macierz[i][j]->wierz<<setw(1)<< "|" << macierz[i][j]->waga;
			else
				cout << setw(3) << "0"<<setw(1)<<"|"<<"0";
		}
		cout << endl;

	}
}

ifstream& operator>>(ifstream& stream, MacierzIncydencji& obj) {
	
	if (stream.good()) {
		stream >> obj.ile_wierz;
		stream >> obj.ile_kraw;
		
        if (obj.macierz != NULL) {
			obj.usun();
		}


		obj.macierz = new Krawedz**[obj.ile_wierz];
		for (int i = 0; i < obj.ile_wierz; ++i)
		{
			obj.macierz[i] = new Krawedz*[obj.ile_kraw];
		}

		for (int i = 0; i < obj.ile_wierz; ++i)
		{
			for (int j = 0; j < obj.ile_kraw; ++j)
			{
				obj.macierz[i][j] = NULL;
			}
		}

		for (int j = 0; j < obj.ile_kraw; ++j)
		{
			int wierz_pocz, wierz_kon, waga;


			stream >> wierz_pocz;
			stream >> wierz_kon;
			stream >> waga;

			cout << "Dodaje " << wierz_pocz << " " << wierz_kon << " " << waga << endl;
			
			if (wierz_pocz == wierz_kon) {
				obj.macierz[wierz_pocz][j] = new Krawedz(0, waga, true);
			}
			else {
				obj.macierz[wierz_pocz][j] = new Krawedz(1, waga, true);
				obj.macierz[wierz_kon][j] = new Krawedz(-1, waga, true);
			}
		}
		
	}

	return stream;
}








