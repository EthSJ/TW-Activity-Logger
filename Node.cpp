#include "Node.h"
//Overloaded constructor. Simply sets all coeffcients.
Node::Node(std::string nom)
{
    name = nom;
    num_times = 1;
    next = nullptr;
}

//Deconstructor. Error messages due current functionallity
Node::~Node()
{}



