#include "includes.h"

/*a mettre dans libft*/
t_list	*ft_lstnew_doubly_linked(int data)
{
	t_list *new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)	
		return (NULL);
	new_elem->data = data;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}
/**/

void	ft_lstpush_back_stack(t_stack *lst, t_list *node)
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

void	ft_lstpush_front_stack(t_stack *lst, t_list *node)
{
	ft_lstpush_back_stack(lst, node);
	lst->head = node;
}

void	ft_init_stacks(t_stack **a, t_stack **b, char **av, int ac)
{
	int	i;
	int	nb;
	t_list *node;

	i =	1;
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
		return ;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		node = ft_lstnew_doubly_linked(nb);
		ft_lstpush_back_stack(*a, node);
		i++;
	}
}

void	_clean_(t_stack *list)
{
	size_t	i;
	t_list	*dent;

	i = 0;
	while (i < list->size)
	{
		dent = list->head;	
		list->head = dent->next;
		free(dent);
		i++;
	}
	list->head = NULL;
	list->size = 0;
}