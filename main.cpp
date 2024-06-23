#include "lista.h"
#include "barrio.h"
#include "lectura.h"
#include "menu.h"

using namespace std;

int main (int argc, char** argv) {

    // Leo el archivo y guardo los barrios resultantes
    Lista<Barrio*>* barriosArchivo = leerArchivo("paradas-de-colectivo.csv");
    
    // Instancio el menú con los barrios del archivo
    Menu* menu = new Menu(barriosArchivo);

    // Muestro el menú
    menu->mostrarMenu();

    // Borro tanto el menú y los barrios guardados ya que no los necesito más
    delete menu;
    delete barriosArchivo;

    return 0;

}