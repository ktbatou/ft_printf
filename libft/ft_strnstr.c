/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:19:32 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:11:27 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (str2[0] == 0)
		return (str1);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (i + j < len && str1[i + j] == str2[j] && str2[j])
				j++;
			if (str2[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (0);
}
