#include "includes.h"

void	ft_print_elem(t_stack *node)
{
		printf("%p\n", node);
		printf("%d\n", node->data);
		printf("%p\n", node->prev);
		printf("%p\n\n", node->next);
}

/*for tests*/
void		_print_data_(t_data *data)
{
	size_t	i;
	t_stack	*current;

	i = 0;
	current = data->head;
	while (i < data->size)
	{
		ft_print_elem(current);
		current = current->next;
		i++;
	}
}