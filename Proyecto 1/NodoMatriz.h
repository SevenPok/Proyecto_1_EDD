#pragma once
#include "Usuario.h"
class NodoMatriz
{
public:
	Usuario* value;
	NodoMatriz* up;
	NodoMatriz* down;
	NodoMatriz* left;
	NodoMatriz* right;
	NodoMatriz* forward;
	NodoMatriz* back;
	string departamento;
	string empresa;

	NodoMatriz(Usuario* value, string departamento, string empresa) {
		this->value = value;
		up = nullptr;
		down = nullptr;
		left = nullptr;
		right = nullptr;
		forward = nullptr;
		back = nullptr;
		this->departamento = departamento;
		this->empresa = empresa;
	}
};

