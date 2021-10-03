#ifndef CANCIONES_H
#define CANCIONES_H
#include <iostream>

using namespace std;

class Canciones {

private:

    unsigned int nroCancion;
    string interprete;
    string nombreCancion;
    unsigned int duracion;
    string anio;
    string generos;
    unsigned int reproducciones;

public:
    Canciones();
    Canciones(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, string generos, unsigned int reproducciones);
    virtual ~Canciones();

    unsigned int obtenerNroCancion() const;
    string obtenerInterprete() const;
    string obtenerNombreCancion() const;
    unsigned int obtenerDuracion() const;
    string obtenerAnio() const;
    string obtenerGeneros() const;
    unsigned int obtenerReproducciones() const;

    void imprimeDatos();
};

#endif //CANCIONES_H