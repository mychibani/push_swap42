#include "includes.h"

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[j] > tab[i])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		j = 0;
		i++;
	}
}

int *_init_tab_(t_data *list)
{
	int *tab;
	t_stack *current;
	size_t i;

	tab = (int *)malloc(sizeof(int) * list->size);
	if (!tab)
		return (0);
	current = list->head;
	i = 0;
	while (i < list->size)
	{
		tab[i] = current->index;
		current = current->next;
		i++;
	}
	return (tab);
}

int get_median(int *tab, int size)
{
	ft_sort_int_tab(tab, size);
	return (tab[size - 1] / 2);
}

int _sorting_prep_(t_data *a)
{
	t_stack *curr;
	t_stack *to_check;
	size_t i;
	size_t j;

	i = 0;
	curr = a->head;
	to_check = curr;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (curr->data > to_check->data)
				curr->index++;
			to_check = to_check->next;
			j++;
		}
		curr = curr->next;
		i++;
	}
	return (_SUCCESS_);
}

// int	_sorting_algorithms_(t_data *a, t_data *b, t_stack *res)
// {
// 	if (a->size < 3)
// 		_small_sort_(a, res);
// 	else
// 		_bigi_sort_(a, b, res);
// 	return (res);
// }