/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:48:41 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/14 10:58:25 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_prc(t_valeur v, t_detail d)
{
	int		i;
	char	c;

	i = ft_atoi(v.num);
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
			n_putchar(c, &v);
	}
	else
	{
		while (i-- > 0)
			n_putchar(c, &v);
		n_putchar('%', &v);
	}
	return (v.rest);
}

int		cnt(char *str, int n)
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

int		detail_prc(char *str, int n)
{
	t_detail detail;
	t_valeur v;

	intial(&detail, &v);
	v.num = ft_strnew(cnt(str, n));
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
	return (print_prc(v, detail));
}

int		percent(char *str, va_list s2, int n)
{
	s2 = 0;
	return (detail_prc(str, n));
}
