#include "Matriz.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>

NodoMatriz* Matriz::createDepartamento(string departamento)
{
	NodoMatriz* nuevo = new NodoMatriz(nullptr, departamento, "");
	nuevo->left = this->departamento;
	this->departamento->right = nuevo;
	this->departamento = nuevo;
	return nuevo;
}

NodoMatriz* Matriz::createEmpresa(string empresa)
{
	NodoMatriz* nuevo = new NodoMatriz(nullptr, "", empresa);
	nuevo->up = this->empresa;
	this->empresa->down = nuevo;
	this->empresa = nuevo;
	return nuevo;
}

void Matriz::addUsuario(Usuario* data, string departamento, string empresa)
{
	NodoMatriz* nuevo = new NodoMatriz(data, departamento, empresa);
	NodoMatriz* columna = searchDepartamento(departamento);
	NodoMatriz* fila = searchEmpresa(empresa);

	if (columna == nullptr)
		columna = createDepartamento(departamento);
	if (fila == nullptr)
		fila = createEmpresa(empresa);

	NodoMatriz* aux = searchUsuario(fila, columna, empresa, departamento);

	if (aux == nullptr) {
		while (fila->right != nullptr) {
			fila = fila->right;
		}
		fila->right = nuevo;
		nuevo->left = fila;

		while (columna->down != nullptr) {
			columna = columna->down;
		}

		columna->down = nuevo;
		nuevo->up = columna;
		cout << "Se inserto correctamente el usuario" << endl;
	}
	else if (insertUsuario(aux, nuevo)) {
		cout << "Se inserto correctamente el usuario" << endl;
	}
	else {
		cout << "Usuario repetido" << endl;
	}

}

NodoMatriz* Matriz::searchDepartamento(string data)
{
	NodoMatriz* aux = head;
	while (aux != nullptr)
	{
		if (aux->departamento == data)
			return aux;
		aux = aux->right;
	}
	return nullptr;
}

NodoMatriz* Matriz::searchEmpresa(string data)
{
	NodoMatriz* aux = head;
	while (aux != nullptr)
	{
		if (aux->empresa == data)
			return aux;
		aux = aux->down;
	}
	return nullptr;
}

NodoMatriz* Matriz::searUsuario(string usuario, string empresa, string departamento)
{
	NodoMatriz* columna = searchDepartamento(departamento);
	NodoMatriz* fila = searchEmpresa(empresa);

	if (columna == nullptr || fila == nullptr) {
		return nullptr;
	}
	else {
		NodoMatriz* aux = searchUsuario(fila, columna, empresa, departamento);
		if (aux == nullptr) {
			return nullptr;
		}
		else {
			NodoMatriz* aux2 = searchUsuario(aux, usuario);
			if (aux2 == nullptr) {
				return nullptr;
			}
			else {
				return aux2;
			}
		}
	}
	
}

bool Matriz::login(string usuario, string password, string empresa, string departamento)
{
	NodoMatriz* aux = searUsuario(usuario, empresa, departamento);
	if (aux != nullptr) {
		if (aux->value->password == password) {
			return true;
		}
	}
	return false;

}

void Matriz::graficar()
{
	ofstream file;
	file.open("D:\\Documents\\GitHub\\Proyecto_1_EDD\\Matriz.dot", ios::out);
	if (file.fail()) {
		return;
	}
	else
	{
		file << "digraph G {\n";
		file << "node [shape=box];\n";
		string alinear = "{rank=same;";
		NodoMatriz* x = head;
		NodoMatriz* y = head;
		while (x != nullptr && y != nullptr) {
			file << label("", x);
			file << derecha("", x);
			/*file << izquierda("", x);*/
			/*file << arriba("", x);*/
			file << abajo("", x);
			file << adentro("", x);
			alinear += generarID("", x) + ";";
			x = x->right;
			if (x == nullptr) {
				alinear += "}\n";
				file << alinear;
				alinear = "{rank=same;";
				y = y->down;
				x = y;
			}
		}
		file << "}";
	}
	file.close();
	system("dot.exe -Tpng D:\\Documents\\GitHub\\Proyecto_1_EDD\\Matriz.dot -o D:\\Documents\\GitHub\\Proyecto_1_EDD\\Matriz.png");
	cout << "Se genero reporte\n";
}

void Matriz::activoPorEmpresa(string empresa)
{
	NodoMatriz* fila = searchEmpresa(empresa);
	NodoMatriz* aux;
	if (fila != nullptr) {
		archivo.open("D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorEmpresa.dot", ios::out);
		if (archivo.fail()) {
			return;
		}
		else
		{
			archivo << "digraph G {\n";
			while (fila != nullptr) {
				if (fila->forward != nullptr) {
					aux = fila;
					while (aux != nullptr) {
						archivo << label("", aux);
						if (aux->value != nullptr) {
							if (aux->value->renta->root != nullptr) {
								archivo << generarID("", aux) + "->" + generarID("", aux, aux->value->renta->root) + "\n";
								generarArbol(aux, aux->value->renta->root);
							}
						}
						aux = aux->forward;
					}
				}
				else
				{
					archivo << label("", fila);
					if (fila->value != nullptr) {
						if (fila->value->renta->root != nullptr) {
							archivo << generarID("", fila) + "->" + generarID("", fila, fila->value->renta->root) + "\n";
							generarArbol(fila, fila->value->renta->root);
						}
					}
				}
				fila = fila->right;
			}
		
			archivo << "}";
		}
		archivo.close();
		system("dot.exe -Tpng D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorEmpresa.dot -o D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorEmpresa.png");
		cout << "Se genero reporte\n";
	}
	else
	{
		cout << "No se encontro la empresa" << endl;
	}
}

void Matriz::activoPorDepartamento(string departamento)
{
	NodoMatriz* columna = searchDepartamento(departamento);
	NodoMatriz* aux;
	if (columna != nullptr) {
		archivo.open("D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorDepartamento.dot", ios::out);
		if (archivo.fail()) {
			return;
		}
		else
		{
			archivo << "digraph G {\n";
			while (columna != nullptr) {
				if (columna->forward != nullptr) {
					aux = columna;
					while (aux != nullptr) {
						archivo << label("", aux);
						if (aux->value != nullptr) {
							if (aux->value->renta->root != nullptr) {
								archivo << generarID("", aux) + "->" + generarID("", aux, aux->value->renta->root) + "\n";
								generarArbol(aux, aux->value->renta->root);
							}
						}
						aux = aux->forward;
					}
				}
				else
				{
					archivo << label("", columna);
					if (columna->value != nullptr) {
						if (columna->value->renta->root != nullptr) {
							archivo << generarID("", columna) + "->" + generarID("", columna, columna->value->renta->root) + "\n";
							generarArbol(columna, columna->value->renta->root);
						}
					}
				}
				columna = columna->down;
			}

			archivo << "}";
		}
		archivo.close();
		system("dot.exe -Tpng D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorDepartamento.dot -o D:\\Documents\\GitHub\\Proyecto_1_EDD\\activoPorDepartamento.png");
		cout << "Se genero reporte\n";
	}
	else
	{
		cout << "No se encontro el departamento" << endl;
	}
}

NodoMatriz* Matriz::searchUsuario(NodoMatriz* fila, NodoMatriz* columna, string empresa, string departamento)
{
	while (fila != nullptr || columna != nullptr) {
		if (fila != nullptr) {
			if (fila->departamento == departamento && fila->empresa == empresa) {
				return fila;
			}
			else
			{
				fila = fila->right;
			}
		}

		if (columna != nullptr) {
			if (columna->departamento == departamento && columna->empresa == empresa) {
				return columna;
			}
			else
			{
				columna = columna->left;
			}
		}
	}
	return nullptr;
}

bool Matriz::insertUsuario(NodoMatriz* node, NodoMatriz* nuevo)
{
	if (node->value->nickName == nuevo->value->nickName) {
		return false;
	}
	while (node->forward != nullptr) {
		node = node->forward;
		if (node->value->nickName == nuevo->value->nickName) {
			return false;
		}
	}
	nuevo->back = node;
	node->forward = nuevo;
	return true;
}

NodoMatriz* Matriz::searchUsuario(NodoMatriz* node, string usuario)
{
	while (node != nullptr) {
		if (node->value->nickName == usuario) {
			return node;
		}
		node = node->forward;
	}
	return nullptr;
}

string Matriz::arriba(string cadena, NodoMatriz* node)
{
	if (node->up != nullptr) {
		cadena += generarID("", node) + "->" + generarID("", node->up) + "\n";
		cadena += generarID("", node->up) + "->" + generarID("", node) + "\n";
	}
	return cadena;
}

string Matriz::abajo(string cadena, NodoMatriz* node)
{
	if (node->down != nullptr) {
		cadena += generarID("", node) + "->" + generarID("", node->down) + "\n";
		cadena += generarID("", node->down) + "->" + generarID("", node) + "\n";
	}
	return cadena;
}

string Matriz::izquierda(string cadena, NodoMatriz* node)
{
	if (node->left != nullptr) {
		cadena += generarID("", node) + "->" + generarID("", node->left) + "\n";
		cadena += generarID("", node->left) + "->" + generarID("", node) + "\n";
	}
	return cadena;
}

string Matriz::derecha(string cadena, NodoMatriz* node)
{
	if (node->right != nullptr) {
		cadena += generarID("", node) + "->" + generarID("", node->right) + "\n";
		cadena += generarID("", node->right) + "->" + generarID("", node) + "\n";
	}
	return cadena;
}

string Matriz::generarID(string cadena, NodoMatriz* node)
{
	if (node->value != nullptr) {
		cadena += node->value->nickName + "" + node->departamento + "" + node->empresa;
	}
	else if (node->departamento != "") {
		cadena += node->departamento;
	}
	else
	{
		cadena += node->empresa;
	}
	return cadena;
}

string Matriz::adentro(string cadena, NodoMatriz* node)
{
	if (node->forward != nullptr) {
		cadena += generarID("", node) + "[style=filled, fillcolor=red]\n";
	}
	return cadena;
}

string Matriz::label(string cadena, NodoMatriz* node)
{
	if (node->value != nullptr) {
		cadena += generarID("", node) + "[label=\"" + node->value->nickName + "\"]\n";
	}
	else if (node->departamento != "") {
		cadena += generarID("", node) + "[label=\"" + node->departamento + "\"]\n";
	}
	else
	{
		cadena += generarID("", node) + "[label=\"" + node->empresa + "\"]\n";
	}
	return cadena;
}

void Matriz::generarArbol(NodoMatriz* usaurio, NodeTree* arbol)
{
	if (arbol != nullptr) {
		generarArbol(usaurio,arbol->left);
		archivo << label("", usaurio, arbol);
		if (arbol->left != nullptr) {
			archivo << generarID("", usaurio, arbol) + "->" + generarID("", usaurio, arbol->left) + "\n";
		}
		if (arbol->right != nullptr) {
			archivo << generarID("", usaurio, arbol) + "->" + generarID("", usaurio, arbol->right) + "\n";
		}
		generarArbol(usaurio,arbol->right);
	}
}

string Matriz::generarID(string cadena, NodoMatriz* usaurio, NodeTree* arbol)
{
	if (arbol != nullptr) {
		cadena = generarID("", usaurio) + "_" + arbol->value->id;
	}
	return cadena;
}

string Matriz::label(string caden, NodoMatriz* usaurio, NodeTree* arbol)
{
	if (arbol != nullptr) {
		caden += generarID("", usaurio, arbol) + "[label=" + arbol->value->graficar() + "]\n";
	}
	return caden;
}
