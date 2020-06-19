#pragma once
#include "Nodo.h"
#include "Transaccion.h"
#include <stdio.h>
#include <stdlib.h>

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
	void ordenar();
	void ordenar2();
	void graficar();
	void usuario(Usuario* usuario);
};

