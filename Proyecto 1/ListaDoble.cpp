#include "ListaDoble.h"
#include "Nodo.h"
#include "Transaccion.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
bool ListaDoble::isEmpty()
{
	return size == 0;
}

void ListaDoble::addFirst(Transaccion* value)
{
	Nodo* nuevo = new Nodo(value,nullptr,nullptr);
	if (isEmpty()) {
		nuevo->next = nuevo;
		nuevo->back = nuevo;
		head = nuevo;
		end = nuevo;
	}
	else
	{
		nuevo->next = head;
		nuevo->back = end;
		head->back = nuevo;
		end->next = nuevo;
		head = nuevo;
	}
	size++;
}

void ListaDoble::addLast(Transaccion* value)
{
	if (isEmpty()) {
		addFirst(value);
	}
	else
	{
		Nodo* nuevo = new Nodo(value, nullptr, nullptr);
		nuevo->next = head;
		nuevo->back = end;
		head->back = nuevo;
		end->next = nuevo;
		end = nuevo;
		size++;
	}
}

Nodo* ListaDoble::search(string value)
{
	if (isEmpty()) {
		return 0;
	}
	else
	{
		Nodo* aux = head;
		do
		{
			if (value == aux->value->id) {
				return aux;
			}
			aux = aux->next;
		} while (aux != head);
		return 0;
	}
}

void ListaDoble::remove(string data)
{
	Nodo* value = search(data);
	if (value != 0) {
		if (size == 1) {
			Nodo* aux = head;
			head = nullptr;
			end = nullptr;
			delete(aux);
		}
		else if (value == head) {
			Nodo* aux = head;
			head = head->next;
			head->back = end;
			end->next = head;
			delete(aux);
		}
		else if (value == end)
		{
			Nodo* aux = end;
			end = end->back;
			end->next = head;
			head->back = end;
			delete(aux);
		}
		else
		{
			value->back->next = value->next;
			value->next->back = value->back;
			delete(value);
		}
		size--;
	}
}

void ListaDoble::show()
{
	if (isEmpty()) {
		cout << "La lista esta vacia";
	}
	else
	{
		Nodo* aux = head;
		cout << "--------------ACTIVOS--------------" << endl;
		do
		{
			cout << aux->value->toString() << endl;
			cout << "-----------------------------------" << endl;
			aux = aux->next;
		} while (aux != head);
	}
}

void ListaDoble::ordenar()
{
	if (!isEmpty()) {
		Transaccion* aux;
		Nodo* i, * j;
		i = head;
		do
		{
			j = i->next;
			while (j != head)
			{
				if (i->value->id.compare(j->value->id) > 0) {
					aux = j->value;
					j->value = i->value;
					i->value = aux;
				}
				j = j->next;
			}
			i = i->next;
			j = i->next;
		} while (i != head);
		cout << "Se ordeno correctamente" << endl;
	}
	else
	{
		cout << "Esta vacia la lista" << endl;
	}
}

void ListaDoble::ordenar2()
{
	if (!isEmpty()) {
		Transaccion* aux;
		Nodo* i, * j;
		i = head;
		do
		{
			j = i->next;
			while (j != head)
			{
				if (i->value->id.compare(j->value->id) < 0) {
					aux = j->value;
					j->value = i->value;
					i->value = aux;
				}
				j = j->next;
			}
			i = i->next;
			j = i->next;
		} while (i != head);
		cout << "Se ordeno correctamente" << endl;
	}
	else
	{
		cout << "Esta vacia la lista" << endl;
	}
}

void ListaDoble::graficar()
{
	ofstream file;
	file.open("D:\\Documents\\GitHub\\Proyecto_1_EDD\\ListaDoble.dot", ios::out);
	if (file.fail()) {
		return;
	}
	else
	{
		Nodo* aux = head;
		if (aux != nullptr) {
			file << "digraph G {\n";
			do
			{
				file << aux->value->id + "[label=" + aux->value->toString() + "];\n";
				aux = aux->next;
			} while (aux != head);

			do
			{
				file << aux->value->id + "->" + aux->next->value->id + "\n";
				file << aux->value->id + "->" + aux->back->value->id + "\n";
				aux = aux->next;
			} while (aux != head);
			file << "}";
		}
	}
	file.close();
	system("dot.exe -Tpng D:\\Documents\\GitHub\\Proyecto_1_EDD\\ListaDoble.dot -o D:\\Documents\\GitHub\\Proyecto_1_EDD\\ListaDoble.png");
	cout << "Se genero reporte\n";
}

void ListaDoble::usuario(Usuario* usuario)
{
	ofstream file;
	file.open("D:\\Documents\\GitHub\\Proyecto_1_EDD\\rentaPorUsuario.dot", ios::out);
	if (file.fail()) {
		return;
	}
	else
	{
		Nodo* aux = head;
		ListaDoble* usu = new ListaDoble();
		Nodo* gra;
		if (aux != nullptr) {
			file << "digraph G {\n";
			do
			{
				if (aux->value->usuario->nickName == usuario->nickName && aux->value->usuario->departamento == usuario->departamento && aux->value->usuario->empresa == usuario->empresa) {
					file << aux->value->id + "[label=" + aux->value->toString() + "];\n";
					usu->addLast(aux->value);
				}
				aux = aux->next;
			} while (aux != head);

			gra = usu->head;
			file << gra->value->id + "->" + gra->next->value->id + "\n";
			gra = gra->next;
			while (gra->next != usu->head) {
				file << gra->value->id + "->" + gra->next->value->id + "\n";
				gra = gra->next;
			}

			file << "}";
		}
	}
	file.close();
	system("dot.exe -Tpng D:\\Documents\\GitHub\\Proyecto_1_EDD\\rentaPorUsuario.dot -o D:\\Documents\\GitHub\\Proyecto_1_EDD\\rentaPorUsuario.png");
	cout << "Se genero reporte\n";
}







