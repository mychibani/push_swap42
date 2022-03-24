/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:18:44 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:08:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	_gnl_clean_(char *str)
{
	free(str);
}

int	_stdin_parsing_(char *str, t_data *a, t_data *b)
{
	if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sa\0"))
		sa(a, "");
	else if (!ft_strcmp(str, "sb\n") || !ft_strcmp(str, "sb\0"))
		sb(b, "");
	else if (!ft_strcmp(str, "ss\n") || !ft_strcmp(str, "ss\0"))
		ss(a, b, "");
	else if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pa\0"))
		pa(a, b, "");
	else if (!ft_strcmp(str, "pb\n") || !ft_strcmp(str, "pb\0"))
		pb(a, b, "");
	else if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "ra\0"))
		ra(a, "");
	else if (!ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rb\0"))
		rb(b, "");
	else if (!ft_strcmp(str, "rr\n") || !ft_strcmp(str, "rr\0"))
		rr(a, b, "");
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rra\0"))
		rra(a, "");
	else if (!ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rrb\0"))
		rrb(b, "");
	else if (!ft_strcmp(str, "rrr\n") || !ft_strcmp(str, "rrr\0"))
		rrr(a, b, "");
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int	_do_prompt_instructions_(t_data *a, t_data *b)
{
	char	*str;

	str = __gnl(0);
	while (str)
	{
		if (_stdin_parsing_(str, a, b) == _ERROR_)
			return (_ERROR_);
		_gnl_clean_(str);
		str = __gnl(0);
	}
	return (_SUCCESS_);
}

int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;
	t_op		*op;

	op = init_op();
	if (_init_stacks_(&a, &b) == _ERROR_)
		return (0);
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_do_prompt_instructions_(a, b) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_is_sorted_stack_(a))
		return (_clean_(a, b, op), ft_putstr_fd("OK\n", 1));
	else
		return (_clean_(a, b, op), ft_putstr_fd("KO\n", 1));
	return (_clean_(a, b, op), 0);
}
