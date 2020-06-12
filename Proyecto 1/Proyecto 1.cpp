#include <iostream>
#include "ListaDoble.h"
#include "Transaccion.h"
#include "Usuario.h"
#include "Activo.h"
#include "ArbolAVL.h"
#include <time.h>
#include <stdio.h>
#include "Tree.h"
#include "Matriz.h"

using namespace std;
int main()
{

	//Activo* a1 = new Activo("1", "activo 1", "activo caro");
	//Activo* a2 = new Activo("2", "activo 2", "activo caro");
	//Activo* a3 = new Activo("3", "activo 2", "activo caro");
	//Activo* a4 = new Activo("4", "activo 2", "activo caro");
	//Activo* a5 = new Activo("5", "activo 2", "activo caro");
	//Activo* a6 = new Activo("6", "activo 2", "activo caro");
	//Activo* a7 = new Activo("7", "activo 2", "activo caro");
	//Activo* a8 = new Activo("8", "activo 2", "activo caro");
	//

	//Tree* arbol = new Tree();

	//arbol->addAVL(a1);
	//arbol->addAVL(a2);
	//arbol->addAVL(a3);
	//arbol->addAVL(a4);
	//arbol->addAVL(a5);
	//arbol->addAVL(a6);
	//arbol->addAVL(a7);
	//arbol->addAVL(a8);
	//cout << "Se encontro el nodo";
	//arbol->search("3");
	//cout << "---------------------" << endl;

	//arbol->inOrden();
	Matriz* matriz = new Matriz();
	matriz->addUsuario(new Usuario("SevenPok", "123", "Gerber Colindres"), "Guatemala", "Microsoft");
	matriz->addUsuario(new Usuario("Joselito", "123", "Jose Colindres"), "Guatemala", "Microsoft");
	matriz->addUsuario(new Usuario("Jovin", "123", "Jovin Mendez"), "Quetzaltenango", "Microsoft");
	matriz->addUsuario(new Usuario("Josue", "123", "Josue Lopez"), "Quetzaltenango", "Microsoft");
	matriz->addUsuario(new Usuario("SevenPok", "tiburcio", "Gerber Colindres"), "Quetzaltenango", "Microsoft");
	
	matriz->searUsuario("Admin", "", "")->value->renta->addAVL(new Activo("a5l8a","Activo 1","Activo caro"));
	matriz->searUsuario("Admin", "", "")->value->renta->inOrden();
	return 0;
}

