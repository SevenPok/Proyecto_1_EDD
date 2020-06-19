#include <iostream>
#include <conio.h>
#include <string>
#include "Menu.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

void Menu::principal()
{
	string nickName = "";
	string password = "";
	string departamento = "";
	string empresa = "";
	string espacio = "";
	while (true) {
		system("cls");
		cout << "--------------------Renta de activos-----------------\n";
		cout << "------------------ 1. Iniciar Sesion-----------------\n";
		cout << "Ingrese usuario: ";
		getline(cin, nickName);
		cout << "Ingrese pasword: ";
		getline(cin, password);
		cout << "Ingrese empresa: ";
		getline(cin, empresa);
		cout << "Ingrese departamento: ";
		getline(cin, departamento);
		NodoMatriz* usuario = admin->searUsuario(nickName, empresa, departamento);
		if (usuario != nullptr) {
			if (admin->login(nickName, password, empresa, departamento)) {
				cout << "Bienvenido\n";
				getline(cin, espacio);
				if (usuario == admin->head) {
					menuAdmin();
				}
				else {
					menuUsuario(usuario->value);
				}
				
			}
			else
			{
				cout << "Usuario o contrasenia incorrectas\n";
				getline(cin, espacio);
			}
		}
		else
		{
			cout << "Usuario no existente\n";
			getline(cin, espacio);
		}
	}
}

void Menu::menuAdmin()
{
	string opcion = "";
	while (true)
	{
		system("cls");
		cout << "-------------------Admin------------------\n";
		cout << "1. Registrar usuario\n2. Agregar activo\n3. Eliminar activo\n4. Modificar activo\n5. Mis activos\n6. Reportes\n7. Ordenar transacciones ascendente\n8. Ordenar transacciones descendentes\n9. Cerrar sesion";
		cout << "\nIngrese opcion: ";
		getline(cin, opcion);
		if (opcion == "1") {
			subMenu1Admin();
		}
		else if (opcion == "2") {
			subMenu2Admin();
		}
		else if (opcion == "3") {

		}
		else if (opcion == "4") {
			subMenu4Admin();
		}
		else if (opcion == "5") {
			subMenu5Admin();
		}
		else if (opcion == "6") {
			subMenu6Admin();
		}
		else if (opcion == "7") {
			subMenu7Admin();
		}
		else if (opcion == "8") {
			transaccion->ordenar2();
			string espacio = "";
			getline(cin, espacio);
		}
		else if (opcion == "9") {
			break;
		}
		else {

		}
	}

}

void Menu::menuUsuario(Usuario* usuario)
{
	string opcion = "";
	while (true)
	{
		system("cls");
		cout << "--------------------Renta de activos-----------------\n";
		cout << "1. Rentar activo\n2. Eliminar activo\n3. Mis activos\n4. Cerrar sesion";
		cout << "\nIngrese opcion: ";
		getline(cin, opcion);
		if (opcion == "1") {
			subMenu1Usuario(usuario);
		}
		else if (opcion == "2") {

		}
		else if (opcion == "3") {
			subMenu3Usuario(usuario);
		}
		else if (opcion == "4") {
			break;
		}
		else {

		}
	}
}

void Menu::subMenu1Usuario(Usuario* usuario)
{
	string espacio = "";
	string id = "";
	string fecha = "";
	string tiempo = "";
	system("cls");
	cout << "-----------------Usuario------------------\n";
	cout << "----------------Catalogo------------------\n";
	admin->head->value->renta->inOrden();

	cout << "Ingrese el codigo correspondiente del activo: ";
	getline(cin, id);
	
	NodeTree* renta = admin->head->value->renta->getNode(admin->head->value->renta->root,id);
	if (renta == nullptr) {
		cout << "No existe el activo" << endl;
	}
	else
	{
		if (renta->value->disponibilidad) {
			usuario->renta->addAVL(renta->value);
			cout << "Ingrese el tiempo de renta: ";
			getline(cin, tiempo);
			cout << "Ingrese la fecha: ";
			getline(cin, fecha);
			cout << "Se acaba de rentar el activo" << endl;
			renta->value->disponibilidad = false;
			transaccion->addFirst(new Transaccion(generarId(), renta->value, usuario, usuario->departamento, usuario->empresa, fecha, tiempo));
		}
		else
		{
			cout << "ACtivo no disponible" << endl;
		}
	}
	getline(cin, espacio);
}

void Menu::subMenu3Usuario(Usuario* usuario)
{
	string espacio = "";
	system("cls");
	cout << "------------------Usuario------------------\n";
	cout << "----------------Mis activos------------------\n";
	usuario->renta->inOrden();
	getline(cin, espacio);
}

void Menu::subMenu1Admin()
{
	string espacio = "";
	Usuario* nuevo = new Usuario("","","","","");
	
	system("cls");
	cout << "-------------------Admin------------------\n";
	cout << "-------------Registrar Usuario------------\n";
	cout << "Ingrese Nickname: ";
	getline(cin, nuevo->nickName);
	cout << "Ingrese Password: ";
	getline(cin, nuevo->password);
	cout << "Ingrese Nombre: ";
	getline(cin, nuevo->nombre);
	cout << "Ingrese Empresa: ";
	getline(cin, nuevo->empresa);
	cout << "Ingrese Departamento: ";
	getline(cin, nuevo->departamento);

	if (nuevo->nickName == "" || nuevo->password == "" || nuevo->nombre == "" || nuevo->empresa == "" || nuevo->departamento == "") {
		cout << "Debe de llenar todos los campos" << endl;
	}
	else
	{
		admin->addUsuario(nuevo, nuevo->departamento, nuevo->empresa);
	}
	getline(cin, espacio);
}

void Menu::subMenu2Admin()
{
	string id = generarId();
	string nombre = "";
	string descripcion = "";
	string espacio = "";
	system("cls");
	cout << "-------------------Admin------------------\n";
	cout << "--------------Registrar Activo------------\n";
	cout << "Ingrese nombre: ";
	getline(cin, nombre);
	cout << "Ingrese descripcion: ";
	getline(cin, descripcion);
	if (nombre != "" && descripcion != "") {
		admin->head->value->renta->addAVL(new Activo(id, nombre, descripcion));
		cout << "Se agrego correctamente" << endl;
	}
	else
	{
		cout << "Debe llenar todos los campos"<<endl;
	}
	getline(cin, espacio);
}

void Menu::subMenu4Admin()
{
	string id = "";
	string descripcion = "";
	string espacio = "";
	system("cls");
	cout << "----------------------Admin---------------------\n";
	cout << "----------------Modificar activos---------------\n";
	admin->head->value->renta->inOrden();
	cout << "Ingrese id del activo: ";
	getline(cin, id);
	NodeTree* activo = admin->head->value->renta->getNode(admin->head->value->renta->root, id);
	if (activo == nullptr) {
		cout << "No se encontro el activo" << endl;
	}
	else
	{
		cout << "Ingrese nueva descripcion: ";
		getline(cin, descripcion);
		activo->value->descripcion = descripcion;
		cout << "Se actualizo exitosamente" << endl;
	}
	getline(cin, espacio);
}

void Menu::subMenu5Admin()
{
	string espacio = "";
	system("cls");
	cout << "-------------------Admin------------------\n";
	cout << "----------------Mis activos---------------\n";
	admin->head->value->renta->inOrden();
	getline(cin, espacio);
}

//Reportes
void Menu::subMenu6Admin()
{
	string opcion = "";
	string usuario = "";
	string empresa = "";
	string departamento = "";
	string espacio = "";
	while (true)
	{
		system("cls");
		cout << "-------------------Admin------------------\n";
		cout << "1. Reporte matriz dispersa\n";
		cout << "2. Reporte activos por empresa\n";
		cout << "3. Reporte activos por departamento\n";
		cout << "4. Reporte transacciones\n";
		cout << "5. Reporte activos por usuario\n";
		cout << "6. Reporte activos rentados por un usuario\n";
		cout << "7. Salir\n";
		cout << "Ingrese opcion: ";
		getline(cin, opcion);
		if (opcion == "1") {
			admin->graficar();
			getline(cin, espacio);
		}
		else if (opcion == "2") {
			cout << "Ingrese empresa: ";
			getline(cin, empresa);
			if (empresa != "") admin->activoPorEmpresa(empresa);
			else cout << "Debe de llenar todos los campos\n";
			getline(cin, espacio);
		}
		else if (opcion == "3") {
			cout << "Ingrese departamento: ";
			getline(cin, departamento);
			if (departamento != "") admin->activoPorDepartamento(departamento);
			else cout << "Debe de llenar todos los campos\n";
			getline(cin, espacio);
		}
		else if (opcion == "4") {
			transaccion->graficar();
			getline(cin, espacio);
		}
		else if (opcion == "5") {
			cout << "Ingrese usuario: ";
			getline(cin, usuario);
			cout << "Ingrese empresa: ";
			getline(cin, empresa);
			cout << "Ingrese departamento: ";
			getline(cin, departamento);
			if (usuario != "") {
				NodoMatriz* usu = admin->searUsuario(usuario, empresa, departamento);
				if (usu != nullptr) {
					usu->value->renta->graficar(usu->value->nickName);
				}
				else
				{
					cout << "No se encontro al usaurio\n";
				}
			}
			else cout << "Debe de llenar todos los campos\n";
			getline(cin, espacio);
		}
		else if (opcion == "6") {
			cout << "Ingrese usuario: ";
			getline(cin, usuario);
			cout << "Ingrese empresa: ";
			getline(cin, empresa);
			cout << "Ingrese departamento: ";
			getline(cin, departamento);
			if (usuario != "") {
				NodoMatriz* usu = admin->searUsuario(usuario, empresa, departamento);
				if (usu != nullptr) {
					transaccion->usuario(usu->value);
				}
				else
				{
					cout << "No se encontro al usuario\n";
				}
				
			} 
			else cout << "No se genero el reporte\n";
			getline(cin, espacio);
		}
		else if (opcion == "7") {
			break;
		}
	}
}

void Menu::subMenu7Admin()
{
	string espacio = "";
	transaccion->ordenar();
	getline(cin, espacio);
}

string Menu::generarId()
{
	string cadena = "";
	srand(time(NULL));
	int numero = 0;
	int eleccion;
	numero = 65 + rand() % (91 - 65);
	cadena += char(numero);
	for (int i = 0; i < 14; i++)
	{
		//cadenas 0-9
		eleccion = 1 + rand() % (4 - 1);
		if (eleccion == 1) {
			numero = 48 + rand() % (58 - 48);
		}
		//cadenas a-z
		else if (eleccion == 2) {
			numero = 65 + rand() % (91 - 65);
		}
		//cadenas A-Z
		else if (eleccion == 3) {
			numero = 97 + rand() % (123 - 97);
		}
		cadena += char(numero);
	}
	
	return cadena;
}
