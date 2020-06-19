#pragma once
#include "ListaDoble.h"
#include "Matriz.h"

class Menu
{
public:
	Matriz* admin;
	ListaDoble* transaccion;
	Menu() {
		admin = new Matriz();
		transaccion = new ListaDoble();
	}

	void principal();
private:
	void menuAdmin();
	void menuUsuario(Usuario* usuario);
	void subMenu1Usuario(Usuario* usuario);
	void subMenu2Usuario(Usuario* usuario);
	void subMenu3Usuario(Usuario* usuario);
	void subMenu1Admin();
	void subMenu2Admin();
	void subMenu3Admin();
	void subMenu4Admin();
	void subMenu5Admin();
	void subMenu6Admin();
	void subMenu7Admin();
	string generarId();
	
};

