#include "includes.h"

int _sorting_prep_(t_data *a)
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

int	ft_is_median(t_data *a, int median)
{
	int i;
	t_stack *current;

	i = 0;
	current = a->head;
	while (i < (int)a->size)
	{
		if (current->index < median)
			return (1);
		i++;
	}
	return (0);
}

int	ft_big_algo(t_data *a, t_data *b)
{
	int		median;

	median = a->size / 2;
	while (a->size > 3)
	{
		if (a->head->index > median)
		{
			printf("ra\n");
			ra(a);
		}
		else
		{
			printf("pb\n");
			pb(a, b);
		}
		if (!ft_is_median(a, median))
			break ;
	}
	while (a->size > 3)
	{
		printf("pb\n");
		pb(a, b);
	}
	return (median);
}
// int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
// {
// 	if (a->size < 3)
// 		_small_sort_(a, res);
// 	else
// 		_bigi_sort_(a, b, res);
// 	return (res);
// }