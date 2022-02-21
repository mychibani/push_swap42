#include "includes.h"

int	rra(t_data *a)
{
	printf("rra\n");
	a->head = a->head->prev;
	return (RRA);
}

int	rrb(t_data *b)
{
	printf("rrb\n");
	b->head = b->head->prev;
	return (RRB);
}

int	rrr(t_data *a, t_data *b)
{
	printf("rrr\n");
	rra(a);
	rrb(b);
	return (RRR);
}
