#include "lista.h"
#include "parada.h"
#include "barrio.h"
#include "asistente.h"

using namespace std;

int main (int argc, char** argv) {

    Asistente asistente = Asistente();

    Lista<Parada>* paradas = new Lista<Parada>;
    Parada parada = Parada("Diaz Colodrero 3195", 71, -34.56713986016535, -58.49069929103298);
    paradas->agregar(parada, paradas->getTamanio() + 1);
    parada = Parada("Diaz Colodrero 3495", 71, -34.56382815931894, -58.49316661007587);
    paradas->agregar(parada, paradas->getTamanio() + 1);
    Barrio<Parada> barrio = Barrio<Parada>(2, "Villa Urquiza", parada);
    barrio.agregarParada(paradas->obtener(1));
    barrio.agregarParada(paradas->obtener(2));
    paradas = asistente.obtenerParadasOrdenadasPorDistancia(barrio, 71, -34, -58);

    cout << paradas->obtener(1).obtenerDireccion() << endl;
    cout << paradas->obtener(2).obtenerDireccion();

}
