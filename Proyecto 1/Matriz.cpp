#include "Matriz.h"

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
			columna = columna->right;
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
