#include "ListaDoble.h"
#include "Nodo.h"
#include "Transaccion.h"

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
