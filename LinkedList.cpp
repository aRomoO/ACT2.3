//
// Created by fredi on 7/10/23.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->size = 0;
    this->head = this->tail = nullptr;
}
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Getters
int LinkedList::length()
{
    return this->size;
}
bool LinkedList::isEmpty()
{
    return this->size == 0;
}
Dato *LinkedList::first()
{
    if (this->size != 0)
    {
        return this->head->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el primer valor de una lista vacía");
    }
}
Dato *LinkedList::last()
{
    if (size != 0)
    {
        return this->tail->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el último valor de una lista vacía");
    }
}
Dato *LinkedList::getAt(int pos)
{
    // Checar que la lista no esté vacía y la posición esté entre [0,lenght]
    if (!(this->length() != 0 && pos >= 0 && pos <= this->length() - 1))
    {
        throw invalid_argument("Position out of bounds");
    }
    Node *current = this->head;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    return current->data;
}

// Inserts
void LinkedList::insertFirst(Dato *data)
{ // Used only if list is empty
    this->head = new Node(data, this->head);
    this->head->prev = nullptr; // si es el primer elemento, su previo es un nullptr
    this->size++;
    if (size == 1)
    {
        // Si solo hay un elemento, head y tail son el mismo nodo
        this->tail = this->head;
    }
}
void LinkedList::insertLast(Dato *data)
{
    // Si la lista está vacía, usamos insertFirst
    if (this->size == 0)
    {
        this->insertFirst(data);
    }

    else
    {
        // Crear nuevo ultimo nodo y ligarlo con el penultimo
        this->tail->next = new Node(data);

        // ligar ultimo con penultimo
        this->tail->next->prev = this->tail;

        this->tail = this->tail->next; // asignamos tail al actual nuevo ultimo
        this->tail->data = data;       // asignamos data a el ultimo elemento
        this->size++;
    }
}
void LinkedList::insertAt(int pos, Dato *data)
{
    // Si la  posicion es negativa o mayor que la lista, throw error
    if (pos < 0 || pos > (this->size))
    {
        throw invalid_argument("Position out of bounds");
    }

    // Si la pos es 0, usar insertFirst
    else if (pos == 0)
    {
        this->insertFirst(data);
    }

    // Si es la última, usar insertLast
    else if (pos == this->size)
    {
        this->insertLast(data);
    }

    // Si tenemos que insertar entre el nodo 2 y n-1
    else
    {

        Node *currentPtr = head;          // Ptr para recorrer la lista
        for (int i = 0; i < pos - 1; i++) // POS -1 Para seleccionar el nodo anterior y poder ligar los nodos
        {
            currentPtr = currentPtr->next;
        }

        // Guardar posicion del nodo a insertar + 1 en un temp
        Node *temp = currentPtr->next;

        // Insertar nuevo nodo
        Node *newNode = new Node(data, temp);

        currentPtr->next = newNode;

        // ligar nodo insertado con nodo previo
        newNode->prev = currentPtr;
        // ligar nodo insertado + 1 con nodo insertado
        temp->prev = newNode;

        this->size++;
    }
}
void LinkedList::setAt(int pos, Dato *data)
{
    if (pos < 0 || pos > this->size - 1)
    {
        throw invalid_argument("Position out of bounds");
    }

    Node *current = this->head; // Ptr para recorrer la  lista
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    current->data = data;
}

bool LinkedList::Compara(Node *a, Node *b)
{
    for (int i = 1; i <= 5; i++)
    {
        if (a->data->getOcteto(i) > b->data->getOcteto(i))
        {
            swap(a, b);
            return 0;
        }
        else if (a->data->getOcteto(i) < b->data->getOcteto(i))
        {
            return 1;
        }
    }
    return 0;
}

void LinkedList::swap(Node *a, Node *b)
{
    Dato *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void LinkedList::bubbleSort()
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (Compara(ptr1, ptr1->next))
            {
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void LinkedList::binsearch(string inicio, string fin)
{
    int inicio_oct1, fin_oct1;
    std::stringstream ssini(inicio);
    ssini >> inicio_oct1;
    std::stringstream ssfin(fin);
    ssfin >> fin_oct1;

    // queremos encontrar el primer nodo que tenga el octeto 1 mayor o igual a inicio_oct1, por medio de busqueda binaria
    // y guardaremos la direccion de memoria de ese nodo en un puntero
    Node *inicio_ptr = this->head;
    int inicio_index = 0;
    int inicio_left = 0;
    int inicio_right = this->size - 1;
    int inicio_mid = 0;
    while (inicio_left <= inicio_right)
    {
        inicio_mid = (inicio_left + inicio_right) / 2;
        if (inicio_ptr->data->getOcteto(1) == inicio_oct1)
        {
            break;
        }
        else if (inicio_ptr->data->getOcteto(1) < inicio_oct1)
        {
            inicio_left = inicio_mid + 1;
        }
        else
        {
            inicio_right = inicio_mid - 1;
        }
        inicio_ptr = inicio_ptr->next;
        inicio_index++;
    }

    // queremos encontrar el primer nodo que tenga el octeto 1 mayor o igual a fin_oct1, por medio de busqueda binaria
    // y guardaremos la direccion de memoria de ese nodo en un puntero
    Node *fin_ptr = this->head;
    int fin_index = 0;
    int fin_left = 0;
    int fin_right = this->size - 1;
    int fin_mid = 0;
    while (fin_left <= fin_right)
    {
        fin_mid = (fin_left + fin_right) / 2;
        if (fin_ptr->data->getOcteto(1) == fin_oct1)
        {
            break;
        }
        else if (fin_ptr->data->getOcteto(1) < fin_oct1)
        {
            fin_left = fin_mid + 1;
        }
        else
        {
            fin_right = fin_mid - 1;
        }
        fin_ptr = fin_ptr->next;
        fin_index++;
    }

    // ahora que tenemos los punteros de inicio y fin, podemos recorrer la lista desde inicio_ptr hasta fin_ptr
    // modificamos la lista original para que solo tenga los nodos que cumplen con la condicion
    Node *current = inicio_ptr;
    for (int i = inicio_index; i < fin_index; i++)
    {
        current = current->next;
    }
    this->head = inicio_ptr;
    this->tail = current;
    this->size = fin_index - inicio_index + 1;
}

void LinkedList::linearsearch(string inicio, string fin)
{
    int inicio_oct1, fin_oct1;
    std::stringstream ssini(inicio);
    ssini >> inicio_oct1;
    std::stringstream ssfin(fin);
    ssfin >> fin_oct1;

    // queremos encontrar el primer nodo que tenga el octeto 1 mayor o igual a inicio_oct1, por medio de busqueda lineal
    // y guardaremos la direccion de memoria de ese nodo en un puntero
    Node *inicio_ptr = this->head;
    int inicio_index = 0;
    while (inicio_ptr->data->getOcteto(1) < inicio_oct1)
    {
        inicio_ptr = inicio_ptr->next;
        inicio_index++;
    }

    // queremos encontrar el primer nodo que tenga el octeto 1 mayor o igual a fin_oct1, por medio de busqueda lineal
    // y guardaremos la direccion de memoria de ese nodo en un puntero
    Node *fin_ptr = this->head;
    int fin_index = 0;
    while (fin_ptr->data->getOcteto(1) < fin_oct1)
    {
        fin_ptr = fin_ptr->next;
        fin_index++;
    }

    // ahora que tenemos los punteros de inicio y fin, podemos recorrer la lista desde inicio_ptr hasta fin_ptr
    // modificamos la lista original para que solo tenga los nodos que cumplen con la condicion
    Node *current = inicio_ptr;
    for (int i = inicio_index; i < fin_index; i++)
    {
        current = current->next;
    }
    this->head = inicio_ptr;
    this->tail = current;
    this->size = fin_index - inicio_index + 1;
}
// Removes

// Operator overloads
ostream &
operator<<(ostream &os, const LinkedList &list)
{
    Node *current = list.head;
    for (int i = 0; i < list.size; i++)
    {
        os << (*current->data) << endl;
        current = current->next;
    }

    return os;
}
