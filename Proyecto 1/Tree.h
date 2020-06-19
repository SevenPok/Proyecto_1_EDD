#pragma once
#include <iostream>
#include "NodeTree.h"
#include "Activo.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
class Tree
{
public:
	NodeTree* root;
	ofstream file;
	Tree() {
		this->root = nullptr;
	}

	bool isEmpty();
	NodeTree* getRoot();
	void add(Activo* data);
	void remove(string data);
	void search(string data);
	void inOrden();
	void preOrden();
	void postOrden();
	int getFE(NodeTree* node);
	NodeTree* leftRotate(NodeTree* node);
	NodeTree* rightRotate(NodeTree* node);
	NodeTree* doubleLeftRotate(NodeTree* node);
	NodeTree* doubleRightRotate(NodeTree* node);
	void addAVL(Activo* data);
	NodeTree* getNode(NodeTree* node, string data);
	void graficar(string usuario);
	void inOrden2(NodeTree* node);

private:
	void removeLeaf(NodeTree* node);
	void removeChild(NodeTree* node, int type);
	NodeTree* minSubTree(NodeTree* node);
	void remove(NodeTree* node);
	void preOrden(NodeTree* node);
	void inOrden(NodeTree* node);
	void postOrden(NodeTree* node);
	NodeTree* add(NodeTree* node, Activo* value);
	bool isRoot(NodeTree* node);
	bool isLeaf(NodeTree* node);
	bool isInternal(NodeTree* node);
	int height(NodeTree* node);
	int depth(NodeTree* node);
	NodeTree* addAVL(NodeTree* nuevo, NodeTree* subAr);
};

