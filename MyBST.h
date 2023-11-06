// Ivan Estrada - A01643642
#ifndef MYBST_H
#define MYBST_H

#include <iostream>
#include "Dato.h"
using namespace std;

struct MyNodeBST{
    int data;
    string IP;
    MyNodeBST *left, *right;
    MyNodeBST(int data, string ip){
        this->data=data;
        this->IP=ip;
        this->left=this->right=nullptr;
    }
};

class MyBST{
private:
    int size;
    MyNodeBST* root;
public:
    MyBST();
    int length();
    bool isEmpty();
    bool insert(int data, string ip);//true si lo inserto o no

    void ultimos(MyNodeBST* current, int &n);
    void ultimos(int n);
};

#endif