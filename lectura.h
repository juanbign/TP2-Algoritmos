#ifndef LECTURA_H_
#define LECTURA_H_

#include "lista.h"
#include "barrio.h"
#include <string>

/**
* pre: El string pasado debe ser la dirección + nombre de un archivo csv ("C:/Documentos/archivo.csv") con el formato indicado en el manual de programador
* post: Devuelve una lista de barrios con paradas, basado en el csv pasado por parámetro
*/
Lista<Barrio*>* leerArchivo(std::string archivo);

#endif /* LECTURA_H_ */ 