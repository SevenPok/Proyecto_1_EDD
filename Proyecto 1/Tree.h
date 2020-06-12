#pragma once
#include <iostream>
#include "NodeTree.h"
#include "Activo.h"
using namespace std;
class Tree
{
public:
	NodeTree* root;

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

private:
	void removeLeaf(NodeTree* node);
	void removeChild(NodeTree* node, int type);
	NodeTree* minSubTree(NodeTree* node);
	void remove(NodeTree* node);
	NodeTree* getNode(NodeTree* node, string data);
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

