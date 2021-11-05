#include "ListaString.h"

ListaString::ListaString() {
    this->cabeza = nullptr;
    this->final = nullptr;
    this->publico = nullptr;
    this->longitud = 0;
}

void ListaString::insertarLista(string generos) {
    nodoString* insertar = new nodoString;

    insertar->generos = generos;
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

void ListaString::avanzar() {
    this->publico = this->publico->sig;
}

ListaString::~ListaString() {
    /*nodoString* aux = this->cabeza;
    while (aux != nullptr)
    {
        this->cabeza = this->cabeza->sig;
        delete aux;
        aux = this->cabeza;
    }*/
}