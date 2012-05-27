#include "sort.hpp"

Node* quicksort(Node* list, int size)
{
    const int max(size/2); // We decide that the pivot will be in the middle
    int current(0), sizes[2] = {0, 0};
    Node* lists[2] = {NULL, NULL}; // The two alternate linked lists
    Node* heads[2] = {NULL, NULL}; // and their last node
    Node* pivot(NULL), *elem(list); // Pivot and temp nodes

    if (list == NULL)
        return NULL; // Nothing to do

    // Looking for the pivot... 
    for(int i(0); i <= max && elem != NULL ; ++i, elem = elem->next)
        pivot = elem;

    if (pivot == NULL)
        return NULL; // No pivot, so, no sorting

    for(elem = list ; elem != NULL ; elem = next)
    {
        next = elem->next;
        elem->next = NULL; 
        // Pointing the next node to NULL 
        // (the node no longer belongs to the current list)

        if (elem != pivot) // We don't compare the pivot to itself
        {
            // Determining which of the two lists we will use by comparing str
            current = (compareStr(elem->line, pivot->line) < 0) ? 0 : 1; 
            sizes[current]++;

            // Filling the alternate list
            if (lists[current] == NULL)
                lists[current] = elem; // Initializing the alternate list
            else
                heads[current]->next = elem; // Pointing to the new head

            // The current head of this list is the current node
            heads[current] = elem;
        }
    }

    // Recursive calling in order to quicksort our alternate lists... 
    lists[0] = quicksort(lists[0], sizes[0]);
    lists[1] = quicksort(lists[1], sizes[1]);

    // Looking for the (new) head of the first alternate list
    elem = NULL;
    if (lists[0] != NULL)
        for (Node* next(lists[0]) ; next != NULL ; next = elem->next)
            elem = next;

    // Placing our pivot between our two alternate lists

    // The pivot is at the end of the first list...
    if (elem != NULL)
        elem->next = pivot;
    else
        lists[0] = pivot; // ...and may also be the only node of that list. 

    // The pivot is pointing to the first node of the second list 
    // (which can be empty, but we don't care)
    pivot->next = lists[1];

    return lists[0]; // Return the first element of our sorted list
}
