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

    //check on file
    myfile.open(argv[1]);
    if (myfile.fail())
    {
        std::cerr<<"Opening file failed\n";
        return -1;
    }

    /* Parsing */
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
            list.addNode(huge_list);
            huge_list.clear();
            enable = false;
        }
        //re-enable reading
        else if(c ==')')
        {  enable = true;  }
    }
    myfile.close();

    list.RNGwinner();
    list.printList();

    return 0;
}
