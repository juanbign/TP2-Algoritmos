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

        Menu(Lista<Barrio*>* barriosArchivo);

        virtual ~Menu();

        void mostrarMenu();

};