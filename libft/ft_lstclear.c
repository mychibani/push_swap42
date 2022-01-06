/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:02:34 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/24 08:22:48 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_delete;

	while (*lst)
	{
		to_delete = *lst;
		(*del)(to_delete->content);
		*lst = to_delete->next;
		free(to_delete);
	}
	*lst = NULL;
}
