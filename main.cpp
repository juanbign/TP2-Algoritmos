#include "lista.h"
#include "barrio.h"
#include "lectura.h"
#include "menu.h"

using namespace std;

int main (int argc, char** argv) {

    Lista<Barrio*>* barriosArchivo = leerArchivo("paradas-de-colectivo.csv");
    
    Menu* menu = new Menu(barriosArchivo);

    menu->mostrarMenu();

    delete menu;
    delete barriosArchivo;

    return 0;

}