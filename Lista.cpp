#include <string>
#include "Lista.h"

using namespace std;
Lista::Lista()
{
    this->cabeza = NULL;
    this->publico = NULL;
}

Lista::~Lista()
{
    nodo* aux = this->cabeza;
    while (aux != NULL)
    {
        this->cabeza = this->cabeza->sig;
        delete aux;
        aux = this->cabeza;
    }
}

bool Lista::listaVacia(nodo* pointer)
{
    if (pointer == NULL)
        return true;
    else
        return false;
}

void Lista::insertarLista(Canciones& item)
{
    nodo* aux = this->cabeza;
    nodo* insertar = new nodo;

    insertar->dato = &item;
    insertar->sig = NULL;

    if (aux == NULL)
        this->cabeza = insertar;
    else
    {
        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = insertar;
    }
}

Canciones* Lista::obtenerDato()
{
    return this->publico->dato;
}

void Lista::volverInicio()
{
    this->publico = this->cabeza;
}

void Lista::avanzar()
{
    this->publico = this->publico->sig;
}