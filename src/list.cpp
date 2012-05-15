#include "list.hpp"

Node* addTailNode(Node* tail, const std::string& data)
{
	Node* node = new Node;

	node->line = data;
	node->next = tail;

	return node; // Returning the tail node
}

Node* addHeadNode(Node* head, const std::string& data)
{
	Node* node = new Node;

	node->line = data;
	node->next = NULL;
	
	if (head != NULL)
		head->next = node;
	return node; // Returning the head node
}
