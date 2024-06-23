#ifndef MENU_H_
#define MENU_H_

#include "lista.h"
#include "barrio.h"
#include "parada.h"

class Menu {

    private:
        
        /**
        * pre: 
        * post: Devuelve un barrio sin paradas y el nombre especificado
        */
        Lista<Barrio*>* barrios;
        Lista<std::string>* nombreBarrios;

    public:

        /**
        * pre:
        * post: Crea una lista de los nombres de los barrios
        */
        Menu(Lista<Barrio*>* barrios);

        virtual ~Menu();
        
        /**
        * pre: 
        * post: Muestra el menú y pide una entrada. Termina su ejecución cuando el usuario indica que quiere salir.
        */
        void mostrarMenu();

};

#endif /* MENU_H_ */