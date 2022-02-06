/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/02/04 14:20:00by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	_init_stacks_(t_data **a, t_data **b)
{

	*a = (t_data *)malloc(sizeof(t_data));
	*b = (t_data *)malloc(sizeof(t_data));
	if (!a || !b)
		return (_ERROR_);
	(*a)->size = 0;
	(*a)->head = NULL;
	(*b)->size = 0;
	(*b)->head = NULL;
	return (_SUCCESS_);
}

int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;

	if (_init_stacks_(&a, &b) == _ERROR_)
		return (0);
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_is_sorted_stack_(a))
		return (_clean_(a, b), 0);
	if (_sorting_prep_(a) == _ERROR_)
		return (_clean_(a, b), 0);
	//if (_sorting_algorithms_(a, b, res))
	// 	return (_clean_(a, b), 0);
	// if (_optimus_algo_(a, b))
	// 	return (_clean(a, b), 0);
	return (_clean_(a, b), 0);
}
