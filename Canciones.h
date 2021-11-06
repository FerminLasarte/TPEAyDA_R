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

    void ordArrPorCriterioNombre();
    void ordArrPorCriterioRepro();
    estructura *orrPorNombreRecursivo(estructura *arreglo[], int inicio, int fin);

    void imprimirNombreCancionInOrder(estructura *actual);
    Cancion *buscarEnArbolNombre(estructura *actual, string nombreCancion);
    //void buscarEnArrGenero(estructura *pointer, string genero);

public:

    Canciones();
    virtual ~Canciones();

    void setMax(int maximo);
    void addCancion(Cancion& cancion);

    void imprimirNorm();
    void imprimirNombreCancion();
    void buscarPorNombre(string nombreCancion);
    //void buscarPorGenero(string genero);
    void recorrerEntreRangos(Lista<Cancion> &listaCancionRetorno, string minAnio, string maxAnio);
};

#endif //TPAYDAFIN_CANCIONES_H