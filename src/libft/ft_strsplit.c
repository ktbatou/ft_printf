/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:20:00 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/26 12:20:08 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(const char *str, char c)
{
	int	i;
	int	flag;
	int	nb;

	i = 0;
	flag = 1;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (flag)
				nb++;
			flag = 0;
		}
		else if (str[i] == c)
			flag = 1;
		i++;
	}
	return (nb);
}

static int	len(const char *str, int i, char c)
{
	int	nb;

	nb = 0;
	while (str[i] != c)
	{
		i++;
		nb++;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		t;
	char	**str;

	i = 0;
	t = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_word(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
		{
			k = 0;
			if (!(str[t] = (char *)malloc(sizeof(char) * (len(s, i, c) + 1))))
				return (NULL);
			while (s[i] && s[i] != c)
				str[t][k++] = s[i++];
			str[t++][k] = '\0';
		}
	}
	str[t] = 0;
	return (str);
}
