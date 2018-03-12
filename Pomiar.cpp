
#include "Pomiar.h"

Pomiar::Pomiar() {
	MSTprim = 0;		// Na koñcu nazwy:
	MSTkruskal = 0;				// TL -> dotyczy tablicy albo listy 
	NSdijkstra = 0;
	NSford_bellman = 0;

	long ilosc_wierzcholkow=0;
	long ilosc_krawedzi=0;
}


void Pomiar::show() {

	cout.setf(ios::fixed);

	if (kontener == Kontener::MacierzIncydencji) {
		cout << "\tDane dla Macierzy incydencji\n";
	}
	else {
		cout << "\tDane dla ListaSasiedztwa\n";
	}

	cout << "Kolejno w kolumnie:" << endl;
	cout << "Ilosc wierzcholkow" << endl;
	cout << "Gestosc" << endl;
	cout << "Sredni czas wyznaczenia minimalnego drzewa rozpinaj¹cego - algorytm Prima [sekund]" << endl;
	cout << "Sredni czas wyznaczenia minimalnego drzewa rozpinaj¹cego - algorytm Kruskala [sekund]" << endl;
	cout << "Sredni czas wyznaczenia najkrótszej œcie¿ki w grafie – algorytm Dijkstry [sekund]" << endl;
	cout << "Sredni czas wyznaczenia najkrótszej œcie¿ki w grafie - algorytm Forda-Bellmana [sekund]" << endl;
	
	cout << this->ilosc_wierzcholkow << endl;
	cout << this->gestosc << endl;
	cout << this->MSTprim << endl;
	cout << this->MSTkruskal<< endl;
	cout << this->NSdijkstra << endl;
	cout << this->NSford_bellman << endl;


	cout.unsetf(ios::fixed);

}

ostream& operator<<(ostream& stream, Pomiar& pom) {
	pom.show();

	return stream;
}

ofstream& operator<<(ofstream& stream, Pomiar& pom) {

	stream.setf(ios::fixed);

	if (pom.kontener == Pomiar::Kontener::MacierzIncydencji) {
		stream << "\tDane dla Macierzy incydencji\n";
	}
	else {
		stream << "\tDane dla ListaSasiedztwa\n";
	}

	stream << "Kolejno w kolumnie:" << endl;
	stream << "Ilosc wierzcholkow" << endl;
	stream << "Gestosc" << endl;
	stream << "Sredni czas wyznaczenia minimalnego drzewa rozpinajacego - algorytm Prima [sekund]" << endl;
	stream << "Sredni czas wyznaczenia minimalnego drzewa rozpinajacego - algorytm Kruskala [sekund]" << endl;
	stream << "Sredni czas wyznaczenia najkrotszej sciezki w grafie – algorytm Dijkstry [sekund]" << endl;
	stream << "Sredni czas wyznaczenia najkrotszej sciezki w grafie - algorytm Forda-Bellmana [sekund]" << endl;
	stream << pom.ilosc_wierzcholkow << endl;
	stream << pom.gestosc << endl;
	stream << pom.MSTprim << endl;
	stream << pom.MSTkruskal << endl;
	stream << pom.NSdijkstra << endl;
	stream << pom.NSford_bellman << endl;


	stream.unsetf(ios::fixed);

	return stream;
}

void Pomiar::save(string pathToFileWithName) {

	ofstream plik;
	plik.open(pathToFileWithName, ios::out);

	if (plik.good()) {
		try {
			plik << *this;
		}
		catch (...) {
			plik.close();
			throw 1;
		}
	}
	else {
		plik.close();
		throw 2;
	}

	plik.close();
}
