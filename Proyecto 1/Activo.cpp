#include "Activo.h"

string Activo::toString()
{
    string enable = "Disponible";
    if (!disponibilidad) {
        enable = "No disponible";
    }
    return "ID: "+id+", Nombre: "+nombre+", Descripcion: "+descripcion+", Estado: "+enable;
}

string Activo::graficar()
{
    string enable = "Disponible";
    if (!disponibilidad) {
        enable = "No disponible";
    }
    return "\"ID: " + id + "\"+" + "\"\\nNombre: " + nombre + "\"+" + "\"\\nDescripcion: " + descripcion + "\"+" + "\"\\nDiponibildad: " + enable + "\"";
}
