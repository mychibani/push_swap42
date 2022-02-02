#include "includes.h"

// void	pa(t_data *a, t_data *b)
// {
// 	t_stack *elem;
// 	t_stack	*temp;

// 	if (b->size < 1)
// 		return ;
// 	temp = a->head;
// 	elem = a->head;
// 	elem = elem->next;
// 	elem->prev = a->head->prev;
// 	a->head->prev->next = elem;
// 	a->head = elem;
// 	a->size -= 1;
// 	ft_lstpush_front_data(b, temp);
// }

void    reinit(t_data *data, t_stack *head, size_t size)
{
    data->head = head;
    data->size = size;
}

int     pb(t_data *a, t_data *b)
{
    t_stack *elem;

	if (a->size < 1)
		return ;
    if (a->size == 1)
        reinit(a, NULL, 0);
    else
    {
        a->head->next->prev = a->head->prev;
        a->head->prev->next = a->head->next;
        elem = a->head;
        reinit(a, a->head->next, a->size - 1);
    }
	ft_lstpush_front_data(b, elem);
}
