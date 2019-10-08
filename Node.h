#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
//All the variables.
private:
    friend class LinkedList;

    std::string name;
    unsigned num_times;
    Node *next;

    //node constructor
    Node()
    {next=nullptr;}

    //overloaded constructor
    Node(std::string name);

    //destructor
    ~Node();

    std::string getName()
    { return name;  }
    void setName(std::string nom)
    { name = nom;  }

    unsigned getNum()
    { return num_times;  }
    void setNum(unsigned n)
    { num_times = n;  }

    //Just in case, get and set the next node.
    Node *getNext()
    {return next;}
    void setNext(Node* n)
    {next = n; }


};

#endif // NODE_H
