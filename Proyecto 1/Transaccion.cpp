#include "Transaccion.h"

string Transaccion::toString()
{
    return "\"ID: " + id + "\"+" + "\"\\nActivo: " + activo->id + "\"+" + "\"\\nUsuario: " + usuario->nickName + "\"+" + "\"\\nDepartamento: " + usuario->departamento + "\"+"
        + "\"\\nEmpresa: " + usuario->empresa + "\"+" + "\"\\nFecha: " + fecha + "\"+" + "\"\\nTiempo: " + tiempo + "\"";
}
