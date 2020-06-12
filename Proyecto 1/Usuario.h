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

	Usuario(string nickName, string password, string nombre) {
		this->nickName = nickName;
		this->password = password;
		this->nombre = nombre;
		this->renta = new Tree();
	}

	string toString();
};

