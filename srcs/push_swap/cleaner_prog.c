#include "includes.h"

void		_clean_(t_data *a, t_data *b, t_list *res)
{
	size_t		i;
	t_stack		*elem;

	i = 0;
	free(a->string);
	free(a->index_tab);
	while (i < a->size)
	{
		elem = a->head;
		a->head = dent->next;
		free(elem);
		i++;
	}
	a->head = NULL;
	a->size = 0;
	i = 0;
	while (i < b->size)
	{
		elem = b->head;
		b->head = elem->next;
		free(dent);
		i++;
	}
	b->head = NULL;
	b->size = 0;
	free(a);
	free(b);
}
