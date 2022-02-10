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

int	ft_is_median(t_stack *elem, int median)
{
	if	(elem->index > median)
		return (1);
	return (0);
}

int	ft_big_algo(t_data *a, t_data *b)
{
	int		median;
	int		i;

 	median = a->size / 2;
	i = 0 ;
 	while (i < median - 1)
 	{
 		if (a->head->index < median - 1)
 		{
			printf("pb\n");
 			pb(a, b);
			i++;
 		}
 		else
 		{
			printf("rra\n");
 			rra(a);
 		}
 	}
 	while (a->size > 3)
 	{
		if (a->head->index > median + 1)
 		{
			printf("pb\n");
 			pb(a, b);
			i++;
 		}
 		else
 		{
			printf("rra\n");
 			rra(a);
 		}
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