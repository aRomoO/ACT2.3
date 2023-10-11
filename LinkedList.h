//
// Created by fredi on 7/10/23.
//

#ifndef ACT2_3_LINKEDLIST_H
#define ACT2_3_LINKEDLIST_H

#include <ostream>
#include "Dato.h"

typedef struct Node
{
    Dato *data;           // ptr to dato object
    Node *next;           // ptr to next node of the list
    Node *prev = nullptr; // ptr to previous node

    // Constructors
    explicit Node(Dato *data) : data(data) {}
    Node(Dato *data, Node *next) : data(data), next(next) {}

} Node;

class LinkedList
{
private:
    int size;
    Node *tail;
    Node *head;

public:
    // Constructors and destructors
    LinkedList();
    ~LinkedList();

    // Getters
    int length();         // O(1)
    bool isEmpty();       // O(1)
    Dato *first();        // O(1)
    Dato *last();         // O(1)
    Dato *getAt(int pos); // O(1)

    // Setters
    void insertFirst(Dato *data);       // O(1)
    void insertLast(Dato *data);        // O(1)
    void insertAt(int pos, Dato *data); // O(n)
    void swap(Node *a, Node *b);        // O(1

    void setAt(int pos, Dato *data); // O(n)
    void bubbleSort();
    bool Compara(Node *comp, Node *comp2);
    void binsearch(string inicio, string fin);
    // Removers
    /*
    void removeFirst(); //O(1)
    void removeLast(); //O(n)
    void removeAt(int pos); //O(n)*/

    // Operator overloads
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list); // O(1)
};

#endif // ACT2_3_LINKEDLIST_H
