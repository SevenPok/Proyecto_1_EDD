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
	ofstream archivo;
	Matriz() {
		head = new NodoMatriz(new Usuario("Admin","123","Gerber Colindres","",""),"","");
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
	void graficar();
	void activoPorEmpresa(string empresa);
	void activoPorDepartamento(string departamento);
private:
	NodoMatriz* searchUsuario(NodoMatriz* fila, NodoMatriz* columna, string empresa, string departamento);
	bool insertUsuario(NodoMatriz* node, NodoMatriz* nuevo);
	NodoMatriz* searchUsuario(NodoMatriz* node, string usuario);
	string arriba(string cadena, NodoMatriz* node);
	string abajo(string cadena, NodoMatriz* node);
	string izquierda(string cadena, NodoMatriz* node);
	string derecha(string cadena, NodoMatriz* node);
	string generarID(string cadena, NodoMatriz* node);
	string adentro(string cadena, NodoMatriz* node);
	string label(string cadena, NodoMatriz* node);
	void generarArbol(NodoMatriz* usaurio, NodeTree* arbol);
	string generarID(string cadena, NodoMatriz* usaurio, NodeTree* arbol);
	string label(string caden, NodoMatriz* usaurio, NodeTree* arbol);
};

