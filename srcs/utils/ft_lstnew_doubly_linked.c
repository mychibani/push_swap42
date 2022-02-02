#include "includes.h"

t_stack	*ft_lstnew_doubly_linked(int data)
{
	t_stack *new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)	
		return (NULL);
	new_elem->data = data;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}
