#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
private:
	T data;
	Node<T>* next;
	Node<T>* back;
public:
	Node(T data, Node<T>* next, Node<T>* back) {
		this->data = data;
		this->next = next;
		this->back = back;
	}

	T getData() {
		return data;
	}

	void setData(T data) {
		this->data = data;
	}
	
	Node<T>* getNext() {
		return next;
	}

	void setNext(Node<T>* next) {
		this->next = next;
	}

	Node<T>* getBack() {
		return back;
	}

	void setBack(Node<T>* back) {
		this->back = back;
	}
};