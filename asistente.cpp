#include "lista.h"
#include "parada.h"
#include "barrio.h"
#include "asistente.h"
#include <limits>
#include <cmath>

static const int MAXIMO_NUM_LINEA_COLECTIVO = 195;

const int obtenerMaximoNumLineaColectivo() {

    return MAXIMO_NUM_LINEA_COLECTIVO;

} 

Lista<int>* obtenerCantidadParadasPorBarrio(Lista<Barrio*>* barrios) {

    Lista<int>* cantidadParadasPorBarrio = new Lista<int>;

    barrios->iniciarCursor();

    while (barrios->avanzarCursor()) {

        // Agrego el conteo de paradas a la lista
        cantidadParadasPorBarrio->agregar(barrios->obtenerCursor()->contarParadas());

    }


    return cantidadParadasPorBarrio;

}

Lista<Parada*>* obtenerParadasDeColectivo(Lista<Barrio*>* barrios, int colectivo) {
		
    Lista<Parada*>* paradasPorLinea = new Lista<Parada*>;
    barrios->iniciarCursor();

    Barrio* barrio;

    while (barrios->avanzarCursor()) {

        barrio = barrios->obtenerCursor();

        // Voy por cada índice de parada
        for (int j = 1; j < barrio->contarParadas() + 1; j++) {

            // Si el colectivo es igual al pasado por parámetro
            if (barrio->obtenerParada(j)->obtenerColectivo() == colectivo) { 

                // Agrego la parada a la lista
                paradasPorLinea->agregar(barrio->obtenerParada(j));

            }

        }

    }

    return paradasPorLinea;

}

Lista<int>* obtenerCantidadParadasPorColectivo(Lista<Barrio*>* barrios) {

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
Parada* obtenerParadaMasCercana(Lista<Barrio*>* barrios, long double lat, long double lon) {

    // Numero máximo del tipo "long double"
    long double minDistancia = std::numeric_limits<long double>::max();
    long double nuevaDistancia;
    Parada* minParada;
    Parada* nuevaParada;

    bool paradaEncontrada = false;
    
    barrios->iniciarCursor();

    Barrio* barrio;

    while (barrios->avanzarCursor()) {

        barrio = barrios->obtenerCursor();

        // Voy por cada índice de parada
        for (int j = 1; j < barrio->contarParadas() + 1; j++) {

            nuevaParada = barrio->obtenerParada(j);
            
            // Obtengo la distancia con pitágoras 
            nuevaDistancia = sqrt(pow(nuevaParada->obtenerLatitud() - lat, 2) + pow(nuevaParada->obtenerLongitud() - lon, 2));
            
            // Si la nueva distancia es menor a la mínima
            if (nuevaDistancia < minDistancia) {

                // Igualo al nuevo mínimo
                minDistancia = nuevaDistancia;
                minParada = nuevaParada;
                paradaEncontrada = true;

            }

        }

    }

    // Si no se encuentra ni una parada, creo una de error
    if (!paradaEncontrada) {

        minParada = new Parada("NULL", 1, 0, 0);

    }

    return minParada;
    
}

Lista<Parada*>* obtenerParadasOrdenadasPorDistancia(Barrio* barrio, int colectivo, long double lat, long double lon) {

    Lista<Parada*>* listaParadas = new Lista<Parada*>;
    Parada* parada;

    // Voy por cada índice de parada
    for (int i = 1; i < barrio->contarParadas() + 1; i++) {

        parada = barrio->obtenerParada(i);
        
        // Si el colectivo es igual al pasado por parámetro
        if (parada->obtenerColectivo() == colectivo) { 
        
            listaParadas->agregar(parada);
        
        }

    }

    // Creo un array para guardar las distancias de la parada
    long double* distancias = new long double[listaParadas->getTamanio()];

    listaParadas->iniciarCursor();
    
    // Recorro la lista con las paradas obtenidas usando un índice
    for (int i = 0; listaParadas->avanzarCursor(); i++) {
        
        listaParadas->avanzarCursor();

        parada = listaParadas->obtenerCursor();

        // Calculo la distancia con pitágoras
        distancias[i] = sqrt(pow(parada->obtenerLatitud() - lat, 2) + pow(parada->obtenerLongitud() - lon, 2));

    }

    bool desordenado = false;

    // Ordeno usando ordenamiento burbuja
    for (int i = 0; i < listaParadas->getTamanio() - 1; i++) {
        
        desordenado = false;

        for (int j = 0; j < listaParadas->getTamanio() - i - 1; j++) {
            
            // Si las dos posiciones están desordenadas
            if (distancias[j] > distancias[j + 1]) {

                // Uso la función swap para intercambiar las posiciones del array
                std::swap(distancias[j], distancias[j + 1]);
                
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