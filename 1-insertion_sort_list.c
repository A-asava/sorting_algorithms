#include "sort.h"

/**
 *nodes_swap - swaps the nodes of givn list
 *@head: head pointer of the given list
 *@n1: node1 to be inserted
 *@n2: node2 to be inserted
 */

void nodes_swap(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 *insertion_sort_list - sort a particular list
 *@list: pointer to the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j && j->n > i->n)
		{
			nodes_swap(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
