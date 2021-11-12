#include "Cancion.h"

using namespace std;

Cancion::Cancion() {
    // com
}

Cancion::Cancion(unsigned int nroCancion, string interprete, string nombreCancion, unsigned int duracion, string anio) {
    this->nroCancion = nroCancion;
    this->interprete = interprete;
    this->nombreCancion = nombreCancion;
    this->duracion = duracion;
    this->anio = anio;
    this->reproducciones = 0;
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

bool Cancion::generoPertenece(string generoABuscar) {
    listaGeneros.volverInicio();
    while ((listaGeneros.publico != nullptr) && (listaGeneros.publico->dato != generoABuscar))
        listaGeneros.avanzar();

    if (listaGeneros.publico != nullptr)
        return true;
    else return false;
}

void Cancion::agregarGenero(string &generoAAgregar) {
    this->listaGeneros.insertarLista(generoAAgregar);
}

void Cancion::setReproducciones(unsigned int reproducciones) {
    this->reproducciones = reproducciones;
}

void Cancion::imprimeDatos() {
    cout << " Numero de Cancion:    " << this->nroCancion << endl;
    cout << " Interprete:           " << this->interprete << endl;
    cout << " Nombre de la Cancion: " << this->nombreCancion << endl;
    cout << " Duracion:             " << this->duracion << endl;
    cout << " Anio de Lanzamiento:  " << this->anio << endl;
    cout << " Generos:              ";
    listaGeneros.volverInicio();
    while (listaGeneros.publico != nullptr) {
        cout << this->listaGeneros.publico->dato << " ";
        listaGeneros.avanzar();
    }
    cout << endl;
    cout << " Reproducciones        " << this->reproducciones << endl;
    cout << "--------------------------------------------------\n";
}