#include "includes.h"

void	_next_greater_(t_data *a, int to_check, int pos_b, t_op **op)
{
	int			i;
	int			temp;
	t_stack		*check_index;

	i = 0;
	(*op)->pos_b = pos_b;
	check_index = a->head;
	temp = _find_max_(a);
	while (i < (int)a->size)
	{
		if (to_check < check_index->index && temp >= check_index->index)
		{
			(*op)->pos_a = i;
			temp = check_index->index;
		}
		i++;
		check_index = check_index->next;
	}
}


void	_rotate_stacks_(t_data *a, t_data *b, t_op **op)
{
	while ((*op)->ra)
	{
		ra(a, "ra\n");
		(*op)->ra--;
	}
	while ((*op)->rb)
	{
		rb(a, "rb\n");
		(*op)->rb--;
	}
}

void	_reverse_rotate_stacks(t_data *a, t_data *b, t_op **op)
{
	while((*op)->rra)
	{
		rra(a, "rra\n");
		(*op)->rra--;
	}
	while((*op)->rrb)
	{
		rrb(b, "rrb\n");
		(*op)->rrb--;
	}
}

void	_rotate_both_stacks(t_data *a, t_data *b, t_op **op)
{
	while ((*op)->rrr)
	{
		rrr(a, b, "rrr\n");
			(*op)->rrr--;
		(*op)->rra--;
		(*op)->rrb--;
	}
	while ((*op)->rr)
	{
		rr(a, b, "rr\n");
			(*op)->rr--;
	}
}

void	_rotate_(t_data *a, t_data *b, t_op **op)
{
	_rotate_both_stacks(a, b, op);
	_rotate_stacks_(a, b, op);
	_reverse_rotate_stacks(a, b, op);
}

int	_sum_op_(t_op *op)
{
	return (op->ra + op->rb + op->rra + op->rrb + op->rrr + op->rr);
}