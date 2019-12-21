/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:48:41 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/21 16:26:55 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prc(char *num, t_detail d)
{
	int		i;
	char	c;

	i = ft_atoi(num);
	c = ' ';
	if (i >= 1)
		i--;
	else
		i = 0;
	if (d.zero == 1 && d.minus == 0)
		c = '0';
	if (d.minus == 1)
	{
		ft_putchar('%');
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
		ft_putchar('%');
	}
}

int		count(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n] != '%')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

void	detail_prc(char *str, int n)
{
	t_detail detail;
	t_valeur v;

	v.flag = 0;
	v.j = 0;
	detail.minus = 0;
	detail.zero = 0;
	v.num = ft_strnew(count(str, n));
	while (str[n] != '%')
	{
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		n++;
	}
	print_prc(v.num, detail);
}

int		percent(char *str, va_list s2, int n)
{
	detail_prc(str, n);
	return (0);
}
