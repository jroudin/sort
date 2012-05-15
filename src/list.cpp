#include "list.hpp"

Node* addTailNode(Node* tail, DynStr* data)
{
	Node* node = new Node;

	node->line = data;
	node->next = tail;

	return node; // Returning the tail node
}

Node* addHeadNode(Node* head, DynStr* data)
{
	Node* node = new Node;

	node->line = data;
	node->next = NULL;
	
	if (head != NULL)
		head->next = node;
	return node; // Returning the head node
}

void freeNode(Node* tail)
{
	Node* next(NULL);

	for(Node* elem(tail) ; elem != NULL ; elem = next)
	{
		next = elem->next;
		freeStr(elem->line);
		delete elem; // Farewell, node ! Your job was great, wanna lunch someday ? 
	}
}
