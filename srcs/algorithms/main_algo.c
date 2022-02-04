#include "includes.h"

void    get_index(t_data *a, t_data *b)
{
    int *tab_a;
    int *tab_b;
    int i;

    i = 0;
    tab_a = (int *)malloc(sizeof(a->size));
    while (i < a->size)
    {
        tab_a[i] = i;
        i++;
    }
    a->index_tab = tab_a;
    i = 0;
    tab_b = (int *)malloc(sizeof(b->size));
    while (i < b->size)
    {
        tab_b[i] = i;
        i++;
    }
}

t_list *_bigi_sort_(t_data *a, t_data *b, t_list *res)
{

}