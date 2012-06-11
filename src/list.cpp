#include "list.hpp"

Node* addTailNode(Node* tail, DynStr* data)
{
    Node* node = new Node;

    node->line = data;
    node->next = tail;

    return node; // Returning the tail node
}

void freeNode(Node* node)
{
    if (node == NULL)
        return;

    freeStr(node->line);
    freeNode(node->next); // Recursive call
    delete node;
}
