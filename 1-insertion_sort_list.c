#include "sort.h"

/**
 * insertion_sort_list - function of the prototype
 * @list: doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *q, *r, *nextnodes;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	q = (*list)->next;
	nextnodes = q->next;
	while (q)
	{
		if (q->n < q->prev->n)
		{
			r = q->prev;
			while (r && (q->n < r->n))
			{
				if (!(r->prev))
				{
					r->prev = q;
					q->prev->next = q->next;
					if (q->next)
						q->next->prev = q->prev;
					q->next = r;
					q->prev = NULL;
					*list = q;
				}
				else
				{
					q->prev->next = q->next;
					if (q->next)
						q->next->prev = q->prev;
					r->prev->next = q;
					q->prev = r->prev;
					r->prev = q;
					q->next = r;
				}
				print_list(*list);
				r = q->prev;
			}
		}
		q = nextnodes;
		q ? (nextnodes = q->next) : (nextnodes = NULL);
	}
}

