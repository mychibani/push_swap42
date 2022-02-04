#include "includes.h"

int	*_init_index_tab(int size)
{
	int	*tab;
	int	i;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	_sorting_prep_(t_data *a)
{
	t_stack *curr;
	t_stack *to_check;
	int 	*index_tab;
	int		i;
	int		j;

	i = 0;
	index_tab = _init_index_tab(a->size);
	curr = a->head;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (curr->data > to_check->data)
				index_tab[i]++;
			if (to_check->data == curr->data)
			{
				to_check = to_check->next;
				j++;
			}
			to_check = to_check->next;
			j++;
		}
		i++;
	}
	a->index_tab = index_tab;
	return (_SUCCESS_);
}

t_list *_small_sort_(t_data *a, t_list *res)
{
	int tab[3];

	tab[0] = (int)a->head->data;
	tab[1] = (int)a->head->next->data;
	tab[2] = (int)a->head->next->next->data;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[1])
		ft_lst_add_back(&res, ft_lst_new(sa(a)));
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ft_lst_add_back(&res, ft_lst_new(ra(a)));
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		ft_lst_add_back(&res, ft_lst_new(rra(a)));
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		ft_lst_add_back(&res, ft_lst_new(sa(a)));
		ft_lst_add_back(&res, ft_lst_new(ra(a)));
	}
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[3])
	{
		ft_lst_add_back(&res, ft_lst_new(sa(a)));
		ft_lst_add_back(&res, ft_lst_new(rra(a)));
	}
	return (res);
}

int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
{
	if (a->size < 3)
		_small_sort_(a, res);
	else
		_bigi_sort_(a, b, res);
	return (res);
}
