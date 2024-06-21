#include "lista.h"
#include "parada.h"
#include "barrio.h"
#include "asistente.h"
#include <limits>
#include <cmath>

using namespace std;

static const int MAXIMO_NUM_LINEA_COLECTIVO = 195;

Lista<Parada>* Asistente::obtenerParadasDeColectivo(Lista<Barrio>* barrios, int colectivo) {
		
    Lista<Parada>* paradasPorLinea = new Lista<Parada>;
    barrios->iniciarCursor();

    // Obtengo el primer barrio para no tener que crear una lista de Paradas solo para inicializar
    Barrio barrio = Barrio("");

    while (barrios->avanzarCursor()) {

        barrio = barrios->obtenerCursor();

        for (int j = 1; j < barrio.contarParadas(); j++) {

            // Si el colectivo es igual al pasado por parámetro
            if (barrio.obtenerParada(j).obtenerColectivo() == colectivo) { 

                // Agrego la parada a la lista
                paradasPorLinea->agregar(barrio.obtenerParada(j), paradasPorLinea->getTamanio() + 1);

            }

        }

    }
    
    return paradasPorLinea;

}

Lista<int>* Asistente::obtenerCantidadParadasPorColectivo(Lista<Barrio>* barrios) {

    Lista<int>* colectivos = new Lista<int>;

    // Recorro todos los colectivos desde 1 a MAXIMO_NUM_LINEA_COLECTIVO + 1 (195) 
    for (int i = 1; i < MAXIMO_NUM_LINEA_COLECTIVO + 1; i++) {

        // Agrego el tamaño de la lista de paradas del colectivo
        // Si no se encuentra ninguna parada el valor es 0
        colectivos->agregar(obtenerParadasDeColectivo(barrios, i)->getTamanio(), i);

    }

    return colectivos;

}

/**
* pre: 
* post: Devuelve la parada más cercana a una coordenada  
*/
Parada Asistente::obtenerParadaMasCercana(Lista<Barrio>* barrios, double lat, double lon) {

    // Numero máximo del tipo "double"
    double min_distancia = numeric_limits<double>::max();
    double nueva_distancia;
    Parada min_parada = Parada("placeholder", 1, 0, 0);
    Parada nueva_parada = Parada("placeholder", 1, 0, 0);
    
    barrios->iniciarCursor();

    Barrio barrio = Barrio("");

    while (barrios->avanzarCursor()) {

        barrio = barrios->obtenerCursor();

        for (int j = 1; j < barrio.contarParadas() + 1; j++) {

            nueva_parada = barrio.obtenerParada(j);
            
            // Obtengo la distancia con pitágoras 
            nueva_distancia = sqrt(pow(nueva_parada.obtenerLatitud() - lat, 2) + pow(nueva_parada.obtenerLongitud() - lon, 2));
            
            // Si la nueva distancia es menor a la mínima
            if (nueva_distancia < min_distancia) {

                // Igualo al nuevo mínimo
                min_distancia = nueva_distancia;
                min_parada = nueva_parada;

            }

        }

    }

    return min_parada;
    
}

Lista<Parada>* Asistente::obtenerParadasOrdenadasPorDistancia(Barrio barrio, int colectivo, double lat, double lon) {

    Lista<Parada>* listaParadas = new Lista<Parada>;
    Parada parada = Parada("", 1, 0, 0);

    for (int i = 1; i < barrio.contarParadas() + 1; i++) {

        parada = barrio.obtenerParada(i);
        
        // Si el colectivo es igual al pasado por parámetro
        if (parada.obtenerColectivo() == colectivo) { 
        
            listaParadas->agregar(parada, listaParadas->getTamanio() + 1);
        
        }

    }

    // Creo un array para guardar las distancias de la parada
    double* distancias = new double[listaParadas->getTamanio()];

    listaParadas->iniciarCursor();
    
    for (int i = 0; i < listaParadas->getTamanio(); i++) {
        
        listaParadas->avanzarCursor();

        parada = listaParadas->obtenerCursor();

        // Calculo la distancia con pitágoras
        distancias[i] = sqrt(pow(parada.obtenerLatitud() - lat, 2) + pow(parada.obtenerLongitud() - lon, 2));

    }

    bool desordenado = false;

    // Ordeno usando ordenamiento burbuja
    for (int i = 0; i < listaParadas->getTamanio() - 1; i++) {
        
        desordenado = false;

        for (int j = 0; j < listaParadas->getTamanio() - i - 1; j++) {
            
            // Si las dos posiciones están desordenadas
            if (distancias[j] > distancias[j + 1]) {

                // Uso la función swap para intercambiar las posiciones del array
                swap(distancias[j], distancias[j + 1]);
                
                // Uso un variable temporal para intercambiar las paradas
                parada = listaParadas->obtener(j + 1);
                listaParadas->cambiar(listaParadas->obtener(j + 2), j + 1);
                listaParadas->cambiar(parada, j + 2);
                
                desordenado = true;
            
            }

        }

        // Si no se ordenó ninguna posición de la lista
        if (!desordenado) {
            
            //Salgo del bucle
            break;
        
        }

    }

    delete[] distancias;

    return listaParadas;

}