#include <iostream>
#include <string>
#include "Canciones.h"

using namespace std;


Canciones::Canciones() {

}

Canciones::Canciones(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, string generos, unsigned int reproducciones) {

    this->nroCancion = nroCancion;
    this->interprete = interprete;
    this->nombreCancion = nombreCancion;
    this->duracion = duracion;
    this->anio = anio;
    this->generos = generos;
    this->reproducciones = reproducciones;
}

Canciones::~Canciones() {
    //comentario
}

unsigned int Canciones::obtenerNroCancion() const {
    return nroCancion;
}

string Canciones::obtenerInterprete() const {
    return interprete;
}

string Canciones::obtenerNombreCancion() const {
    return nombreCancion;
}

unsigned int Canciones::obtenerDuracion() const {
    return duracion;
}

string Canciones::obtenerAnio() const {
    return anio;
}

string Canciones::obtenerGeneros() const {
    return generos;
}

unsigned int Canciones::obtenerReproducciones() const {
    return reproducciones;
}

void Canciones::imprimeDatos()
{
    cout << " Numero de Cancion:    " << this->nroCancion << endl;
    cout << " Interprete:           " << this->interprete << endl;
    cout << " Nombre de la Cancion: " << this->nombreCancion << endl;
    cout << " Duracion:             " << this->duracion << endl;
    cout << " Año de Lanzamiento:   " << this->anio << endl;
    cout << " Generos:              " << this->generos << endl;
    cout << " Reproducciones        " << this->reproducciones << endl;
    cout << "--------------------------------------------------\n";
}