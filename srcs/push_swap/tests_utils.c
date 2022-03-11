#include "includes.h"

/*for tests*/
void	ft_print_elem(t_stack *node)
{
//		printf("\tnode == %p\n", node);
	//printf("\tnode data == %d\n", node->data);
	printf("\tnode index == %d\n", node->index);
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

void		_print_op_(t_op *op)
{
	printf("----------\n\n");
	printf("RA NBR [%d]\n", op->ra);
	printf("RB NBR [%d]\n", op->rb);
	printf("RRA NBR [%d]\n", op->rra);
	printf("RRB NBR [%d]\n", op->rrb);
	printf("RRR NBR [%d]\n", op->rrr);
	printf("RR NBR [%d]\n", op->rr);
	printf("COUNT OF MOVE [%d]\n", op->max_op);
	printf("POS_A [%d]\n", op->pos_a);
	printf("POS_B [%d]\n", op->pos_b);
	printf("----------\n\n");
}