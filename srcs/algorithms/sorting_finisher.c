#include "includes.h"

void	_reset_stack_(t_data *a, t_data *b, t_op *op)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = a->head;
	while (i < (int)a->size)
	{
		if (!current->index)
			break;
		i++;
		current = current->next;
	}
	if (i < (int)a->size / 2)
		op->ra = i;
	else
		op->rra = a->size - i;
	_rotate_(a, b, &op);
}

