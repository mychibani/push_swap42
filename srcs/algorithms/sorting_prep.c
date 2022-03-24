/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:46:06 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:46:25 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	_sorting_prep_(t_data *a)
{
	t_stack	*curr;
	t_stack	*to_check;
	size_t	i;
	size_t	j;

	i = 0;
	curr = a->head;
	to_check = curr;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (curr->data > to_check->data)
				curr->index++;
			to_check = to_check->next;
			j++;
		}
		curr = curr->next;
		i++;
	}
	return (_SUCCESS_);
}

void	_algo_prep_(t_data *a, t_data *b, size_t opti)
{
	int	i;
	int	median;
	int	max;

	max = _find_max_(a);
	median = a->size / 2;
	i = 0;
	while (a->size > opti)
	{
		if (a->head->index == max)
			ra(a, "ra\n");
		pb(a, b, "pb\n");
		if (b->head->index < median)
			rb(b, "rb\n");
		i++;
	}
}
