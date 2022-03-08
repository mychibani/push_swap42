#include "includes.h"

void	_sort_2_(t_data *a)
{
	sa(a);
}

void	_sort_3_(t_data *a)
{
	int elem0;
	int elem1;
	int elem2;

	elem0 = a->head->index;
	elem1 = a->head->next->index;
	elem2 = a->head->next->next->index;
	if (elem0 > elem1 && elem0 > elem2)
		ra(a, "ra\n");
	else if (elem0 < elem1 && elem1 > elem2)
		rra(a, "rra\n");
	if (a->head->index > a->head->next->index)
	    sa(a);
}