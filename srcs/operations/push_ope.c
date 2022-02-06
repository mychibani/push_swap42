#include "includes.h"

void    reinit(t_data *data, t_stack *head, size_t size)
{
    data->head = head;
    data->size = size;
}

int     pb(t_data *a, t_data *b)
{
    t_stack *elem;

	if (a->size < 1)
		return (-1);
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
    return (PB);
}

int     pa(t_data *a, t_data *b)
{
    t_stack *elem;

	if (b->size < 1)
		return (-1);
    if (b->size == 1)
        reinit(a, NULL, 0);
    else
    {
        b->head->next->prev = b->head->prev;
        b->head->prev->next = b->head->next;
        elem = b->head;
        reinit(b, b->head->next, b->size - 1);
    }
	ft_lstpush_front_data(b, elem);
    return (PB);
}
