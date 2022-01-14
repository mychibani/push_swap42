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

/*for tests*/
void	ft_print_elem(t_list *node)
{
		printf("%p\n", node);
		printf("%d\n", node->data);
		printf("%p\n", node->prev);
		printf("%p\n\n", node->next);
}

/*for tests*/
void	__print_stack(t_stack *a)
{
	size_t	i;
	t_list	*current;

	i = 0;
	current = a->head;
	while (i < a->size)
	{
		ft_print_elem(current);
		current = current->next;
		i++;
	}
}

void	__clean(t_stack *list)
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

void	__swap(t_stack *meta_data)
{
	int temp;

	if (meta_data->size < 2)
		return ;
	temp = meta_data->head->data;	
	meta_data->head->data = meta_data->head->next->data;
	meta_data->head->next->data = temp;
}
