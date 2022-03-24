/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_reinit_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:38:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:39:08 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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

int	_init_stacks_(t_data **a, t_data **b)
{
	*a = (t_data *)malloc(sizeof(t_data));
	*b = (t_data *)malloc(sizeof(t_data));
	if (!a || !b)
		return (_ERROR_);
	(*a)->size = 0;
	(*a)->string = NULL;
	(*a)->head = NULL;
	(*b)->size = 0;
	(*b)->head = NULL;
	return (_SUCCESS_);
}
