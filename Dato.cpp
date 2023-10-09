#include "Dato.h"


Dato::Dato(string line) {
    // obtenemos la linea de texto del archivo .txt
    stringstream ss(line);
    string substr;
    vector<string> info;
    // separamos por espacios los datos de dicha linea
    while (getline(ss, substr, ' ')) {
        info.push_back(substr);
        // Despues de almacenar la ip, el texto restante lo almacenamos como la razon de fallo
        if (info.size() > 4) {
            this->fallo = this->fallo + substr + " ";
        }

    }
    this->mes = info[0];
    this->dia = stoi(info[1]);
    this->hora = info[2];
    this->ip = info[3];

    //Meter ip a su Struct
    IP_VALUE.FILL_IP(this->ip);

}

int Dato::getDia(){
    return this->dia;
}

string Dato::getMes() const {
    return mes;
}

const string &Dato::getHora() const {
    return hora;
}




