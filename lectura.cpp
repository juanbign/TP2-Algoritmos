#include "lectura.h"
#include <fstream>
#include <iostream>

using namespace std;

void leerArchivo(string archivo) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;

	entrada.open(archivo.c_str());

	while (!entrada.eof()) {

		string linea;
		getline(entrada, linea);
		cout << "*** " << linea << " ***" << endl;
	
	}

	entrada.close();

}