#include <iostream>
#include "Dato.h"
#include "MyBST.h"
#include <map>

using namespace std;


#define NUM_DATOS_MOSTRADOS 5


#define LINUX_PREFIX "../"

int main(){
    string line; // Var donde se almacenará la linea que se está leyendo del txt

    // leemos el archivo de texto
    cout << LINUX_PREFIX"Recolectando Datos del Archivo" << endl;

    ifstream File(LINUX_PREFIX"bitacora2.txt");

    // inicializamos el mapa donde registraremos la cantidad de veces que se repiten las direcciones ip
    map<string, int> ipMap; // como clave tenemos la direccion ip, sin el su puerto, y como valor, las n veces que se repite

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while (getline(File, line)){
        lines_num++; // Aumentar contador de lineas
        Dato *dato = new Dato(line); // convertimos la linea del archivo en un objeto tipo dato
        string strIP = dato->getIP(); // de esta manera, obtenemos la ip sin el puerto, de dicho dato
        if(ipMap.find(strIP) == ipMap.end()){
            ipMap[strIP] = 1; // si la ip no ha sido registrada en el mapa, le asignamos el valor de 1 repeticion
        }
        else{
            ipMap[strIP]++; // si la ip ya habia sido registrada en el mapa, le incrementamos en 1 la cantidad de repeticiones
        }
    }
    File.close();

    if(lines_num == 0){
        cout << "No se pudieron cargar los datos\n";
    }

    // escribimos en un nuevo archivo de texto, las distintas ips con sus respectivas repeticiones
    cout << "Mapeo" << endl;
    ofstream File2(LINUX_PREFIX"Mapeo.txt");

    // creamos un BST llamado bst, donde ingresaremos las distintas ip con sus n repeticiones
    // dichas repeticiones seran la clave de cada nodo del BST
    MyBST *bst = new MyBST();

    // para recorrer el mapa que construimos previamente, me base en la siguiente liga:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
    map<string, int>::iterator i;
    for (i = ipMap.begin(); i != ipMap.end(); i++){
        string clave = i->first;
        int valor = i->second;
        File2 << "La direccion Ip: " << clave << " intento acceder " << valor << " veces" << endl;
        bst->insert(valor, clave); // insertamos las distintas ips con sus respectivas repeticiones, en el BST
    }
    File.close(); // dejamos de escribir en el archivo

    // Buscamos las direcciones IP que mas veces trataron de ingresar
    bst->ultimos(NUM_DATOS_MOSTRADOS);

    return 0;
}