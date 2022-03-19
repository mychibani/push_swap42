#include "includes.h"

void	_rotate_stacks_(t_data *a, t_data *b, t_op **op)
{
	while ((*op)->ra)
	{
		ra(a, "ra\n");
		(*op)->ra--;
	}
	while ((*op)->rb)
	{
		rb(b, "rb\n");
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
	}
	while ((*op)->rr)
	{
		rr(a, b, "rr\n");
		(*op)->rr--;
	}
}

void	_rotate_(t_data *a, t_data *b, t_op **op)
{
	_reverse_rotate_stacks(a, b, op);
	_rotate_both_stacks(a, b, op);
	_rotate_stacks_(a, b, op);
    reinit_op(*op);
	pa(a, b);
}