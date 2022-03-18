#include "includes.h"
#include "unistd.h"

int	rra(t_data *a, char *str)
{
	if (a->size > 1)
	{
		a->head = a->head->prev;
		ft_putstr_fd(str, 1);
		//write(1, "TWROITJSIUGHSUIDGHISUGBSIUGBSUIG", 12);
	}
	return (RRA);
}

int	rrb(t_data *b, char *str)
{
	if (b->size > 1)
	{
		b->head = b->head->prev;
		ft_putstr_fd(str, 1);
	}
	return (RRB);
}

int	rrr(t_data *a, t_data *b, char *str)
{
	rra(a, "");
	rrb(b, "");
	ft_putstr_fd(str, 1);
	return (RRR);
}
