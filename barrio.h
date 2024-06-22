#ifndef BARRIO_H_
#define BARRIO_H_

#include "parada.h"
#include "lista.h"
#include <string>

class Barrio {
    
    private:

        Lista<Parada*>* paradas;
        std::string nombre;

    public:

        Barrio(std::string nombre);

        Barrio();

        virtual ~Barrio();

        std::string obtenerNombre();

        void cambiarNombre(std::string nombre);

        Parada* obtenerParada(int posicion);

        void agregarParada(Parada* dato);

        int contarParadas();

        bool estaVacio();

        void asignarParada(Parada* dato, int posicion);
        
        void removerParada(int posicion);

};

#endif // BARRIO_H_