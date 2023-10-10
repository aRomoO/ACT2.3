#include <iostream>
#include "Dato.h"
#include "LinkedList.h"

using namespace std;

int partition(LinkedList &llDatos, int low, int high)
{
    Dato *pivot = llDatos.getAt(high);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (llDatos.getAt(j) < pivot)
        {
            i++;
            llDatos.swap(i, j);
        }
    }
    llDatos.swap(i + 1, high);
    return i + 1;
}

void quicksort(LinkedList &llDatos, int low, int high)
{
    if (low < high)
    {
        int pivotPos = partition(llDatos, low, high);

        quicksort(llDatos, low, pivotPos - 1);
        quicksort(llDatos, pivotPos + 1, high);
    }
}

int main()
{
    string line;        // Var donde se almacenará la linea que se está leyendo del txt
    LinkedList llDatos; // Linked list donde se almacenarán los datos

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
    }
    File.close();

    // Imprimimos los datos tal como están en el archivo
    cout << llDatos << endl;

    // Ordenamos los datos
    cout << "Ordenando Datos" << endl;
    quicksort(llDatos, 0, llDatos.length() - 1);

    // Imprimimos los datos ordenados
    cout << llDatos << endl;

    // Guardamos los datos ordenados en un nuevo archivo
    cout << "Guardando Datos Ordenados" << endl;
    ofstream File2("bitacora_ordenada.txt");
    File2 << llDatos;
    File2.close();

    return 0;
}
