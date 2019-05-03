#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    char c;
    std::ifstream myfile;
    LinkedList list;
    std::string huge_list;
    bool enable = true;

    /* Parsing */
    myfile.open("name.txt");
    while(myfile >> c)
    {
        //remove commas while reading
        if(c ==',' && enable == true)
        { continue; }

        //adding names
        if(c != '(' && enable == true && c!= ' ')
        { huge_list += c; }

        //disable reading and add prior name
        else if (c =='(')
        {
            Node* add = new Node(huge_list);
            list.addNode(add);
            huge_list.clear();
            enable = false;
        }
        //re-enable reading
        else if(c ==')')
        {  enable = true;  }
    }
    myfile.close();
    std::string yep;
    list.RNGwinner(yep);
    list.printList(yep);

    return 0;
}
