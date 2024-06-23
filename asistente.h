#ifndef ASISTENTE_H_
#define ASISTENTE_H_

#include "lista.h"
#include "parada.h"
#include "barrio.h"

// Funciones de utilidad para la consulta a la base de datos

/**
* pre: 
* post: Devuelve el número maxímo de líneas de colectivo posibles (195 por defecto)
*/
const int obtenerMaximoNumLineaColectivo();

/**
* pre: 
* post: Devuelve una lista de la cantidad de paradas de colectivo en todos los barrios
*/
Lista<int>* obtenerCantidadParadasPorBarrio(Lista<Barrio*>* barrios);

/**
* pre: 
* post: Devuelve una lista de las paradas de un colectivo en todos los barrios 
*/
Lista<Parada*>* obtenerParadasDeColectivo(Lista<Barrio*>* barrios, int colectivo);

/**
* pre: 
* post: Devuelve una lista de la cantidad de paradas de todos los colectivos en todos los barrios 
*/
Lista<int>* obtenerCantidadParadasPorColectivo(Lista<Barrio*>* barrios);

/**
* pre: 
* post: Devuelve la parada más cercana a una coordenada  
*/
Parada* obtenerParadaMasCercana(Lista<Barrio*>* barrios, long double lat, long double lon);

/**
* pre: 
* post: Devuelve una lista de todas las paradas de un colectivo en un barrio, ordenadas por distancia de una coordenada 
*/
Lista<Parada*>* obtenerParadasOrdenadasPorDistancia(Barrio* barrio, int colectivo, long double lat, long double lon);

#endif /* ASISTENTE_H_ */