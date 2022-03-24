/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:48:38 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:51:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	_main_algorithm_(t_data *a, t_data *b, t_op *op)
{
	t_stack	*current;
	t_op	*best_op;
	int		i;

	i = 0;
	best_op = init_op();
	current = b->head;
	while (b->size > 0)
	{
		while (i < (int)b->size)
		{
			reinit_op(best_op);
			_next_greater_(a, current->index, i, &best_op);
			_next_greater_(a, current->index, i, &op);
			if (op->max_op > _calcul_positions_(a, b, best_op))
				_calcul_positions_(a, b, op);
			current = current->next;
			i++;
		}
		_rotate_(a, b, &op);
		current = b->head;
		i = 0;
	}
	_reset_stack_(a, b, op, best_op);
	return (_SUCCESS_);
}

int	_big_algo_(t_data *a, t_data *b, t_op *op)
{
	_algo_prep_(a, b, 1);
	_main_algorithm_(a, b, op);
	return (_SUCCESS_);
}

int	_medium_sort_(t_data *a, t_data *b, t_op *op)
{
	_algo_prep_(a, b, 3);
	_small_sort_(a);
	if (_is_sorted_stack_(b))
		sb(b, "sb\n");
	_main_algorithm_(a, b, op);
	return (_SUCCESS_);
}

int	_sorting_algorithms_(t_data *a, t_data *b, t_op *op)
{
	if (a->size == 2)
		sa(a, "sa\n");
	else if (a->size == 3)
		_small_sort_(a);
	else if (a->size < 6)
		_medium_sort_(a, b, op);
	else
		_big_algo_(a, b, op);
	return (_SUCCESS_);
}
