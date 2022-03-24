/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:17:59 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:28:26 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

long	_atol_(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	nbr_check(char *str, int size)
{
	long	nbr;

	nbr = _atol_(str);
	if (size > _INT_SIZE_MAX || nbr > _INT_MAX_ || nbr < _INT_MIN_)
		return (_ERROR_);
	return (_SUCCESS_);
}

int	ft_check_str(char *str)
{
	int	i;
	int	start;

	i = 0;
	if (!str)
		return (_ERROR_);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (_ERROR_);
		start = i;
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] != '\0' && str[i] != ' ')
			return (_ERROR_);
		if (nbr_check(str + start, i - start) == _ERROR_)
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

int	_parse_(int ac, char **av, t_data *data)
{
	int		i;
	char	*res;

	i = 1;
	res = NULL;
	if (ac < 2)
		return (_ERROR_);
	while (i < ac)
	{
		res = _strjoin(res, " ");
		res = _strjoin(res, av[i]);
		i++;
	}
	if (ft_check_str(res) == _SUCCESS_)
	{
		data->string = res;
		return (_SUCCESS_);
	}
	return (free(res), _ERROR_);
}
