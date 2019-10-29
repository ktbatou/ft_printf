/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:45:49 by ktbatou           #+#    #+#             */
/*   Updated: 2019/10/29 13:59:11 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(char *l)
{
	int i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}


void	d(char *s, int nb)
{
	int i;
	char c;
	char *str;

	i = 0;
	c = nb + '0';
	str = ft_strnew(ft_size(s) + 1);
	while (s[i])
	{
		str[i] = s[i];
		if (s[i] == '%' && s[i+1] == 'd')
			str[i++] = c;
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
	
}
