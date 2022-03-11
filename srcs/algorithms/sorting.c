#include "includes.h"

t_op	*init_op(void)
{
	t_op *new;

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

void	reinit_op(t_op *new)
{
	new->rr = 0;
	new->rrr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->ra = 0;
	new->rb = 0;
	new->pos_a = 0;
	new->pos_b = 0;
	new->max_op = _INT_MAX_;
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

int	a_up_and_b_down(t_data *b, t_op *op)
{
	op->ra = op->pos_a;
	op->rb = 0;
	op->rra = 0;
	op->rrb = b->size - op->pos_b;
	op->rrr = 0;
	op->rr = 0;
	op->max_op = op->ra + op->rrb;
	return (op->max_op);
}

int	b_up_and_a_down(t_data *a, t_op *op)
{
	op->ra = 0;
	op->rb = op->pos_b;
	op->rra = a->size - op->pos_a;
	op->rrb = 0;
	op->rrr = 0;
	op->rr = 0;
	op->max_op = op->rb + op->rra;
	return (op->max_op);
}

t_op *_calcul_positions(t_data *a, t_data *b, t_op *op)
{
	t_op *best_case;

	best_case = init_op();
	if (op->max_op > a_up_and_b_down(b, best_case))
		a_up_and_b_down(b, op);
	if (op->max_op > b_up_and_a_down(a, best_case))
		b_up_and_a_down(a, op);
	if (op->max_op > a_up_and_b_up)
	free(best_case);
	return (op);
}

int	ft_sorting_algo(t_data *a, t_data *b, t_op *op)
{
	t_stack *current;
	int		i;

	i = 0;
	_algo_prep_(a, b);
	current = b->head;
	while (b->size > 0)
	{
		op->max_op = _INT_MAX_;
		while (i < (int)b->size)
		{
			_next_greater_(a, current->index, i, &op);
			_calcul_positions(a, b, op);
			i++;
			current = current->next;
		}
		_rotate_(a, b, &op);
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