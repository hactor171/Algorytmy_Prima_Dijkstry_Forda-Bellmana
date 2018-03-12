#include "ListaKrawedzi.h"
#include "main.h"



ListaKrawedzi::ListaKrawedzi() {
	head = NULL;
	size = 0;
}

ListaKrawedzi::~ListaKrawedzi(){
	node *local;

	while (head)
	{
		local = head->next;
		delete head;
		head = local;
	}

}

void ListaKrawedzi::dodaj_sasiada(int nr_wierz, int waga) {
	node* local = new node();
	local->next = NULL;
	local->waga = waga;
	local->wierzcholek = nr_wierz;

node* local2 = head;

	if (head) {
		
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

int ListaKrawedzi::dostan_sasiada(int nr) {
	if (nr > size || nr < 0)
		return -100;


	node* local = head;
	for (int i = 0; i < nr; i++)
	{
		local = local->next;
	}
	
	if (local)
		return local->wierzcholek;

	return -101;
}

int ListaKrawedzi::dostan_wage(int nr) {
	if (nr > size || nr < 0)
		return -100;


	node* local = head;
	for (int i = 0; i < nr; i++)
	{
		local = local->next;
	}

	if (local)
		return local->waga;

	return -101;
}

int ListaKrawedzi::dostan_ilosc_sasiadow() {
	return this->size;
}