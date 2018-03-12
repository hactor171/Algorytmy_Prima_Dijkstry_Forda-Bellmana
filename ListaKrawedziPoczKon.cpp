#include "ListaKrawedziPoczKon.h"
#include "main.h"

ListaKrawedziPoczKon::ListaKrawedziPoczKon() {
	head = NULL;
	size = 0;
}

ListaKrawedziPoczKon::~ListaKrawedziPoczKon() {
	node *local;

	while (head)
	{
		local = head->next;
		delete head;
		head = local;
	}

}

void ListaKrawedziPoczKon::dodaj_krawedz(int wp, int wk, int waga) {
	node* local = new node();
	node *local2;
	local->next = NULL;
	local->kr.waga = waga;
	local->kr.wp= wp;
	local->kr.wk = wk;

	if (head) {
		local2 = head;
		while (local2->next) {
			local2 = local2->next;
		}
		local2->next = local;
	}
	else {
		head = local;
	}

	++size;
}

KrawedzPoczKon ListaKrawedziPoczKon::dostan_krawedz(int nr) {
	if (nr > size || nr < 0)
		return KrawedzPoczKon();


	node* local = head;
	for (int i = 0; i < nr; i++)
	{
		local = local->next;
	}

	if (local)
		return local->kr;

	return KrawedzPoczKon();
}

int ListaKrawedziPoczKon::dostan_ilosc_krawedzi() {
	return this->size;
}

void ListaKrawedziPoczKon::sortuj() {
	node* local;
	

	for (int i = 0; i < size-1; i++)
	{
		local = head;
		for (int j = 0; j < size-1; j++)
		{
			if (local->kr.waga > local->next->kr.waga) {
				
				KrawedzPoczKon k1 = local->kr;
				KrawedzPoczKon k2 = local->next->kr;
				
				local->kr= k2;
				local->next->kr = k1;				
			}
			
			local = local->next;
			
		}
	}
}


void ListaKrawedziPoczKon::wypisz() {
	node* local;
	local = head;

	while (local) {
		cout << "Wp: " << local->kr.wp << " wk: " << local->kr.wk << " waga: " << local->kr.waga << endl;
		local = local->next;
	}
	
}