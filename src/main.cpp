#include <iostream>
#include <clocale>
#include "list.hpp"
#include "sort.hpp"
#include "dynstr.hpp"

int main()
{
    Node* head(NULL), *tail(NULL);
    DynStr* str(NULL), *strHead(NULL);
    int size(0);

    setlocale(LC_COLLATE, "");

     // getting standard input until its end
    for (char c(std::cin.get()) ; !std::cin.eof() ; c = std::cin.get() )
    {
        if (c == '\n') // the line stopped there
        {
            ++size;
            head = addHeadNode(head, str); // creating a node with the line... 
            if (tail == NULL) // the line has just been created, 
                tail = head;  // so we initialize the tail
            strHead = str = NULL;
        }
        else
        {
            strHead = addChar(strHead, c);
            if (str == NULL)
                str = strHead;
        }
    }

    // In case of STDIN terminating without stopping the current line... 
    if (str != NULL)
        head = addHeadNode(head, str);

    tail = quicksort(tail, size);

    // Displaying every line
    for (Node* elem(tail) ; elem != NULL ; elem = elem->next)
        displayStr(elem->line);

    freeNode(tail); // Freeing every node

    return 0;
}
