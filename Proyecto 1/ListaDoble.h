#pragma once
#include "Nodo.h"
#include "Transaccion.h"

using namespace std;
class ListaDoble
{
public:
	Nodo* head;
	Nodo* end;
	int size;

	ListaDoble() {
		head = nullptr;
		end = nullptr;
		size = 0;
	}

	bool isEmpty();
	void addFirst(Transaccion* value);
	void addLast(Transaccion* value);
	Nodo* search(string value);
	void remove(string value);
	void show();
};

