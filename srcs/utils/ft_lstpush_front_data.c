/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:03:27 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:03:36 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_lstpush_front_data(t_data *lst, t_stack *node)
{
	ft_lstpush_back_data(lst, node);
	lst->head = node;
}
