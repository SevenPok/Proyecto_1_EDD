#pragma once
#include <iostream>
#include "Transaccion.h"
using namespace std;

class Nodo
{
public:
	Transaccion* value;
	Nodo* next;
	Nodo* back;

	Nodo(Transaccion* value, Nodo* next, Nodo* back) {
		this->value = value;
		this->next = next;
		this->back = back;
	}


};

