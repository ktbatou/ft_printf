/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:38:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:05:18 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	l;

	str = (unsigned char *)b;
	l = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = l;
		i++;
	}
	return ((void*)str);
}
