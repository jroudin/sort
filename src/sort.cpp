#include "sort.hpp"

void quicksort(Node** list, int size)
{
	const int max(size/2);
	int current(0), sizes[2] = {0, 0};
	Node* lists[2] = {NULL, NULL};
	Node* heads[2] = {NULL, NULL};
	Node* pivot(NULL), *elem(NULL), *next(NULL);

	if (list == NULL)
		return;

	elem = *list;
	for(int i(0); i <= max && elem != NULL ; ++i, elem = elem->next)
		pivot = elem;

	if (pivot == NULL)
		return;

	for(elem = *list ; elem != NULL ; elem = next)
	{
		next = elem->next;
		if (elem != pivot)
		{
			current = (elem->line.compare(pivot->line) <= 0) ? 0 : 1;
			sizes[current]++;

			if (lists[current] == NULL)
			{
				lists[current] = elem;
				lists[current]->next = NULL;

				heads[current] = lists[current];
			}
			else
			{
				heads[current]->next = elem;
				heads[current] = heads[current]->next;
			}
		}
	}

	if (heads[0] != NULL)
		heads[0]->next = NULL;

	if (heads[1] != NULL)
		heads[1]->next = NULL;

	elem = NULL;

	quicksort(lists, sizes[0]);
	quicksort(lists+1, sizes[1]);

	if (lists[0] != NULL)
		for (next = lists[0] ; next != NULL ; next = elem->next)
			elem = next;

	if (elem != NULL)
		elem->next = pivot;
	else
		lists[0] = pivot;
	pivot->next = lists[1];

	*list = lists[0];

}
