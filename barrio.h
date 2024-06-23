#ifndef BARRIO_H_
#define BARRIO_H_

#include "parada.h"
#include "lista.h"
#include <string>

// Barrio con nombre y una lista de las paradas ubicadas en él
class Barrio {
    
    private:

        Lista<Parada*>* paradas;
        std::string nombre;

    public:
        
        /**
        * pre: 
        * post: Devuelve un barrio sin paradas y el nombre especificado
        */
        Barrio(std::string nombre);
        
        /**
        * pre: 
        * post: Devuelve un barrio sin paradas y nombre vacío
        */
        Barrio();

        
        virtual ~Barrio();

        /**
        * pre: 
        * post: Devuelve el nombre del barrio
        */
        std::string obtenerNombre();

        /**
        * pre: 
        * post: Cambia el nombre del barrio
        */
        void cambiarNombre(std::string nombre);

        /**
        * pre: 
        * post: Devuelve la parada en la posición indicada de la lista de paradas del barrio
        */
        Parada* obtenerParada(int posicion);

        /**
        * pre: 
        * post: Agrega una parada a la lista de paradas del barrio
        */
        void agregarParada(Parada* parada);
        
        /**
        * pre: 
        * post: Devuelve la cantidad de paradas en la lista de paradas del barrio
        */
        int contarParadas();

        /**
        * pre: 
        * post: Devuelve true si no hay paradas en la lista de paradas del barrio 
        */
        bool estaVacio();

        /**
        * pre: 
        * post: Cambia la parada en la posición indicada de la lista de paradas del barrio
        */
        void asignarParada(Parada* parada, int posicion);
        
        /**
        * pre: 
        * post: Remueve la parada en la posición indicada de la lista de paradas del barrio
        */
        void removerParada(int posicion);

};

#endif /* BARRIO_H_ */