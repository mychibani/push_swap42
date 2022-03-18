
#include "includes.h"
#include "unistd.h"


t_op	*init_op(void)
{
	t_op	*new;

	new = (t_op *)malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->rr = 0;
	new->rrr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->ra = 0;
	new->rb = 0;
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
	new->max_op = _INT_MAX_;
}

int	_sum_op_(t_op *op)
{
	return (op->ra + op->rb + op->rra + op->rrb + op->rrr + op->rr);
}

void	reset_stack(t_data *a, t_data *b)
{
	int		i;
	t_stack	*current;
	t_op	*op;

	i = 0;
	op = init_op();
	current = a->head;
	while (i < (int)a->size)
	{
		if (!current->index)
			break;
		i++;
		current = current->next;
	}
	if (i < a->size / 2)
		op->ra = i;
	else
		op->rra = a->size - i;
	_rotate_(a, b, &op);
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
	reinit_op(op);
	op->ra = op->pos_a;
	op->rrb = b->size - op->pos_b;
	op->max_op = _sum_op_(op);
	// printf("a up and b down [%d]\n", op->max_op);
	return (op->max_op);
}

int	b_up_and_a_down(t_data *a, t_op *op)
{
	reinit_op(op);
	op->rb = op->pos_b;
	op->rra = a->size - op->pos_a;
	op->max_op = _sum_op_(op);
	// printf("a and b down [%d]\n", op->max_op);
	return (op->max_op);
}

int	a_and_b_up(t_op *op)
{
	reinit_op(op);
	if (op->pos_a >= op->pos_b)
	{
		op->ra = op->pos_a - op->pos_b;
		op->rr = op->pos_a - op->ra;
	}
	else
	{
		op->rb = op->pos_b - op->pos_a;
		op->rr = op->pos_b - op->rb;
	}
	op->max_op = _sum_op_(op);
	/*ft_putnbr_fd(op->max_op, 1);
	ft_putstr_fd("   machin\n", 1);*/
	// printf("a and b up [%d]\n", op->max_op);
	return (op->max_op);
}

int	a_and_b_down(t_op *op, t_data *a, t_data *b)
{
	reinit_op(op);
	op->pos_a = a->size - op->pos_a;
	op->pos_b = b->size - op->pos_b;
	if (op->pos_a >= op->pos_b)
	{
		op->rra = op->pos_a - op->pos_b;
		op->rrr = op->pos_a - op->rra;
	}
	else
	{
		op->rrb = op->pos_b - op->pos_a;
		op->rrr = op->pos_b - op->rrb;
	}
	op->max_op = _sum_op_(op);
	
	/*ft_putnbr_fd(op->max_op, 1);
	ft_putstr_fd("   truc\n", 1);
	// printf("a and b down [%d]\n", op->max_op);*/
	return (op->max_op);
}

int	_calcul_positions(t_data *a, t_data *b, t_op *op)
{
	t_op *best_case;

	best_case = init_op();
	best_case->pos_a = op->pos_a;
	best_case->pos_b = op->pos_b;
	if (op->max_op > a_up_and_b_down(b, best_case))
	  	a_up_and_b_down(b, op);
	if (op->max_op > b_up_and_a_down(a, best_case))
		b_up_and_a_down(a, op);
	if (op->max_op > a_and_b_up(best_case))
	 	a_and_b_up(op);
	if (op->max_op > a_and_b_down(best_case, a, b))
		a_and_b_down(op, a, b);
	free(best_case);
	return (op->max_op);
}

int	ft_sorting_algo(t_data *a, t_data *b, t_op *op)
{
	t_stack *current;
	t_op	*best_op;
	int		i;

	i = 0;
	_algo_prep_(a, b);
	best_op = init_op();
	current = b->head;
	while (b->size > 0)
	{
		reinit_op(op);
		while (i < (int)b->size)
		{
			reinit_op(best_op);
			_next_greater_(a, current->index, i, &best_op);
			_next_greater_(a, current->index, i, &op);
			if (op->max_op > _calcul_positions(a, b, best_op))
				_calcul_positions(a, b, op);
			i++;
			current = current->next;
		}
		/*_print_data_(a);
		_print_data_(b);*/
		_rotate_(a, b, &op);
		i = 0;
		current = b->head;
	}
	reset_stack(a, b);
	free(best_op);
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
