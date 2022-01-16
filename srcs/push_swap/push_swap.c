/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/16 17:54:37 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	if (_parse_(ac, av) == _ERROR_)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_init_stacks(&a, &b, av, ac);
	_print_stack(a);
	printf("-------------------\n");
	_print_stack(b);
	_clean_(a);
	_clean_(b);
	free(a);
	free(b);
	return (0);
}
