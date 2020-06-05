#pragma once
#include <string>
using namespace std;

class Usuario
{
private:
	string nickName;
	string password;
	string nombre;
public:
	Usuario(string nickName, string password, string nombre) {
		this->nickName = nickName;
		this->password = password;
		this->nombre = nombre;
	}
};

