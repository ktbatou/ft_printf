/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:13 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/08 14:48:41 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u(char *str, t_valeur v, t_detail d)
{
	int		n;

	n = ft_strlen(str);
	v.n = n;
	v.i = 0;
	v.j = 0;
	if (v.num)
		v.i = ft_atoi(v.num);
	if (v.pre)
	{
		v.j = ft_atoi(v.pre);
		if (v.j > n && v.j > 0)
			n = v.j;				
		if (v.j == 0 && ft_atoi(str) == 0)
			n = 0;
		v.j -= v.n;
	}
	if (v.i > n)
		v.i -= n;
	else
		v.i = 0;
	cond_u(d, v, str);
	return (v.i + n);
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
