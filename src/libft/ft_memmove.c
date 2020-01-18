/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:14:04 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:02:41 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	int		j;
	char	*dstt;
	char	*srcc;

	i = 0;
	j = (int)len;
	dstt = (char *)dst;
	srcc = (char *)src;
	if (dstt > srcc)
	{
		j--;
		while (j >= i)
		{
			dstt[j] = srcc[j];
			j--;
		}
	}
	else
		dstt = ft_memcpy(dst, src, len);
	return ((void *)dstt);
}
