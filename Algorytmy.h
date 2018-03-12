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
	TNode ** A;                   // Tablica list s¹siedztwa
	int Alen;                     // Liczba komórek w tablicy
	int weight;                   // Waga ca³ego drzewa
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
	int v, w;                        // numer wêz³a docelowego i waga krawêdzi
};
slistEl ** A;                     // Tablica dynamiczna list s¹siedztwa
long long * d;                    // Tablica kosztów dojœcia
int * p;                          // Tablica poprzedników


