/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:36:38 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:37:43 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	a_up_and_b_down(t_data *b, t_op *op)
{
	reinit_op(op);
	op->ra = op->pos_a;
	op->rrb = b->size - op->pos_b;
	op->max_op = _sum_op_(op);
	return (op->max_op);
}

int	b_up_and_a_down(t_data *a, t_op *op)
{
	reinit_op(op);
	op->rb = op->pos_b;
	op->rra = a->size - op->pos_a;
	op->max_op = _sum_op_(op);
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
	return (op->max_op);
}

int	_calcul_positions_(t_data *a, t_data *b, t_op *op)
{
	t_op	*best_case;

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
