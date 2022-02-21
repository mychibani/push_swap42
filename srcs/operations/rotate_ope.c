#include "includes.h"

int ra(t_data *a)
{
    if (a->size < 2)
        return (-1);
    a->head = a->head->next;
    printf("ra\n");
    return (RA);
}

int rb(t_data *b)
{
    if (b->size < 2)
        return (-1);
    b->head = b->head->next;
    printf("rb\n");
    return (RB);
}

int	rr(t_data *a, t_data *b)
{
    printf("rr\n");
    ra(a);
    rb(b);
    return (RRR);
}