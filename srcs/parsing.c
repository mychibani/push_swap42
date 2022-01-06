#include "includes.h"

char *ft_strdup(char *str)
{
	int	i;
	char *final_str;

	i = 0;
	while (str[i])
		i++;
	final_str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		final_str[i] = str[i];
		i++;
	}	
	final_str[i] = '\0';
	return (final_str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (_TRUE_);
	return (_FALSE_);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *final_line;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (_FALSE_);
	final_line = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_line)
		return (_FALSE_);
	while (s1[i])
	{
		final_line[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_line[i] = s2[j];
		i++;
		j++;
	}
	final_line[i] = '\0';
	return (final_line);
}

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

int	ft_parser(int ac, char **av)
{
	int	i;
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

int	main(int ac, char **av)
{
	printf("%d\n", ft_parser(ac, av));
	while (1);
}
