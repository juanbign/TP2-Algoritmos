#include "lista.h"
#include "parada.h"
#include "barrio.h"
#include "asistente.h"
#include <limits>
#include <cmath>

using namespace std;

int Asistente::obtenerMaximoNumeroColectivo() {

    return this->MAXIMO_NUM_LINEA_COLECTIVO;

}

Lista<Parada>* Asistente::obtenerParadasDeColectivo(Lista<Barrio<Parada> >* barrios, int colectivo) {
		
    Lista<Parada>* paradasPorLinea = new Lista<Parada>;
    Barrio<Parada> barrio = barrios->obtener(1);
    
    for (int i = 1; i < barrios->getTamanio() + 1; i++) {

        barrio = barrios->obtener(i);

        for (int j = 1; j < barrio.contarParadas(); j++) {

            if (barrio.obtenerParada(j).obtenerColectivo() == colectivo) {

                paradasPorLinea->agregar(barrio.obtenerParada(j), paradasPorLinea->getTamanio() + 1);

            }

        }

    }
    
    return paradasPorLinea;

}

Lista<int>* Asistente::obtenerCantidadParadasPorColectivo(Lista<Barrio<Parada> >* barrios) {

    Lista<int>* colectivos = new Lista<int>;

    for (int i = 1; i < MAXIMO_NUM_LINEA_COLECTIVO + 1; i++) {

        colectivos->agregar(obtenerParadasDeColectivo(barrios, i)->getTamanio(), i);

    }

    return colectivos;

}

/**
* pre: 
* post: Devuelve la parada más cercana a una coordenada  
*/
Parada Asistente::obtenerParadaMasCercana(Lista<Barrio<Parada> >* barrios, double lat, double lon) {

    double distancia = numeric_limits<double>::max();
    double nueva_distancia;
    Parada parada = Parada("placeholder", 1, 0, 0);
    Parada nueva_parada = Parada("placeholder", 1, 0, 0);
    Barrio<Parada> barrio = barrios->obtener(1);

    for (int i = 1; i < barrios->getTamanio() + 1; i++) {

        barrio = barrios->obtener(i);

        for (int j = 1; j < barrios->obtener(i).contarParadas() + 1; j++) {

            nueva_parada = barrio.obtenerParada(j);
            nueva_distancia = sqrt(pow(parada.obtenerLatitud() - lat, 2) + pow(parada.obtenerLongitud() - lon, 2));
            
            if (nueva_distancia < distancia) {

                distancia = nueva_distancia;
                parada = nueva_parada;

            }

        }

    }

    return parada;

}

Lista<Parada>* Asistente::obtenerParadasOrdenadasPorDistancia(Barrio<Parada> barrio, int colectivo, double lat, double lon) {

    Lista<Parada>* listaParadas = new Lista<Parada>;
    Parada parada = Parada("placeholder", 1, 0, 0);

    for (int i = 1; i < barrio.contarParadas() + 1; i++) {

        parada = barrio.obtenerParada(i);
        
        if (parada.obtenerColectivo() == colectivo) { 
        
            listaParadas->agregar(parada, listaParadas->getTamanio() + 1);
        
        }

    }

    double* distancias = new double[listaParadas->getTamanio()];
    
    for (int i = 1; i < listaParadas->getTamanio() + 1; i++) {
        
        parada = listaParadas->obtener(i);
        distancias[i] = sqrt(pow(parada.obtenerLatitud() - lat, 2) + pow(parada.obtenerLongitud() - lon, 2));

    }

    bool desordenado = false; 

    for (int i = 0; i < listaParadas->getTamanio() - 1; i++) {
        
        desordenado = false;

        for (int j = 0; j < listaParadas->getTamanio() - i - 1; j++) {
            
            if (distancias[j] > distancias[j + 1]) {

                swap(distancias[j], distancias[j + 1]);
                
                parada = listaParadas->obtener(j + 1);
                listaParadas->cambiar(listaParadas->obtener(j + 2), j);
                listaParadas->cambiar(parada, j + 2);
                
                desordenado = true;
            
            }

        }

        if (!desordenado) {
        
            break;
        
        }

    }

    return listaParadas;

}