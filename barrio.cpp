#include "parada.h"
#include "lista.h"
#include "barrio.h"
#include <string>

Barrio::Barrio(std::string nombre) {

    this->nombre = nombre;
    this->paradas = new Lista<Parada*>;   

}

Barrio::Barrio() {

    this->nombre = "";
    this->paradas = new Lista<Parada*>;

}

Barrio::~Barrio() {

    delete this->paradas;

}

std::string Barrio::obtenerNombre() {

    return this->nombre;

}

void Barrio::cambiarNombre(std::string nombre) {

    this->nombre = nombre;

}

Parada* Barrio::obtenerParada(int posicion) {

    return this->paradas->obtener(posicion);

}

void Barrio::agregarParada(Parada* dato) {

    this->paradas->agregar(dato);

}

int Barrio::contarParadas() {

    return this->paradas->getTamanio();

}

bool Barrio::estaVacio() {

    return this->paradas->estaVacia();

}

void Barrio::asignarParada(Parada* dato, int posicion) {

    this->paradas->cambiar(dato, posicion);

}

void Barrio::removerParada(int posicion) {

    this->paradas->remover(posicion);

}