/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:47:51 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:48:29 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	_next_greater_(t_data *a, int to_check, int pos_b, t_op **op)
{
	int		i;
	int		temp;
	t_stack	*check_index;

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

int	_find_max_(t_data *stack)
{
	int		i;
	int		max_value;
	t_stack	*index;

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

int	_sum_op_(t_op *op)
{
	return (op->ra + op->rb + op->rra + op->rrb + op->rrr + op->rr);
}
