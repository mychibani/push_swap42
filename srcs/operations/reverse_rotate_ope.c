/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ope.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:34:26 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:34:27 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	rra(t_data *a, char *str)
{
	if (a->size > 1)
	{
		a->head = a->head->prev;
		ft_putstr_fd(str, 1);
	}
	return (RRA);
}

int	rrb(t_data *b, char *str)
{
	if (b->size > 1)
	{
		b->head = b->head->prev;
		ft_putstr_fd(str, 1);
	}
	return (RRB);
}

int	rrr(t_data *a, t_data *b, char *str)
{
	rra(a, "");
	rrb(b, "");
	ft_putstr_fd(str, 1);
	return (RRR);
}
