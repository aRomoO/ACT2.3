// Ivan Estrada - A01643642
#include "MyBST.h"

MyBST::MyBST(){
    this->root = nullptr;
    this->size = 0;
}

int MyBST::length(){
    return this->size;
}

bool MyBST::isEmpty(){
    return (this->root==nullptr);
}

bool MyBST::insert(int data, string ip){
    if(isEmpty()){
        this->root = new MyNodeBST(data,ip);
        this->size++;
        return true;
    }
    MyNodeBST *current = this->root;
    while(current != nullptr){
        if(data < current->data){
            if(current->left == nullptr){
                current->left = new MyNodeBST(data,ip);
                this->size++;
                return true;
            }
            current = current->left;
        }
        else{
            if(current->right == nullptr){
                current->right = new MyNodeBST(data,ip);
                this->size++;
                return true;
            }
            current = current->right;
        }
    }
    return false;
}

void MyBST::ultimos(MyNodeBST* current, int &n){
    if(current == nullptr || n <= 0){ // si nos hemos desplazado hasta un nullptr, salimos de esta recursion
        return;
    }
    ultimos(current->right,n); // nos desplazamos hasta la derecha del arbol, es decir, hasta el nodo de mayor valor
    if(n != 0){ // imprimimos la direccion ip mas accedida, si todavia no hemos impreso las direcciones la cantidad de n veces solicitadas
        cout << "La direccion Ip: " << current->IP << " intento acceder " << current->data << " veces" << endl;
        n--;
    }
    ultimos(current->left,n); // una vez verificado que no hay otro nodo a la derecha y que ya hayamos impreso el nodo actual, nos movemos al nodo izquiero, para ver si cuenta con hijos y para seguir imprimiendo valores de nodos
}

void MyBST::ultimos(int n){
    if(n > length()){
        throw invalid_argument("El numero de busqueda es mayor al numero de registros disponibles");
    }
    ultimos(this->root,n);
}