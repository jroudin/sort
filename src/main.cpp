#include <iostream>
#include "list.hpp"

int main()
{
	Node* head(NULL);
	Node* tail(NULL);
	std::string buffer("");

	for (char c(std::cin.get()) ; !std::cin.eof() ; c = std::cin.get() ) // getting standard input until its end
	{
		if (c == '\n') // the line stopped there
		{
			head = addHeadNode(head, buffer); // creating a node with the line... 
			if (tail == NULL)
				tail = head; // the line has just been created, so we initialize the tail
			buffer.clear();
		}
		else
			buffer += c;
	}

	if (!buffer.empty()) // In case of STDIN terminating without stopping the current line... 
		head = addHeadNode(head, buffer);

	for (Node* elem(tail) ; elem != NULL ; elem = elem->next) // Displaying every line
		std::cout << elem->line << std::endl;

	return 0;
}
