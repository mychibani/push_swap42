#include "includes.h"

int	_is_duplicate_elem_(t_data *a)
{
	t_stack		*current;
	t_stack		*to_check;
	size_t		i;
	size_t		j;

	i = 0;
	current = a->head;
	while(i < a->size)
	{
		j = i + 1;
		to_check = current->next;
		while (j < a->size)
		{
			if (current->data == to_check->data)
				return (_TRUE_);
			to_check = to_check->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (_FALSE_);
}

int	_is_sorted_stack_(t_data *a)
{
	size_t	i;
	t_stack *current;

	i = 0;
	current = a->head;
	if (a->size < 2)
		return (_TRUE_);
	while (i < a->size - 1)
	{
		if (current->data > current->next->data)
			return (_FALSE_);
		current = current->next;
		i++;
	}
	return (_TRUE_);
}

int		_init_(t_data *a)
{
	size_t	i;
	char	*res;

	i = 0;
	res = a->string;
	while (res[i])
	{
		while (res[i] == ' ')
			i++;
		if (!res[i])
			break ;
		ft_lstadd_back_data(a, (int)ft_atoi(&res[i]));
		while (ft_isdigit(res[i]) || res[i] == '-')
			i++;
	}
	if (_is_duplicate_elem_(a))
		return (_ERROR_);
	return (_SUCCESS_);
}