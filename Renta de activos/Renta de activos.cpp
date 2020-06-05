#include <iostream>
#include <stdio.h>
#include "ListaDobleCircular.h"

using namespace std;

int main()
{
    ListaDobleCircular<string> lista = ListaDobleCircular<string>();
    lista.addFinal("Gerber");
    lista.remove("asda");
    lista.show();
   
    
    return 0;
}


