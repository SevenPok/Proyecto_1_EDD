#include "ArbolAVL.h"

void ArbolAVL::add(int key, Activo* value)
{
	NodoArbol* nuevo = new NodoArbol(key);
	nuevo->value = value;

	if (root == nullptr) {
		root = nuevo;
	}
	else {
		NodoArbol* aux = root;
		while (aux != nullptr) {
			nuevo->parent = aux;
			if (nuevo->key >= aux->key) {
				aux = aux->right;
			}
			else {
				aux = aux->left;
			}
		}
		if (nuevo->key < nuevo->parent->key) {
			nuevo->parent->left = nuevo;
		}
		else {
			nuevo->parent->right = nuevo;
		}
	}
}

void ArbolAVL::inOrden(NodoArbol* node)
{
	if (node != nullptr) {
		inOrden(node->left);
		cout << node->key << endl;
		inOrden(node->right);
	}
}
