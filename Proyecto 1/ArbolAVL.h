#pragma once
#include "NodoArbol.h"
#include "Activo.h"

class ArbolAVL
{
public:
	NodoArbol* root;

	ArbolAVL() {
		root = nullptr;
	}

	void add(int key, Activo* value);
	void inOrden(NodoArbol* node);
};

