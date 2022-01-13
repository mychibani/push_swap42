#include "includes.h"

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (_FALSE_);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			return (_FALSE_);
		if (str[i] == '-' && str[i])
		 	i++;
		 while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] && str[i] != ' ')
			return (_FALSE_);
	}
	return (_TRUE_);
}

int	_parse_(int ac, char **av)
{
i	int	i;
	char *res;

	res = ft_strdup("");
	i = 1;
	if (ac < 2)
		return (_ERROR_);
	else
	{
		while (i < ac)
		{
			res = ft_strjoin(res, " ");
			res = ft_strjoin(res, av[i]);
			i++;
		}
		if (ft_check_str(res))
		{
			free(res);
			return (_SUCCESS_);
		}
	}
	free(res);
	return (_FALSE_);
}
