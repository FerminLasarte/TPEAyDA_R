#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Cancion.h"
#include "Canciones.h"

using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen, Canciones &conjunto)
{
    int i = 0;
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_canciones = atoi(linea.c_str());
        conjunto.setMax(cantidad_canciones);
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
            Lista<string> listaGeneros;
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                listaGeneros.insertarLista(generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos));
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }
            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int reproducciones = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            Cancion tCancion(nroCancion, interprete, nombreCancion, duracion, anio, listaGeneros, reproducciones);
            conjunto.addCancion(tCancion);
            nroCancion++;
        }
    }
}

void compruebaValores(string minAnio, string maxAnio) {
    while (minAnio > maxAnio) {
        cout << "   Datos ingresados incorrectos. Ingrese nuevamente." << endl;
        cout << "   Anio Menor: ";
        cin >> minAnio;
        cout << "   Anio Mayor: ";
        cin >> maxAnio;
    }
}

void showMenu() {
    cout << endl;
    cout << "-----------Elija la opcion a realizar.-----------" << endl;
    cout << "1. Mostrar el listado completo de canciones." << endl;
    cout << "2. Verificar si existe una cancion." << endl;
    cout << "3. Listar todos las canciones lanzadas en algun rango de anios en particular." << endl;
    cout << endl;
}

void opciones(Canciones &conjunto) {
    int opcion = 0;
    string nombreCancion, genero;
    char seguir;

    while (opcion != -1) {
        showMenu();
        seguir = 's';
        cout << "   Seleccione una opcion. Si quiere terminar, ingrese -1: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                conjunto.imprimirNorm();
                break;
            }
            case 2: {
                // faltan comodines
                while ((seguir == 's') || (seguir == 'S')) {
                    cout << "   Elija una cancion de la lista. " << endl;
                    cout << "   Para utilizar comodines, ingrese un '*' o un '?' para buscar por palabras o caracteres respectivamente." << endl;
                    cout << "   Nombre de la cancion: ";
                    cin.ignore();
                    getline(cin, nombreCancion);
                    cout << endl;

                    conjunto.buscarPorNombre(nombreCancion);

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

                    compruebaValores(minAnio, maxAnio);

                    Lista auxLista = conjunto.recorrerEntreRangos();
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
                    cout << "   Elija un genero de la lista: " << endl;
                    cin.ignore();
                    getline(cin, genero);
                    cout << endl;
                }
                break;
            }
            default: {
                if (opcion != -1)
                    cout << "   La opcion ingresada es incorrecta...\n";
                break;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode

    Canciones conjunto;
    procesar_archivo_entrada("canciones.csv", conjunto);
    opciones(conjunto);
    return 0;
}