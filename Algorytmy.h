#pragma once
#include "MacierzIncydencji.h"
//#include "main.h"
#include "tools.cpp"
#include "ListaSasiedztwa.h"
class Algorytmy
{
public:
	Algorytmy(void);
	~Algorytmy(void);
};
struct Edge
{
	int v1, v2, weight;               
};

class Queue
{
private:
	Edge * Heap;
	int hpos;
public:
	Queue(int n);
	~Queue();
	Edge front();
	void push(Edge e);
	void pop();
};


struct TNode
{
	TNode * next;
	int v, weight;
};

class MSTree
{
private:
	TNode ** A;                   // Tablica list s�siedztwa
	int Alen;                     // Liczba kom�rek w tablicy
	int weight;                   // Waga ca�ego drzewa
public:
	MSTree(int n);
	~MSTree();
	void addEdge(Edge e);
	TNode * getAList(int n);
	void print();
};
class DSStruct
{
	struct DSNode
	{
		int up, rank;
	};

	DSNode * Z;
public:
	DSStruct(int n);
	~DSStruct();
	void MakeSet(int v);
	int FindSet(int v);
	void UnionSets(Edge e);
};
struct slistEl
{
	slistEl * next;
	int v, w;                        // numer w�z�a docelowego i waga kraw�dzi
};
slistEl ** A;                     // Tablica dynamiczna list s�siedztwa
long long * d;                    // Tablica koszt�w doj�cia
int * p;                          // Tablica poprzednik�w


