#ifndef LIST_HPP
#define LIST_HPP
#include <string>

struct Node
{
	std::string line;
	Node* next;
};

Node* addTailNode(Node* tail, const std::string& data);
Node* addHeadNode(Node* head, const std::string& data);
void freeNode(Node* tail);



#endif // LIST_HPP
