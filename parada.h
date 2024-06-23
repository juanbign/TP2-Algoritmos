#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada {
private:

    // Dirección de la parada
    std::string direccion;

    // Número de la línea de colectivo
    int colectivo;

    // Latitud  y longitud de la parada
    long double lat;
    long double lon;

public:

    /**
    * pre: El número del colectivo debe ser mayor o igual a 1 
    * post: Devuelve una parada con las propiedades indicadas
    */
    Parada(std::string direccion, int colectivo, long double lat, long double lon);

    /**
    * pre: 
    * post: Devuelve una parada genérica (dirección: "", colectivo: 0, lat: 0, lon: 0)
            (compatibilidad con clase nodo)
    
    */
    Parada();

    /**
    * pre: 
    * post: Devuelve la dirección de la parada
    */
    std::string obtenerDireccion();

    /**
    * pre: 
    * post: Devuelve el número de la línea de colectivo de la parada
    */
    int obtenerColectivo();

    /**
    * pre: 
    * post: Devuelve la coordenada latitud de la parada
    */
    long double obtenerLatitud();

    /**
    * pre: 
    * post: Devuelve la coordenada longitud de la parada
    */
    long double obtenerLongitud();

    /**
    * pre: 
    * post: Cambia la dirección de la parada
    */
    void cambiarDireccion(std::string direccion);

    /**
    * pre: El número del colectivo debe ser mayor o igual a 1
    * post: Cambia el número del colectivo de la parada
    */
    void cambiarColectivo(int colectivo);

    /**
    * pre: 
    * post: Cambia la coordenada latitud de la parada
    */
    void cambarLatitud(long double lat);

    /**
    * pre: 
    * post: Cambia la coordenada longitud de la parada
    */
    void cambiarLongitud(long double lon);

};

#endif /* MENU_H_ */