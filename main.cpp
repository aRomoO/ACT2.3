#include <iostream>
#include "Dato.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    string line;                    // Var donde se almacenará la linea que se está leyendo del txt
    LinkedList llDatos, sortedList; // Linked list donde se almacenarán los datos

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;

    ifstream File("bitacora.txt");

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while (getline(File, line))
    {
        // Insertar cada linea como un objecto dato a la Linked List
        llDatos.insertLast(new Dato(line));
        lines_num++; // Aumentar contador de lineas
        // imprimir la ip de cada linea
    }
    File.close();

    if (lines_num == 0)
    {
        cout << "no se pudieron cargar los datos\n";
    }

    // Imprimimos los datos tal como están en el archivo
    // Ordenamos los datos
    cout << "Ordenando Datos" << endl;
    llDatos.bubbleSort();
    cout << "Datos Ordenados" << endl;
    // cout << llDatos << endl;

    // Imprimimos los datos ordenados


    // Guardamos los datos ordenados en un nuevo archivo
    cout << "Guardando Datos Ordenados" << endl;
    ofstream File2("bitacora_ordenada.txt");
    File2 << llDatos;
    File2.close();

    bool continuar = true;
    int nbusquedas = 0;
    while (continuar)
    {
        string inicio, fin;
        cout << "Ingresa la IP del inicio de la busqueda: ";
        cin >> inicio;
        cout << "Ingresa la IP del final de la busqueda: ";
        cin >> fin;

        LinkedList busqueda = llDatos;

        busqueda.linearsearch(inicio, fin);

        cout << "Guardando Busqueda" << endl;
        nbusquedas++;
        ofstream File3("salidaN-Eq");
        File3 << busqueda;
        File3.close();

        cout << "Busqueda Guardada" << endl;
        cout << "Desea realizar otra busqueda? (1 = si, 0 = no): ";
        cin >> continuar;

        if (continuar == 0)
        {
            cout << "Numero de busquedas realizadas: " << nbusquedas << endl;
        }
    }

    return 0;
}
