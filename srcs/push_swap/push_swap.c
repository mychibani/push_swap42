/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/14 14:19:26 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (_parse_(ac, av) == _ERROR_)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
