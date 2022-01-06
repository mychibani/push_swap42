/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:13:33 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/23 15:50:30 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	final_str = ft_calloc(i, sizeof(char));
	if (!(final_str))
		return (0);
	ft_strlcpy(final_str, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(final_str, (char *)s2, i);
	return (final_str);
}
