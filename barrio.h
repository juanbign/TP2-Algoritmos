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

        Barrio(std::string nombre) {

            this->nombre = nombre;
            this->paradas = new Lista<Parada>;   

        }

        Barrio() {

            this->nombre = "";
            this->paradas = new Lista<Parada>;
        }

        virtual ~Barrio() {

            delete this->paradas;

        }

        std::string obtenerNombre() {

            return this->nombre;

        }

        Parada obtenerParada(int posicion) {

            return this->paradas->obtener(posicion);

        }

        void agregarParada(Parada dato) {

            this->paradas->agregar(dato, this->paradas->getTamanio() + 1);

        }

        int contarParadas() {

            return this->paradas->getTamanio();

        }

        bool estaVacio() {

            return this->paradas->estaVacia();

        }

        void asignarParada(Parada dato, int posicion) {

            this->paradas->cambiar(dato, posicion);

        }
        
        void removerParada(int posicion) {

            this->paradas->remover(posicion);

        }

};

#endif // BARRIO_H_