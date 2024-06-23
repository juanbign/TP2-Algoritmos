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
    this->asistente = new Asistente();

    this->barriosArchivo->iniciarCursor();

    std::string nombreBarrioTemp;

    while (this->barriosArchivo->avanzarCursor()) {

        nombreBarrioTemp = this->barriosArchivo->obtenerCursor()->obtenerNombre();

        if (nombreBarrioTemp != "") {

            this->nombreBarrios->agregar(nombreBarrioTemp);

        }

    }

}

Menu::~Menu() {

    delete this->asistente;
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
    Parada* parada;
    Barrio* barrio;
    Lista<Parada*>* paradas;
    Lista<int>* cantidadParadas;

    while (continuar) {

        std::cout << std::endl << "Bienvenido! Estas son las opciones disponibles" << std::endl << std::endl;
        std::cout << "1: Mostrar listado de cantidad de paradas por barrio" << std::endl;
        std::cout << "2: Mostrar la parada mas cercana a una coordenada" << std::endl;
        std::cout << "3: Mostrar listado de paradas de un colectivo" << std::endl;
        std::cout << "4: Mostrar listado de cantidad de paradas por colectivo" << std::endl;
        std::cout << "5: Mostrar listado de paradas en un barrio ordenadas por distancia de una coordenada" << std::endl << std::endl;

        std::cout << "Elija una opcion: ";

        std::cin >> opcion;

        std::cout << std::endl << std::endl;

        switch (opcion) {

            case '1': 
                
                cantidadParadas = this->asistente->obtenerCantidadParadasPorBarrio(barriosArchivo);
                this->nombreBarrios->iniciarCursor();
                cantidadParadas->iniciarCursor();

                while (this->nombreBarrios->avanzarCursor() && cantidadParadas->avanzarCursor()) {

                    std::cout << this->nombreBarrios->obtenerCursor() << ": " << cantidadParadas->obtenerCursor() << " paradas" << std::endl;

                }

                std::cout << std::endl << std::endl;

                delete cantidadParadas;

                break;

            case '2':

                std::cout << "Ingrese latitud (escrita como 1.23 o -1.23): ";
                std::cin >> lat;
                std::cout << std::endl << "Ingrese longitud (escrita como 1.23 o -1.23): ";
                std::cin >> lon;
                parada = this->asistente->obtenerParadaMasCercana(barriosArchivo, lat, lon);
                
                std::cout << std::endl << std::endl << "La parada mas cercana esta en " << parada->obtenerDireccion() << ", a " << sqrt(pow(parada->obtenerLatitud() - lat, 2) + pow(parada->obtenerLongitud() - lon, 2)) << " grados de distancia";

                std::cout << std::endl << std::endl;

                delete parada;

                break;

            case '3':
            
                std::cout << "Ingrese numero del colectivo: ";
                std::cin >> colectivo;

                paradas = this->asistente->obtenerParadasDeColectivo(barriosArchivo, colectivo);

                paradas->iniciarCursor();

                std::cout << std::endl << std::endl;

                if (paradas->avanzarCursor()) {

                    std::cout << '"' << paradas->obtenerCursor()->obtenerDireccion() << '"';

                    while (paradas->avanzarCursor()) {
                 
                        std::cout << ", " << '"' << paradas->obtenerCursor()->obtenerDireccion() << '"';

                    }
                
                } else {

                    std::cout << "No hay paradas de ese colectivo";

                }

                std::cout << std::endl << std::endl;

                delete paradas;

                break;

            case '4':

                cantidadParadas = this->asistente->obtenerCantidadParadasPorColectivo(barriosArchivo);

                cantidadParadas->iniciarCursor();

                i = 1;

                if (cantidadParadas->avanzarCursor()) {

                    std::cout << "Colectivo " << i << ": " << cantidadParadas->obtenerCursor() << " paradas";

                    while (cantidadParadas->avanzarCursor()) {

                        i++;
                 
                        std::cout << std::endl << "Colectivo " << i << ": " << cantidadParadas->obtenerCursor() << " paradas";

                    }
                
                } else {

                    std::cout << "No hay colectivos";

                }

                std::cout << std::endl << std::endl;

                delete cantidadParadas;

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
                    barriosArchivo->iniciarCursor();

                    while(barriosArchivo->avanzarCursor() && this->nombreBarrios->avanzarCursor()) {

                        if (this->nombreBarrios->obtenerCursor() == nombreBarrio) {

                            barrio = barriosArchivo->obtenerCursor();
                            barrioEncontrado = true;

                        }

                    }

                    if (!barrioEncontrado) {

                        std::cout << "El barrio " << nombreBarrio << " no existe, por favor ingrese otro";

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

                barriosArchivo->iniciarCursor();

                paradas = this->asistente->obtenerParadasOrdenadasPorDistancia(barrio, colectivo, lat, lon);
                
                paradas->iniciarCursor();

                if (paradas->avanzarCursor()) {

                    std::cout << std::endl << paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    while (paradas->avanzarCursor()) {
                 
                        std::cout << std::endl << paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    }
                
                } else {

                    std::cout << std::endl << "No hay paradas del colectivo " << colectivo << " en el barrio " << nombreBarrio;

                }

                std::cout << std::endl << std::endl;

                delete barrio;
                delete paradas;

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