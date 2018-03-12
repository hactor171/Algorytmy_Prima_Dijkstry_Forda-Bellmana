#ifndef Krawedz_
#define Krawedz_

class MacierzIncydencji;

class Krawedz {

	friend class MacierzIncydencji;
	int wierz;
	int waga;
	bool czy_skierowana;
public:
	Krawedz();
	Krawedz(int wierz, int waga, bool czy_skierowana);
};

#endif