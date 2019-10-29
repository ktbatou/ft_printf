/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:58:24 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:13:39 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	l;
	char	*str;

	i = 0;
	l = (char)c;
	str = (char *)s;
	if (str[ft_strlen(str)] == l)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == l)
			return (str + i);
		i++;
	}
	return (NULL);
}
