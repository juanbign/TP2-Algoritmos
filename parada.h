#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada {
private:

    std::string direccion;
    int colectivo;
    long double lat;
    long double lon;

public:

    Parada(std::string direccion, int colectivo, long double lat, long double lon);
    Parada();
    std::string obtenerDireccion();
    int obtenerColectivo();
    long double obtenerLatitud();
    long double obtenerLongitud();
    void cambiarDireccion(std::string direccion);
    void cambiarColectivo(int colectivo);
    void cambarLatitud(long double lat);
    void cambiarLongitud(long double lon);

};

#endif // PARADA_H_