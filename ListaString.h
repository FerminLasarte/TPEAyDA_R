#ifndef TPEAYDA_R_LISTASTRING_H
#define TPEAYDA_R_LISTASTRING_H
#include <string>

using namespace std;

class ListaString {

private:

    struct nodoString {
        string generos;
        nodoString* sig;
    };

    nodoString *cabeza, *final;
    int longitud;

public:

    ListaString();
    virtual ~ListaString();

    void insertarLista(string generos);

    nodoString *publico;

    void avanzar();
};

#endif //TPEAYDA_R_LISTASTRING_H