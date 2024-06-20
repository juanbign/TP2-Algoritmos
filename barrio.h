#ifndef BARRIO_H_
#define BARRIO_H_

#include "parada.h"
#include "Lista.h"
#include <string>

template <typename Parada>
class Barrio {
    
    private:

        Lista<Parada>* paradas;
        std::string nombre;

    public:

        Barrio(int largo, std::string nombre, Parada dato_inicial) {

            if (largo < 1) {

                //throw invalid_argument("El largo debe ser mayor o igual a 1");

            } else {

                this->nombre = nombre;
                this->paradas = new Lista<Parada>;

            }        

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

            return this->paradas->vacia();

        }

        void asignarParada(int posicion, Parada dato) {

            this->paradas->cambiar(posicion, dato);

        }
        
        void removerParada(int posicion) {

            this->paradas->remover(posicion);

        }

};

#endif // BARRIO_H_
