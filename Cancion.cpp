#include "Cancion.h"

using namespace std;

Cancion::Cancion() {
    // com
}

Cancion::Cancion(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio, list<string> listaGeneros, unsigned int reproducciones) {
    this->nroCancion = nroCancion;
    this->interprete = interprete;
    this->nombreCancion = nombreCancion;
    this->duracion = duracion;
    this->anio = anio;
    list<string>::const_iterator it = listaGeneros.begin();
    while (it != listaGeneros.end()) {
        this->listaGeneros = listaGeneros;
        it++;
    }
    this->reproducciones = reproducciones;
}

Cancion::~Cancion() {
    // ads
}

unsigned int Cancion::obtenerNroCancion() const {
    return nroCancion;
}

string Cancion::obtenerInterprete() const {
    return interprete;
}

string Cancion::obtenerNombreCancion() const {
    return nombreCancion;
}

unsigned int Cancion::obtenerDuracion() const {
    return duracion;
}

string Cancion::obtenerAnio() const {
    return anio;
}

unsigned int Cancion::obtenerReproducciones() const {
    return reproducciones;
}

void Cancion::imprimeDatos() {
    cout << " Numero de Cancion:    " << this->nroCancion << endl;
    cout << " Interprete:           " << this->interprete << endl;
    cout << " Nombre de la Cancion: " << this->nombreCancion << endl;
    cout << " Duracion:             " << this->duracion << endl;
    cout << " Anio de Lanzamiento:  " << this->anio << endl;
    cout << " Generos:              ";
    list<string>::const_iterator it = listaGeneros.begin();
    while (it != listaGeneros.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    cout << " Reproducciones        " << this->reproducciones << endl;
    cout << "--------------------------------------------------\n";
}