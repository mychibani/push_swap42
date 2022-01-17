#include "includes.h"

void	ft_print_elem(t_stack *node)
{
		printf("%p\n", node);
		printf("%d\n", node->data);
		printf("%p\n", node->prev);
		printf("%p\n\n", node->next);
}

/*for tests*/
void	_print_data(t_data *a)
{
	size_t	i;
	t_stack	*current;

	i = 0;
	current = a->head;
	while (i < a->size)
	{
		ft_print_elem(current);
		current = current->next;
		i++;
	}
}