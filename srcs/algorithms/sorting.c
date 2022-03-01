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

void	_next_greater_(t_data *a, int to_check, int max, t_op *op)
{
	int			i;
	int			temp;
	t_stack		*check_index;

	i = 0;
	check_index = a->head;
	temp = max;
	while (i < (int)a->size)
	{
		if (to_check < check_index->index && temp >= check_index->index)
		{
			if (i > (int)a->size / 2)
				op->rra = a->size - i;
			else
				op->ra = i;
			temp = check_index->index;
		}
		i++;
		check_index = check_index->next;
	}
}

void	reinit_op(t_op **new)
{
	(*new)->rra = 0;
	(*new)->rrb = 0;
	(*new)->ra = 0;
	(*new)->rb = 0;
}

void	_rotate_stacks_(t_data *a, t_data *b, t_op **op)
{
	while ((*op)->ra && (*op)->rb)
	{
		rr(a, b);
		(*op)->ra--;
		(*op)->rb--;
	}
	while ((*op)->rra && (*op)->rrb)
	{
		rrr(a, b);
		(*op)->rra--;
		(*op)->rrb--;
	}
	while ((*op)->ra)
	{
		ra(a);
		(*op)->ra--;
	}
	while ((*op)->rb)
	{
		rb(a);
		(*op)->rb--;
	}
}

int	ft_sorting_algo(t_data *a, t_data *b, t_op *op)
{
	t_stack *current;
	// t_op	*min_move;
	int		temp;
	int		i;
	int		max;

	i = 0;
	ft_push_to_b(a, b);
	max = a->head->index;
	pa(a, b);
	current = b->head;
	temp = _INT_MAX_;
	// while (b->size > 1)
	// {
		while (i < (int)b->size)
		{
			_next_greater_(a, current->index, max, op);
			if (i > (int)b->size / 2)
			{
				op->rb = 0;
				op->rrb = b->size - i;
			}
			else
				op->rb = i;
			current = current->next;
			if (temp > op->ra + op->rb + op->rb + op->rra + op->rrb)
			{
				temp = op->ra + op->rb + op->ra + op->rra + op->rrb;
				//min_move = op;
			}
			i++;
		}
		_print_op_(op);
		// _rotate_stacks_(a, b, &min_move);
	// }
	return (1);
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