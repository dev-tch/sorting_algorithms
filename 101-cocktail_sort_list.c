#include "sort.h"

void swap_two_nodes(listint_t **list, listint_t *node1, listint_t *node2);
/**
* cocktail_sort_list - orts a doubly linked list of integers
*in ascending order using the Cocktail shaker sort algorithm
* @list: doubly linked list
* Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	int flag_swap_done;
	listint_t *current_node;

	if (list == NULL || *list == NULL)
		return;

	do {
		flag_swap_done = 0;
		current_node = *list;
		while (current_node->next != NULL)
		{
			if (current_node->n > current_node->next->n)
			{
				swap_two_nodes(list, current_node, current_node->next);
				print_list(*list);
				flag_swap_done = 1;
			}
			else
				current_node = current_node->next;
		}
		if (flag_swap_done == 0)
			break;
		flag_swap_done = 0;
		while (current_node->prev != NULL)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_two_nodes(list, current_node->prev, current_node);
				print_list(*list);
				flag_swap_done = 1;
			}
			else
				current_node = current_node->prev;
		}
	} while (flag_swap_done);
}

/**
* swap_two_nodes - reverse order of two nodes in list
* @list: doubly linked list
* @node_x: first node
* @node_y : second node
* Return: void
*/
void swap_two_nodes(listint_t **list, listint_t *node_x, listint_t *node_y)
{
	if (node_x->prev != NULL)
		node_x->prev->next = node_y;
	else
		*list = node_y;

	if (node_y->next != NULL)
		node_y->next->prev = node_x;

	node_x->next = node_y->next;
	node_y->prev = node_x->prev;
	node_x->prev = node_y;
	node_y->next = node_x;
}
