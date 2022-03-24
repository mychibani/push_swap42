/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy_doubly_linked.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:03:51 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:05:54 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_data	*ft_lstcopy_doubly_linked(t_data *a)
{
	t_data	*a_copy;
	int		i;

	i = 0;
	a_copy = NULL;
	while (i < a->size)
	{
		ft_lst_addback(a_copy, a->head->data);
		a->head = a->head->next;
		i++;
	}
	return (a_copy);
}
