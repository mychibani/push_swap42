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

void	free_all(t_data *a, t_data *b)
{
	free(a);
	free(b);
}

int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;

	a = malloc(sizeof(t_data));
	b = malloc(sizeof(t_data));
	if (!a || !b)
		return(ft_putstr_fd("Error\n", 2));
	if (_parse_(ac, av, a) == _ERROR_)
		return(free_all(a, b), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return(free_all(a, b), ft_putstr_fd("Error\n", 2));
	_print_data_(a);
	_clean_(a, b);
	free_all(a, b);
	return (0);
}
