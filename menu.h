#include "lista.h"
#include "barrio.h"
#include "asistente.h"
#include "parada.h"

class Menu {

    private:

        Lista<Barrio*>* barriosArchivo;
        Asistente* asistente;
        Lista<std::string>* nombreBarrios;

    public:

        /**
        * pre: Guardar todos los barrios del archivo en el parámetro
        * post: Crea una lista de los nombres de los barrios
        */
        Menu(Lista<Barrio*>* barriosArchivo);

        virtual ~Menu();
        /**
        * pre: 
        * post: Muestra el menú y pide una entrada. Termina su ejecución cuando el usuario indica que quiere salir.
        */
        void mostrarMenu();

};