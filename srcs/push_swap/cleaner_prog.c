#include "includes.h"

void		_list_clean_(t_data *list, void(*free_data)(void *))
{
	size_t			i;
	t_stack		*temp;
	t_stack		*current;

	i = 0;
	if (list == 0 || list->size == 0 || free_data == 0)
		return ;
	current = list->head;
	while (i < list->size)
	{
		temp = current;
		current = current->next;
		free(temp);
		i++;
	}
	free(list->string);
	list->string = NULL;
	list->head = 0;
	list->size = 0;
}

void _clean_(t_data *a, t_data *b)
{
	_list_clean_(a, free);
	_list_clean_(b, free);
	free(a);
	free(b);
}