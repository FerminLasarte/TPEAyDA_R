#include "Canciones.h"

Canciones::Canciones() {
    this->raizOrdenNombre = nullptr;
    this->arrCanciones = nullptr;
    this->actual = 0;
    this->longitud = 0;
}

Canciones::~Canciones() {
    delete[] this->arrCanciones;
}

void Canciones::setMax(int maximo) {
    this->arrCanciones = new estructura[maximo];
    this->longitud = maximo;
}

void Canciones::addCancion(Cancion &cancion) {
    this->arrCanciones[actual].dato = cancion;
    this->arrCanciones[actual].mayNombreCancion = nullptr;
    this->arrCanciones[actual].menNombreCancion = nullptr;
    actual++;
    if (actual == longitud)
        ordArrPorCriterioNombre();
}

void Canciones::ordArrPorCriterioNombre() {
    estructura *temp[longitud];

    for (int i = 0; i < longitud; i++)
        temp[i] = nullptr;
    for (int k = 0; k < longitud; k++)
    {
        int i=0;
        while ((i < longitud) && (temp[i] != nullptr) && (temp[i]->dato.obtenerNombreCancion() < arrCanciones[k].dato.obtenerNombreCancion()))
            i++;
        if (temp[i] != nullptr)
            for (int j = longitud - 1; j > i; j--)
                temp[j] = temp[j - 1];
        temp[i] = &arrCanciones[k];
    }

    this->raizOrdenNombre = orrPorNombreRecursivo(temp, 0, longitud - 1);
}

Canciones::estructura *Canciones::orrPorNombreRecursivo(estructura *arreglo[], int inicio, int fin) {
    if (inicio > fin)
        return nullptr;
    else {
        int mid = ((inicio + fin) / 2);
        arreglo[mid]->mayNombreCancion = orrPorNombreRecursivo(arreglo, mid + 1, fin);
        arreglo[mid]->menNombreCancion = orrPorNombreRecursivo(arreglo, inicio, mid - 1);
        return arreglo[mid];
    }
}

void Canciones::imprimirNorm() {
    for (int i = 0; i < longitud; i++)
        arrCanciones[i].dato.imprimeDatos();
}

void Canciones::imprimirNombreCancion() {
    imprimirNombreCancionInOrder(raizOrdenNombre);
}

void Canciones::imprimirNombreCancionInOrder(estructura *actual) {
    if (actual != nullptr) {
        imprimirNombreCancionInOrder(actual->menNombreCancion);
        actual->dato.imprimeDatos();
        imprimirNombreCancionInOrder(actual->mayNombreCancion);
    }
}

Cancion *Canciones::buscarEnArbolNombre(estructura *actual, string nombreCancion) {
    if (actual == nullptr)
        return nullptr;
    else if (actual->dato.obtenerNombreCancion() == nombreCancion)
        return &actual->dato;
    else if (actual->dato.obtenerNombreCancion() < nombreCancion)
        return buscarEnArbolNombre(actual->mayNombreCancion, nombreCancion);
    else return buscarEnArbolNombre(actual->menNombreCancion, nombreCancion);
}

void Canciones::buscarPorNombre(string nombreCancion) {
    Cancion *mostrar = buscarEnArbolNombre(raizOrdenNombre, nombreCancion);
    if (mostrar != nullptr)
        mostrar->imprimeDatos();
    else
        cout << "La cancion: " << nombreCancion << " no se encuentra en la lista." << endl;
}

bool Canciones::contiene(string cancionPorComparar, string nombreCancion) const {
    int i = 0, j = 1;
    while ((i < cancionPorComparar.size()) && (j < nombreCancion.size())) {
        j = 1;
        while ((j < nombreCancion.size()) && (i < cancionPorComparar.size()) && (cancionPorComparar[i] == nombreCancion[j])) {
            i++;
            j++;
        }
        i++;
    }

    if (j >= nombreCancion.size())
        return true;
    else return false;
}

void Canciones::busquedaLinealComodin(Lista<Cancion> &listaComodinRetorno, string nombreCancion) {
    for (int i = 0; i < longitud; i++) {
        if (contiene(arrCanciones[i].dato.obtenerNombreCancion(), nombreCancion))
            listaComodinRetorno.insertarLista(arrCanciones[i].dato);
    }
}

void Canciones::recorrerEntreRangos(Lista<Cancion> &listaCancionRetorno, string minAnio, string maxAnio) {
    for (int i = 0; i < longitud; i++)
        if ((arrCanciones[i].dato.obtenerAnio() >= minAnio) && (arrCanciones[i].dato.obtenerAnio() <= maxAnio))
            listaCancionRetorno.insertarLista(arrCanciones[i].dato);
}

void Canciones::obtenerTopTen(Lista<Cancion> &listaTopGeneros, string generoABuscar) {
    estructura *temp[longitud];

    for (int i = 0; i < longitud; i++)
        temp[i] = nullptr;
    for (int k = 0; k < longitud; k++)
    {
        int i=0;
        while ((i < longitud) && (temp[i] != nullptr) && (temp[i]->dato.obtenerReproducciones() > arrCanciones[k].dato.obtenerReproducciones()))
            i++;
        if (temp[i] != nullptr)
            for (int j = longitud - 1; j > i; j--)
                temp[j] = temp[j - 1];
        temp[i] = &arrCanciones[k];
    }

    int i = 0;
    while ((listaTopGeneros.calculaLeng() < 10) && (i < longitud)) {
        if (temp[i]->dato.generoPertenece(generoABuscar))
            listaTopGeneros.insertarLista(temp[i]->dato);
        i++;
    }
}