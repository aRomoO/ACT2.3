//
// Created by fredi on 7/10/23.
//

#ifndef ACT2_3_DATO_H
#define ACT2_3_DATO_H


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

//Struct para guardar cada octeto del ip  y el puerto con la menor cantidad de bits posibles

class Dato{
private:
    string  mes,
            hora,
            ip,
            fallo;

    int dia;
    uint64_t IP_VALUE;

public:
    //Constructor
    Dato(string line);

    //Getters
    string getMes() const;
    int getDia();
    const string &getHora() const;
    //Utilities
    void ASSIGN_IP_VALUE(string IP);
    //Operator overload
    friend ostream& operator<<(ostream& os, Dato& d){
        os << d.mes << " " << d.dia << " " << d.hora << " " << d.ip << " " << d.fallo;
        return os;
    }
};



#endif //ACT2_3_DATO_H
