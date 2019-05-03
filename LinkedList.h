#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

class LinkedList
{
private:
    Node* head;

public:
    LinkedList();
    LinkedList(Node *next);
    ~LinkedList();

    Node* getLead()
    {return head;}

    //Add nodes + get rid of node.
    void addNode(Node* newNode);

    //prints the node.
    void printList(std::string &winner);

    void RNGwinner(std::string &win);

};

#endif // LINKEDLIST_H

