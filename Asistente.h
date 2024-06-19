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

	void obtenerParadasPorLinea(int lineaColectivo, Barrio* barrio,Lista<Parada*>* paradasPorLinea){

		Lista<Parada*>* paradas = barrio->obtenerParadas();

		paradas ->iniciarCursor();
		while(paradas->avanzarCursor()){
			Parada* parada = paradas->obtenerCursor();
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
	Lista<Parada*>* obtenerParadasPorLinea(int lineaColectivo,Lista<Barrio*>* barrios){
		Lista<Parada*>* paradasPorLinea = new Lista<Parada*>();
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

	int cantidadParadasPorLinea(int lineaColectivo,Lista<Barrio*>* barrios){
		Lista<Parada*>* paradasPorLinea =  obtenerParadasPorLinea(lineaColectivo,barrios);
		return paradasPorLinea->obtenerCantidad();
	}
};
/*******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/


#endif /* ASISTENTE_H_ */
