#include "includes.h"

// void	sa(t_data *a)
// {
//  	int temp;

//  	if (a->size < 2)
//  		return ;
//  	temp = a->head->data;	
//  	a->head->data = a->head->next->data;
//  	a->head->next->data = temp;
// 	printf("sa\n");
// }

// void	sb(t_data *b)
// {
//  	int temp;

//  	if (b->size < 2)
//  		return ;
//  	temp = b->head->data;	
//  	b->head->data = b->head->next->data;
//  	b->head->next->data = temp;
// 	printf("sb\n");
// }


// void	ss(t_data *a, t_data *b)
// {
// 	sa(a);
// 	sa(b);
// 	printf("sb\n");
// }

void	sa(t_data *a)
{
	a->head = a->head->next;
	a->head->prev->next = a->head->next;
	a->head->next = a->head->prev;
	a->head->prev = a->tail;
}