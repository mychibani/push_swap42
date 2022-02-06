#include "includes.h"

int	sa(t_data *a)
{
 	int temp;

 	if (a->size < 2)
 		return (-1);
 	temp = a->head->data;	
 	a->head->data = a->head->next->data;
 	a->head->next->data = temp;
	temp = a->head->index;
	a->head->index = a->head->next->index;
	a->head->next->index = temp;
	return (SA);
}

int	sb(t_data *b)
{
 	int temp;

  	if (b->size < 2)
 		return (-1);
 	temp = b->head->data;	
 	b->head->data = b->head->next->data;
 	b->head->next->data = temp;
	temp = b->head->index;
	b->head->index = b->head->next->index;
	b->head->next->index = temp;
	return (SB);
}


int	ss(t_data *a, t_data *b)
{
	sa(a);
	sa(b);
	return (SS);
}