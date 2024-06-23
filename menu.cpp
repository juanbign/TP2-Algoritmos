#include "lista.h"
#include "barrio.h"
#include "parada.h"
#include "asistente.h"
#include "menu.h"

#include <iostream>
#include <string>
#include <cmath>

Menu::Menu(Lista<Barrio*>* barrios) {

    this->nombreBarrios = new Lista<std::string>;
    this->barrios = barrios;

    this->barrios->iniciarCursor();

    std::string nombreBarrioTemp;

    // Recorro los barrios pasados por parámetro
    while (this->barrios->avanzarCursor()) {

        // Agrego sus nombres a la lista
        this->nombreBarrios->agregar(this->barrios->obtenerCursor()->obtenerNombre());

    }

}

Menu::~Menu() {

    delete this->nombreBarrios;

}

void Menu::mostrarMenu() {

    // ¿Desea el usuario continuar la ejecución?
    char continuar = true;

    // La opción que elije el usuario
    char opcion;

    // Propiedades de parada
    int colectivo;
    long double lat;
    long double lon;

    // ¿Se encontró el barrio en la lista de barrios?
    bool barrioEncontrado;

    // Nombre del barrio que ingresa el usuario
    std::string nombreBarrio;

    // Variables genéricas para guardar resultados
    Parada* parada;
    Barrio* barrio;
    Lista<Parada*>* paradas;
    Lista<int>* cantidadParadas;

    // Mientras que el usuario quiera seguir la ejecución
    while (continuar) {

        // Muestro opciones
        std::cout << std::endl << "Bienvenido! Estas son las opciones disponibles" << std::endl << std::endl;
        std::cout << "1: Mostrar listado de cantidad de paradas por barrio" << std::endl;
        std::cout << "2: Mostrar la parada mas cercana a una coordenada" << std::endl;
        std::cout << "3: Mostrar listado de paradas de un colectivo" << std::endl;
        std::cout << "4: Mostrar listado de cantidad de paradas por colectivo" << std::endl;
        std::cout << "5: Mostrar listado de paradas en un barrio ordenadas por distancia de una coordenada" << std::endl;
        std::cout << "6: Salir" << std::endl << std::endl;

        std::cout << "Elija una opcion: ";

        // Obtengo la elección
        std::cin >> opcion;

        std::cout << std::endl << std::endl;

        // Hago switch dependiendo de la elección
        switch (opcion) {

            // Mostrar listado de cantidad de paradas por barrio
            case '1': 
                
                // Obtengo la cantidad de paradas por barro
                cantidadParadas = obtenerCantidadParadasPorBarrio(barrios);
                this->nombreBarrios->iniciarCursor();
                cantidadParadas->iniciarCursor();

                // Si hay al menos un barrio
                if (this->nombreBarrios->avanzarCursor()) {

                    // Si hay al menos una parada
                    if (cantidadParadas->avanzarCursor()) {

                        std::cout << this->nombreBarrios->obtenerCursor() << ": " << cantidadParadas->obtenerCursor() << " paradas" << std::endl;
                        
                        // Avanzo con ambos cursores y muestro el resultado
                        while (this->nombreBarrios->avanzarCursor() && cantidadParadas->avanzarCursor()) {

                            std::cout << this->nombreBarrios->obtenerCursor() << ": " << cantidadParadas->obtenerCursor() << " paradas" << std::endl;

                        }

                    // Si no hay paradas, lo comunico al usuario
                    } else {

                        std::cout << "No hay paradas en ningún barrio" << std::endl;

                    }

                // Si no hay barrios, lo comunico al usuario
                } else {

                    std::cout << "No hay barrios en la lista" << std::endl;                    

                }

                // Libero la memoria
                delete cantidadParadas;

                break;

            // Mostrar la parada mas cercana a una coordenada
            case '2':

                std::cout << "Ingrese latitud (escrita como 1.23 o -1.23): ";
                std::cin >> lat;
                std::cout << std::endl << "Ingrese longitud (escrita como 1.23 o -1.23): ";
                std::cin >> lon;

                // Obtengo la parada más cercanas a las coordenadas ingresadas (en grados)
                parada = obtenerParadaMasCercana(barrios, lat, lon);

                // Si la dirección es igual a "NULL", signifca que no hay paradas
                if (parada->obtenerDireccion() == "NULL") {

                    // Lo comunico al usuario
                    std::cout << "No hay paradas en ningún barrio";

                    //Libero memoria ya que la parada tuvo que ser creada
                    delete parada;

                } else { 
                
                    // Muestro el resultado
                    std::cout << "La parada mas cercana esta en " << parada->obtenerDireccion() << ", a " << sqrt(pow(parada->obtenerLatitud() - lat, 2) + pow(parada->obtenerLongitud() - lon, 2)) << " grados de distancia";

                }

                break;

            // Mostrar listado de paradas de un colectivo
            case '3':
            
                std::cout << "Ingrese numero del colectivo (entre 1 y " << obtenerMaximoNumLineaColectivo() << "): ";
                std::cin >> colectivo;

                // Obtengo las paradas del colectivo elegido
                paradas = obtenerParadasDeColectivo(barrios, colectivo);

                paradas->iniciarCursor();

                std::cout << std::endl << std::endl;

                // Si se encuentra al menos una parada, muestro los resultados
                if (paradas->avanzarCursor()) {

                    std::cout << '"' << paradas->obtenerCursor()->obtenerDireccion() << '"';

                    while (paradas->avanzarCursor()) {
                 
                        std::cout << ", " << '"' << paradas->obtenerCursor()->obtenerDireccion() << '"';

                    }
                
                // Si no, lo comunico al usuario
                } else {

                    std::cout << "No hay paradas de ese colectivo";

                }

                // Libero memoria
                delete paradas;

                break;

            // Mostrar listado de cantidad de paradas por colectivo
            case '4':

                // Obtengo la cantidad de paradas por colectivo
                cantidadParadas = obtenerCantidadParadasPorColectivo(barrios);

                cantidadParadas->iniciarCursor();

                // Inicializo el contador
                colectivo = 1;

                // Si hay al menos un colectivo
                if (cantidadParadas->avanzarCursor()) {

                    std::cout << "Colectivo " << colectivo << ": " << cantidadParadas->obtenerCursor() << " paradas";

                    while (cantidadParadas->avanzarCursor()) {

                        // Muestro el contador del cursor
                        colectivo++;
                 
                        std::cout << std::endl << "Colectivo " << colectivo << ": " << cantidadParadas->obtenerCursor() << " paradas";

                    }
                
                // Si no, lo comunico al usuario
                } else {

                    std::cout << "No hay colectivos";

                }

                // Libero memoria
                delete cantidadParadas;

                break;

            // Mostrar listado de paradas en un barrio ordenadas por distancia de una coordenada
            case '5':

                // Inicializo el booleano
                barrioEncontrado = false;

                std::cout << "Barrios disponibles: " << std::endl;
                
                this->nombreBarrios->iniciarCursor();

                // Si hay al menos un barrio
                if (this->nombreBarrios->avanzarCursor()) {

                    // Muestro todos los barrios disponibles
                    while(this->nombreBarrios->avanzarCursor()) {

                        std::cout << this->nombreBarrios->obtenerCursor() << std::endl;

                    }

                // Si no, lo comunico al usuario
                } else {

                    std::cout << "No hay ningún barrio disponible";
                    break;

                }

                // Mientras que el barrio que ingrese el usuario no exista
                while (!barrioEncontrado) {

                    std::cout << std::endl << "Ingrese el nombre del barrio: ";

                    // Sincronizo el input porque si no obtiene un string vacío
                    std::cin.sync();

                    // Obtengo toda la línea del input así se pueden ingresar strings con espacios
                    std::getline(std::cin, nombreBarrio);

                    this->nombreBarrios->iniciarCursor();
                    barrios->iniciarCursor();

                    // Recorro con ambos cursores
                    while(barrios->avanzarCursor() && this->nombreBarrios->avanzarCursor()) {

                        // Si se encuentra el barrio
                        if (this->nombreBarrios->obtenerCursor() == nombreBarrio) {

                            barrio = barrios->obtenerCursor();
                            barrioEncontrado = true;
                            break;

                        }

                    }

                    // Si no se encontró el barrio, lo comunico al usuario
                    if (!barrioEncontrado) {

                        std::cout << "El barrio " << nombreBarrio << " no existe, por favor ingrese otro";

                    }

                    std::cout << std::endl;

                }

                // Si se encontró el barrio

                std::cout << "Ingrese latitud (escrita como 1.23 o -1.23): ";
                std::cin >> lat;
                std::cout << std::endl << "Ingrese longitud (escrita como 1.23 o -1.23): ";
                std::cin >> lon;
                std::cout << std::endl << "Ingrese numero del colectivo (entre 1 y " << obtenerMaximoNumLineaColectivo() << "): ";
                int colectivo;
                std::cin >> colectivo;

                barrios->iniciarCursor();

                // Obtengo las paradas ordenadas por distancia
                paradas = obtenerParadasOrdenadasPorDistancia(barrio, colectivo, lat, lon);
                
                paradas->iniciarCursor();

                // Si hay al menos una parada
                if (paradas->avanzarCursor()) {

                    std::cout << std::endl << paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    while (paradas->avanzarCursor()) {
                 
                        std::cout << std::endl << paradas->obtenerCursor()->obtenerDireccion() << ", a " << sqrt(pow(paradas->obtenerCursor()->obtenerLatitud() - lat, 2) + pow(paradas->obtenerCursor()->obtenerLongitud() - lon, 2)) << " grados de distancia" << std::endl;;

                    }
                
                // Si no, lo comunico al usuario
                } else {

                    std::cout << std::endl << "No hay paradas del colectivo " << colectivo << " en el barrio " << nombreBarrio;

                }

                // Libero memoria
                delete paradas;

                break;

            // Salir
            case '6':

                break;

            // Si el usuario ingresa una opción no reconocida por el programa
            default: 
                
                // Lo comunico y pido una opción de vuelta
                std::cout << "Por favor ingrese una opcion correcta";

                // Muestro las opciones de vuelta
                continue;
            
        }

        // Si el usuario quiere salir, termino el while
        if (opcion == '6') {

            break;

        }

        // Pregunto al usuario si desea continuar una vez que haya completado su consulta
        std::cout << std::endl << std::endl << "Desea continuar? (S/N)" << std::endl;
        
        char deseaContinuar;
        std::cin >> deseaContinuar;

        // Si ingresa cualquier cosa que no sea "SÍ", se termina la ejecución
        if (deseaContinuar != 'S') {
        
            continuar = false;
        
        }

    }

}