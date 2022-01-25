#include "includes.h"

/*a mettre dans libft*/
t_stack	*ft_lstnew_doubly_linked(int data)
{
	t_stack *new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)	
		return (NULL);
	new_elem->data = data;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}
/**/

void		ft_lstpush_back_data(t_data *lst, t_stack *node)
{
	if (!lst->size)
	{
		lst->head = node;
		node->prev = node;	
		node->next = node;	
		lst->size += 1;
		return ;
	}
	node->next = lst->head;
	node->prev = lst->head->prev;
	lst->head->prev = node;
	node->prev->next = node;
	lst->size += 1;
}

void		ft_lstpush_front_data(t_data *lst, t_stack *node)
{
	ft_lstpush_back_data(lst, node);
	lst->head = node;
}

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
	int		i;
	char	*res;
	t_stack	*temp;

	i = 0;
	res = a->string;
	while (res[i])
	{
		while (res[i] == ' ')
			i++;
		if (!res[i])
			break ;
		temp = ft_lstnew_doubly_linked(ft_atoi(&res[i]));
		ft_lstpush_back_data(a, temp);
		while (ft_isdigit(res[i]) || res[i] == '-')
			i++;
	}
	if (_is_duplicate_elem_(a))
	{
		free(a->string);
		return (_ERROR_);
	}
	free(a->string);
	return (_SUCCESS_);
}

void		_clean_(t_data *a, t_data *b)
{
	size_t		i;
	t_stack		*dent;

	i = 0;
	while (i < a->size)
	{
		dent = a->head;
		a->head = dent->next;
		free(dent);
		i++;
	}
	a->head = NULL;
	a->size = 0;
	while (i < b->size)
	{
		dent = b->head;
		b->head = dent->next;
		free(dent);
		i++;
	}
	b->head = NULL;
	b->size = 0;
	free(a);
	free(b);
}