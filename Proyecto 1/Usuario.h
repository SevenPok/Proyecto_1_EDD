#pragma once
#include <iostream>
#include "Tree.h"
using namespace std;
class Usuario
{
public:
	string nickName;
	string password;
	string nombre;
	Tree* renta;
	string empresa;
	string departamento;

	Usuario(string nickName, string password, string nombre, string empresa, string departamento) {
		this->nickName = nickName;
		this->password = password;
		this->nombre = nombre;
		this->renta = new Tree();
		this->empresa = empresa;
		this->departamento = departamento;
	}

	string toString();
};

