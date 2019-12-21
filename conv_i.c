/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:31:50 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/21 14:25:20 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_i(t_valeur v, t_valeur t, t_detail d, t_detail det)
{
	int		n;
	char	*str;

	str = type_conv(t, det);
	n = ft_strlen(str);
	v.n = n;
	v.i = 0;
	v.j = 0;
	if (v.num)
		v.i = ft_atoi(v.num);
	if ((t.j == 0 && d.point == 1 && ft_atoi(v.pre) > ft_strlen(str)))
		v.n--;
	if (v.num)
		v.i = ft_atoi(v.num);
	if (v.pre)
		n = pre_vlr(&v, t, n);
	if (v.i > n)
		v.i -= n;
	else
		v.i = 0;
	if (d.plus == 1)
		v.i--;
	cond(d, v, t, str);
	return (v.i + n);
}

int			i_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] != 'i')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

int			i_check(t_detail *d, t_valeur *v, char *s, int n)
{
	int i;

	i = 0;
	if (s[n] == '+' && v->n == 1)
		d->plus = 1;
	if (s[n] == '-')
		d->minus = 1;
	if (s[n] == ' ' && v->n == 1)
		d->space = 1;
	if (s[n] >= '0' && s[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(v->i);
		if (s[n] == '0' && v->flag == 0)
			d->zero = 1;
		v->flag = 1;
		v->num[v->j++] = s[n];
	}
	if (s[n] == '.')
	{
		v->pre = ft_strnew(pre_size(s, n + 1));
		i = prec(s, n + 1, *v);
		d->point = 1;
	}
	return (i);
}

int			i_detail(t_valeur val, t_detail d, char *str, int n)
{
	t_valeur	v;
	t_detail	detail;

	intial(&detail, &v);
	v.num = ft_strnew(i_size(str, n));
	v.n = val.j;
	while (str[n] != 'i')
	{
		n += i_check(&detail, &v, str, n);
		n++;
	}
	return (print_i(v, val, detail, d));
}

int			conv_i(char *str, va_list s2, int n)
{
	t_detail det;
	t_valeur v;

	det = type_flag(str, n);
	v.j = 0;
	types(s2, det, &v);
	return (i_detail(v, det, str, n));
}
