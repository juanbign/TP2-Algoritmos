#include "lectura.h"
#include "barrio.h"
#include "parada.h"
#include "lista.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


Lista<Barrio*>* leerArchivo(std::string archivo) {

	//Abro el archivo
	std::ifstream entrada;
	entrada.open(archivo.c_str());
	
	std::string* campos;
	std::string campoActual;
	std::string linea;
	bool comilla;
	bool barrioEncontrado;
	int contCampo;
	int colectivo;
	int indiceBarrio;
	int indiceCampoColectivo;
	long double lat;
	long double lon;

	Lista<std::string>* barriosEncontrados = new Lista<std::string>;
    Lista<Barrio*>* barrios = new Lista<Barrio*>;
	Barrio* barrio;
	Parada* parada;
	
	// Parseo de string a long double
	std::stringstream latParser("0");
	std::stringstream lonParser("0");

	// Salteo cabeceras del csv
	std::getline(entrada, linea);

	// Hasta que llegue al final del archivo
	while (!entrada.eof()) {

		// Obtengo la línea actual
		std::getline(entrada, linea);
		
		// Vacío los parsers
		latParser.str("");
		latParser.clear(); 
		lonParser.str("");
		lonParser.clear();

		// ¿Está el campo actual entre comillas?
		comilla = false;
		
		// Índice del campo actual en la línea
		contCampo = 0;

		// Array para guardar todos los campos en la línea actual
		campos = new std::string[19];
		campoActual = "";

		// ¿El barrio de esta línea ya se agregó a la lista de barrios?
		barrioEncontrado = false;

		// Índice del barrio correspondiente en la lista de barrios
		indiceBarrio = 0;

		// Índice de los campos que pueden contener colectivos
		indiceCampoColectivo = 7;

		// Propiedades de la parada
		lat = 0;
		lon = 0;
		colectivo = 1;

		for (size_t i = 0; i < linea.size(); ++i) {

			// Si la posición actual es una comilla
			if (linea[i] == '"') {

				// Invierto el estado actual del booleano
				comilla = !comilla;

				// Ésto hace que la siguiente condición 
				// (se encuentra un coma que actúa de divisor)
				// no sea verdadera hasta que se cierren las comillas

			// Si la posición actual es una coma y no está entre comillas
			} else if (linea[i] == ',' && !comilla) {

				// Igualo el campo correspondiente al obtenido
				campos[contCampo] = campoActual;

				// Reinicio el valor y avanzo en el array
				campoActual = "";
				contCampo++;

			// Si la posición actual es parte de un campo
			} else {

				// La agrego al campo actual
				campoActual += linea[i];

			}

		}

		// Agrego cualquier campo que pudo haber quedado
		// por si acaso me aseguro que no se salga del tamaño del array
		if (contCampo < 19) {
			
			campos[contCampo] = campoActual;

		}

		// A veces el nombre del barrio no está
		if (campos[6] == "") {

			// No agrego esta parada a la lista
			// Continúo con la siguiente iteración del bucle
			delete[] campos;
			continue;

		}

		barriosEncontrados->iniciarCursor();

		// Recorro todos los barrios ya encontrados
		for (int i = 1; barriosEncontrados->avanzarCursor(); i++) {

			// Si el barrio de la parada actual ya existe
			if (barriosEncontrados->obtenerCursor() == campos[6]) {

				// Guardo su índice 
				barrioEncontrado = true;
				indiceBarrio = i;
				break;

			}

		}

		// Si no se encontró el barrio de la parada actual
		if (!barrioEncontrado) {
		
			// Lo agrego a los barrios encontrados
			barriosEncontrados->agregar(campos[6]);

			// Creo un nuevo barrio
			barrio = new Barrio(campos[6]);
		
		} else {

			// Lo obtengo de la lista ya existente
			barrio = barrios->obtener(indiceBarrio);

		}

		// Parseo los doubles
		std::stringstream latParser(campos[4]);
		latParser >> lat;
		std::stringstream lonParser(campos[3]);
		lonParser >> lon;

		// Mientras el índice sea menor al tamaño del array de campos
		while (indiceCampoColectivo < 19) {

			// Si el campo no está vacío
			if (campos[indiceCampoColectivo] != "") {
				
				// Lo parseo a int
				std::istringstream(campos[indiceCampoColectivo]) >> colectivo;

				// Creo una nueva parada y la agrego al barrio
				parada = new Parada(campos[2], colectivo, lat, lon);
				barrio->agregarParada(parada);

			}

			indiceCampoColectivo += 2;

		}

		// Si no encontré el barrio, lo agrego a la lista
		if (!barrioEncontrado) {

			barrios->agregar(barrio);

		}

		// Libero la memoria de los campos
		delete[] campos;

	}

	// Libero la memoria de la lista
	delete barriosEncontrados;

	// Cierro el lector del archivo
	entrada.close();

	return barrios;

}