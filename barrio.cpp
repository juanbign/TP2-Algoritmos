#include "lista.h"
#include "barrio.h"
#include "parada.h"

#include <iostream>

using namespace std;

Barrio::Barrio(int longitud, string nombre, Parada dato_inicial) {

    if (longitud < 1) {

        throw invalid_argument("La longitud debe ser mayor o igual a 1");

    } else {

        this->nombre = nombre;
        this->paradas = new Lista<Parada>(longitud, dato_inicial);

    }

}

Barrio::~Barrio() {

    delete this->paradas;

}

Parada& Barrio::obtenerParada(int posicion) {

    return this->paradas->obtener(posicion);

}

int Barrio::agregarParada(Parada dato) {

    return this->paradas->agregar(dato);

}

int Barrio::contarParadas() {

    return this->paradas->contarElementos();

}

bool Barrio::estaVacio() {

    return this->paradas->estaVacio();

}

void Barrio::asignarParada(int posicion, Parada dato) {

    this->paradas->asignar(posicion, dato);

}

void Barrio::removerParada(int posicion) {

    this->paradas->remover(posicion);

}

void Barrio::recorrerParadas() {

    this->paradas->recorrer();

}