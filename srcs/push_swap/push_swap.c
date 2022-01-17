/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/17 20:27:25 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_data		*prog_data_a;
	t_data		*prog_data_b;

	prog_data_a = (t_data *)malloc(sizeof(t_data));
	prog_data_b = (t_data *)malloc(sizeof(t_data));
	prog_data_a = NULL;
	prog_data_b = NULL;
	if (!prog_data_a || !prog_data_b)
		return(ft_putstr_fd("Error\n", 2));
	if (_parse_(ac, av, prog_data_a) == _ERROR_)
		return(ft_putstr_fd("Error\n", 2));
	if (_init_(prog_data_a) == _ERROR_)
		return(ft_putstr_fd("Error\n", 2));






	// _clean_(prog_data_a);
	return (0);
}
