#include <stdio.h>
#include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_stack		t_stack;

struct s_list
{
	int	data;

	t_list *prev;
	t_list *next;
};

struct s_stack
{
	t_list *head;
	size_t size;
	
};

t_list	*ft_lstnew(int data)
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

void	ft_lstpush_back(t_stack *lst, t_list *node)
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

void	ft_lstpush_front(t_stack *lst, t_list *node)
{
	ft_lstpush_back(lst, node);
	lst->head = node;
}

void	ft_print_elem(t_list *node)
{
		printf("%p\n", node);
		printf("%d\n", node->data);
		printf("%p\n", node->prev);
		printf("%p\n\n", node->next);
}

void	ft_print_lst(t_stack *a)
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
	int		i;
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
	meta_data->next->data = temp;
}

int	main(void)
{
	t_stack		a;
	t_stack		b;
	t_list		*test;
	t_list		*test2;
	t_list		*test3;

	a.head = NULL;
	a.size = 0;
	test = ft_lstnew(1);
	test2 = ft_lstnew(2);	
	test3 = ft_lstnew(3);
	if (!test)
		return (0);
	ft_lstpush_back(&a, test);
	ft_lstpush_back(&a, test2);
	ft_lstpush_front(&a, test3);
	__swap(a.head);
	ft_print_lst(&a);
	ft_clean_stack(&a);
}