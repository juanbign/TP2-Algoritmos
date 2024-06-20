#include "lista.h"
#include "parada.h"
#include "barrio.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

#ifndef ASISTENTE_H_
#define ASISTENTE_H_

class Asistente{


    public:

/******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/

	/**
	 * pre:
	 * post: Devuelve una lista de todas las paradas de una linea de colectivo en un barrio 
	 */

	Lista<Parada>* obtenerParadasPorColectivoYBarrio(Lista<Barrio<Parada> >* barrios, int colectivo, std::string nombreBarrio){

		Lista<Parada>* paradasPorLinea = new Lista<Parada>;
        Barrio<Parada> barrio = barrios->obtener(1);
		
        for (int i = 1; i < barrios->getTamanio() + 1; i++) {

            barrio = barrios->obtener(i);

            if (barrio.obtenerNombre() != nombreBarrio) {

                continue;

            }

            for (int j = 1; j < barrio.contarParadas(); j++) {

                if (barrio.obtenerParada(j).obtenerColectivo() == colectivo) {

                    paradasPorLinea->agregar(barrio.obtenerParada(j), paradasPorLinea->getTamanio() + 1);

                }

            }

            break;

        }
		
		return paradasPorLinea;

	}
   /**
    * pre: 
    * post: Devuelve una lista de todas las paradas de una linea de colectivo en todos los barrios 
    */
	Lista<Parada>* obtenerParadasPorColectivo(Lista<Barrio<Parada> >* barrios, int colectivo) {
		
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

	/**
	 * pre
	 * post: devuelve la cantidad de paradas de una determinada linea de colectivos de todos los barrios
	 * de la ciudad
	 */

	int cantidadParadasPorLinea(Lista<Barrio<Parada> >* barrios, int colectivo) {

		Lista<Parada>* paradasPorLinea = obtenerParadasPorColectivo(barrios, colectivo);

		return paradasPorLinea->getTamanio();
	
    }

    Parada paradaMasCercana(Lista<Barrio<Parada> >* barrios, double lat, double lon) {

        double distancia = std::numeric_limits<double>::max();
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

    void mostrarParadasOrdenadasPorDistancia(Barrio<Parada> barrio, int colectivo, double lat, double lon) {

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

        bool desordenado; 

        for (int i = 0; i < listaParadas->getTamanio() - 1; i++) {
            
            desordenado = false;

            for (int j = 0; j < listaParadas->getTamanio() - i - 1; j++) {
                
                if (distancias[j] > distancias[j + 1]) {

                    std::swap(distancias[j], distancias[j + 1]);
                    
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

        std::cout << listaParadas->obtener(1).obtenerDireccion(); 

        for (int i = 2; i < listaParadas->getTamanio() + 1; i++) {

            std::cout << "; " << listaParadas->obtener(i).obtenerDireccion();

        }

    }

};
/*******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/


#endif /* ASISTENTE_H_ */
