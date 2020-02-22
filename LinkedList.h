#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

class LinkedList
{
private:
    Node* head;
    std::string win;

public:
    LinkedList();
    LinkedList(Node *next);
    ~LinkedList();

    Node* getLead()
    {return head;}

    //Add nodes + get rid of node.
    void addNode(std::string hlist);

    //prints the node.
    void printList(std::string& name);

    void RNGwinner();

};

#endif // LINKEDLIST_H

