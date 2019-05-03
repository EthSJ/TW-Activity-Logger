#include "LinkedList.h"

#include <fstream>
#include <stdlib.h>
#include <iostream>

//linked list marker.
LinkedList::LinkedList()
{
    head = NULL;
}

//overloaded linked list constructor.
LinkedList::LinkedList(Node *next)
{
    head = next;
}

//Linked List obliterator. Deletes all nodes as well.
LinkedList::~LinkedList()
{
    Node *del = head;
    while (del!= NULL)
    {
        head = head->next;
        delete del;
        del = head;
    }
    head = NULL;
}

//adds a new node in.
//If no head, add. If it's bigger than head, swap. Else find a spot for it.
void LinkedList::addNode(Node* newNode)
{
    if (!head)
        head = newNode;
    else if(head->name == newNode->name)
        head->num_times++;
    else if ((newNode->name) < (head->name))
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* p1 = head;
        while (p1->next)
        {
            //same person
            if(p1->name == newNode->name)
            {
                p1->num_times++;
                return;
            }
            if ((p1->next->name) > (newNode->name))
            {
                newNode->next = p1->next;
                p1->next = newNode;
                return;
            }
            p1 = p1->next;
        }
        p1->next = newNode;
    }

}

void LinkedList::printList(std::string &winner)
{
    std::ofstream file;
    file.open("output.txt");

    Node* ptr = head;
    //print it out
    if(ptr==NULL)
    {
        file << "\n";
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->name.size() < 8)
                file << ptr->name << "\t\t\t Responded: "<< ptr->num_times <<"\n\n";
            else if(ptr->name.size() >= 16)
                file << ptr->name << "\t Responded: "<< ptr->num_times <<"\n\n";
            else
                file << ptr->name << "\t\t Responded: "<< ptr->num_times <<"\n\n";
            ptr = ptr->next;
        }
    }
    //people in drawing
    ptr = head;
    if(ptr==NULL)
    {
        file << "\n";
        return;
    }
    else
    {
        file<<"\n\nThose in drawing:\n";
        while(ptr!=NULL)
        {
            if(ptr->num_times >=5)
            {
                if(ptr->name == winner)
                    file << "Winner: "<< ptr->name << " with "<< ptr->num_times <<"\n";
                else
                    file << ptr->name << " with "<< ptr->num_times <<"\n";
                ptr = ptr->next;
            }
            else
                ptr= ptr->next;
        }
    }
    delete ptr;
    file.close();
}

void LinkedList::RNGwinner(std::string &win)
{
    Node* ptr = head;
    int random=0;

    if(ptr==NULL)
    {
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->num_times >=5)
            {
                ++random;
                ptr = ptr->next;
            }
            else
                ptr=ptr->next;
        }
    }
    ptr=head;
    random= rand()%random+1;
    unsigned k=0;

    if(ptr==NULL)
    {
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->num_times>=5)
            {
                ++k;
                if(k == random)
                    win = ptr->name;
                else
                    ptr=ptr->next;
            }
            else
                ptr=ptr->next;
        }
    }
    delete ptr;
}
