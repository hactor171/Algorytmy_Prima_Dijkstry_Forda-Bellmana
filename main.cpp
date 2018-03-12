#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"
#include "ListaSasiedztwaSkierowana.h"
#include "KrawedzPoczKon.h"
#include "ListaKrawedziPoczKon.h"
#include "Pomiar.h"
#include "main.h"

int main()
{
	MacierzIncydencji* wskm = NULL;
	ListaSasiedztwa* wskl = NULL;
    char w;
	bool a,b,c;
	a=b=c=true;
	
    while (a) {
        b=c=true;
        cout << "\n== Menu Glowne ==\n"<<endl;
        cout << "Wybierz:"<<endl;
		cout<<"-1- Macierz Incydencji"<<endl;
		cout<<"-2- Lista Sasiedstwa"<<endl;
		cout<<"-3- Zakonc program"<<endl;
        cout << "\n>>>: ";
        cin >> w;
        system("cls");
        switch(w) {
        case '1' : {
            while(b) {
                cout << "\n<<Menu macierzy>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytaj graf z pliku:"<<endl;
				cout<<"-2- Wprowadz graf:"<<endl;
				cout<<"-3- Stworz losowo:"<<endl;
				cout<<"-4- Pokaz graf"<<endl;
				cout<<"\n-5- Algorytm Prima" << endl;
				cout<<"-6- Algorytm Kruskala" << endl;
				cout<<"-7- Algorytm Dijkstry" << endl;
				cout<<"-8- Algorytm Forda-Bellmana" << endl;
				cout<<"-9- Algorytm Forda-Fulkersona" << endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";
				
				cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                   string nazwaPliku;
			       cout << "Podaj nazwe pliku: ";
			       cin >> nazwaPliku;

			       wskm = new MacierzIncydencji();

			       ifstream plik1;
			       plik1.open(nazwaPliku, ios::in);

			       if (plik1.good())
				   plik1 >> *wskm;
			       else
				   cout << "Blad pliku" << endl;

			       plik1.close();
				   wskm->wypisz();
                    break;
                } case '2' : {
                    int w, k;
			        cout << "Podaj ilosc wierzcholkow: ";
			        cin >> w;
			        cout << "Podaj ilosc krawedzi: ";
			        cin >> k;
			        wskm = new MacierzIncydencji(w, k);
					wskm->wypisz();
					cout<<endl;
					wskm->wypiszNieskierowany();
					
                    break;
                } case '3' : {
                    float ges;
			        int w;

			        cout << "Podaj ilosc wierzcholkow: ";
			        cin >> w;
			        cout << "Podaj gestosc: ";
			        cin >> ges;

			        wskm = new MacierzIncydencji(ges, w, true);
					wskm->wypisz();
                    break;
                } case '4' :{
					wskm->wypisz();
					break;
				}case '5' : {
                    wskm->MDRprim();
                    break;
                } case '6' : {
                    wskm->MDRkruskal();
                    break;
                } case '7' : {
                    wskm->sciezkaDijkstra();
                    break;
                } case '8' : {
                    wskm->sciezkaBellmana();
                    break;
                } case '9' : {
                    
                    break;
                } 


                  case 'a' : {
                    b = false;
                    break;
                }
                }
            } 
            break;
	   }
        case '2' : {
            while(c) {
                cout << "\n<<Menu listy>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytaj graf z pliku:"<<endl;
				cout<<"-2- Wprowadz graf:"<<endl;
				cout<<"-3- Stworz losowo:"<<endl;
				cout<<"-4- Pokaz graf"<<endl;
				cout<<"\n-5- Algorytm Prima" << endl;
				cout<<"-6- Algorytm Kruskala" << endl;
				cout<<"-7- Algorytm Dijkstry" << endl;
				cout<<"-8- Algorytm Forda-Bellmana" << endl;
				cout<<"-9- Algorytm Forda-Fulkersona" << endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";

				cin>>w;
                system("cls");
                switch(w) {
                case '1' : {
                   string nazwaPliku;
			       cout << "Podaj nazwe pliku: ";
			       cin >> nazwaPliku;

				   wskl = new ListaSasiedztwa();

			       ifstream plik1;
			       plik1.open(nazwaPliku, ios::in);

			       if (plik1.good())
				   plik1 >> *wskl;
			       else
				   cout << "Blad pliku" << endl;

			       plik1.close();
				   wskl->wypisz();
				   wskl->wypiszNieSkierowany();
                    break;
                } case '2' : {
                    int w, k;
			        cout << "Podaj ilosc wierzcholkow: ";
			        cin >> w;
			        cout << "Podaj ilosc krawedzi: ";
			        cin >> k;
					wskl = new ListaSasiedztwa(w, k);
					wskl->wypisz();
					cout<<endl; 
					wskl->wypiszNieSkierowany();
                    break;
                } case '3' : {
                    float ges;
			        int w;

			        cout << "Podaj ilosc wierzcholkow: ";
			        cin >> w;
			        cout << "Podaj gestosc: ";
			        cin >> ges;

					wskl = new ListaSasiedztwa(ges, w, true);
					wskl->wypisz();
					cout<<endl;
					wskl->wypiszNieSkierowany();
                    break;
                } case '4' :{
					wskl->wypisz();
					break;
				}case '5' : {
                    wskl->MDRprim();
                    break;
                } case '6' : {
                    wskl->MDRkruskal();
                    break;
                } case '7' : {
                    wskl->sciezkaDijkstra();
                    break;
                } case '8' : {
                    wskl->sciezkaBellmana();
                    break;
                } case '9' : {
					wskl->FordaFulkersona();
                    break;
                } 
                    case 'a' : {
                    c = false;
                    break;
                }
                }
            } 
            break;
        } 
		case '3': {
			a=false;
			break;
	   }

    }
  }
}


