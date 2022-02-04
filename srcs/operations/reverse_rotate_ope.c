#include "includes.h"

int	rra(t_data *a)
{
	a->head = a->head->prev;
	return (RA);
}

int	rrb(t_data *a, t_data *b)
{
	a->head = a->head->prev;
	return (RRB);
}

int	rrr(t_data *a, t_data *b)
{
	rra(a);
	rrb(b);
	return (RRR);
}
