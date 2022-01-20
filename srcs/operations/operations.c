#include "includes.h"

void	swap(t_stack *meta_data)
{
 	int temp;

 	if (meta_data->size < 2)
 		return ;
 	temp = meta_data->head->data;	
 	meta_data->head->data = meta_data->head->next->data;
 	meta_data->head->next->data = temp;
}

void    rotate(t_stack *meta_data)
{


}

void    push(t_stack *stack_a, t_stack *stack_b)
{

}

void    reverse_rotate(t_stack *a, t_stack *b)
{

}