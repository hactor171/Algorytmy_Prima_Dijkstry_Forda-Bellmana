#ifndef KPK_
#define KPK_

class MacierzIncydencji;
class ListaKrawedziPoczKon;

class KrawedzPoczKon {
public:
	friend class MacierzIncydencji;
	friend class ListaKrawedziPoczKon;

	int wp, wk, waga;


	KrawedzPoczKon() {
		this->wp = -1;
		this->wk = -1;
		this->waga = -1;
	}
	KrawedzPoczKon(int w_pocz, int w_kon, int waga) {
		this->wp = w_pocz;
		this->wk = w_kon;
		this->waga = waga;
	}
};

#endif