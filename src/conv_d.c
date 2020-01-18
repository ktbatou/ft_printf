/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/26 10:41:09 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_d(t_valeur v, t_valeur vl, t_detail d, t_detail det)
{
	int		n;
	char	*str;

	v.i = 0;
	str = type_conv(vl, det);
	n = ft_strlen(str);
	v.n = n;
	if ((vl.j == 0 && d.point == 1 && ft_atoi(v.pre) > (int)ft_strlen(str)))
		v.n--;
	if (v.num)
		v.i = ft_atoi(v.num);
	if (v.pre)
		n = pre_vlr(&v, vl, n);
	if (v.i > n)
		v.i -= n;
	else
		v.i = 0;
	if (d.plus == 1)
		v.i--;
	cond(d, v, vl, str);
	return (v.i + n);
}

int			string_size(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n] != 'd')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

int			checker_d(t_detail *d, t_valeur *v, char *s, int n)
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

int			d_detail(t_valeur valeur, char *str, int n, t_detail d)
{
	t_valeur	v;
	t_detail	detail;

	intial(&detail, &v);
	v.i = string_size(str, n);
	v.n = valeur.j;
	while (str[n] != 'd')
	{
		n += checker_d(&detail, &v, str, n);
		n++;
	}
	return (print_d(v, valeur, detail, d));
}

int			conv_d(char *str, va_list s2, int n)
{
	t_detail	detail;
	t_valeur	vlr;

	intial(&detail, &vlr);
	detail = flag_detail(str, n);
	types(s2, detail, &vlr);
	return (d_detail(vlr, str, n, detail));
}
