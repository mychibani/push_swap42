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

void ft_push_to_b(t_data *a, t_data *b)
{
	int i = 0;
	int	median;

	median = a->size / 2;
	printf("median == [%d]\n", median);
	while (a->size > 3)
	{
		if (a->head->index > (int)a->size - 3)
			ra(a);
		pb(a, b);
		if (b->head->index < median)
			rb(b);
		i++;
	}
}


void	sort_3(t_data *a)
{
	int elem0;
	int elem1;
	int elem2;

	elem0 = a->head->index;
	elem1 = a->head->next->index;
	elem2 = a->head->next->next->index;
	if (elem0 > elem1 && elem0 > elem2)
		ra(a);
	else if (elem0 < elem1 && elem1 > elem2)
		rra(a);
	if (a->head->index > a->head->next->index)
		sa(a);
}


int	ft_distance1(t_data *a, int nb)
{
	t_stack *current;
	size_t	count;
	
	count = 0;
	current = a->head;
	while (current->index != nb)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	ft_sorting_algo(t_data *a, t_data *b)
{
	int	to_check;

	ft_push_to_b(a, b);
 	sort_3(a);
	while (i < size)
	printf("distance depuis point a == [%d]\n", ft_distance1(a, ));
	return (1);
}

































































// int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
// {
// 	if (a->size < 3)
// 		_small_sort_(a, res);
// 	else
// 		_bigi_sort_(a, b, res);
// 	return (res);
// }