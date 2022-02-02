#include "includes.h"

t_data	*ft_lstcopy_doubly_linked(t_data *a)
{
	t_data *a_copy;
	i = 0;

	a_copy = NULL;
	while (i < a->size)
	{
		ft_lst_addback(a_copy, a->head->data);
		a->head = a->head->next;
		i++;
	}
	return (a_copy);
}
