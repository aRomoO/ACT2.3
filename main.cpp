#include <iostream>
#include "Dato.h"
#include "LinkedList.h"

using namespace std;
int main()
{
    string line;         // Var donde se almacenará la linea que se está leyendo del txt
    LinkedList llDatos; //Linked list donde se almacenarán los datos

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;
    ifstream File("../bitacoraReducida.txt");
    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while(getline(File, line)) {
        //Insertar cada linea como un objecto dato a la Linked List
        llDatos.insertLast(new Dato(line));
        lines_num++; //Aumentar contador de lineas
    }
    File.close();

    //Imprimimos los datos tal como están en el archivo
    cout << llDatos << endl;

    //Ordenar Datos


    //Ordenar los datos
    return 0;
}
