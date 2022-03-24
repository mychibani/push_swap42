/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_doubly_linked.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:25 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:03:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_stack	*ft_lstnew_doubly_linked(int data)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->index = 0;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}
