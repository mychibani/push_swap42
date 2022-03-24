/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:33:14 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 11:34:01 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	sa(t_data *a, char *str)
{
	int	temp;

	if (a->size < 2)
		return (SA);
	temp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = temp;
	temp = a->head->index;
	a->head->index = a->head->next->index;
	a->head->next->index = temp;
	ft_putstr_fd(str, 1);
	return (SA);
}

int	sb(t_data *b, char *str)
{
	int	temp;

	if (b->size < 2)
		return (SB);
	temp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = temp;
	temp = b->head->index;
	b->head->index = b->head->next->index;
	b->head->next->index = temp;
	ft_putstr_fd(str, 1);
	return (SB);
}

int	ss(t_data *a, t_data *b, char *str)
{
	sa(a, "");
	sb(b, "");
	ft_putstr_fd(str, 1);
	return (SS);
}
