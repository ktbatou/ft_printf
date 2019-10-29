/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:37:21 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:13:31 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*str;

	str = (char *)s;
	j = ft_strlen(str);
	if (str[ft_strlen(str)] == (char)c)
		return (str + ft_strlen(str));
	while (j >= 0)
	{
		if (str[j] == (char)c)
			return (str + j);
		j--;
	}
	return (NULL);
}
