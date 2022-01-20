/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/19 18:17:27by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"


int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;

	a = malloc(sizeof(t_data));
	b = malloc(sizeof(t_data));
	if (!a || !b)
		return(ft_putstr_fd("Error\n", 2));
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_is_sorted_stack_(a))
		return (_clean_(a, b), 0);
	if (_sorting_algorithm_(a, b))
		return (_clean_(a, b), 0);
	if (_optimus_algo_(a, b))
		return (_clean(a, b), 0);
	return (_clean_(a, b), 0);
}
