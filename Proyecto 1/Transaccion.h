#pragma once
#include <iostream>
#include "Activo.h"
#include "Usuario.h"

using namespace std;
class Transaccion
{
public:
	string id;
	Activo* activo;
	Usuario* usuario;
	string departamento;
	string empresa;
	string fecha;
	string tiempo;
	

	Transaccion(string id, Activo* activo, Usuario* usuario, string departamento, string empresa, string fecha, string tiempo) {
		this->id = id;
		this->activo = activo;
		this->usuario = usuario;
		this->departamento = departamento;
		this->empresa = empresa;
		this->fecha = fecha;
		this->tiempo = tiempo;
	}

	string toString();
};

