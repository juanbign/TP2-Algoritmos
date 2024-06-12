#ifndef PARADA_H_
#define PARADA_H_

#include <string>

class Parada {
private:

    std::string direccion;
    int colectivo;
    int lat;
    int lon;

public:

    Parada(std::string direccion, int colectivo);
    virtual ~Parada();
    std::string obtenerDireccion();
    int obtenerColectivo();
    void cambiarDireccion(std::string direccion);
    void cambiarColectivo(int colectivo);

};

#endif // PARADA_H_