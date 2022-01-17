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

void	ft_lstpush_back_data(t_data *lst, int nb)
{
	t_stack *node;

	node = ft_lstnew_doubly_linked(nb);
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

void	ft_lstpush_front_data(t_data *lst, int nb)
{
	t_stack *node;

	node = ft_lstnew_doubly_linked(nb);
	if (!lst->size)
	{
		lst->head = node;
		node->prev = node;	
		node->next = node;	
		return ;
	}
	node->next = lst->head;
	node->prev = lst->head->prev;
	lst->head->prev = node;
	node->prev->next = node;
	lst->head = node;
}

int		_init_(t_data *prog_data)
{
	int	i;
	char *res;

	i = 0;
	res = prog_data->string;
	while (res[i])
	{
		while (res[i] == ' ')
			i++;
		if (!res[i])
			break ;
		ft_lstpush_back_data(prog_data, ft_atoi(&res[i]));
		printf("%zu\n", prog_data->size);
		while (ft_isdigit(res[i]) || res[i] == '-')
			i++;
	}
	return (_SUCCESS_);
}

void	_clean_(t_data *stack)
{
	size_t		i;
	t_stack		*dent;

	i = 0;
	while (i < stack->size)
	{
		dent = stack->head;
		stack->head = dent->next;
		free(dent);
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}