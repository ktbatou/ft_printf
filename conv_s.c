/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:19 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/17 15:05:53 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision(char *str, int n, char *num)
{
	int i;

	i = 0;
	if (str[n] >= 48 && str[n] <= 57)
	{
		while (str[n] >= 48 && str[n] <= 57)
		{
			num[i++] = str[n];
			n++;
		}
	}
	else
		num[i] = '0';
	return (i);
}

static int	ft_size(char *str, int i)
{
	int n;

	n = 0;
	while (str[i++] != 's')
		n++;
	return (n);
}

int			s_detail(t_detail *d, t_valeur *v, char *s1, int n)
{
	int	i;

	i = 0;
	if (s1[n] == '-')
		d->minus = 1;
	if (s1[n] >= 48 && s1[n] <= 57)
	{
		if (!v->num)
			v->num = ft_strnew(ft_size(s1, n));
		v->num[v->i++] = s1[n];
	}
	if (s1[n] == '.')
	{
		v->pre = ft_strnew(pre_size(s1, n + 1));
		i = precision(s1, n + 1, v->pre);
		d->point = 1;
	}
	return (i);
}

int			conv_s(char *s1, va_list s2, int n)
{
	t_valeur	v;
	t_detail	detail;
	char		*str;

	v.i = 0;
	v.num = 0;
	v.pre = 0;
	detail.minus = 0;
	detail.point = 0;
	str = va_arg(s2, char*);
	if (str == NULL)
		str = "(null)";
	while (s1[n] != 's')
	{
		n += s_detail(&detail, &v, s1, n);
		n++;
	}
	return (print_num(v.num, v.pre, str, detail));
}

int			print_num(char *n, char *pre, char *str, t_detail d)
{
	int	i;
	int j;
	int nn;
	int v;

	v = 0;
	i = 0;
	j = 0;
	if (n)
		i = atoi(n);
	if (pre)
		j = atoi(pre);
	nn = ft_strlen(str);
	if (d.point == 1 && (j < ft_strlen(str)))
		nn = j;
	if (nn < i)
		i -= nn;
	else
		i = 0;
	v = i;
	cond_s(d, str, i, j);
	ft_strdel(&n);
	ft_strdel(&pre);
	return (v + nn);
}
