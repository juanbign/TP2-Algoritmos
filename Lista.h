/*
 * Lista.h
 *
 *  Created on: 28 abr. 2024
 *      Author: martin
 */

#include "Nodo.h"
#include <iostream>


template <typename TipoVariable>

#ifndef LISTA_H_
#define LISTA_H_


class Lista{

private:
	int cantidadNodos;
	Nodo<TipoVariable> * punteroPrimerNodo;

public:
	Lista(){
		cantidadNodos = 0;
		punteroPrimerNodo = NULL;
	}

	virtual ~Lista(){
		for (unsigned int i=cantidadNodos;i<1;i--){
			delete ObtenerNodo(cantidadNodos);
			cantidadNodos--;
		}
	}

	int ObtenerLargo(){
		//pre una lista con nodos
		//pos:devuelve la cantidad de nodos de la lista
		return cantidadNodos;
	}

	void AgregarNodo(int datoInicial ,int posicion){
		//pre -
		//pos agrega un nodo a la lista

		Nodo<TipoVariable>* nuevoNodo =new Nodo<TipoVariable>(datoInicial);

		if (posicion==1){
			nuevoNodo->cambiarSiguiente(NULL);
			punteroPrimerNodo = nuevoNodo;
		}

		else{

			Nodo<TipoVariable> * nodoAnterior = ObtenerNodo(posicion-1);
			nuevoNodo -> cambiarSiguiente(nodoAnterior->obtenerSiguiente());
			nodoAnterior -> cambiarSiguiente(nuevoNodo);

		}

		cantidadNodos ++;

	}

	void EliminarNodo(int posicion){

		Nodo<TipoVariable> * nodoAEliminar;

		if(posicion==1){
			nodoAEliminar = punteroPrimerNodo;
			punteroPrimerNodo = nodoAEliminar->obtenerSiguiente();

		}
		else{
			Nodo<TipoVariable>* nodoAnterior = ObtenerNodo(posicion-1);
			nodoAEliminar = nodoAnterior->obtenerSiguiente();
			nodoAnterior -> cambiarSiguiente(nodoAEliminar->obtenerSiguiente());

		}
		delete nodoAEliminar;
		cantidadNodos--;
	}

	void ModificarDatoNodo(int dato, int posicion){
		//pre
		//pos modifica el dato de un nodo de la lista
		Nodo<TipoVariable> * punteroNodoBuscado = ObtenerNodo(posicion);
		punteroNodoBuscado -> cambiarDato(dato);
	}

	int MostrarDatoNodo(int posicion){
		//pre
		//pos muestra el dato de un nodo de la lista
		Nodo<TipoVariable>* punteroNodoBuscado = ObtenerNodo(posicion);
		return 	punteroNodoBuscado -> obtenerDato();

	}

	bool vacia(){
		//pre
		//pos devuelve true si la lista esta vacia
		return cantidadNodos == 0;

	}

	void Productos(){
		for (int i=0; i<cantidadNodos;i+=2){
			int factor1 = MostrarDatoNodo(i);
			int factor2 = MostrarDatoNodo(i++);
			int producto = factor1 * factor2;
			AgregarNodo(producto,i++);
		}

	}

	void SepararContiguosDivisibles(){
		if (!vacia()){
			for ( int i=1; i<cantidadNodos;i++){
				int dividendo = MostrarDatoNodo(i++);
				int divisor = MostrarDatoNodo(i);
				if((divisor != 0) && (dividendo % divisor ==0)){
					int divicion = dividendo / divisor;
					AgregarNodo(divicion,i++);
					i++;
				}
			}
		}
	}

private:

	Nodo<TipoVariable> * ObtenerNodo(int posicion){
		//pre -
		//pos devuelve un puntero al nodo en el cual se encuentra
		Nodo<TipoVariable>* punteroNodoBuscado = punteroPrimerNodo;

		for (int i=1; i<posicion; i++){
			punteroNodoBuscado = punteroNodoBuscado -> obtenerSiguiente();
		}

		return punteroNodoBuscado;
	}
};

#endif /* LISTA_H_ */
