#include "includes.h"

/*for tests*/
void	ft_print_elem(t_stack *node)
{
//		printf("\tnode == %p\n", node);
	printf("\tnode data == %d\n", node->data);
	//printf("\tnode index == %d\n", node->index);
	//	printf("\tnode prev == %p\n", node->prev);
		//printf("\tnode next == %p\n\n", node->next);
}

/*for tests*/
void		_print_data_(t_data *data)
{
	t_stack		*current;
	size_t		i;

	i = 0;
	current = data->head;
	//printf("data->head == %p\n", data->head);
	printf("data->size == %zu\n", data->size);
	while (i < data->size)
	{
		ft_print_elem(current);
		current = current->next;
		i++;
	}
}