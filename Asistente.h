#include "lista.h"
#include "parada.h"
#include "barrio.h"

#ifndef ASISTENTE_H_
#define ASISTENTE_H_

class Asistente{

    private:

        const int MAXIMO_NUM_LINEA_COLECTIVO = 195;

    public:

/******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/

	
   /**
    * pre: 
    * post: Devuelve una lista de las paradas de una linea de colectivo en todos los barrios 
    */
	Lista<Parada>* obtenerParadasDeColectivo(Lista<Barrio<Parada> >* barrios, int colectivo);

    /**
    * pre: 
    * post: Devuelve una lista de la cantidad de paradas de todos los colectivos en todos los barrios 
    */
    Lista<int>* obtenerCantidadParadasPorColectivo(Lista<Barrio<Parada> >* barrios);

    /**
    * pre: 
    * post: Devuelve la parada más cercana a una coordenada  
    */
    Parada obtenerParadaMasCercana(Lista<Barrio<Parada> >* barrios, double lat, double lon);

    /**
    * pre: 
    * post: Devuelve una lista de todas las paradas en todos los barrios, ordenadas por distancia de una coordenada 
    */
    Lista<Parada>* obtenerParadasOrdenadasPorDistancia(Barrio<Parada> barrio, int colectivo, double lat, double lon);

};
/*******************************************************************************************************************
 * Primera aproximación, falta pruebas
 ******************************************************************************************************************/


#endif /* ASISTENTE_H_ */
