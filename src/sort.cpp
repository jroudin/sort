#include "sort.hpp"

void quicksort(Node** list, int size)
{
	const int max(size/2); // We decide that the pivot will be in the middle of the linked list
	int current(0), sizes[2] = {0, 0};
	Node* lists[2] = {NULL, NULL}; // The two alternate linked lists
	Node* heads[2] = {NULL, NULL}; // and their last node
	Node* pivot(NULL), *elem(NULL), *next(NULL); // Pivot and iterative nodes
	std::string strElem(""), strPivot("");

	if (list == NULL)
		return; // Nothing to do

	elem = *list;
	for(int i(0); i <= max && elem != NULL ; ++i, elem = elem->next) // Looking for the pivot... 
		pivot = elem;

	if (pivot == NULL)
		return; // No pivot, so, no sorting

	adapt(strPivot = pivot->line);

	for(elem = *list ; elem != NULL ; elem = next)
	{
		next = elem->next;
		if (elem != pivot) // We assume the pivot is not in the linked list anymore
		{
			adapt(strElem = elem->line);
			current = (strElem.compare(strPivot) <= 0) ? 0 : 1; // Determining which of the two lists
																	  // we will use by comparing the data
			sizes[current]++;

			if (lists[current] == NULL)
			{
				// Initializing the alternate list
				lists[current] = elem;
				lists[current]->next = NULL;

				heads[current] = lists[current]; // The head is currently the tail
			}
			else
			{
				// Filling the alternate list
				heads[current]->next = elem;
				heads[current] = heads[current]->next;
			}
		}
	}

	// Both of alternate lists must end with their head pointing to NULL

	if (heads[0] != NULL)
		heads[0]->next = NULL;

	if (heads[1] != NULL)
		heads[1]->next = NULL;

	elem = NULL;

	// Recursive calling in order to quicksort our alternate lists... 
	quicksort(lists, sizes[0]);
	quicksort(lists+1, sizes[1]);

	if (lists[0] != NULL)
		for (next = lists[0] ; next != NULL ; next = elem->next) // Looking for the (new) head of the first alternate list
			elem = next;

	if (elem != NULL) // Placing our pivot between our two alternate lists
		elem->next = pivot;
	else
		lists[0] = pivot; // Or beginning with the pivot
	pivot->next = lists[1];

	*list = lists[0]; // Applying the quicksort
}

void adapt(std::string& str)
{
	int size(str.size());
	for(int i(0) ; i < size && size > 0 ; ++i)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			str.erase(i,1);
			--i;
			--size;
		}
		else
			str[i] = std::tolower(str[i]);
	}
}
