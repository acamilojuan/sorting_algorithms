#include "sort.h"
/**
 * insertion_sort_list - 
 * @list:
 */
void swap(listint_t **list, listint_t *back, listint_t *front)
{
	if(back->prev)
		back->prev->next = front;
	else
		*list = front;
	back->next = front->next;
	front->next = back;
	if(back->next)
		back->next->prev = back;
	front->prev = back->prev;
	back->prev = front;
}

void insertion_sort_list(listint_t **list)
{ 
	listint_t *current, *back, *front;
	back = (*list);
	front = (*list)->next;
	current = front->next;

	if((*list)->next)
	{
		while(front)
		{
			while(front->prev && front->prev->n > front->n)
			{
				swap(list, back, front);
				/**front = current->prev;*/
				back = front->prev;
				print_list(*list);
			}
			front = current;
			if (front)
			{
				current = current->next;
				back = front->prev;

			}
			else
			{
				break;
			}
		}
	}

	/**listint_t *node, *current;

	node = (*list)->next;
	current = node->next;

	while (node)
	{
		while (node->prev && node->n < node->prev->n)
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;

			if (node->prev == NULL)
				*list = node;
			else
				node->prev->next = node;
			print_list(*list);
		}
		node = current;
		if (node)
			current = current->next;
		else
		{
			break;
		}
		
		
		
	}*/
}
