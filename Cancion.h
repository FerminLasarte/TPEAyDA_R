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
    Lista<Cancion> listaGeneros;
    unsigned int reproducciones;

public:
    Cancion();
    Cancion(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, Lista<Cancion> listaGeneros, unsigned int reproducciones);
    virtual ~Cancion();

    unsigned int obtenerNroCancion() const;
    string obtenerInterprete() const;
    string obtenerNombreCancion() const;
    unsigned int obtenerDuracion() const;
    string obtenerAnio() const;
    unsigned int obtenerReproducciones() const;

    void imprimeDatos();
};

#endif //TPAYDAFIN_CANCION_H