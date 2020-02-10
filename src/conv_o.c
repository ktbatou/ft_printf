/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:12:16 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/10 13:26:48 by ktbatou          ###   ########.fr       */
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
	if (v->num && (v->rest = ft_atoi(v->num)))
		v->i = ft_atoi(v->num);
	if (v->pre)
	{
		v->j = ft_atoi(v->pre);
		v->f = v->j;
		if (v->j > n && v->j > 0)
			n = v->j;
		if (v->j == 0 && ft_atoi(str) == 0)
			n = 0;
		v->j -= v->n;
	}
	if (v->i > n)
		v->i -= n;
	else
		v->i = 0;
	o_cond(d, *v, str);
	printf("{v->n == %d} \n", v->n);
	printf("{v->f == %d} \n", v->f);
	if ((d.hash == 1 && d.point == 1 && v->f == 0 && v->rest == 0) ||
		(d.hash == 1 && d.point == 1 && vl.signe == 1 && n >= v->rest && v->n > v->f) ||
		(d.hash == 1 && d.point == 0 &&  n >= v->rest))
		return (v->i + n + 1);
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
	detail->minus = str[n] == '-' ? 1 : detail->minus;
	if (str[n] == '#')
		detail->hash = 2;
	detail->hash = (detail->hash == 2 && v->a == 1) ? 1 : detail->hash;
	if (str[n] >= '0' && str[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(num_size(str, n));
		if (str[n] == '0' && v->flag == 0)
			detail->zero = 1;
		v->flag = 1;
		v->num[v->j++] = str[n];
	}
	if (str[n] == '.' && (detail->point = 1))
	{
		v->pre = ft_strnew(pre_size(str, n + 1));
		i = prec(str, n + 1, *v);
		detail->hash = (detail->hash == 2 && v->a == 0) ? 1 : detail->hash;
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
	t_detail		det;
	t_unsigned_v	v;

	v.signe = 0;
	det = flag_det(str, n);
	o_types(&det, &v, s2);
	return (detail_o(str, n, v, det));
}
