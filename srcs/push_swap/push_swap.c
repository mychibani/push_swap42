#include "includes.h"

int	main(void)
{
	t_stack		a;
	t_stack		b;
	t_list		*test;
	t_list		*test2;
	t_list		*test3;

	a.head = NULL;
	a.size = 0;
	test = ft_lstnew_doubly_linked(1);
	test2 = ft_lstnew_doubly_linked(2);	
	test3 = ft_lstnew_doubly_linked(3);
	if (!test)
		return (0);
	ft_lstpush_back_stack(&a, test);
	ft_lstpush_back_stack(&a, test2);
	ft_lstpush_front_stack(&a, test3);
	__swap(&a);
	__print_stack(&a);
	__clean(&a);
}
