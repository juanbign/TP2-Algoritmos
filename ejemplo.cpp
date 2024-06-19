
#include <string>
#include "lectura.h"

int main() {

	std::string archivo = "datos/paradas-de-colectivo.csv";
	//almaceno la ruta del archivo

	leerArchivo(archivo);
	//ejecuto para leer los datos del archivo

	return 0;
}

