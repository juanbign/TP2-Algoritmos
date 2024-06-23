#include "lectura.h"
#include "barrio.h"
#include "parada.h"
#include "lista.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


Lista<Barrio*>* leerArchivo(std::string archivo) {

	/* crea el archivo y abre la ruta especificada */
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
	int indiceColectivo;
	long double lat;
	long double lon;

	Lista<int>* colectivos;
	Lista<std::string>* barriosAgregados = new Lista<std::string>;
    Lista<Barrio*>* barrios = new Lista<Barrio*>;
	Barrio* barrio;
	Parada* parada;
	
	std::stringstream latParser("0");
	latParser >> lat;
	std::stringstream lonParser("0");
	lonParser >> lon;
	latParser.str("");
	latParser.clear(); 
	lonParser.str("");
	lonParser.clear(); 

	// Salteo cabeceras del csv
	std::getline(entrada, linea);

	while (!entrada.eof()) {

		std::getline(entrada, linea);

		comilla = false;
		contCampo = 0;
		campos = new std::string[19];
		colectivos = new Lista<int>;
		campoActual = "";
		barrioEncontrado = false;
		indiceBarrio = 0;
		indiceColectivo = 7;
		lat = 0;
		lon = 0;
		colectivo = 1;

		for (size_t i = 0; i < linea.size(); ++i) {

			if (linea[i] == '"') {

				// Invierto el estado actual del booleano
				comilla = !comilla;

			} else if (linea[i] == ',' && !comilla) {

				campos[contCampo] = campoActual;
				campoActual = "";
				contCampo++;

			} else {

				campoActual += linea[i];

			}

		}

		campos[contCampo] = campoActual;

		if (campos[6] == "") {

			if (campos[8] == "") {

				break;

			}

			campos[6] = campos[8];

		}

		barriosAgregados->iniciarCursor();

		for (int i = 0; barriosAgregados->avanzarCursor(); i++) {

			if (barriosAgregados->obtenerCursor() == campos[6]) {

				barrioEncontrado = true;
				indiceBarrio = i;
				break;

			}

		}

		std::stringstream latParser(campos[4]);
		latParser >> lat;
		std::stringstream lonParser(campos[3]);
		lonParser >> lon;
		latParser.str("");
		latParser.clear(); 
		lonParser.str("");
		lonParser.clear();

		while (indiceColectivo < 19) {

			if (campos[indiceColectivo] != "") {
				
				std::istringstream(campos[indiceColectivo]) >> colectivo;
				colectivos->agregar(colectivo);

			}

			indiceColectivo += 2;

		}

		if (!barrioEncontrado) {
		
			barriosAgregados->agregar(campos[6]);
			barrio = new Barrio(campos[6]);
			barrios->agregar(barrio);
		
		} else {

			barrio = barrios->obtener(indiceBarrio + 1);

		}

		colectivos->iniciarCursor();

		while (colectivos->avanzarCursor()) {

			parada = new Parada(campos[2], colectivos->obtenerCursor(), lat, lon);
			barrio->agregarParada(parada);
		
		}

		delete[] campos;
		delete colectivos;

	}

	delete barriosAgregados;

	entrada.close();

	return barrios;

}