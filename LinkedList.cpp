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

void LinkedList::swap(int pos1, int pos2)
{
    if (pos1 < 0 || pos1 > this->size - 1 || pos2 < 0 || pos2 > this->size - 1)
    {
        throw invalid_argument("Position out of bounds");
    }

    Node *current = this->head; // Ptr para recorrer la  lista
    for (int i = 0; i < pos1; i++)
    {
        current = current->next;
    }
    Node *current2 = this->head; // Ptr para recorrer la  lista
    for (int i = 0; i < pos2; i++)
    {
        current2 = current2->next;
    }

    Dato *temp = current->data;
    current->data = current2->data;
    current2->data = temp;
}

// Removes

// Operator overloads
ostream &operator<<(ostream &os, const LinkedList &list)
{
    Node *current = list.head;
    for (int i = 0; i < list.size; i++)
    {
        os << (*current->data) << endl;
        current = current->next;
    }

    return os;
}
