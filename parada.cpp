#include "parada.h"

#include <string>
#include <stdexcept>

using namespace std;

Parada::Parada(string direccion, int colectivo, double lat, double lon) {

    if (colectivo < 1) {

        throw invalid_argument("El numero del colectivo debe ser mayor o igual a 1");

    } else {

        this->direccion = direccion;
        this->colectivo = colectivo;
        this->lat = lat;
        this->lon = lon;

    }

}

string Parada::obtenerDireccion() {

    return this->direccion;

}

int Parada::obtenerColectivo() {

    return this->colectivo;
    
}

double Parada::obtenerLatitud() {

    return this->lat;
    
}

double Parada::obtenerLongitud() {

    return this->lon;
    
}

void Parada::cambiarDireccion(string direccion) {

    this->direccion = direccion;
    
}

void Parada::cambiarColectivo(int colectivo) {

    this->colectivo = colectivo;
    
}
