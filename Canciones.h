#ifndef TPAYDAFIN_CANCIONES_H
#define TPAYDAFIN_CANCIONES_H
#include <iostream>
#include "Cancion.h"
#include "Lista.h"

class Canciones {

private:

    struct estructura {
        Cancion dato;
        estructura *mayNombreCancion, *menNombreCancion;
    };

    estructura *arrCanciones;
    estructura *raizOrdenNombre;
    int actual, longitud;

    void ordArrPorCriterio();
    estructura *orrPorNombreRecursivo(estructura *arreglo[], int inicio, int fin);

    void imprimirNombreCancionInOrder(estructura *actual);
    Cancion *buscarEnArbol(estructura *actual, string nombreCancion);

public:

    Canciones();
    virtual ~Canciones();

    void setMax(int maximo);
    void addCancion(Cancion& cancion);

    void imprimirNorm();
    void imprimirNombreCancion();
    void buscarPorNombre(string nombreCancion);
    Lista recorrerEntreRangos(string minAnio, string maxAnio);
};

#endif //TPAYDAFIN_CANCIONES_H