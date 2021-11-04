#include "Lista.h"

using namespace std;
Lista::Lista() {
    this->cabeza = nullptr;
    this->final = nullptr;
    this->longitud = 0;
    this->publico = nullptr;
}

Lista::~Lista() {
    nodo* aux = this->cabeza;
    while (aux != nullptr)
    {
        this->cabeza = this->cabeza->sig;
        delete aux;
        aux = this->cabeza;
    }
}

bool Lista::listaVacia() const {
    return (longitud == 0);
}

void Lista::insertarLista(Cancion& item) {
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

Cancion* Lista::obtenerDato() {
    return this->publico->dato;
}

void Lista::volverInicio() {
    this->publico = this->cabeza;
}

void Lista::avanzar() {
    this->publico = this->publico->sig;
}

void Lista::imprimirLista() {
    nodo* aux = this->cabeza;
    while (aux != nullptr)
    {
        aux->dato->imprimeDatos();
        aux = aux->sig;
    }
}