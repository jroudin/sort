#include <iostream>
#include "list.hpp"
#include "sort.hpp"
#include "dynstr.hpp"

int main()
{
	Node* head(NULL);
	Node* tail(NULL);
	DynStr* str(NULL), *strHead(NULL);
	int size(0);

	for (char c(std::cin.get()) ; !std::cin.eof() ; c = std::cin.get() ) // getting standard input until its end
	{
		if (c == '\n') // the line stopped there
		{
			++size;
			head = addHeadNode(head, str); // creating a node with the line... 
			if (tail == NULL)
				tail = head; // the line has just been created, so we initialize the tail
			strHead = str = NULL;
		}
		else
		{
			strHead = addChar(strHead, c);
			if (str == NULL)
				str = strHead;
		}
	}

	if (str != NULL) // In case of STDIN terminating without stopping the current line... 
		head = addHeadNode(head, str);

	quicksort(&tail, size);

	for (Node* elem(tail) ; elem != NULL ; elem = elem->next) // Displaying every line
		displayStr(elem->line);

	freeNode(tail); // Freeing every node

	return 0;
}
