#include "includes.h"

t_op	*init_op(void)
{
	t_op	*new;

	new = (t_op *)malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->rr = 0;
	new->rrr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->ra = 0;
	new->rb = 0;
	new->max_op = _INT_MAX_;
	new = NULL;
	return (new);
}

void	reinit_op(t_op *new)
{
	new->rr = 0;
	new->rrr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->ra = 0;
	new->rb = 0;
	new->max_op = _INT_MAX_;
	new = NULL;
}
