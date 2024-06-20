/*
 * Asistente.h
 *
 *  Created on: 19 jun. 2024
 *      Author: martin
 */
#include "Lista.h"
#include "parada.h"
#include "barrio.h"

#ifndef ASISTENTE_H_
#define ASISTENTE_H_

class Asistente{


/******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/

	/**
	 * pre:
	 * post: Agrega las paradas de un determinado barrio y linea de colectivo a la lista de paradas
	 * de una deteminada linea de colectivo de todos los barrios de la ciudad
	 */

	void obtenerParadasPorLinea(int lineaColectivo, Barrio barrio, Lista<Parada>* paradasPorLinea){

		Lista<Parada>* paradas = barrio.obtenerParadas();

		paradas ->iniciarCursor();
		while(paradas->avanzarCursor()){
			Parada parada = paradas.obtenerCursor();
			if (parada->obtenerLineaColetivo() == lineaColectivo){
				paradasPorLinea->agregarNodoFinal(parada);

			}
		}

	}
   /**
    * pre: Cada parada de colectivo tiene asociada una sola linea de colectivos
    * post: Devuelve una lista de paradas, con todas las paradas de una deteminada linea de colectivo
    * de todos los barrios de la ciudad
    */
	Lista<Parada>* obtenerParadasPorLinea(int lineaColectivo,Lista<Barrio>* barrios){
		
		Lista<Parada>* paradasPorLinea = new Lista<Parada*>;
		barrios -> iniciarCursor();
		
		while(barrios->avanzarCursor()){
			
			Barrio* barrio = barrios->obtenerCursor();
			paradaPorLinea(lineaColectivo,barrio,paradasPorLinea);

			return paradasPorLinea;

		}

	}
	/**
	 * pre
	 * post: devuele la cantidad de paradas de una determinada linea de colectivos de todos los barrios
	 * de la ciudad
	 */

	int cantidadParadasPorLinea(int lineaColectivo,Lista<Barrio>* barrios){
		Lista<Parada>* paradasPorLinea = obtenerParadasPorLinea(lineaColectivo,barrios);
		return paradasPorLinea->obtenerCantidad();
	}

    Parada paradaMasCercana(Lista<Barrio<Parada> > barrios, double lat, double lon) {

        double distancia = numeric_limits<double>::max();
        double nueva_distancia;
        Parada parada = Parada("placeholder", 1, 0, 0);
        Parada nueva_parada = Parada("placeholder", 1, 0, 0);

        for (int i = 1; i < barrios.ObtenerLargo() + 1; i++) {

            for (int j = 1; j < barrios.MostrarDatoNodo(i).contarParadas() + 1; j++) {

                nueva_parada = barrios.MostrarDatoNodo(i).obtenerParada(j);
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
            
                listaParadas->AgregarNodo(parada, listaParadas->ObtenerLargo() + 1);
            
            }

        }

        double* distancias = new double[listaParadas->ObtenerLargo()];
        
        for (int i = 1; i < listaParadas->ObtenerLargo() + 1; i++) {
            
            parada = listaParadas->MostrarDatoNodo(i);
            distancias[i] = sqrt(pow(parada.obtenerLatitud() - lat, 2) + pow(parada.obtenerLongitud() - lon, 2));

        }

        bool desordenado; 

        for (int i = 0; i < listaParadas->ObtenerLargo() - 1; i++) {
            
            desordenado = false;

            for (int j = 0; j < listaParadas->ObtenerLargo() - i - 1; j++) {
                
                if (distancias[j] > distancias[j + 1]) {

                    swap(distancias[j], distancias[j + 1]);
                    
                    parada = listaParadas->MostrarDatoNodo(j + 1);
                    listaParadas->ModificarDatoNodo(listaParadas->MostrarDatoNodo(j + 2), j);
                    listaParadas->ModificarDatoNodo(parada, j + 2);
                    
                    desordenado = true;
                
                }

            }

            if (!desordenado) {
            
                break;
            
            }

        }

        cout << listaParadas->MostrarDatoNodo(1).obtenerDireccion(); 

        for (int i = 2; i < listaParadas->ObtenerLargo() + 1; i++) {

            cout << "; " << listaParadas->MostrarDatoNodo(i).obtenerDireccion();

        }

    }
};
/*******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/


#endif /* ASISTENTE_H_ */
