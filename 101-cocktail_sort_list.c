#include "sort.h"

void swap(listint_t *a, listint_t *b, listint_t **list);
/**
 * swap - function of the prototype
 * @a: first node to swap
 * @b: second node to swap
 * @list: list to set null or not
 */
void swap(listint_t *a, listint_t *b, listint_t **list)
{
	if (!(a->prev))
	{
		a->next = b->next;
		if (b->next)
			b->next->prev = a;
		b->next = a;
		b->prev = NULL;
		a->prev = b;
		*list = b;
	}
	else
	{
		b->prev->next = b->next;
		if (b->next)
			b->next->prev = b->prev;
		a->prev->next = b;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	}
}

/**
 * cocktail_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *a, *nextnode1;
	int changed;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	a = (*list);
	do {
		changed = 0;
		while (a->next)
		{
			nextnode1 = a->next;
			if (nextnode1 && a->n > nextnode1->n)
			{
				swap(a, nextnode1, list);
				changed = 1;
				print_list((*list));
			}
			else
				a = a->next;
		}
		a = a->prev;
		while (a->prev)
		{
			nextnode1 = a->prev;
			if (nextnode1 && a->n < nextnode1->n)
			{
				swap(nextnode1, a, list);
				changed = 1;
				print_list((*list));
			}
			else
				a = a->prev;
		}
		a = a->next;
	} while (changed);
}

