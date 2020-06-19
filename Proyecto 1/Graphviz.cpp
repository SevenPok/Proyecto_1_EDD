#include "Graphviz.h"
using namespace std;

void Graphviz::graficar(string cadena, string nombre)
{
	string cmd = "dot.exe -Tpng " + nombre + ".dot -o " + nombre + ".png";
}
