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
    estructura *orrPorNombreRecursivo(estructura *arreglo[], int inicio, int fin);

    bool contiene(string cancionPorComparar, string nombreCancion) const;
    void imprimirNombreCancionInOrder(estructura *actual);
    Cancion *buscarEnArbolNombre(estructura *actual, string nombreCancion);

public:

    Canciones();
    virtual ~Canciones();

    void setMax(int maximo);
    void addCancion(Cancion& cancion);

    void imprimirNorm();
    void imprimirNombreCancion();
    void buscarPorNombre(string nombreCancion);
    void busquedaLinealComodin(Lista<Cancion> &listaComodinRetorno, string nombreCancion);
    void obtenerTopTen(Lista<Cancion> &listaTopGeneros, string generoABuscar);
    void recorrerEntreRangos(Lista<Cancion> &listaCancionRetorno, string minAnio, string maxAnio);
};

#endif //TPAYDAFIN_CANCIONES_H