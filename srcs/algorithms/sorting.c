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

int		_next_greater_(t_data *a, int to_check, int *pos_a, int max, t_op *op)
{
	int			i;
	int			temp;
	int			sign;
	t_stack		*check_index;

	i = 0;
	sign = 1;
	check_index = a->head;
	temp = max;
	while (i < (int)a->size)
	{
		if (to_check < check_index->index && temp >= check_index->index)
		{
			if (i > (int)a->size / 2)
				*pos_a = a->size - i;
			else
			{
				*pos_a = i;
				sign *= -1;
			}
			temp = check_index->index;
		}
		i++;
		check_index = check_index->next;
	}
	if (sign < 0)
		op->ra = *pos_a;
	else
		op->rra = *pos_a;
	return (temp);
}

void	reinit_op(t_op **new)
{
	(*new)->rra = 0;
	(*new)->rrb = 0;
	(*new)->ra = 0;
	(*new)->rb = 0;
}

void	_rotate_stacks_(t_data *a, t_data *b, t_op *op)
{
	while (op->ra-- && op->rb--)
		rr(a, b);
	while (op->rra-- && op->rrb--)
		rrr(a, b);
	while (op->ra--)
		ra(a);
	while (op->rb--)
		rb(a);
}

int	ft_sorting_algo(t_data *a, t_data *b)
{
	t_stack *current;
	t_op	*op;
	int		i;
	int		pos_a;
	int		pos_b;
	int		max;
	int		sign;

	i = 0;
	sign = 1;
	op = malloc(sizeof(t_op));
	if (!op)
		return (-1);
	reinit_op(&op);
	ft_push_to_b(a, b);
	max = a->head->index;
	pa(a, b);
	current = b->head;
	while (b->size > 1)
	{
		while (i < (int)b->size)
		{
			_next_greater_(a, current->index, &pos_a, max, op);
			if (i > (int)b->size / 2)
				pos_b = b->size - i;
			else
				pos_b = i;
				sign *= -1;
			i++;
			current = current->next;
			if (sign < 0)
				op->rrb = pos_b;
			else
				op->rb = pos_b;
			_rotate_stacks_(a, b, op);
			reinit_op(&op);
		}
		pa(a, b);
	}
	free(op);
	//do_best_push(a, b);
	return (pos_b);
}

// int temp;

// int nbr;
// int i;
// t_op op;

// while (i stack b)
// {
// 	///count operation
// 	(if (temp > op.rra + op.rrb + o.ra + op.rb))
// 		temp = addition
// 		index = nbr;
// 	//ft_init_nb_of_moves(&a, &b);
// }

// insert(nbr)





























































// int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
// {
// 	if (a->size == 2)
// 		return (sa(a));
//  	else if (a->size < 3)
//  		return (_small_sort_(a, res));
//  	else
//  		return (_bigi_sort_(a, b, res));
//  }