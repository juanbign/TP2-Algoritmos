#ifndef BARRIO_H_
#define BARRIO_H_

#include "parada.h"
#include "lista.h"
#include <string>


class Barrio {
private:

    Lista<Parada>* paradas;
    std::string nombre;

public:

    Barrio(int longitud, std::string nombre, Parada dato_inicial);
    virtual ~Barrio();
    Parada& obtenerParada(int posicion);
    int agregarParada(Parada dato);
    int contarParadas();
    bool estaVacio();
    void asignarParada(int posicion, Parada dato);
    void removerParada(int posicion);
    void recorrerParadas();

};

#endif // BARRIO_H_