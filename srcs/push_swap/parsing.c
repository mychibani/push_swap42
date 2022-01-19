#include "includes.h"

int	nbr_check(char *str, int size)
{
	long	nbr;

	/*faire atol*/
	nbr = atol(str);
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
		start =	i;
		if (str[i] == '-')
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

	res = ft_strdup("");
	i = 1;
	if (ac < 2)
		return (free(res), _ERROR_);
	while (i < ac)
	{
		res = ft_strjoin(res, " ");
		res = ft_strjoin(res, av[i]);
		i++;
	}
	if (ft_check_str(res) == _SUCCESS_)
	{
		data->string = res;
		return (_SUCCESS_);
	}
	return (free(res), _ERROR_);
}
