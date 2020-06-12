#pragma once
#include "NodoMatriz.h"
#include "Usuario.h"
using namespace std;
class Matriz
{
public:
	NodoMatriz* head;
	NodoMatriz* departamento;
	NodoMatriz* empresa;
	Matriz() {
		head = new NodoMatriz(new Usuario("Admin","123","Gerber Colindres"),"","");
		departamento = head;
		empresa = head;
	}

	NodoMatriz* createDepartamento(string departamento);
	NodoMatriz* createEmpresa(string empresa);
	void addUsuario(Usuario* data, string departamento, string empresa);
	NodoMatriz* searchDepartamento(string data);
	NodoMatriz* searchEmpresa(string data);
	NodoMatriz* searUsuario(string usuario, string empresa, string departamento);
	bool login(string usuario, string password, string empresa, string departamento);
private:
	NodoMatriz* searchUsuario(NodoMatriz* fila, NodoMatriz* columna, string empresa, string departamento);
	bool insertUsuario(NodoMatriz* node, NodoMatriz* nuevo);
	NodoMatriz* searchUsuario(NodoMatriz* node, string usuario);
};

