#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Cancion.h"

template <typename T>

class Lista {

private:

    struct nodo
    {
        T* dato;
        nodo* sig = nullptr;
    };

    nodo *cabeza, *final;
    int longitud;

public:

    Lista();
    virtual ~Lista();

    void insertarLista(T &item);
    bool listaVacia() const;
    T* obtenerDato();

    nodo* publico;

    void volverInicio();
    void avanzar();
};

#endif // LISTA_H