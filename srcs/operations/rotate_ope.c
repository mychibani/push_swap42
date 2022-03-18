#include "includes.h"

int ra(t_data *a, char *str)
{
    if (a->size > 1)
    {
        a->head = a->head->next;
        ft_putstr_fd(str, 1);
    }
    return (RA);
}

int rb(t_data *b, char *str)
{
    if (b->size > 1)
    {
        b->head = b->head->next;
        ft_putstr_fd(str, 1);
    }
    return (RB);
}

int	rr(t_data *a, t_data *b, char *str)
{
    ra(a, "");
    rb(b, "");
    ft_putstr_fd(str, 1);
    return (RRA);
}