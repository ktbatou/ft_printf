/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:12:16 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/23 17:08:14 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_o(t_valeur *v, t_detail d, t_unsigned_v vl, t_detail det)
{
	int		n;
	char	*str;

	str = conv_flag(vl, det);
	n = ft_strlen(str);
	v->n = n;
	if (v->num)
		v->i = ft_atoi(v->num);
	if (v->pre)
	{
		v->j = ft_atoi(v->pre);
		v->f = v->j;
		if (v->j > n)
			n = v->j;
		if (v->j == 0)
			n = 0;
		v->j -= v->n;
	}
	if (v->i > n)
		v->i -= n;
	else
		v->i = 0;
	o_cond(d, *v, str);
	return (v->i + n);
}

int		num_size(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n] != 'o')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

int		o_checker(char *str, int n, t_detail *detail, t_valeur *v)
{
	int i;

	i = 0;
	if (str[n] == '-')
		detail->minus = 1;
	if (str[n] == '#' && v->a == 1)
		detail->hash = 1;
	if (str[n] >= '0' && str[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(num_size(str, n));
		if (str[n] == '0' && v->flag == 0)
			detail->zero = 1;
		v->flag = 1;
		v->num[v->j++] = str[n];
	}
	if (str[n] == '.')
	{
		v->pre = ft_strnew(pre_size(str, n + 1));
		i = prec(str, n + 1, *v);
		detail->point = 1;
	}
	return (i);
}

int		detail_o(char *str, int n, t_unsigned_v vl, t_detail d)
{
	t_detail detail;
	t_valeur v;

	intial(&detail, &v);
	v.a = vl.signe;
	while (str[n] != 'o')
	{
		n += o_checker(str, n, &detail, &v);
		n++;
	}
	return (print_o(&v, detail, vl, d));
}

int		conv_o(char *str, va_list s2, int n)
{
	char			*num;
	t_detail		det;
	t_unsigned_v	v;

	v.signe = 0;
	det = flag_det(str, n);
	o_types(&det, &v, s2);
	return (detail_o(str, n, v, det));
}
