#include "includes.h"

void	ft_print_elem(t_list *node)
{
		printf("%p\n", node);
		printf("%d\n", node->data);
		printf("%p\n", node->prev);
		printf("%p\n\n", node->next);
}

/*for tests*/
void	_print_stack(t_stack *a)
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
