#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

/**
 * listint_len - count elements of a double link list
 * Description: count all the elements of a double link list
 * @h: double link list
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t n;

	n = 0;
	if (h == NULL)
		return (n);
	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}

/**
 * get_dnodeint_at_index- get a node in a double link list
 * Description: function that get a given node in a list_t list
 * @head: head of the link list
 * @index: indexof the node to get
 * Return: node
 */
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node = NULL;
	listint_t *tmp = head;
	unsigned int i;

	i = 0;
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL && i != index)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp != NULL)
		node = tmp;
	return (node);
}

/**
 * insertion_sort_list - insertion sort algorithm
 * Description: sort a list using insertion algorithm
 * @list: list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *newnext, *newprev, *tmp = *list;
	size_t count, d, i;

	count = listint_len(tmp);
	if (tmp != NULL && count > 1)
	{
		for (d = 2; d <= count; d++)
		{
			tmp = *list;
			node = get_dnodeint_at_index(tmp, d - 1);
			i = 0;
			while (node->n > tmp->n && i < d - 1)
			{
				tmp = tmp->next;
				i++;
			}
			if (i < d - 1)
			{
				newnext = node->next;
				newprev = node->prev;
				while (node->next != tmp)
				{
					if (newprev->prev != NULL)
						newprev->prev->next = node;
					node->prev = newprev->prev;
					node->next = newprev;
					newprev->prev = node;
					newprev->next = newnext;
					if (newnext != NULL)
						newnext->prev = newprev;
					newprev = node->prev;
					newnext = node->next;
					if (node->prev == NULL)
						*list = node;
					print_list(*list);
				}
			}
		}
	}
}
