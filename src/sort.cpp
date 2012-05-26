#include "sort.hpp"

void quicksort(Node** list, int size)
{
	const int max(size/2); // We decide that the pivot will be in the middle of the linked list
	int current(0), sizes[2] = {0, 0};
	Node* lists[2] = {NULL, NULL}; // The two alternate linked lists
	Node* heads[2] = {NULL, NULL}; // and their last node
	Node* pivot(NULL), *elem(NULL), *next(NULL); // Pivot and iterative nodes

	if (list == NULL)
		return; // Nothing to do

	elem = *list;
	for(int i(0); i <= max && elem != NULL ; ++i, elem = elem->next) // Looking for the pivot... 
		pivot = elem;

	if (pivot == NULL)
		return; // No pivot, so, no sorting

	for(elem = *list ; elem != NULL ; elem = next)
	{
		next = elem->next;
		elem->next = NULL; // Pointing the next node to NULL (the node no longer belongs to the current list)

		if (elem != pivot) // We assume the pivot is not in the linked list anymore
		{
			// Determining which of the two lists we will use by comparing the data
			current = (compareStr(elem->line, pivot->line) < 0) ? 0 : 1; 
			sizes[current]++;

			// Filling the alternate list
			if (lists[current] == NULL)
				lists[current] = elem; // Initializing the alternate list
			else
				heads[current]->next = elem; // Pointing to the (future) new head

			heads[current] = elem; // The current head of this list is the current node
		}
	}

	// Recursive calling in order to quicksort our alternate lists... 
	quicksort(lists, sizes[0]);
	quicksort(lists+1, sizes[1]);

	elem = NULL;
	if (lists[0] != NULL)
		for (next = lists[0] ; next != NULL ; next = elem->next) // Looking for the (new) head of the first alternate list
			elem = next;

	// Placing our pivot between our two alternate lists

	// The pivot is at the end of the first list...
	if (elem != NULL)
		elem->next = pivot;
	else
		lists[0] = pivot; // ...and may also be the only node of that list. 

	// The pivot is pointing to the first node of the second list (which can be empty)
	pivot->next = lists[1];

	*list = lists[0]; // Applying the quicksort
}
