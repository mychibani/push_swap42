/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:37:53 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:38:21 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	_small_sort_(t_data *a)
{
	int	elem0;
	int	elem1;
	int	elem2;

	elem0 = a->head->index;
	elem1 = a->head->next->index;
	elem2 = a->head->next->next->index;
	if (elem0 > elem1 && elem0 > elem2)
		ra(a, "ra\n");
	else if (elem0 < elem1 && elem1 > elem2)
		rra(a, "rra\n");
	if (!_is_sorted_stack_(a))
		sa(a, "sa\n");
	return (_SUCCESS_);
}
