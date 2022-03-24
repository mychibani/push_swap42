/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_finisher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:35:22 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:54:28 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	_reset_stack_(t_data *a, t_data *b, t_op *op, t_op *op_to_kill)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = a->head;
	while (i < (int)a->size)
	{
		if (!current->index)
			break ;
		i++;
		current = current->next;
	}
	if (i < (int)a->size / 2)
		op->ra = i;
	else
		op->rra = a->size - i;
	_rotate_(a, b, &op);
	free(op_to_kill);
}
