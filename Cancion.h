#ifndef TPAYDAFIN_CANCION_H
#define TPAYDAFIN_CANCION_H
#include <iostream>
#include "Lista.h"

using namespace std;

class Cancion {

private:

    unsigned int nroCancion;
    string interprete;
    string nombreCancion;
    unsigned int duracion;
    string anio;
    Lista<string> listaGeneros;
    unsigned int reproducciones;

public:
    Cancion();
    Cancion(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio);
    virtual ~Cancion();

    unsigned int obtenerNroCancion() const;
    string obtenerInterprete() const;
    string obtenerNombreCancion() const;
    unsigned int obtenerDuracion() const;
    string obtenerAnio() const;
    unsigned int obtenerReproducciones() const;

    bool generoPertenece(string generoABuscar);
    void agregarGenero(string &generoAAgregar);
    void setReproducciones(unsigned int reproducciones);
    void imprimeDatos();
};

#endif //TPAYDAFIN_CANCION_H