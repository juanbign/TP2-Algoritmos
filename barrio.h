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

        Barrio(int longitud, std::string nombre, Parada dato_inicial) {

            if (longitud < 1) {

                //throw invalid_argument("La longitud debe ser mayor o igual a 1");

            } else {

                this->nombre = nombre;
                this->paradas = new Lista<Parada>(longitud, dato_inicial);

            }        

        }

        virtual ~Barrio() {

            delete this->paradas;

        }

        Parada& obtenerParada(int posicion) {

            return this->paradas->obtener(posicion);

        }

        int agregarParada(Parada dato) {

            return this->paradas->agregar(dato);

        }
        int contarParadas() {

            return this->paradas->contarElementos();

        }
        bool estaVacio() {

            return this->paradas->estaVacio();

        }

        void asignarParada(int posicion, Parada dato) {

            this->paradas->asignar(posicion, dato);

        }
        
        void removerParada(int posicion) {

            this->paradas->remover(posicion);

        }

        void recorrerParadas() {

            this->paradas->recorrer();

        }

};

#endif // BARRIO_H_