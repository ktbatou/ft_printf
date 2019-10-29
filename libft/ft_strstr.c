/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:06:27 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:10:40 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (s2[0] == 0)
		return (s1);
	while (s1[i])
	{
		if (s2[0] == s1[i])
		{
			j = 0;
			while (s2[j] == s1[i + j] && s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (0);
}
