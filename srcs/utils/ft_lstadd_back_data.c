#include "includes.h"

void	ft_lstadd_back_data(t_data *a, int data)
{
	t_stack *new;

	new = ft_lstnew_doubly_linked(data);
	ft_lstpush_back_data(a, new);
}
