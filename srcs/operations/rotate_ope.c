#include "includes.h"

int ra(t_data *a)
{
    a->head = a->head->next;
    return (RA);
}

int rb(t_data *b)
{
    b->head = b->head;
    return (RB);
}

int	rr(t_data *a, t_data *b)
{
    ra(a);
    rb(b);
    return (RRR);
}