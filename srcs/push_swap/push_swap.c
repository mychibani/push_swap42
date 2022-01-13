/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/13 14:57:45by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
	if (!a || !b)
		ft_putstr_fd("Error\n", 2);
	if (!_parse_(ac, av))
		ft_putstr_fd("Error\n", 2);
	return (0);
}
