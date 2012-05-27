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

void freeNode(Node* node)
{
    if (node == NULL)
        return;

    freeStr(node->line);
    freeNode(node->next); // Recursive call
    delete node;
}
