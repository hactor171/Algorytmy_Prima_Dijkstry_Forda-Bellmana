#include "Algorytmy.h"
#include "Timer.h"

Timer*czas = new Timer(); 
const int MAXINT_ = 2147483647;
Queue::Queue(int n)
{
	Heap = new Edge[n];            // Tworzymy tablicê
	hpos = 0;                       // Pozycja w kopcu
}


Queue::~Queue()
{
	delete[] Heap;
}


Edge Queue::front()
{
	return Heap[0];
}


void Queue::push(Edge e)
{
	int i, j;

	i = hpos++;                     // i ustawiamy na koniec kopca
	j = (i - 1) >> 1;               // Obliczamy pozycjê rodzica

									// Szukamy miejsca w kopcu dla e

	while (i && (Heap[j].weight > e.weight))
	{
		Heap[i] = Heap[j];
		i = j;
		j = (i - 1) >> 1;
	}

	Heap[i] = e;                    // KrawêdŸ e wstawiamy do kopca
}


void Queue::pop()
{
	int i, j;
	Edge e;

	if (hpos)
	{
		e = Heap[--hpos];

		i = 0;
		j = 1;

		while (j < hpos)
		{
			if ((j + 1 < hpos) && (Heap[j + 1].weight < Heap[j].weight)) j++;
			if (e.weight <= Heap[j].weight) break;
			Heap[i] = Heap[j];
			i = j;
			j = (j << 1) + 1;
		}

		Heap[i] = e;
	}
}


MSTree::MSTree(int n)
{
	int i;

	A = new TNode *[n];            // Tworzymy tablicê dynamiczn¹
	for (i = 0; i < n; i++) A[i] = NULL; // i wype³niamy j¹ pustymi listami
	Alen = n - 1;                   // Zapamiêtujemy d³ugoœæ tablicy
	weight = 0;                     // Zerujemy wagê drzewa
}


MSTree::~MSTree()
{
	int i;
	TNode *p, *r;

	for (i = 0; i <= Alen; i++)
	{
		p = A[i];
		while (p)
		{
			r = p;                      // Zapamiêtujemy wskazanie
			p = p->next;                // Przesuwamy siê do nastêpnego elementu listy
			delete r;                   // Usuwamy element
		}
	}

	delete[] A;                    // Usuwamy tablicê list s¹siedztwa
}


void MSTree::addEdge(Edge e)
{
	TNode *p;

	weight += e.weight;             // Do wagi drzewa dodajemy wagê krawêdzi
	p = new TNode;                  // Tworzymy nowy wêze³
	p->v = e.v2;                    // Wierzcho³ek koñcowy
	p->weight = e.weight;           // Waga krawêdzi
	p->next = A[e.v1];              // Dodajemy p do listy wierzcho³ka v1
	A[e.v1] = p;

	p = new TNode;                  // To samo dla krawêdzi odwrotnej
	p->v = e.v1;                    // Wierzcho³ek koñcowy
	p->weight = e.weight;           // Waga krawêdzi
	p->next = A[e.v2];              // Dodajemy p do listy wierzcho³ka v2
	A[e.v2] = p;
}


TNode * MSTree::getAList(int n)
{
	return A[n];
}


void MSTree::print()
{
	int i;
	TNode *p;

	cout << endl;
	for (i = 0; i <= Alen; i++)
	{
		cout << "Vertex " << i << " - ";
		for (p = A[i]; p; p = p->next) cout << p->v << ":" << p->weight << " ";
		cout << endl;
	}
	cout << endl << endl << "Minimal Spanning Tree Weight = " << weight << endl << endl;
}




double MacierzIncydencji::MDRprim() {

						// Liczba wierzcho³ków i krawêdzi
	Edge e;
	TNode * p;
	int i, v;


	Queue Q(ile_kraw);                     // Kolejka priorytetowa oparta na kopcu
	MSTree T(ile_wierz);                    // Minimalne drzewo rozpinaj¹ce
	MSTree G(ile_wierz);                    // Graf
	bool * visited = new bool[ile_wierz];

	for (i = 0; i <  ile_wierz; i++)
		visited[i] = false;           // Inicjujemy tablicê odwiedzin


	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/

	for (int j = 0; j < ile_kraw; ++j)
	{
		int wp = -100, wk = -100;
		for (int i = 0; i < ile_wierz; ++i)
		{

			if (macierz[i][j] != NULL) {

				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}



				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}

				if (wp != -100 && wk != -100) {
					e.v1 = wp;
					e.v2 = wk;
					e.weight = macierz[i][j]->waga;          // Czytamy wierzcho³ki krawêdzi oraz jej wagê

					G.addEdge(e);
				}

			}
		}
	}


	// Tworzymy minimalne drzewo rozpinaj¹ce

	v = 0;                          // Wierzcho³ek startowy
	visited[v] = true;              // Oznaczamy go jako odwiedzonego

	for (i = 1; i < ile_wierz; i++)          // Do drzewa dodamy n - 1 krawêdzi grafu
	{
		for (p = G.getAList(v); p; p = p->next) // Przegl¹damy listê s¹siadów
			if (!visited[p->v])          // Jeœli s¹siad jest nieodwiedzony,
			{
				e.v1 = v;                 // to tworzymy krawêdŸ
				e.v2 = p->v;
				e.weight = p->weight;
				Q.push(e);                // Dodajemy j¹ do kolejki priorytetowej
			}

		do
		{
			e = Q.front();              // Pobieramy krawêdŸ z kolejki
			Q.pop();
		} while (visited[e.v2]);       // KrawêdŸ prowadzi poza drzewo?

		T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa rozpinaj¹cego
		visited[e.v2] = true;         // Oznaczamy drugi wierzcho³ek jako odwiedzony
		v = e.v2;
	}


	//performanceCountEnd = endTimer();
	

	// Wyœwietlamy wyniki

	T.print();

	delete[] visited;

	return 0;
	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
}


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

// Konstruktor
DSStruct::DSStruct(int n)
{
	Z = new DSNode[n];             // Tworzymy tablicê dla elementów zbiorów
}

// Destruktor
//-----------
DSStruct::~DSStruct()
{
	delete[] Z;                    // Usuwamy tablicê ze zbiorami
}

// Tworzy wpis w tablicy Z
//------------------------
void DSStruct::MakeSet(int v)
{
	Z[v].up = v;
	Z[v].rank = 0;
}

// Zwraca indeks reprezentanta zbioru, w którym jest wierzcho³ek v
//----------------------------------------------------------------
int DSStruct::FindSet(int v)
{
	if (Z[v].up != v) Z[v].up = FindSet(Z[v].up);
	return Z[v].up;
}

// £¹czy ze sob¹ zbiory z v i u
//-----------------------------
void DSStruct::UnionSets(Edge e)
{
	int ru, rv;

	ru = FindSet(e.v1);             // Wyznaczamy korzeñ drzewa z wêz³em u
	rv = FindSet(e.v2);             // Wyznaczamy korzeñ drzewa z wêz³em v
	if (ru != rv)                    // Korzenie musz¹ byæ ró¿ne
	{
		if (Z[ru].rank > Z[rv].rank)   // Porównujemy rangi drzew
			Z[rv].up = ru;              // ru wiêksze, do³¹czamy rv
		else
		{
			Z[ru].up = rv;              // równe lub rv wiêksze, do³¹czamy ru
			if (Z[ru].rank == Z[rv].rank) Z[rv].rank++;
		}
	}
}


double MacierzIncydencji::MDRkruskal() {

	Edge e;
	int i;

							   

	DSStruct Z(ile_wierz);                  // Struktura zbiorów roz³¹cznych
	Queue Q(ile_kraw);                     // Kolejka priorytetowa oparta na kopcu
	MSTree T(ile_wierz);                    // Minimalne drzewo rozpinaj¹ce

	for (i = 0; i < ile_wierz; i++)
		Z.MakeSet(i);                 // Dla ka¿dego wierzcho³ka tworzymy osobny zbiór


	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/


	for (int j = 0; j < ile_kraw; ++j)
	{
		int wp = -100, wk = -100;
		for (int i = 0; i < ile_wierz; ++i)
		{

			if (macierz[i][j] != NULL) {

				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}



				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}

				if (wp != -100 && wk != -100) {
					e.v1 = wp;
					e.v2 = wk;
					e.weight = macierz[i][j]->waga;          // Czytamy wierzcho³ki krawêdzi oraz jej wagê
					
					Q.push(e);
				}

			}
		}
	}





	for (i = 1; i < ile_wierz; i++)          // Pêtla wykonuje siê n - 1 razy !!!
	{
		do
		{
			e = Q.front();              // Pobieramy z kolejki krawêdŸ
			Q.pop();                    // KrawêdŸ usuwamy z kolejki
		} while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
		T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa
		Z.UnionSets(e);               // Zbiory z wierzcho³kami ³¹czymy ze sob¹
	}

	//performanceCountEnd = endTimer();

	// Wyœwietlamy wyniki

	T.print();

	return 0;
	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------




double MacierzIncydencji::sciezkaDijkstra()
{
	int i, j, v, u, w, x, y, sptr, *d, *p, *S;
	bool *QS;                       // Zbiory Q i S
	slistEl **graf;                 // Tablica list s¹siedztwa
	slistEl *pw, *rw;
	int poc, kon;		
	cout<<"Wpisz wierzcowek poczatkowy:"<<endl;
	cin>>poc;
	cout<<"Wpisz wierzcowek koncowy:"<<endl;
	cin>>kon;						// Wêze³ startowy, liczba wierzcho³ków i krawêdzi
	v = poc;  //Wierzcho³ek, od którego ma zacz¹æ szukaæ œcie¿ki



	d = new int[ile_wierz];                // Tablica kosztów dojœcia
	p = new int[ile_wierz];                // Tablica poprzedników
	QS = new bool[ile_wierz];              // Zbiory Q i S
	graf = new slistEl *[ile_wierz];       // Tablica list s¹siedztwa
	S = new int[ile_wierz];                // Stos
	sptr = 0;                       // WskaŸnik stosu

									// Inicjujemy tablice dynamiczne

	for (i = 0; i < ile_wierz; i++)
	{
		d[i] = MAXINT_;
		p[i] = -1;
		QS[i] = false;
		graf[i] = NULL;
	}



	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/


	// Odczytujemy dane wejœciowe

	for (int j = 0; j < ile_kraw; ++j)
	{
		int wp = -100, wk = -100;
		for (int i = 0; i < ile_wierz; ++i)
		{

			if (macierz[i][j] != NULL) {

				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}



				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}

				if (wp != -100 && wk != -100) {
					x = wp;
					y = wk;
					w = macierz[i][j]->waga;          // Czytamy wierzcho³ki krawêdzi oraz jej wagê

					pw = new slistEl;             // Tworzymy element listy s¹siedztwa
					pw->v = y;                    // Wierzcho³ek docelowy krawêdzi
					pw->w = w;                    // Waga krawêdzi
					pw->next = graf[x];
					graf[x] = pw;
				}

			}
		}
	}



	d[v] = 0;                       // Koszt dojœcia v jest zerowy

									// Wyznaczamy œcie¿ki

	for (i = poc; i <= kon; i++)
	{
		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = poc; QS[j]; j++);
		for (u = j++; j <= kon; j++)
			if (!QS[j] && (d[j] < d[u])) u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		for (pw = graf[u]; pw; pw = pw->next)
			if (!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
			{
				d[pw->v] = d[u] + pw->w;
				p[pw->v] = u;
			}
	}


	//performanceCountEnd = endTimer();


	// Gotowe, wyœwietlamy wyniki

	for (i = poc; i <= kon; i++)
	{
		cout << i << ": ";

		// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
		// Zapisuj¹c na stosie kolejne wierzcho³ki

		for (j = i; j > -1; j = p[j]) S[sptr++] = j;

		// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

		while (sptr) cout << S[--sptr] << " ";

		// Na koñcu œcie¿ki wypisujemy jej koszt

		cout << "$" << d[i] << endl;
	}

	// Usuwamy tablice dynamiczne

	delete[] d;
	delete[] p;
	delete[] QS;
	delete[] S;

	for (i = 0; i < ile_wierz; i++)
	{
		pw = graf[i];
		while (pw)
		{
			rw = pw;
			pw = pw->next;
			delete rw;
		}
	}

	delete[] graf;

	return 0;

	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



                         // Liczba krawêdzi i wierzcho³ków w grafie

bool BF(int v, int wierz)
{
	int i, x;
	bool test;
	slistEl * pv;

	d[v] = 0;                       // Zerujemy koszt dojœcia do v
	for (i = 1; i < wierz; i++)          // Pêtla relaksacji
	{
		test = true;                  // Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
		for (x = 0; x < wierz; x++)        // Przechodzimy przez kolejne wierzcho³ki grafu
			for (pv = A[x]; pv; pv = pv->next) // Przegl¹damy listê s¹siadów wierzcho³ka x
				if (d[pv->v] > d[x] + pv->w) // Sprawdzamy warunek relaksacji
				{
					test = false;           // Jest zmiana w d i p
					d[pv->v] = d[x] + pv->w; // Relaksujemy krawêdŸ z x do jego s¹siada
					p[pv->v] = x;           // Poprzednikiem s¹siada bêdzie x
				}
		if (test) return true;         // Jeœli nie by³o zmian, to koñczymy
	}

	// Sprawdzamy istnienie ujemnego cyklu

	for (x = 0; x < wierz; x++)
		for (pv = A[x];pv;pv = pv->next)
			if (d[pv->v] > d[x] + pv->w) return false; // ujemny cykl!!

	return true;
}


double MacierzIncydencji::sciezkaBellmana() {

	int i, v, x, y, w, sptr, *S;
	slistEl *rv, *pv;
    int poc, kon;
	cout<<"Wpisz wierzcowek poczatkowy:"<<endl;
	cin>>poc;
	cout<<"Wpisz wierzcowek koncowy:"<<endl;
	cin>>kon;
	v = poc;
	            // Wierzcho³ek startowy, liczba wierzcho³ków i krawêdzi

	A = new slistEl *[ile_wierz];          // Tworzymy tablicê list s¹siedztwa
	d = new long long[ile_wierz];          // Tworzymy tablicê kosztów dojœcia
	p = new int[ile_wierz];                // Tworzymy tablice poprzedników
	for (i = 0; i < ile_wierz; i++)          // Inicjujemy struktury danych
	{
		d[i] = MAXINT_;
		p[i] = -1;
		A[i] = NULL;
	}


	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/

	for (int j = 0; j < ile_kraw; ++j)
	{
		int wp = -100, wk = -100;
		for (int i = 0; i < ile_wierz; ++i)
		{

			if (macierz[i][j] != NULL) {

				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}



				if (macierz[i][j]->wierz == 1) {
					wp = i;
				}
				else {
					wk = i;
				}

				if (wp != -100 && wk != -100) {
					x = wp;
					y = wk;
					w = macierz[i][j]->waga;          // Czytamy wierzcho³ki krawêdzi oraz jej wagê
					
					pv = new slistEl;             // Tworzymy element listy
					pv->v = y;                    // Inicjujemy go
					pv->w = w;
					pv->next = A[x];              // Dodajemy go na pocz¹tek listy s¹siadów wierzcho³ka x
					A[x] = pv;
				}

			}
		}
	}

	// Wyznaczamy najkrótsze œcie¿ki algorytmem Bellmana-Forda

	if (BF(v,kon))
	{
		S = new int[kon];              // Tworzymy prosty stos
		sptr = 0;

		for (i = poc; i <= kon; i++)
		{
			cout << i << ": ";
			for (x = i;x != -1;x = p[x]) // Wierzcho³ki œcie¿ki umieszczamy na stosie
				S[sptr++] = x;            // w kolejnoœci od ostatniego do pierwszego

			while (sptr)                 // Wierzcho³ki ze stosu drukujemy
				cout << S[--sptr] << " "; // w kolejnoœci od pierwszego do ostatniego

			cout << "$" << d[i] << endl; // Na koñcu wyœwietlamy koszt
		}
		delete[] S;                  // Usuwamy stos
	}
	else cout << "Negative Cycle found!" << endl;

	//performanceCountEnd = endTimer();

	// Usuwamy struktury dynamiczne

	for (i = 0; i < ile_wierz; i++)
	{
		pv = A[i];
		while (pv)
		{
			rv = pv;
			pv = pv->next;
			delete rv;
		}
	}

	delete[] A;
	delete[] d;
	delete[] p;

	return 0;
	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------





double ListaSasiedztwa::MDRprim() {


	int n, m;                        // Liczba wierzcho³ków i krawêdzi
	Edge e;
	TNode * p;
	int i, v;

	n = ile_wierz; m = ile_kraw;// Czytamy liczbê wierzcho³ków i krawêdzi

	Queue Q(m);                     // Kolejka priorytetowa oparta na kopcu
	MSTree T(n);                    // Minimalne drzewo rozpinaj¹ce
	MSTree G(n);                    // Graf
	bool * visited = new bool[n];

	for (i = 0; i < n; i++)
		visited[i] = false;           // Inicjujemy tablicê odwiedzin


	czas->startTimer();
	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/


		// Odczytujemy kolejne krawêdzie grafu
	for (int i = 0; i < ile_wierz; ++i)
	{

		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			e.v1 = i;
			e.v2 = listaKrawedzi[i].dostan_sasiada(j);
			e.weight = listaKrawedzi[i].dostan_wage(j);

			G.addEdge(e);
		}
	}

					// i umieszczamy je w G
	

	// Tworzymy minimalne drzewo rozpinaj¹ce

	v = 0;                          // Wierzcho³ek startowy
	visited[v] = true;              // Oznaczamy go jako odwiedzonego




	for (i = 1; i < n; i++)          // Do drzewa dodamy n - 1 krawêdzi grafu
	{
		for (p = G.getAList(v); p; p = p->next) // Przegl¹damy listê s¹siadów
			if (!visited[p->v])          // Jeœli s¹siad jest nieodwiedzony,
			{
				e.v1 = v;                 // to tworzymy krawêdŸ
				e.v2 = p->v;
				e.weight = p->weight;
				Q.push(e);                // Dodajemy j¹ do kolejki priorytetowej
			}

		do
		{
			e = Q.front();              // Pobieramy krawêdŸ z kolejki
			Q.pop();
		} while (visited[e.v2]);       // KrawêdŸ prowadzi poza drzewo?

		T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa rozpinaj¹cego
		visited[e.v2] = true;         // Oznaczamy drugi wierzcho³ek jako odwiedzony
		v = e.v2;
	}


	//performanceCountEnd = endTimer();
	ZapiszDoPlikuiEndTimer(0,"Algorytm Prima(Lista Sąsiedstwa):");


	// Wyœwietlamy wyniki

	T.print();

	delete[] visited;

	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
	return 0;
}



//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



double ListaSasiedztwa::MDRkruskal() {


	int n, m;				// Liczba wierzcho³ków i krawêdzi
	n = ile_wierz;
	m = ile_kraw;			// Czytamy liczbê wierzcho³ków i krawêdzi
	Edge e;
	int i;



	DSStruct Z(n);                  // Struktura zbiorów roz³¹cznych
	Queue Q(m);                     // Kolejka priorytetowa oparta na kopcu
	MSTree T(n);                    // Minimalne drzewo rozpinaj¹ce

	for (i = 0; i < n; i++)
		Z.MakeSet(i);                 // Dla ka¿dego wierzcho³ka tworzymy osobny zbiór


	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/

	for (int i = 0; i < ile_wierz; ++i)
	{

		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			e.v1 = i;
			e.v2 = listaKrawedzi[i].dostan_sasiada(j);
			e.weight = listaKrawedzi[i].dostan_wage(j);

			Q.push(e);
		}
	}



	for (i = 1; i < n; i++)          // Pêtla wykonuje siê n - 1 razy !!!
	{
		do
		{
			e = Q.front();              // Pobieramy z kolejki krawêdŸ
			Q.pop();                    // KrawêdŸ usuwamy z kolejki
		} while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
		T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa
		Z.UnionSets(e);               // Zbiory z wierzcho³kami ³¹czymy ze sob¹
	}


	//performanceCountEnd = endTimer();

	// Wyœwietlamy wyniki

	T.print();

	return 0;
	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;


}


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------


double ListaSasiedztwa::sciezkaBellmana() {



	int i, v, x, y, w, sptr, *S;
	slistEl *rv, *pv;
	int poc, kon;
	cout<<"Wpisz wierzcowek poczatkowy:"<<endl;
	cin>>poc;
	cout<<"Wpisz wierzcowek koncowy:"<<endl;
	cin>>kon;
	v = poc;							// Wierzcho³ek startowy
		           

	A = new slistEl *[ile_wierz];          // Tworzymy tablicê list s¹siedztwa
	d = new long long[ile_wierz];          // Tworzymy tablicê kosztów dojœcia
	p = new int[ile_wierz];                // Tworzymy tablice poprzedników
	for (i = 0; i < ile_wierz; i++)          // Inicjujemy struktury danych
	{
		d[i] = MAXINT_;
		p[i] = -1;
		A[i] = NULL;
	}

	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/


	for (int i = 0; i < ile_wierz; ++i)
	{

		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			x = i;
			y = listaKrawedzi[i].dostan_sasiada(j);
			w = listaKrawedzi[i].dostan_wage(j);

			pv = new slistEl;             // Tworzymy element listy
			pv->v = y;                    // Inicjujemy go
			pv->w = w;
			pv->next = A[x];              // Dodajemy go na pocz¹tek listy s¹siadów wierzcho³ka x
			A[x] = pv;
		}
	}

	cout << endl;

	// Wyznaczamy najkrótsze œcie¿ki algorytmem Bellmana-Forda



	if (BF(v, kon))
	{
		S = new int[kon];              // Tworzymy prosty stos
		sptr = 0;

		for (i = poc; i <= kon; i++)
		{
			cout << i << ": ";
			for (x = i;x != -1;x = p[x]) // Wierzcho³ki œcie¿ki umieszczamy na stosie
				S[sptr++] = x;            // w kolejnoœci od ostatniego do pierwszego

			while (sptr)                 // Wierzcho³ki ze stosu drukujemy
				cout << S[--sptr] << " "; // w kolejnoœci od pierwszego do ostatniego

			cout << "$" << d[i] << endl; // Na koñcu wyœwietlamy koszt
		}
		delete[] S;                  // Usuwamy stos
	}
	else cout << "Negative Cycle found!" << endl;

	//performanceCountEnd = endTimer();

	// Usuwamy struktury dynamiczne

	for (i = 0; i < ile_wierz; i++)
	{
		pv = A[i];
		while (pv)
		{
			rv = pv;
			pv = pv->next;
			delete rv;
		}
	}

	delete[] A;
	delete[] d;
	delete[] p;

	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
	return 0;

}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------


double ListaSasiedztwa::sciezkaDijkstra()
{



	int i, j, v, u, w, x, y, sptr, *d, *p, *S;
	bool *QS;                       // Zbiory Q i S
	slistEl **graf;                 // Tablica list s¹siedztwa
	slistEl *pw, *rw;
	int poc, kon;

	cout<<"Wpisz wierzcowek poczatkowy:"<<endl;
	cin>>poc;
	cout<<"Wpisz wierzcowek koncowy:"<<endl;
	cin>>kon;

	v = poc;				// Wêze³ startowy
							// Tworzymy tablice dynamiczne

	d = new int[ile_wierz];                // Tablica kosztów dojœcia
	p = new int[ile_wierz];                // Tablica poprzedników
	QS = new bool[ile_wierz];              // Zbiory Q i S
	graf = new slistEl *[ile_wierz];       // Tablica list s¹siedztwa
	S = new int[ile_wierz];                // Stos
	sptr = 0;                       // WskaŸnik stosu

									// Inicjujemy tablice dynamiczne

	for (i = 0; i < ile_wierz; i++)
	{
		d[i] = MAXINT_;
		p[i] = -1;
		QS[i] = false;
		graf[i] = NULL;
	}

	// Odczytujemy dane wejœciowe


	/*LARGE_INTEGER performanceCountStart, performanceCountEnd, freq;
	QueryPerformanceFrequency(&freq);
	performanceCountStart = startTimer();*/


	for (int i = 0; i < ile_wierz; ++i)
	{

		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			x = i;
			y = listaKrawedzi[i].dostan_sasiada(j);
			w = listaKrawedzi[i].dostan_wage(j);

			pw = new slistEl;             // Tworzymy element listy s¹siedztwa
			pw->v = y;                    // Wierzcho³ek docelowy krawêdzi
			pw->w = w;                    // Waga krawêdzi
			pw->next = graf[x];
			graf[x] = pw;                 // Element do³¹czamy do listy
		}
	}


	cout << endl;

	d[v] = 0;                       // Koszt dojœcia v jest zerowy

									// Wyznaczamy œcie¿ki



	

	for (i = poc; i <= kon; i++)
	{
		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = poc; QS[j]; j++);
		for (u = j++; j <= kon; j++)
			if (!QS[j] && (d[j] < d[u])) u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		for (pw = graf[u]; pw; pw = pw->next)
			if (!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
			{
				d[pw->v] = d[u] + pw->w;
				p[pw->v] = u;
			}
	}

	//performanceCountEnd = endTimer();


	// Gotowe, wyœwietlamy wyniki

	for (i = poc; i <= kon; i++)
	{
		cout << i << ": ";

		// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
		// Zapisuj¹c na stosie kolejne wierzcho³ki

		for (j = i; j > -1; j = p[j]) S[sptr++] = j;

		// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

		while (sptr) cout << S[--sptr] << " ";

		// Na koñcu œcie¿ki wypisujemy jej koszt

		cout << "$" << d[i] << endl;
	}

	// Usuwamy tablice dynamiczne

	delete[] d;
	delete[] p;
	delete[] QS;
	delete[] S;

	for (i = 0; i < ile_wierz; i++)
	{
		pw = graf[i];
		while (pw)
		{
			rw = pw;
			pw = pw->next;
			delete rw;
		}
	}

	delete[] graf;


	//return static_cast<double>(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq.QuadPart;
	return 0;

}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------



struct slistEl1
{
  slistEl1 * next;
  int v,c,f;
};

// Definicja typu obiektowego queue
//---------------------------------
class queue1
{
  private:
    slistEl1 * head;
    slistEl1 * tail;

  public:
    queue1();      // konstruktor
    ~queue1();     // destruktor
    bool empty(void);
    int  front(void);
    void push(int v);
    void pop(void);
};

//---------------------
// Metody obiektu queue
//---------------------

// Konstruktor - tworzy pustą listę
//---------------------------------
queue1::queue1()
{
  head = tail = NULL;
}

// Destruktor - usuwa listę z pamięci
//-----------------------------------
queue1::~queue1()
{
  while(head) pop();
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool queue1::empty(void)
{
  return !head;
}

// Zwraca początek kolejki.
// Wartość specjalna to -MAXINT
//-----------------------------
int queue1::front(void)
{
  if(head) return head->v;
  else     return -MAXINT;
}

// Zapisuje do kolejki
//--------------------
void queue1::push(int v)
{
  slistEl1 * p = new slistEl1;
  p->next = NULL;
  p->v = v;
  if(tail) tail->next = p;
  else     head = p;
  tail = p;
}

// Usuwa z kolejki
//----------------
void queue1::pop(void)
{
  if(head)
  {
    slistEl1 * p = head;
    head = head->next;
    if(!head) tail = NULL;
    delete p;
  }
}

//---------------
// Program główny
//---------------

double ListaSasiedztwa::FordaFulkersona()
{
  int m,n;                        // Liczba krawędzi i wierzchołków w grafie
  slistEl1 ** L;                   // Tablica list sąsiedztwa
  int s,t;                        // Numer wierzchołka źródła s i ujscia t
  int fmax;                       // Maksymalny przepływ sieciowy
  queue1 Q;                        // Kolejka
  int *P;                         // Tablica poprzedników
  int *CFP;                       // Tablica przepustowości rezydualnych dla ścieżek
  int i,cp,u,v;                   // Zmienne pomocnicze
  slistEl1 *x, *z;                 // Wskaźniki elementów listy sąsiedztwa
  bool test;

  // Najpierw odczytujemy liczbę wierzchołków i krawędzi grafu

 // cin >> n >> m;
  n = ile_wierz; m = ile_kraw;

  // Tworzymy i inicjujemy struktury dynamiczne

  L = new slistEl1 * [n];          // Tablica wskaźników list
  for(i = 0; i < n; i++)
    L[i] = NULL;                  // Tablicę wypełniamy pustymi listami

  P   = new int [n];
  CFP = new int [n];

  // Teraz wczytujemy definicje poszczególnych krawędzi grafu.
  // Każda krawędź jest zdefiniowana przez trzy liczby u, v i cp:
  // u  - wierzchołek początkowy krawędzi
  // v  - wierzchołek końcowy krawędzi
  // cp - przepustowość krawędzi

  for (int i = 0; i < ile_wierz; ++i)
	{

		for (int j = 0; j < listaKrawedzi[i].dostan_ilosc_sasiadow(); j++)
		{
			u = i;
			v = listaKrawedzi[i].dostan_sasiada(j);
			cp = listaKrawedzi[i].dostan_wage(j);
			x = new slistEl1;

    // Wypełniamy jego pola danych

    x->v = v;
    x->c = cp;
    x->f = 0;                     // Zerujemy przepływ

    // Element dołączamy do listy sąsiadów wierzchołka u

    x->next = L[u];
    L[u] = x;
			
		}
	}

  

    
  

  // Na koniec odczytujemy numery wierzchołków źródła i ujścia

  cin >> s >> t;

  //**************************************************
  //** Tutaj rozpoczyna się algorytm Edmondsa-Karpa **
  //**************************************************

  // Zerujemy wartość maksymalnego przepływu sieciowego

  fmax = 0;

  // Tworzymy w grafie strukturę sieci rezydualnej

  for(u = 0; u < n; u++)
  {
    for(x = L[u]; x; x = x->next)
    {
      // Sprawdzamy, czy na liście sąsiadów x jest wierzchołek u.
      // Jeśli tak, to krawędź zwrotna istnieje i nie ma potrzeby
      // jej tworzenia.

      test = false;               // Zakładamy brak krawędzi zwrotnej
      for(z = L[x->v]; z; z = z->next)
        if(z->v == u)
        {
          test = true; break;
        }
      if(test) continue;          // Jeśli jest krawędź, sprawdzamy kolejnego sąsiada

      // Tworzymy krawędź zwrotną

      z = new slistEl1;
      z->v = u;
      z->c = z->f = 0;
      z->next = L[x->v];
      L[x->v] = z;
    }
  }

  // Sieć rezydualna została utworzona. Teraz zajmiemy się wyznaczeniem
  // maksymalnych przepływów w sieci.

  while(1)
  {
    for(i = 0; i < n; i++)
      P[i] = -1;                  // Zerujemy tablicę poprzedników

    CFP[s] = MAXINT;              // Przepustowość źródła jest nieskończona

    while(!Q.empty()) Q.pop();    // Zerujemy kolejkę

    Q.push(s);                    // W kolejce umieszczamy źródło s

    // Szukamy ścieżki w sieci rezudualnej od źródła s do ujścia t

    while(!Q.empty())
    {
      test = false;             // Zakładamy brak takiej ścieżki
      u = Q.front(); Q.pop();   // Pobieramy wierzchołek z kolejki

      // Przeglądamy listę sąsiadów wierzchołka u

      for(x = L[u]; x; x = x->next)
      {
        // Wyznaczamy przepustowość rezydualną kanału

        cp = x->c - x->f;

        // Przetwarzamy tylko istniejące i nieodwiedzone jeszcze krawędzie

        if(cp && (P[x->v] == -1))
        {
          // Zapamiętujemy poprzednik na ścieżce

          P[x->v] = u;

          // Obliczamy przepustowość rezydualną do węzła x->v

          CFP[x->v] = cp < CFP[u] ? cp : CFP[u];

          // Sprawdzamy, czy ścieżka sięga do ujścia

          if(x->v == t)
          {
             test = true;         // Sygnalizujemy znalezioną ścieżkę
             break;               // Wychodzimy z pętli for
          }
          else Q.push(x->v);      // Inaczej umieszczamy w kolejce wierzchołek x->v
        }
      }

      if(test) break;             // Jeśli jest ścieżka, wychodzimy z pętli while
    }

    if (!test) break;             // Jeśli brak ścieżki, kończymy algorytm

    // Zwiększamy przepływ sieciowy

    fmax += CFP[t];

    // Cofamy się po ścieżce od ujścia t do źródła s

    for(v = t; v != s; v = u)
    {
      u = P[v];                   // u jest poprzednikiem v na ścieżce

      // Szukamy na liście sąsiadów u krawędzi prowadzącej do v.

      for(z = L[u]; z; z = z->next)
        if(z->v == v)
        {
          z->f += CFP[t];         // W kierunku zgodnym ze ścieżką zwiększamy przepływ
          break;
        }

      // Szukamy na liście sąsiadów v krawędzi prowadzącej do u.

      for(z = L[v]; z; z = z->next)
        if(z->v == u)
        {
          z->f -= CFP[t];         // W kierunku przeciwnym do ścieżki zmnejszamy przepływ
          break;
        }
    }
  }

  // Prezentujemy wyniki obliczeń. Najpierw wypisujemy
  // wartość maksymalnego przepływu

  cout << "\nfmax = " << fmax << endl << endl;

  // Następnie wypisujemy znalezione przez algorytm przepływy w
  // kanałach pierwotnej sieci przepływowej. Kanały rozpoznajemy
  // po niezerowej wartości ich przepustowości.

  for(i = 0; i < n; i++)
    for(z = L[i]; z; z = z->next)
      if(z->c)
        cout << i << " -> " << z->v << " " << z->f << ":" << z->c << endl;

  cout << endl;

  // Koniec, usuwamy struktury dynamiczne

  for(i = 0; i < n; i++)
  {
    x = L[i];
    while(x)
    {
      z = x;
      x = x->next;
      delete z;
    }
  }

  delete [] L;
  delete [] P;
  delete [] CFP;

  return 0;
} 





void ListaSasiedztwa::ZapiszDoPlikuiEndTimer(double Czas, string Text)
{
Czas =0;
Czas = czas->endTimer();
cout<<Text<<Czas<<endl;
CzasPlik("CzasPlik.txt",Text,Czas);
}
void ListaSasiedztwa::CzasPlik(string filename,string Text, double Czas)
{
	ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) 
	{
		file << Text << Czas << "\n\n";
	 } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}