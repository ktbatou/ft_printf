/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/19 18:34:00 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u(char *str, t_valeur v, t_detail d)
{
	int		i;
	int		j;
	char	c;
	int		n;

	c = ' ';
	n = ft_strlen(str);
	v.n = n;
	i = 0;
	j = 0;
	if (v.num)
		i = ft_atoi(v.num);
	if (v.pre)
	{
		j = ft_atoi(v.pre);
		if (j > n)
			n = j;
		if (j == 0)
			n = 0;
		j -= v.n;
	}
	if (i > n)
		i -= n;
	else
		i = 0;
	v.a = i;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
	{
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(str, 0);
		else
			ft_putstr(str);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(str, 0);
		else
			ft_putstr(str);
	}
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
	return (v.a + n);
}

int			u_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] != 'u')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

int			u_check(char *str, t_detail *d, t_valeur *v, int n)
{
	int i;

	i = 0;
	if (str[n] == '-')
		d->minus = 1;
	if (str[n] >= '0' && str[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(u_size(str, n));
		if (str[n] == '0' && v->flag == 0)
			d->zero = 1;
		v->flag = 1;
		v->num[v->i++] = str[n];
	}
	if (str[n] == '.')
	{
		v->pre = ft_strnew(pre_size(str, n + 1));
		i = prec(str, n + 1, *v);
		d->point = 1;
	}
	return (i);
}

int			u_detail(char *num, char *str, int n)
{
	t_detail detail;
	t_valeur v;

	detail.minus = 0;
	detail.zero = 0;
	detail.point = 0;
	v.flag = 0;
	v.i = 0;
	v.pre = 0;
	v.num = 0;
	while (str[n] != 'u')
	{
		n += u_check(str, &detail, &v, n);
		n++;
	}
	return (print_u(num, v, detail));
}

int			conv_u(char *str, va_list s2, int n)
{
	t_unsigned_v	v;
	t_detail		d;
	char			*num;

	d = flags(str, n);
	u_types(d, &v, &num, s2);
	return (u_detail(num, str, n));
}
