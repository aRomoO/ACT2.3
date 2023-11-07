#include <iostream>
#include "Dato.h"
#include "MyBST.h"
#include <map>
#include <vector>

using namespace std;

#define LINUX_PREFIX "./"

int main()
{
    string line; // Var donde se almacenará la linea que se está leyendo del txt

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;

    ifstream File(LINUX_PREFIX"bitacora2.txt");

    // inicializamos el mapa donde registraremos la cantidad de veces que se repiten las direcciones ip
    map<string, int> ipMap; // como clave tenemos la direccion ip, sin el su puerto, y como valor, las n veces que se repite
    // inicializamos el vector donde registraremos las distintas lineas del archivo de texto
    vector<Dato *> Datos; // cada elemento del vector, sera una linea del archivo de texto

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while (getline(File, line)){
        Datos.push_back(new Dato(line)); // agregamos la linea de la bitacora al vector
        string strIP = Datos[lines_num]->getIpNoPort(); // obtenemos la ip del primer dato del vector
        if(ipMap.find(strIP) == ipMap.end()){
            ipMap[strIP] = 1; // si la ip no ha sido registrada en el mapa, le asignamos el valor de 1 repeticion
        }
        else{
            ipMap[strIP]++; // si la ip ya habia sido registrada en el mapa, le incrementamos en 1 la cantidad de repeticiones
        }
        lines_num++; // Aumentar contador de lineas
    }
    File.close();

    if(lines_num == 0){
        cout << "No se pudieron cargar los datos\n";
    }

    cout << "Ordenando los datos de la bitacora " << endl;
    // ordenamos los datos de la bitacora por direcciones ip con un quicksort
    //quickSort();
    cout << "Se ordenaron los datos de la bitacora correctamente" << endl;

    ofstream File2("bitacoraOrdenadaIP-Eq7-BST.txt");
    for(int i = 0; i < Datos.size()-1; i++){
        File2 << *Datos[i];
    }
    File2.close();


    // creamos un BST llamado bst, donde ingresaremos las distintas ip con sus n repeticiones
    // dichas repeticiones seran la clave de cada nodo del BST
    MyBST *bst = new MyBST(); 

    // para recorrer el mapa que construimos previamente, me base en la siguiente liga:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
    map<string, int>::iterator i;
    for (i = ipMap.begin(); i != ipMap.end(); i++){
        string clave = i->first;
        int valor = i->second;
        bst->insert(valor, clave); // insertamos las distintas ips con sus respectivas repeticiones, en el BST
    }

    cout << "Imprimiendo las direcciones IP de la bitacora mas repetidas" << endl;
    // Buscamos las direcciones IP que mas veces trataron de ingresar
    bst->ultimos(5);

    return 0;
}
