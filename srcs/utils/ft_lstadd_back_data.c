/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:01:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:01:53 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_lstadd_back_data(t_data *a, int data)
{
	t_stack	*new;

	new = ft_lstnew_doubly_linked(data);
	ft_lstpush_back_data(a, new);
}
