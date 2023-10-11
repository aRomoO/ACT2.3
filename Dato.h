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

// Struct para guardar cada octeto del ip  y el puerto con la menor cantidad de bits posibles
struct IP
{
    uint16_t oct1;
    uint16_t oct2;
    uint16_t oct3;
    uint16_t oct4;
    uint16_t port;

    void FILL_IP(std::string ip)
    {
        std::stringstream ss(ip);
        char dot, colon;

        // Extraer valores y meterlos al struct de IP
        ss >> this->oct1 >> dot >> this->oct2 >> dot >> this->oct3 >> dot >> this->oct4 >> colon >> this->port;
    }
};

class Dato
{
private:
    string mes,
        hora,
        ip,
        fallo;

    int dia;
    IP IP_VALUE;

public:
    // Constructor
    Dato(string line);

    // Getters
    int getIP();
    int getOcteto(int index);
    string getMes() const;
    int getDia();
    const string &getHora() const;

    // Operator overload
    friend ostream &operator<<(ostream &os, Dato &d)
    {
        os << d.mes << " " << d.dia << " " << d.hora << " " << d.ip << " " << d.fallo;
        return os;
    }
};

#endif // ACT2_3_DATO_H
