#include "Tree.h"
#include <iostream>
#include <algorithm> 
using namespace std;

bool Tree::isEmpty()
{
    return root == nullptr;
}

NodeTree* Tree::getRoot()
{
    return root;
}

void Tree::add(Activo* data)
{
    add(root,data);
}

bool Tree::isRoot(NodeTree* node)
{
    return root == node;
}

bool Tree::isLeaf(NodeTree* node)
{
    return node->left == nullptr && node->right == nullptr;
}

bool Tree::isInternal(NodeTree* node)
{
    return !isLeaf(node);
}

NodeTree* Tree::add(NodeTree* node, Activo* value)
{
    NodeTree* nuevo = new NodeTree(value);
    if (isEmpty()) {
        root = new NodeTree(value);
    }
    else
    {
        if (node->value->id.compare(value->id) > 0) {
            if (node->left != nullptr) {
                add(node->left,value);
            }
            else
            {
                nuevo->parent = node;
                node->left = nuevo;
            }
        }
        else
        {
            if (node->right != nullptr) {
                add(node->right, value);
            }
            else
            {
                nuevo->parent = node;
                node->right = nuevo;
            }
        }
    }
    return nuevo;
}

void Tree::preOrden(NodeTree* node)
{
    if (node != nullptr) {
        cout << node->value->toString() << endl;
        cout << "-------------------------" << endl;
        preOrden(node->left);
        preOrden(node->right);
    }
}

void Tree::inOrden(NodeTree* node)
{
    if (node != nullptr) {
        inOrden(node->left);
        cout << node->value->toString() << endl;
        cout << "-------------------------" << endl;
        inOrden(node->right);
    }
}

void Tree::postOrden(NodeTree* node)
{
    if (node != nullptr) {
        postOrden(node->left);
        postOrden(node->right);
        cout << node->value->toString() << endl;
        cout << "-------------------------" << endl;
    }
}

int Tree::height(NodeTree* node)
{
    int altura = 0;
    if (isInternal(node)) {
        if (node->left != nullptr) {
            altura = max(altura, height(node->left));
        }

        if (node->right != nullptr) {
            altura = max(altura, height(node->right));
        }
        altura++;
    }
    return altura;
}

int Tree::depth(NodeTree* node)
{
    int profundidad = 0;
    if (node != getRoot()) {
        profundidad = 1 + depth(node->parent);
    }
    return profundidad;
}

void Tree::remove(string data)
{
    NodeTree* node = getNode(root,data);
    if (node != nullptr)
    {
        remove(node);
    }
    else
    {
        cout << "No se encontro el item" << endl;
    }
}

void Tree::search(string data)
{
    NodeTree* node = getNode(root, data);
    if (node != nullptr)
    {
        cout << node->value->toString() << endl;
    }
    else
    {
        cout << "No se encontro el item" << endl;
    }
}

void Tree::inOrden()
{
    inOrden(root);
}

void Tree::preOrden()
{
    preOrden(root);
}

void Tree::postOrden()
{
    postOrden(root);
}

int Tree::getFE(NodeTree* node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->fe;
    }
}

NodeTree* Tree::leftRotate(NodeTree* node)
{
    NodeTree* aux = node->left;
    node->left = aux->right;
    aux->right = node;
    node->fe = max(getFE(node->left), getFE(node->right)) + 1;
    aux->fe = max(getFE(aux->left), getFE(aux->right)) + 1;
    return aux;
}

NodeTree* Tree::rightRotate(NodeTree* node)
{
    NodeTree* aux = node->right;
    node->right = aux->left;
    aux->left = node;
    node->fe = max(getFE(node->left), getFE(node->right)) + 1;
    aux->fe = max(getFE(aux->left), getFE(aux->right)) + 1;
    return aux;
}

NodeTree* Tree::doubleLeftRotate(NodeTree* node)
{
    NodeTree* aux;
    node->left = rightRotate(node->left);
    aux = leftRotate(node);
    return aux;
}

NodeTree* Tree::doubleRightRotate(NodeTree* node)
{
    NodeTree* aux;
    node->right = leftRotate(node->right);
    aux = rightRotate(node);
    return aux;
}

void Tree::addAVL(Activo* data)
{
    NodeTree* nuevo = new NodeTree(data);
    if (root == nullptr) {
        root = nuevo;
    }
    else
    {
        root = addAVL(nuevo, root);
    }
}

NodeTree* Tree::addAVL(NodeTree* nuevo, NodeTree* subAr)
{
    NodeTree* nuevoPadre = subAr;
    if (nuevo->value->id.compare(subAr->value->id) < 0)
    {
        if (subAr->left == nullptr) {
            subAr->left = nuevo;
        }
        else
        {
            subAr->left = addAVL(nuevo, subAr->left);
            if ((getFE(subAr->left) - getFE(subAr->right)) == 2) {
                if (nuevo->value->id.compare(subAr->value->id) < 0) {
                    nuevoPadre = leftRotate(subAr);
                }
                else
                {
                    nuevoPadre = doubleLeftRotate(subAr);
                }
            }
        }
    }
    else if (nuevo->value->id.compare(subAr->value->id) > 0) {
        if (subAr->right == nullptr) {
            subAr->right = nuevo;
        }
        else
        {
            subAr->right = addAVL(nuevo, subAr->right);
            if ((getFE(subAr->right) - getFE(subAr->left)) == 2) {
                if (nuevo->value->id.compare(subAr->value->id) > 0) {
                    nuevoPadre = rightRotate(subAr);
                }
                else
                {
                    nuevoPadre = doubleRightRotate(subAr);
                }
            }
        }
    }
    else
    {
        cout << "Nodo duplicado" << endl;
    }

    if ((subAr->left == nullptr && subAr->right != nullptr)) {
        subAr->fe = subAr->right->fe + 1;
    }
    else if((subAr->right == nullptr && subAr->left != nullptr))
    {
        subAr->fe = subAr->left->fe + 1;
    }
    else
    {
        subAr->fe = max(getFE(subAr->left), getFE(subAr->right)) + 1;
    }
    
    return nuevoPadre;
}

void Tree::remove(NodeTree* node)
{
    if (isEmpty()) {
        cout << "Esta vacio el arbol";
    }
    else if (isLeaf(node))
    {
        removeLeaf(node);
    }
    else if(node->right != nullptr && node->left == nullptr)
    {
        removeChild(node,2);
    }
    else if (node->right == nullptr && node->left != nullptr)
    {
        removeChild(node, 1);
    }
    else
    {
        removeChild(node, 3);
    }

}

void Tree::removeLeaf(NodeTree* node)
{
    if (isRoot(node)) {
        root == nullptr;
    }
    else
    {
        NodeTree* parent = node->parent;
        if (parent->left == node) {
            parent->left = nullptr;
        }
        if (parent->right == node) {
            parent->right = nullptr;
        }
        delete(node);
        node = nullptr;
    }
}

void Tree::removeChild(NodeTree* node, int type)
{
    NodeTree* aux = node;
    switch (type)
    {
    case 1:
        aux = node->left;
        break;
    case 2:
        aux = minSubTree(node->right);
        break;
    case 3:
        aux = minSubTree(node->right);
        if (!isRoot(aux->parent)) {
            node->left->parent = aux;
            node->right->parent = aux;

            if (aux->parent->left == aux) {
                aux->parent->left = nullptr;
            }
            else if (aux->parent->right == aux) {
                aux->parent->right = nullptr;
            }
        }
        break;
    default:
        break;
    }

    aux->parent = node->parent;
    if (!isRoot(node)) {
        if (node->parent->left == node) {
            node->parent->left = aux;
        }
        else if (node->parent->right == node) {
            node->parent->right = aux;
        }
    }
    else
    {
        root = aux;
    }
    
    if (node->right != nullptr && node->right != aux) {
        aux->right = node->right;
    }

    if (node->left != nullptr && node->left != aux) {
        aux->left = node->left;
    }
    delete(node);
    node = nullptr;
}

NodeTree* Tree::minSubTree(NodeTree* node)
{
    if (node != nullptr && node->left != nullptr) {
        while (!isLeaf(node)) {
            node = minSubTree(node->left);
        }
    }
    return node;
}

NodeTree* Tree::getNode(NodeTree* node, string data)
{
    if (node == nullptr) {
        return nullptr;
    }
    else if(node->value->id.compare(data) < 0)
    {
        return getNode(node->right, data);
    }
    else if (node->value->id.compare(data) > 0)
    {
        return getNode(node->left, data);
    }
    else
    {
        return node;
    }
}
