#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class ListaDobleCircular
{
private:
	Node<T>* head;
	Node<T>* end;
	int size;
public:
	ListaDobleCircular() {
		this->head = nullptr;
		this->end = nullptr;
		this->size = 0;
	}

	bool isEmty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void addFirst(T data) {
		Node<T>* nuevo = new Node<T>(data,nullptr,nullptr);
		if (isEmty()) {
			nuevo->setNext(nuevo);
			nuevo->setBack(nuevo);
			head = nuevo;
			end = nuevo;
		}
		else
		{
			nuevo->setNext(head);
			nuevo->setBack(end);
			head->setBack(nuevo);
			end->setNext(nuevo);
			head = nuevo;
		}
		size++;
	}

	void addFinal(T data) {
		if (isEmty()) {
			addFirst(data);
		}
		else
		{
			Node<T>* nuevo = new Node<T>(data, nullptr, nullptr);
			nuevo->setNext(head);
			nuevo->setBack(end);
			head->setBack(nuevo);
			end->setNext(nuevo);
			size++;
			end = nuevo;
		}
	}

	Node<T>* search(T data) {
		if (isEmty()) {
			return 0;
		}
		else
		{
			Node<T>* aux = head;
			do
			{
				if (data == aux->getData()) {
					return aux;
				}
				aux = aux->getNext();
			} while (aux != head);
			return 0;
		}
	}

	void remove(T data) {
		Node<T>* value = search(data);
		if (value != 0) {
			if (size == 1) {
				Node<T>* aux = head;
				head = nullptr;
				end = nullptr;
				delete(aux);
			}
			else if (value == head) {
				Node<T>* aux = head;
				head = head->getNext();
				head->setBack(end);
				end->setNext(head);
				delete(aux);
			}
			else if(value == end)
			{
				Node<T>* aux = end;
				end = end->getBack();
				end->setNext(head);
				head->setBack(end);
				delete(aux);
			}
			else
			{
				value->getBack()->setNext(value->getNext());
				value->getNext()->setBack(value->getBack());
				delete(value);
			}
			size--;
		}
	}

	void show() {
		if (isEmty()) {
			cout << "La lista esta vacia";
		}
		else
		{
			Node<T>* aux = head;
			do
			{
				cout << aux->getData()<<endl;
				aux = aux->getNext();
			} while (aux != head);
		}
	}
};
