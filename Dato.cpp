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
    ASSIGN_IP_VALUE(this->ip);

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

void Dato::ASSIGN_IP_VALUE(string IP)
{
    uint64_t combinedValue; //Var de 64 bits para almacenar el int de la IP
    std::stringstream ss(IP);
    char dot, colon;

    // (Las variables de 16 bits luego serán cambiadas a 10, menos port)
    uint16_t oct1, oct2, oct3, oct4, port;
    ss >> oct1 >> dot >> oct2 >> dot >> oct3 >> dot >> oct4 >> colon >> port;

    // Hacemos << para "combinar" todas las partes en una variable de 64 bits
    //Usamos AND con 1024 y FFFF para asegurarnos que el tamaño sea 10 bits y 16 bits
    //10 bits por cada octeto y 16 para el puerto
    combinedValue |= (port & 0xFFFF) << 48;
    combinedValue |= (oct4 & 0x3FF) << 38;
    combinedValue |= (oct3 & 0x3FF) << 28;
    combinedValue |= (oct2 & 0x3FF) << 18;
    combinedValue |= (oct1 & 0x3FF) << 8;

    this->IP_VALUE = combinedValue;
}




