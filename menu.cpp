#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include "asistente.h"
#include "menu.h"

#include <iostream>
#include <string>
#include <cmath>

Menu::Menu(Lista<Barrio*>* barriosArchivo) {

    this->nombreBarrios = new Lista<std::string>;
    this->barriosArchivo = barriosArchivo;

    this->barriosArchivo->iniciarCursor();

    std::string nombreBarrioTemp;

    while (this->barriosArchivo->avanzarCursor()) {

        nombreBarrioTemp = this->barriosArchivo->obtenerCursor()->obtenerNombre();

        if (nombreBarrioTemp == "") {

            continue;

        }

        this->nombreBarrios->agregar(nombreBarrioTemp);

    }


}

Menu::~Menu() {

    delete this->asistente;
    delete this->barriosArchivo;
    delete this->parada;
    delete this->barrio;
    delete this->paradas;
    delete this->barrios;
    delete this->cantidadParadas;
    delete this->nombreBarrios;

}

void Menu::mostrarMenu() {

    char continuar = true;
    char opcion;
    int i;
    int colectivo;
    long double lat;
    long double lon;
    bool barrioEncontrado;
    std::string nombreBarrio;

    while (continuar) {

        std::cout << std::endl << "Bievenido! Estas son las opciones disponibles" << std::endl << std::endl;
        std::cout << "0: Mostrar las opciones de vuelta" << std::endl;
        std::cout << "1: Mostrar listado de cantidad de paradas por barrio" << std::endl;
        std::cout << "2: Mostrar la parada mas cercana a una coordenada" << std::endl;
        std::cout << "3: Mostrar listado de paradas de un colectivo" << std::endl;
        std::cout << "4: Mostrar listado de cantidad de paradas por colectivo" << std::endl;
        std::cout << "5: Mostrar listado de paradas en un barrio ordenadas por distancia de una coordenada" << std::endl << std::endl;

        std::cout << "Elija una opcion: ";

        std::cin >> opcion;

        std::cout << std::endl << std::endl;

        switch (opcion) {

            case '0':

                std::cout << "0: Mostrar las opciones de vuelta" << std::endl;
                std::cout << "1: Mostrar listado de cantidad de paradas por barrio" << std::endl;
                std::cout << "2: Mostrar la parada mas cercana a una coordenada" << std::endl;
                std::cout << "3: Mostrar listado de paradas de un colectivo" << std::endl;
                std::cout << "4: Mostrar listado de cantidad de paradas por colectivo" << std::endl;
                std::cout << "5: Mostrar listado de paradas en un barrio ordenadas por distancia de una coordenada" << std::endl << std::endl;

                std::cout << "Elija una opcion: ";

                std::cin >> opcion;

                std::cout << std::endl << std::endl;

            case '1': 
                
                //this->cantidadParadasPorBarrio = this->asistente->obtenerCantidadParadasPorBarrio(barrios);

                this->barrios->iniciarCursor();

                while (barrios->avanzarCursor()) {

                    this->barrio = this->barrios->obtenerCursor();

                    std::cout << this->barrio->obtenerNombre() << ": " << this->barrio->contarParadas() << " paradas" << std::endl;

                }

                std::cout << std::endl << std::endl;

                break;

            case '2':

                std::cout << "Ingrese latitud (escrita como 1.23 o -1.23): ";
                std::cin >> lat;
                std::cout << std::endl << "Ingrese longitud (escrita como 1.23 o -1.23): ";
                std::cin >> lon;
                this->parada = this->asistente->obtenerParadaMasCercana(barriosArchivo, lat, lon);
                
                std::cout << std::endl << std::endl << "La parada mas cercana esta en " << this->parada->obtenerDireccion() << ", a " << sqrt(pow(this->parada->obtenerLatitud() - lat, 2) + pow(this->parada->obtenerLongitud() - lon, 2)) << " grados de distancia";

                std::cout << std::endl << std::endl;

                break;

            case '3':
            
                std::cout << "Ingrese numero del colectivo: ";
                std::cin >> colectivo;

                this->paradas = this->asistente->obtenerParadasDeColectivo(this->barriosArchivo, colectivo);

                this->paradas->iniciarCursor();

                std::cout << std::endl << std::endl;

                if (this->paradas->avanzarCursor()) {

                    std::cout << '"' << this->paradas->obtenerCursor()->obtenerDireccion() << '"';

                    while (this->paradas->avanzarCursor()) {
                 
                        std::cout << ", " << '"' << this->paradas->obtenerCursor()->obtenerDireccion() << '"';

                    }
                
                } else {

                    std::cout << "No hay paradas de ese colectivo";

                }

                std::cout << std::endl << std::endl;

                break;

            case '4':

                this->cantidadParadas = this->asistente->obtenerCantidadParadasPorColectivo(this->barriosArchivo);

                this->cantidadParadas->iniciarCursor();

                i = 1;

                if (this->cantidadParadas->avanzarCursor()) {

                    std::cout << "Colectivo " << i << ": " << this->cantidadParadas->obtenerCursor() << " paradas";

                    while (this->cantidadParadas->avanzarCursor()) {

                        i++;
                 
                        std::cout << std::endl << "Colectivo " << i << ": " << this->cantidadParadas->obtenerCursor() << " paradas";

                    }
                
                } else {

                    std::cout << "No hay colectivos";

                }

                std::cout << std::endl << std::endl;
                
                break;

            case '5':

                barrioEncontrado = false;

                std::cout << "Barrios disponibles: " << std::endl;
                
                this->nombreBarrios->iniciarCursor();

                while(this->nombreBarrios->avanzarCursor()) {

                    std::cout << this->nombreBarrios->obtenerCursor() << std::endl;

                }

                while (!barrioEncontrado) {

                    std::cout << std::endl << "Ingrese el nombre del barrio: ";

                    std::cin.sync();
                    std::getline(std::cin, nombreBarrio);

                    this->nombreBarrios->iniciarCursor();
                    this->barriosArchivo->iniciarCursor();

                    while(this->barriosArchivo->avanzarCursor() && this->nombreBarrios->avanzarCursor()) {

                        if (this->nombreBarrios->obtenerCursor() == nombreBarrio) {

                            this->barrio = this->barriosArchivo->obtenerCursor();
                            barrioEncontrado = true;

                        }

                    }

                    if (!barrioEncontrado) {

                        std::cout << "El barrio " << nombreBarrio <<" no existe, por favor ingrese otro";

                    }

                    std::cout << std::endl;

                }

                std::cout << "Ingrese latitud: ";
                std::cin >> lat;
                std::cout << std::endl << "Ingrese longitud: ";
                std::cin >> lon;
                std::cout << std::endl << "Ingrese numero del colectivo: ";
                int colectivo;
                std::cin >> colectivo;

                this->barriosArchivo->iniciarCursor();

                this->paradas = this->asistente->obtenerParadasOrdenadasPorDistancia(this->barrio, colectivo, lat, lon);
                
                this->paradas->iniciarCursor();

                if (this->paradas->avanzarCursor()) {

                    std::cout << std::endl << this->paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(this->paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(this->paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    while (this->paradas->avanzarCursor()) {
                 
                        std::cout << std::endl << this->paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(this->paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(this->paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    }
                
                } else {

                    std::cout << std::endl << "No hay paradas del colectivo " << colectivo << " en el barrio " << nombreBarrio;

                }

                std::cout << std::endl << std::endl;

                break;

            default: 
                
                std::cout << "Por favor ingrese una opcion correcta: ";
                std::cin >> opcion;
                std::cout << std::endl << std::endl;
            
        }

        std::cout << "Desea continuar? (S/N)" << std::endl;
        
        char deseaContinuar;
        std::cin >> deseaContinuar;

        if (deseaContinuar != 'S') {
        
            continuar = false;
        
        }

    }

}