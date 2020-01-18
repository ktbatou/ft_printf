/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:47:11 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:19:17 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	if (!(s))
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	n = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (s[i] == '\0')
	{
		str = ft_strsub(s, i, 1);
		str[n] = '\0';
		return (str);
	}
	str = ft_strsub(s, i, (j - i + 1));
	return (str);
}
