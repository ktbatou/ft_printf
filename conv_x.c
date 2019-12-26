/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/26 10:38:52 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_x(char *str, va_list s2, int n)
{
	t_detail		d;
	t_unsigned_v	v;

	d = x_flag(str, n);
	v.signe = 0;
	x_types(s2, &v, d);
	return (get_details(str, n, v, d));
}

int		flag_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] != 'x')
	{
		if (str[n] >= 48 && str[n] <= 57)
			i++;
		n++;
	}
	return (i);
}

int		get_details(char *s1, int i, t_unsigned_v vl, t_detail d)
{
	t_valeur	v;
	t_detail	detail;

	intial(&detail, &v);
	while (s1[i] != 'x')
	{
		detail.minus = s1[i] == '-' ? 1 : detail.minus;
		if (s1[i] == '#' && vl.signe == 1)
			detail.hash = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			v.num = !v.num ? ft_strnew(flag_size(s1, i)) : v.num;
			if (s1[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = s1[i];
		}
		if (s1[i] == '.' && (detail.point = 1))
		{
			v.pre = ft_strnew(pre_size(s1, i + 1));
			i += prec(s1, i + 1, v);
		}
		i++;
	}
	return (print_x(&v, vl, detail, d));
}

int		print_x(t_valeur *v, t_unsigned_v vl, t_detail d, t_detail det)
{
	char	*s2;

	s2 = x_conv(vl, det);
	v->f = ft_strlen(s2);
	v->n = v->f;
	if (v->num)
		v->i = ft_atoi(v->num);
	if (v->pre)
	{
		v->j = ft_atoi(v->pre);
		v->f = v->j > v->f ? v->j : v->f;
		if (v->j == 0)
			v->f = 0;
		v->j -= v->n;
	}
	if (v->i > v->f)
	{
		v->i -= v->f;
		v->i -= d.hash == 1 ? 2 : 0;
	}
	else
		v->i = 0;
	v->a = v->i;
	x_cond(d, v, s2);
	return (v->a + v->f);
}
