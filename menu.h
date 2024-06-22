#include "lista.h"
#include "barrio.h"
#include "asistente.h"
#include "parada.h"

class Menu {

    private:

        Asistente* asistente;
        Lista<Barrio*>* barriosArchivo;
        Parada* parada;
        Barrio* barrio;
        Lista<Parada*>* paradas;
        Lista<Barrio*>* barrios;
        Lista<int>* cantidadParadas;
        Lista<std::string>* nombreBarrios;

    public:

        Menu(Lista<Barrio*>* barriosArchivo);

        virtual ~Menu();

        void mostrarMenu();

};