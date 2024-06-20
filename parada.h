#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada {
private:

    std::string direccion;
    int colectivo;
    double lat;
    double lon;

public:

    Parada(std::string direccion, int colectivo, double lat, double lon);
    Parada();
    std::string obtenerDireccion();
    int obtenerColectivo();
    double obtenerLatitud();
    double obtenerLongitud();
    void cambiarDireccion(std::string direccion);
    void cambiarColectivo(int colectivo);
    void cambarLatitud();
    void cambiarLongitud();

};

#endif // PARADA_H_