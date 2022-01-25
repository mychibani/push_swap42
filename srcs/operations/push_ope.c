#include "includes.h"

void	pa(t_data *a, t_data *b)
{
	t_stack *elem;
	t_stack	*temp;

	if (b->size < 1)
		return ;
	temp = a->head;
	elem = a->head;
	elem = elem->next;
	elem->prev = a->head->prev;
	a->head->prev->next = elem;
	a->head = elem;
	a->size -= 1;
	ft_lstpush_front_data(b, temp);
}

void	pb(t_data *a, t_data *b)
{
	t_stack *elem;
	t_stack	*temp;

	if (b->size < 1)
		return ;
	temp = b->head;
	elem = b->head;
	elem = elem->next;
	elem->prev = b->head->prev;
	b->head->prev->next = elem;
	b->head = elem;
	b->size -= 1;
	ft_lstpush_front_data(a, temp);
}
