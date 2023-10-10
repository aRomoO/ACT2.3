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

    // Imprimimos los datos tal como están en el archivo
    // Ordenamos los datos
    cout << "Ordenando Datos" << endl;
    llDatos.bubbleSort();
    cout << "Datos Ordenados" << endl;
    cout << llDatos << endl;

    // Imprimimos los datos ordenados

    // Guardamos los datos ordenados en un nuevo archivo
    cout << "Guardando Datos Ordenados" << endl;
    ofstream File2("bitacora_ordenada.txt");
    File2 << llDatos;
    File2.close();

    return 0;
}
