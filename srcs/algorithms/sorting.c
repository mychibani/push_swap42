#include "includes.h"

void	_small_sort_(t_data *a, t_data *b)
{
	int i;

	i = 0;
	while (i < 1)
		i++;
	return (0);
}

void	_medium_sort(t_data *a, t_data *b)
{
	_sorted_small_sort_(a, 0);
	_rev_small_sort(b, 0);
}

void	_bigi_sort(t_data *a, t_data *b)
{

}

int	_sorting_algorithms_(t_data *a, t_data *b)
{
	t_res	*res;

	res = NULL;
	if (a->size < 8)
		_small_sort(a, 0);
	else if (a->size < 16)
		_medium_sort_(a, b);
	else
		_bigi_sort(a, b);
	return (res);
}
