#pragma once
#include <iostream>
using namespace std;
class Activo
{
public:
	string id;
	string nombre;
	string descripcion;
	bool disponibilidad;

	Activo(string id, string nombre, string descripcion) {
		this->id = id;
		this->nombre = nombre;
		this->descripcion = descripcion;
		this->disponibilidad = true;
	}

	string toString();
	string graficar();
};

