#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Canciones.h"

class Lista
{

private:

    struct nodo
    {
        Canciones* dato;
        nodo* sig = NULL;
    };

    nodo* cabeza;

public:

    Lista();
    virtual ~Lista();

    void insertarLista(Canciones& item);
    bool listaVacia(nodo* pointer);
    Canciones* obtenerDato();

    nodo* publico;

    void volverInicio();
    void avanzar();
};

#endif // LISTA_H
