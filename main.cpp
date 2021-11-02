#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <clocale>
#include <cstdio>
#include <cctype>
#include <list>
#include "Canciones.h"
#include "Lista.h"

// COMO LEER CANCIONES EN MINUSCULA
// COMODINES LIBRES
// SOLUCIONAR MODULARIZACION BUSQUEDA BINARIA

using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
Canciones* procesar_archivo_entrada(string origen, int& arrFrontera)
{
    int i = 0;
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_canciones = atoi(linea.c_str());
        arrFrontera = cantidad_canciones;
        auto* arrCanciones = new Canciones[cantidad_canciones];

        //Leemos de una linea completa por vez (getline).
        int nroCancion = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            int idCancion = 1;

            //Informacion entre pos_inicial y pos_final
            string interprete = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nombreCancion = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int duracion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string anio = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posición del separador ;
            //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);

            string generos = lst_generos.substr(1, lst_generos.size()-2);
            //string listaGeneros[10];
            list<string> listaGeneros;
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                listaGeneros[nroGenero] = generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos);
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int reproducciones = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            Canciones canciones(nroCancion, interprete, nombreCancion, duracion, anio, listaGeneros, reproducciones);
            arrCanciones[i] = canciones;
            i++;
            nroCancion++;
        }
        return arrCanciones;
    }
    return nullptr;
}

// struct para el arreglo ordenado por nombreCancion para asi realizar busqueda binaria;
struct tsegArreglo
{
    unsigned int nroCancion{};
    string interprete;
    string nombreCancion;
    unsigned int duracion{};
    string anio;
    string generos[10];
    unsigned int reproducciones{};
};

// procedimiento que imprime un arreglo de principio a fin de longitud n;
void imprimeArr(Canciones arrCanciones[], int& arrFrontera) {

    cout << "--------------------------------------------------\n";
    for (int i = 0; i < arrFrontera; i++)
        arrCanciones[i].imprimeDatos();
}

// procedimiento que inicializa un arreglo de principio a fin de longitud n;
void inicArregloNombreCancion(tsegArreglo arrNombreCancion[], int arrFrontera) {

    for (int i = 0; i < arrFrontera; i++) {
        arrNombreCancion[i].nroCancion = -1;
        arrNombreCancion[i].interprete = ' ';
        arrNombreCancion[i].nombreCancion = ' ';
        arrNombreCancion[i].duracion = -1;
        arrNombreCancion[i].anio = ' ';
        for (int n = 0; n < 10; n++)
            arrNombreCancion[n].generos[n] = ' ';
        arrNombreCancion[i].reproducciones = 0;
    }
}

// procedimiento que ordena un arreglo por un criterio, en este caso por nombreCancion;
void ordArrNombreCancion(Canciones arrCanciones[], tsegArreglo arrNombreCancion[], int arrFrontera) {

    for (int i = 0; i < arrFrontera; i++) {
        int j = 0;

        while ((j < arrFrontera) && (arrNombreCancion[j].nombreCancion != " ") && (arrNombreCancion[j].nombreCancion < arrCanciones[i].obtenerNombreCancion()))
            j++;

        if (arrNombreCancion[j].nombreCancion != " ") {
            for (int f = arrFrontera - 1; f > j; f--) {
                arrNombreCancion[f] = arrNombreCancion[f - 1];
            }
        }

        arrNombreCancion[j].nroCancion = arrCanciones[i].obtenerNroCancion();
        arrNombreCancion[j].interprete = arrCanciones[i].obtenerInterprete();
        arrNombreCancion[j].nombreCancion = arrCanciones[i].obtenerNombreCancion();
        arrNombreCancion[j].duracion = arrCanciones[i].obtenerDuracion();
        arrNombreCancion[j].anio = arrCanciones[i].obtenerAnio();
        for (int n = 0; n < 10; n++)
            arrNombreCancion[j].generos[n] = arrCanciones[n].obtenerGeneros(n);
        arrNombreCancion[j].reproducciones = arrCanciones[i].obtenerReproducciones();
    }
}

// procedimiento que realiza busqueda binaria en un arreglo;
void busquedaBinaria(tsegArreglo arrNombreCancion[], const string& nombreCancion, int arrFrontera) {

    int min = 0;
    int max = arrFrontera - 1;
    bool encontrado = false;

    while ((min <= max) && (!encontrado))
    {
        if (arrNombreCancion[(min + max) / 2].nombreCancion == nombreCancion)
            encontrado = true;
        else {
            if (arrNombreCancion[(min + max) / 2].nombreCancion < nombreCancion)
                min = ((min + max) / 2) + 1;
            else
                max = ((min + max) / 2) - 1;
        }
    }

    if (encontrado) {
        cout << endl;
        cout << "-----------------------------------------------------\n";
        cout << "La cancion ingresada existe: " << arrNombreCancion[(min + max) / 2].nroCancion << endl;
        cout << "Interprete:     " << arrNombreCancion[(min + max) / 2].interprete << endl;
        cout << "Duracion:       " << arrNombreCancion[(min + max) / 2].duracion << endl;
        cout << "Anio:           " << arrNombreCancion[(min + max) / 2].anio << endl;
        cout << "Generos:        ";
        for (int i = 0; i < 10; i++)
            cout << arrNombreCancion[(min + max) / 2].generos[i] << " ";
        cout << endl;
        cout << "Reproducciones: " << arrNombreCancion[(min + max) / 2].reproducciones << endl;
        cout << "-----------------------------------------------------\n";
    }
    else
    {
        cout << endl;
        cout << "-----------------------------------------------------\n";
        cout << "La cancion ingresada no se encuentra en la lista." << endl;
        cout << "-----------------------------------------------------\n";
    }
}

void cuentaCaracteres(char cancionUser[], int& contadorCaracteres) {

    for (int i = 1; i <= 49 /* max - 1 */ ; i++) {
        if (cancionUser[i] == ' ') {
            i = 49;
            contadorCaracteres--;
        }
        else
            contadorCaracteres++;
    }
}

// POSIBLES SOLUCIONES ENCUENTRA SECUENCIA PARA COMODINES SERVICIO 1
void encuentraSec(char cancionUser[], char arrCharCancion[], int& arrFrontera, int& inicSec, int& contadorCaracteres, bool& found) {

    found = true;
    for (int i = 0; i <= (contadorCaracteres); i++) {
        if (arrCharCancion[inicSec + i - 1] != cancionUser[i])
            found = false;
    }
}

void buscarSec(string cancionesEncontradras[], char cancionUser[], char arrCharCancion[], int& arrFrontera, int& inicSec, int& contadorCaracteres, bool& found, string& stringCancion) {

    inicSec = 1;
    found = false;

    while ((inicSec <= (50 - contadorCaracteres + 1)) && (!found)) {
        encuentraSec(cancionUser, arrCharCancion, arrFrontera, inicSec, contadorCaracteres, found);
        cout << "stringCancion: " << stringCancion << endl;
        cout << "found: " << found << endl;
        if (!found) {
            inicSec++;
            cout << "inic sec: " << inicSec << endl;
        }
    }

    int indiceCancion = 0;
    if (found) {
        cancionesEncontradras[indiceCancion] = stringCancion;
        indiceCancion++;
    }
}

void stringToCharArr(Canciones arrCanciones[], char arrCharCancion[], int& arrFrontera, int avanzaArr, string& stringCancion) {

    stringCancion = arrCanciones[avanzaArr].obtenerNombreCancion();
    strcpy(arrCharCancion, stringCancion.c_str());
}

void buscarEnArrWord(Canciones arrCanciones[], string cancionesEncontradas[], char arrCharCancion[], char cancionUser[], int inicSec, int& contadorCaracteres, bool found, int& arrFrontera, int avanzaArr, string stringCancion) {

    for (avanzaArr = 0; avanzaArr < arrFrontera; avanzaArr++) {
        stringToCharArr(arrCanciones, arrCharCancion, arrFrontera, avanzaArr, stringCancion);
        buscarSec(cancionesEncontradas, cancionUser, arrCharCancion, arrFrontera, inicSec, contadorCaracteres, found, stringCancion);
    }
}

void imprimeArregloComodinWord(string cancionesEncontradas[], int& arrFrontera) {

    cout << "--------------------------------------------------\n";
    for (int i = 0; i < arrFrontera; i++)
        cout << cancionesEncontradas[i] << endl;
}

// funcion que retorna una Lista que recorre entre 2 rangos (min y max) ingresados por teclado;
Lista recorrerEntreRangos(Canciones arrCanciones[], int& arrFrontera, const string& minAnio, const string& maxAnio) {

    Lista listaCanciones;

    for (int i = 0; i < arrFrontera; i++)
    {
        if ((arrCanciones[i].obtenerAnio() >= minAnio) && (arrCanciones[i].obtenerAnio() <= maxAnio))
            listaCanciones.insertarLista(arrCanciones[i]);
    }
    cout << "--------------------------------------------------\n";
    return listaCanciones;
}

// procedimiento dedicado a mostrar un menu para elegir una opcion a realizar;
void showMenu() {

    cout << endl;
    cout << "-----------Elija la opcion a realizar.-----------" << endl;
    cout << "1. Mostrar el listado completo de canciones." << endl;
    cout << "2. Verificar si existe una cancion." << endl;
    cout << "3. Listar todos las canciones lanzadas en algun rango de anios en particular." << endl;
    cout << endl;
}

// procedimiento con un switch que corresponde a realizar la opcion ingresada por teclado;
void opciones(Canciones arrCanciones[], tsegArreglo arrNombreCancion[], int& arrFrontera) {

    char seguir;
    char nombreCancion[50];
    char aux[1];
    int opcion = 0;

    while (opcion != -1) {
        showMenu();
        seguir = 's';
        cout << "   Seleccione una opcion. Si quiere terminar, ingrese -1: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                imprimeArr(arrCanciones, arrFrontera);
                break;
            }
            case 2: {
                // faltan comodines.

                inicArregloNombreCancion(arrNombreCancion, arrFrontera);
                ordArrNombreCancion(arrCanciones, arrNombreCancion, arrFrontera);
                for (int i = 0; i < 49; i++)
                    nombreCancion[i] = ' ';

                while ((seguir == 's') || (seguir == 'S')) {
                    cout << "   Elija una cancion de la lista. " << endl;
                    cout << "   Para utilizar comodines, ingrese un '*' o un '?' para buscar por palabras o caracteres respectivamente." << endl;
                    cout << "   Nombre de la cancion: ";
                    cin.getline(aux, 1);
                    cin.getline(nombreCancion, 50);

                    int inicSec;
                    int contadorCaracteres;
                    bool found;
                    int avanzaArr;
                    char arrCharCancion[50];
                    string stringCancion;
                    string cancionesEncontradas[arrFrontera];

                    if (nombreCancion[0] == '*') {
                        cuentaCaracteres(nombreCancion, contadorCaracteres);
                        buscarEnArrWord(arrCanciones, cancionesEncontradas, arrCharCancion, nombreCancion, inicSec, contadorCaracteres, found, arrFrontera, avanzaArr, stringCancion);
                        imprimeArregloComodinWord(cancionesEncontradas, arrFrontera);
                    }

                    /*if (nombreCancion[1] == '?')
                        buscarEnArrChar();*/

                    //busquedaBinaria(arrNombreCancion, nombreCancion, arrFrontera);

                    cout << endl;
                    cout << "    Desea ingresar otra cancion?. Su respuesta (s/S): ";
                    cin >> seguir;
                    if ((seguir != 's') && (seguir != 'S'))
                        cout << "    Muchas gracias!" << endl;
                }
                break;
            }
            case 3: {
                while ((seguir == 's') || (seguir == 'S')) {

                    string minAnio, maxAnio;

                    cout << "   Ingrese dos valores como rangos de anios." << endl;
                    cout << "   Anio Menor: ";
                    cin >> minAnio;
                    cout << "   Anio Mayor: ";
                    cin >> maxAnio;
                    cout << endl;

                    while (minAnio > maxAnio)
                    {
                        cout << "   Datos ingresados incorrectos. Ingrese nuevamente." << endl;
                        cout << "   Anio Menor: ";
                        cin >> minAnio;
                        cout << "   Anio Mayor: ";
                        cin >> maxAnio;
                    }

                    Lista auxLista = recorrerEntreRangos(arrCanciones, arrFrontera, minAnio, maxAnio);
                    auxLista.volverInicio();

                    if (auxLista.publico == nullptr)
                        cout << "   No se ha encontrado ninguna cancion entre el rango asignado." << endl;
                    else
                        while (auxLista.publico != nullptr) {
                            auxLista.publico->dato->imprimeDatos();
                            auxLista.avanzar();
                        }

                    cout << endl;
                    cout << "   Desea ingresar otros rangos de anios?. Su respuesta (s/S): ";
                    cin >> seguir;
                    if ((seguir != 's') && (seguir != 'S'))
                        cout << "   Muchas gracias!" << endl;
                }
                break;
            }
            case 4: {
                while ((seguir == 's') || (seguir == 'S')) {

                    // servicio generos
                }
            }
            default: {
                if (opcion != -1)
                    cout << "   La opcion ingresada es incorrecta...\n";
                break;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode

    int arrFrontera;

    Lista listaCanciones;
    Canciones* arrCanciones = procesar_archivo_entrada("canciones.csv", arrFrontera);
    auto* arrNombreCancion = new tsegArreglo[arrFrontera];
    opciones(arrCanciones, arrNombreCancion, arrFrontera);

    delete[] arrCanciones;
    delete[] arrNombreCancion;
    return 0;
}