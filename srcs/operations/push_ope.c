#include "includes.h"

void	pa(t_data *a, t_data *b
{
	t_stack *temp;

	if (b->size < 1)
		return ;
	temp = b->head; 
	ft_lstpush_front_data(a, temp);
	b->head = b->head->next;
}

void	pb(t_data *a, t_data *b
{
	t_stack *temp;

	if (a->size < 1)
		return ;
	temp = a->head; 
	ft_lstpush_front_data(b, temp);
	a->head = a->head->next;
}