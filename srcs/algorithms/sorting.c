#include "includes.h"


t_op	*reinit_op(void)
{
	t_op *new;

	new = NULL;
	new = (t_op *)malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->rr = 0;
	new->rrr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->ra = 0;
	new->rb = 0;
	new->pos_a = 0;
	new->pos_b = 0;
	new->max_op = _INT_MAX_;
	return (new);
}


int	_find_max_(t_data *stack)
{
	int		i;
	int		max_value;
	t_stack *index;

	i = 0;
	max_value = 0;
	index = stack->head;
	while (i < (int)stack->size)
	{
		if (index->index > max_value)
			max_value = index->index;
		index = index->next;
		i++;
	}
	return (max_value);
}


int		calcul_choice(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}


// int _full_calcul()
// {
// 		t_op	*final_move;
// 		if (sum_count < )
// 			final_move = 
// 		test1()
// 		test2()
// 		test3()
// 		test4()
// 		return (op);
// }

int	difference(int x, int y)
{
	return (x - y);
}

int	addition(int x, int y)
{
	return (x + y);
}

void	test_one(t_op **op)
{
	int	temp;

	if ((*op)->pos_a > (*op)->pos_b)
		temp = (*op)->pos_b;
	else
		temp = (*op)->pos_a;
	if (difference((*op)->pos_a, (*op)->pos_b) > 0)
	{
		(*op)->ra = difference((*op)->pos_a, (*op)->pos_b);
		(*op)->rb = 0;
	}
	else
	{
		(*op)->rb = difference((*op)->pos_a, (*op)->pos_b);
		(*op)->ra = 0;
	}
	(*op)->rr = temp;
	(*op)->rra = 0;
	(*op)->rrb = 0;
	(*op)->rrr = 0;
	(*op)->max_op = _sum_op_(op);
}

void	test_two(t_op **op, t_data *a, t_data *b)
{
	int	rrr;
	int rra;
	int rrb;

	rra = a->size - (*op)->pos_a;
	rrb = b->size - (*op)->pos_b;
	if (rra > rrb)
		rrr = difference(rrb, rra);
	else
		rrr = difference(rra, rrb);
	if (difference(rra, rrb > 0))
	{
		(*op)->rra = difference(rra, rrb);
		(*op)->rrb = 0;
	}
	else
	{
		(*op)->rrb = difference(rrb, rra);
		(*op)->rra = 0;
	}
	(*op)->rrr = rrr;
	(*op)->ra = 0;
	(*op)->rb = 0;
	(*op)->rr = 0;
	(*op)->max_op = _sum_op_(op);
}

void	test_three(t_op **op, t_data *b)
{
	(*op)->ra = (*op)->pos_a;
	(*op)->rb = 0;
	(*op)->rra = 0;
	(*op)->rrb = b->size - (*op)->pos_b;
	(*op)->rrr = 0;
	(*op)->rr = 0;
	(*op)->max_op = _sum_op_(op);
}

void	test_four(t_op **op, t_data *a)
{
	(*op)->ra = 0;
	(*op)->rb = (*op)->pos_b;
	(*op)->rra = a->size - (*op)->pos_a;
	(*op)->rrb = 0;
	(*op)->rrr = 0;
	(*op)->rr = 0;
	(*op)->max_op = _sum_op_(op);
}

t_op *all_case(t_data *a, t_data *b, t_op **op)
{
	t_op *best_case;

	best_case = reinit_op();
	test_one(op);
	if (best_case->max_op > (*op)->max_op)
		best_case = *op;
	test_two(op, a, b);
	if (best_case->max_op > (*op)->max_op)
		best_case = *op;
	test_three(op, b);
	if (best_case->max_op > (*op)->max_op)
		best_case = *op;
	test_four(op, a);
	if (best_case->max_op > (*op)->max_op)
		best_case = *op;
	return (best_case);
}

int	ft_sorting_algo(t_data *a, t_data *b, t_op *op)
{
	t_stack *current;
	t_op	*final_move;
	int		i;

	i = 0;
	final_move = reinit_op();
	_algo_prep_(a, b);
	current = b->head;
	while (b->size > 0)
	{
		while (i < (int)b->size)
		{
			_next_greater_(a, current->index, i, &op);
			final_move = all_case(a, b, &op);
			if (final_move > op->max_op)
				final_move = op;
			i++;
			current = current->next;
		}
		_rotate_(a, b, &final_move);
		pa(a, b);
		i = 0;
		current = b->head;
	}	
	return (_SUCCESS_);
}





































// int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
// {
// 	if (a->size == 2)
// 		return (sa(a));
//  	else if (a->size < 3)
//  		return (_small_sort_(a, res));
//  	else
//  		return (_bigi_sort_(a, b, res));
//  }