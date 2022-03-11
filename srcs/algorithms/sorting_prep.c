#include "includes.h"

int	_sorting_prep_(t_data *a)
{
	t_stack *curr;
	t_stack *to_check;
	size_t i;
	size_t j;

	i = 0;
	curr = a->head;
	to_check = curr;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (curr->data > to_check->data)
				curr->index++;
			to_check = to_check->next;
			j++;
		}
		curr = curr->next;
		i++;
	}
	return (_SUCCESS_);
}

void	_algo_prep_(t_data *a, t_data *b)
{
	int i;
	int	median;
	int max;

	max = _find_max_(a);
	median = a->size / 2;
	i = 0;
	while (a->size > 1)
	{
		if (a->head->index == max)
			ra(a, "ra\n");
		pb(a, b);
		if (b->head->index < median)
			rb(b, "rb\n");
		i++;
	}
	pa(a, b);
	_sort_3_(a);
}