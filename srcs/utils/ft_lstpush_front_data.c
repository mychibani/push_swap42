#include "includes.h"

void		ft_lstpush_front_data(t_data *lst, t_stack *node)
{
	ft_lstpush_back_data(lst, node);
	lst->head = node;
}
