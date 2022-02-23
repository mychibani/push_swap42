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
	int i;
	int	median;
	int max;

	max = a->size - 1;
	median = a->size / 2;
	i = 0;
	while (a->size > 1)
	{
		if (a->head->index == max)
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


// int	a_distance_calcul(t_data *a, int pos)
// {
// 	int move;

// 	move = 0;
// 	if (pos > a->size / 2)
// 	{
// 		while (pos < a->size)
// 			move = pos++;
// 	}
// 	else
// 	{
// 		while (pos-- >= 0)
// 			move++;
// 	}
// 	return (move);
// }

// int	b_distance_calcul(t_data *b, int pos)
// {
// 	int move;

// 	move = 0;
// 	if (pos > (int)b->size / 2)
// 	{
// 		while (pos < b->size)
// 			move = pos++;
// 	}
// 	else
// 	{
// 		while (pos-- >= 0)
// 			move++;
// 	}
// 	return (move);
// }


int		_next_greater_(t_data *a, int to_check)
{
	int			i;
	t_stack		*check_index;

	i = 0;
	check_index = a->head;
	while (i < (int)a->size)
	{
		if (to_check < check_index->index)
			return (check_index->index);
		i++;
		check_index = check_index->next;
	}
	return (-1);
}

//void	_sorting_prep_second_part_(t_data **a, t_data **b)
//{
// 	int		i;
// 	int		tmp_move;
// 	t_stack	*elem;
	
// 	tmp_move = a_distance_calcul(elem, 0) + b_distance_calcul(elem, 0);
// 	elem = (*b)->head;
// 	i = 0;
// 	while (i < (int)(*b)->size)
// 	{
// 		i++;
// 		elem = elem->next;
// 	}
//}

int	ft_sorting_algo(t_data *a, t_data *b)
{
	t_stack *oui;
	int	i;

	i = 0;
	if (a->size == 2)
	{
		sa(a);
		return (1232131231);
	}
	ft_push_to_b(a, b);
	pa(a, b);
	oui = b->head;
	int	majorant;
	while (i < (int)b->size)
	{
		majorant = _next_greater_(a, oui->index);	
		ft_init_nb_of_moves(&a, &b, oui, majorant);
		//do_best_push(a, b);
		i++;
		oui = oui->next;
	}
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