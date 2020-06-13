#include "sort.h"
/**
 * insertion_sort_list - 
 * @list:
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *tmp = *list, *aux = (*list)->next;

	while(current->next != NULL)
	{
		if(current->prev->n > current->n)
		{
			current = current->next;
			while(aux->prev->n > aux->n)
			{
				tmp->prev->next = aux;
				aux->prev = tmp->prev;
				tmp->prev = aux;
				tmp->next = current;
				aux->next = tmp;
				tmp = aux->prev;
				print_list(*list);
			}
		}
		else
		{
			current = current->next;
		}	
		aux = current;
		tmp = aux->prev;
	}
}
