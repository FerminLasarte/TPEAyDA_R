#include "Lista.h"
#include "Cancion.h"

using namespace std;

template <typename T> Lista<T>::Lista() {
    this->cabeza = nullptr;
    this->final = nullptr;
    this->longitud = 0;
    this->publico = nullptr;
}

template <typename T> Lista<T>::~Lista() {
    nodo* aux = this->cabeza;
    while (aux != nullptr)
    {
        this->cabeza = this->cabeza->sig;
        delete aux;
        aux = this->cabeza;
    }
}

template <typename T> bool Lista<T>::listaVacia() const {
    return (longitud == 0);
}

template <typename T> void Lista<T>::insertarLista(T &item) {
    nodo* insertar = new nodo;

    insertar->dato = &item;
    insertar->sig = nullptr;

    if (cabeza == nullptr) {
        cabeza = insertar;
        final = insertar;
    } else {
        final->sig = insertar;
        final = final->sig;
    }

    longitud++;
}

template <typename T> T* Lista<T>::obtenerDato() {
    return this->publico->dato;
}

template <typename T> void Lista<T>::volverInicio() {
    this->publico = this->cabeza;
}

template <typename T> void Lista<T>::avanzar() {
    this->publico = this->publico->sig;
}

template class Lista<string>;
template class Lista<Cancion>;