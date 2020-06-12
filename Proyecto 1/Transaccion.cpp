#include "Transaccion.h"

string Transaccion::toString()
{
    return "ID: "+id+"\nID Activo: "+activo->id+"\nUsuario: "+usuario->nickName+"\nFecha: "+fecha+"\nTiempo: "+tiempo;
}
