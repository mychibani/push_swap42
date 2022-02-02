#include "includes.h"

t_res *_sorted_small_sort_(t_data *a, t_res *soluce)
{
	
}

t_res *_medium_sort(t_data *a, t_data *b)
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
