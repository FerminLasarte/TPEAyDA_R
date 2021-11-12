#ifndef LISTA_H
#define LISTA_H
#include <iostream>

template <typename T>

class Lista {

private:

    struct nodo
    {
        T dato;
        nodo* sig = nullptr;
    };

    nodo *cabeza, *cola;
    int longitud;

public:

    Lista();
    virtual ~Lista();

    void insertarLista(T &item);
    bool listaVacia() const;

    nodo* publico;

    int calculaLeng() const;
    void volverInicio();
    void avanzar();
};

#endif // LISTA_H