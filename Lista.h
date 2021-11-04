#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Cancion.h"

class Lista
{

private:

    struct nodo
    {
        Cancion* dato;
        nodo* sig = nullptr;
    };

    nodo *cabeza, *final;
    int longitud;

public:

    Lista();
    virtual ~Lista();

    void insertarLista(Cancion& item);
    bool listaVacia() const;
    Cancion* obtenerDato();

    nodo* publico;

    void volverInicio();
    void avanzar();
    void imprimirLista();
};

#endif // LISTA_H