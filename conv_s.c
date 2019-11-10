/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:19 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/09 17:34:33 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(char *str, int i)
{
	int n;
	
	n = 0;
	while (str[i++] != 's')
		n++;
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
	detail.minus = 0;
	str = va_arg(s2, char*);
	ft_size(s1, n);
	num = ft_strnew(ft_size(s1, n));
	while (s1[n] != 's')
	{
		if (s1[n] == '-')
			detail.minus = 1;
		if (s1[n] >= 48 && s1[n] <= 57)
			num[i++] = s1[n];
		n++;
	}
	print_num(num, str, detail.minus);
	return (0);
}

void	print_num(char *n, char *str, int minus)
{
	int	i;

	i = atoi(n);
	 if (ft_strlen(str) < i)
		 i -= ft_strlen(str);
	 else
		 i = 0;
	 if (minus == 1)
	{
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
}
