/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:16:18 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:07:08 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	s;
	size_t			i;
	size_t			j;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	s = (unsigned char)c;
	i = 0;
	j = 0;
	while (i < n)
	{
		dst1[j] = src1[i];
		if (src1[i] == s)
			return ((void*)(dst1 + i + 1));
		i++;
		j++;
	}
	return (NULL);
}
