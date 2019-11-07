/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:19 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/07 18:38:13 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(char *str, int i)
{
	int n;
	
	n = 0;
	while (str[i] != 's')
	{
		n++;
		i++;
	}
	return (n);
}

int	conv_s(char *s1, va_list s2, int n)
{
	int			i;
	int			j;
	char		*str;
	char		*num;
	t_detail	detail;

	i = 0;
	detail.num = 0;
	str = va_arg(s2, char*);
	ft_size(s1, n);
	num = ft_strnew(ft_size(s1, n));
	while (s1[n] != 's')
	{
		if (s1[n] >= 48 && s1[n] <= 57)
			num[i++] = s1[n];
		n++;
	}
	j = atoi(num);
	ft_putstr(str);
	if (ft_strlen(str) < j)
		j -= ft_strlen(str);
	while (j-- >= 0)
		ft_putchar(' ');
	return (0);
}
