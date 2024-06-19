

#include "lectura.h"

#include <fstream>
#include <iostream>

void leerArchivo(std::string archivo) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivo.c_str());
	while (! entrada.eof()) {
		std::string linea;
		std::getline(entrada, linea);
		std::cout << "*** " << linea << " ***" << std::endl;
	}

	entrada.close();
}


