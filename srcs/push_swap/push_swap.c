/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:21:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;
	t_op		*op;

	op = init_op();
	if (ac < 2)
		return (free(op), 0);
	if (_init_stacks_(&a, &b) == _ERROR_)
		return (0);
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_is_sorted_stack_(a))
		return (_clean_(a, b, op), 0);
	if (_sorting_prep_(a) == _ERROR_)
		return (_clean_(a, b, op), 0);
	if (_sorting_algorithms_(a, b, op) == _SUCCESS_)
		return (_clean_(a, b, op), 0);
	return (_clean_(a, b, op), 0);
}
