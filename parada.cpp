#include "parada.h"

#include <string>
#include <stdexcept>



Parada::Parada(std::string direccion, int colectivo, long double lat, long double lon) {

    if (colectivo < 1) {

        throw std::invalid_argument("El numero del colectivo debe ser mayor o igual a 1");

    } else {

        this->direccion = direccion;
        this->colectivo = colectivo;
        this->lat = lat;
        this->lon = lon;

    }

}

Parada::Parada() {

    this->direccion = "";
    this->colectivo = 1;
    this->lat = 0;
    this->lon = 0;

}

std::string Parada::obtenerDireccion() {

    return this->direccion;

}

int Parada::obtenerColectivo() {

    return this->colectivo;
    
}

long double Parada::obtenerLatitud() {

    return this->lat;
    
}

long double Parada::obtenerLongitud() {

    return this->lon;
    
}

void Parada::cambiarDireccion(std::string direccion) {

    this->direccion = direccion;
    
}

void Parada::cambiarColectivo(int colectivo) {

    this->colectivo = colectivo;
    
}

void Parada::cambarLatitud(long double lat) {

    this->lat = lat;

}

void Parada::cambiarLongitud(long double lon) {

    this->lon = lon;

}