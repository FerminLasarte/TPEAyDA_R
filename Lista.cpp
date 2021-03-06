#include "Lista.h"
#include "Cancion.h"

using namespace std;

template <typename T> Lista<T>::Lista() {
    this->cabeza = nullptr;
    this->cola = nullptr;
    this->longitud = 0;
    this->publico = nullptr;
}

template <typename T> Lista<T>::~Lista() {
    /*nodo* aux = this->cabeza;
    while (aux != nullptr)
    {
        this->cabeza = this->cabeza->sig;
        delete aux;
        aux = this->cabeza;
    }*/
}

template <typename T> bool Lista<T>::listaVacia() const {
    return (longitud == 0);
}

template <typename T> void Lista<T>::insertarLista(T &item) {
    nodo* insertar = new nodo;

    insertar->dato = item;
    insertar->sig = nullptr;

    if (cabeza == nullptr) {
        cabeza = insertar;
        cola = insertar;
    } else {
        cola->sig = insertar;
        cola = cola->sig;
    }

    longitud++;
}

template <typename T> void Lista<T>::volverInicio() {
    this->publico = this->cabeza;
}

template <typename T> void Lista<T>::avanzar() {
    this->publico = this->publico->sig;
}

template<typename T> int Lista<T>::calculaLeng() const {
    return longitud;
}

template class Lista<string>;
template class Lista<Cancion>;