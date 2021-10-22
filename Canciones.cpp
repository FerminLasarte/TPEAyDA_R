#include <iostream>
#include <string>
#include "Canciones.h"

using namespace std;


Canciones::Canciones() {
    // comentario
}

Canciones::Canciones(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, string generos[], unsigned int reproducciones) {

    this->nroCancion = nroCancion;
    this->interprete = interprete;
    this->nombreCancion = nombreCancion;
    this->duracion = duracion;
    this->anio = anio;
    for (int i = 0; i < 10; i++)
        this->generos[i] = generos[i];
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

string Canciones::obtenerGeneros(int i) const {
    if ((i >= 0) && (i<=10))
        return generos[i];
    else return "genero invalido";
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
    cout << " Anio de Lanzamiento:  " << this->anio << endl;
    cout << " Generos:              ";
    for (int i = 0; i < 10; i++)
         cout << this->generos[i] << " ";
    cout << endl;
    cout << " Reproducciones        " << this->reproducciones << endl;
    cout << "--------------------------------------------------\n";
}