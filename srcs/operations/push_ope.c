// #include "includes.h"

// void	_delete_elem_(t_stack *elem)
// {
// 	if (elem = elem->next)
// 		elem = NULL;
// 	else
// 	{
// 		elem->prev->next = elem->next;
// 		elem->next->prev = elem->prev;
// 		elem = elem->next;
// 	}
// }

// void	pa(t_data *a, t_data *b)
// {
// 	t_stack *elem;

// 	if (b->size < 1)
// 		return ;

// }

// void	pb(t_data *a, t_data *b)
// {
// 	t_stack *temp_copy;
// 	t_stack *dent;

// 	if (a->size < 1)
// 		return ;
// 	temp_copy = a->head; 
	
// 	ft_lstpush_back_data(b, temp_copy);
// 	dent = a->head;
// 	a->head = dent->next;
// 	free(dent);
// 	a->size--;
// }