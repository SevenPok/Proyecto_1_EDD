#pragma once
#include <iostream>
#include "Activo.h"
using namespace std;
class NodeTree
{
public:
	Activo* value;
	int fe;
	NodeTree* parent;
	NodeTree* left;
	NodeTree* right;

	NodeTree(Activo* value) {
		this->value = value;
		this->fe = 0;
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};

