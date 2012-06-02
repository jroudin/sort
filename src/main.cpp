#include <iostream>
#include <clocale>
#include "list.hpp"
#include "sort.hpp"
#include "dynstr.hpp"

int main()
{
    Node* list(NULL);
    DynStr* str(NULL), *strHead(NULL);
    int size(0);

    setlocale(LC_COLLATE, "");

     // getting standard input until its end
    for (char c(std::cin.get()) ; !std::cin.eof() ; c = std::cin.get() )
    {
        if (c == '\n') // the line stopped there
        {
            ++size;
            list = addTailNode(list, str); // creating a node with the line... 
            strHead = str = NULL;
        }
        else
        {
            strHead = addChar(strHead, c);
            if (str == NULL)
                str = strHead; // This is the beginning of the string
        }
    }

    // In case of STDIN terminating without stopping the current line... 
    if (str != NULL)
        list = addTailNode(list, str);

    list = quicksort(list, size);

    // Displaying every line
    for (Node* elem(list) ; elem != NULL ; elem = elem->next)
        displayStr(elem->line);

    freeNode(list); // Freeing every node

    return 0;
}
