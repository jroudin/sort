#ifndef LIST_HPP
#define LIST_HPP
#include "dynstr.hpp"

struct Node
{
    DynStr* line;
    Node* next;
};

Node* addTailNode(Node* tail, DynStr* data);
Node* addHeadNode(Node* head, DynStr* data);
void freeNode(Node* tail);



#endif // LIST_HPP
