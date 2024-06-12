/*
 * Nodo.h
 *
 *  Created on: 28 abr. 2024
 *      Author: martin
 */

#include <iostream>
#ifndef NODO_H_
#define NODO_H_

template <typename TipoVariable>

class Nodo{

	private:
		TipoVariable dato;
		Nodo * siguienteNodo;

	public:

		Nodo(TipoVariable datoInicial) {
			//Pre:
			//Pos: crea un nodo con un dato inical y con siguiente Nodo apuntando a NULL
			dato=datoInicial;
			siguienteNodo =NULL;
		}

		void cambiarDato(TipoVariable nuevoDato){
			//Pre: -
			//Pos: cambia el dato del nodo
			dato = nuevoDato;
		}

		void cambiarSiguiente(Nodo* nuevoSiguiente){
		//Pre: -
		//Pos: cambia la direccion del puntero siguienteNodo

			siguienteNodo = nuevoSiguiente;
		}

		TipoVariable obtenerDato(){
			//Pre: -
			//Pos: devuelve el dato que se halla dentro del nodo
			return dato;
		}

		Nodo* obtenerSiguiente(){
			//Pre: _
			//Pos: devuelve el valor de siguenteNodo
			return siguienteNodo;
		}

		~Nodo() {
			// TODO Auto-generated destructor stub

		}

};

#endif /* NODO_H_ */
