/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:11:18 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:10:25 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t dstsize;
	size_t srcsize;
	size_t i;
	size_t j;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	j = 0;
	if (dstsize >= size)
		return (srcsize + size);
	else
	{
		i = srcsize + dstsize;
		while (src[j] && dstsize < size - 1)
		{
			dst[dstsize] = src[j];
			j++;
			dstsize++;
		}
		dst[dstsize] = '\0';
		return (i);
	}
}
