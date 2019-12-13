/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:31:50 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/12 19:49:14 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_conv(t_valeur v, t_detail d)
{
	char 	*str;

	if (d.l == 1)
		str = ft_ntoa(v.l);
	else if (d.l == 2)
		str = ft_ntoa(v.ll);
	else if (d.h == 1)
		str = ft_ntoa(v.h);
	else if (d.h == 2)
		str = ft_ntoa(v.hh);
	else
		str = ft_ntoa(v.i);
	return (str);
}

void	print_i(t_valeur v, t_valeur t, t_detail d, t_detail det)
{
	int		n;
	char	c;
	char	*str;

	c = ' ';
	str = flag_conv(t, det);
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
	{
		v.j = ft_atoi(v.pre);
		if (v.j > n)
		{
			n = v.j;
			if (t.j == 0)
				n++;
		}
		if (v.j == 0)
			n = 0;
		v.j -= v.n;
	}
	if (v.i > n)
		v.i -= n;
	else
		v.i = 0;
	if (d.minus == 0 && d.zero == 1 && d.point == 0)
		c = '0';
	if (d.plus == 1)
		v.i--;
	print_cond(d, v, t, str, c);
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
}

int		i_size(char	*str, int n)
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

void	i_detail(t_valeur val, t_detail d, char *str, int n)
{
	t_valeur	v;
	t_detail	detail;

	v.i = 0;
	detail.minus = 0;
	detail.plus = 0;
	detail.zero = 0;
	detail.space = 0;
	detail.point = 0;
	v.flag = 0;
	v.pre = 0;
	v.num = ft_strnew(i_size(str, n));
	while (str[n] != 'i')
	{
		if (str[n] == '+' && val.j == 1)
			detail.plus = 1;
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] == ' ' && val.j == 1)
			detail.space = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.i++] = str[n];
		}
		if (str[n] == '.')
		{
			v.pre = ft_strnew(pre_size(str, n + 1));
			n += prec(str, n + 1, v);
			detail.point = 1;
		}
		n++;
	}
	print_i(v, val, detail, d);
}

t_detail	type_flag(char *str, int n)
{
	t_detail detail;

	detail.l = 0;
	detail.h = 0;
	while(str[n] != 'i')
	{
		if (str[n] == 'l')
			detail.l++;
		if (str[n] == 'h')
			detail.h++;
		n++;
	}
	return (detail);
}

int		conv_i(char	*str, va_list s2, int n)
{
	t_detail det;
	t_valeur v;

	det = type_flag(str, n);
	v.j = 0;
	if (det.l == 1)
	{
		if ((v.l = va_arg(s2, long int)) >= 0)
			v.j = 1;
	}
	else if (det.l == 2)
	{
		if ((v.ll = va_arg(s2, long long int)) >= 0)
			v.j = 1;
	}
	else if (det.h == 1)
	{
		if ((v.h = (short int)va_arg(s2, int)) >= 0)
			v.j = 1;
	}
	else if (det.h == 2)
	{
		if ((v.hh = (signed char)va_arg(s2, int)) >= 0)
			v.j = 1;
	}
	else
	{
		if ((v.i = va_arg(s2, int)) >= 0)
			v.j = 1;
	}
	i_detail(v, det, str, n);
	return (0);
}
