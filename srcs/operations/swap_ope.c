#include "includes.h"

int	sa(t_data *a)
{
 	int temp;

 	if (a->size < 2)
 		return ;
 	temp = a->head->data;	
 	a->head->data = a->head->next->data;
 	a->head->next->data = temp;
	return (SA);
}

int	sb(t_data *b)
{
 	int temp;

  	if (b->size < 2)
 		return ;
 	temp = b->head->data;	
 	b->head->data = b->head->next->data;
 	b->head->next->data = temp;
	return (SB);
}


int	ss(t_data *a, t_data *b)
{
	sa(a);
	sa(b);
	return (SS);
}