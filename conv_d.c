/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/27 16:43:29 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_conv(t_valeur v, t_detail det)
{
	char	*str;

	if (det.l == 1)
		str = ft_ntoa(v.l);
	else if (det.l == 2)
		str = ft_ntoa(v.ll);
	else if (det.h == 1)
		str = ft_ntoa(v.h);
	else if (det.h == 2)
		str = ft_ntoa(v.hh);
	else
		str = ft_ntoa(v.i);
	return (str);
}

void	print_d(char *num, t_valeur vl, t_detail d, t_detail det)
{
	int	i;
	char	*str;
	char	c;

	i = ft_atoi(num);
	str = type_conv(vl, det);
	c = ' ';
	if (d.zero == 1 && d.minus == 0)
		c = '0';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (d.plus == 1)
		i--;
	if (d.minus == 1)
	{
		if (d.space == 1 && d.plus == 0)
		{
			ft_putchar(' ');
			i--;
		}
		if (d.plus == 1)
			ft_putchar('+');
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(c);
	}
	else if (d.plus == 1 && d.zero == 1)
	{
		ft_putchar('+');
		while (i-- > 0)
			ft_putchar(c);
		ft_putstr(str);
	}	
	else
	{
		if (d.space == 1 && d.plus == 0)
		{
			ft_putchar(' ');
			i--;
		}
		while (i-- > 0)
			 ft_putchar(c);
		if (d.plus == 1)
			ft_putchar('+');
		ft_putstr(str);
	}
}

int		string_size(char *str, int	n)
{
	int 	i;

	i = 0;
	while (str[n] != 'd')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

void	d_detail(t_valeur valeur, char *str, int n, t_detail d)
{
	t_valeur	v;
	t_detail	detail;

	detail.space = 0;
	detail.plus = 0;
	detail.minus = 0;
	detail.zero = 0;
	v.j = 0;
	v.flag = 0;
	v.num = ft_strnew(string_size(str, n));
	while (str[n] != 'd')
	{
		if (str[n] == '+' && valeur.j == 1)
			detail.plus = 1;
		if (str[n] == '-')
			detail.minus =   1;
		if (str[n] == ' ' && valeur.j == 1)
			detail.space = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		n++;
	}
	print_d(v.num, valeur, detail, d);
}

t_detail	flag_detail(char *str, int n)
{
	t_detail flag;

	flag.l = 0;
	flag.h = 0;

	while (str[n] != 'd')
	{
		if (str[n] == 'l')
			flag.l++;
		if (str[n] == 'h')
			flag.h++;
		n++;
	}
	return (flag);
}

int		conv_d(char *str, va_list s2, int n)
{
	char		*s1;
	t_detail	detail;
	t_valeur 	vlr;

	detail.l = 0;
	detail.h = 0;
	vlr.l = 0;
	vlr.h = 0;
	vlr.j = 0;
	detail = flag_detail(str, n);
	if (detail.l == 1)
	{
		if ((vlr.l = va_arg(s2, long int)) >= 0)
			vlr.j = 1;
	}
	else if (detail.l == 2)
	{
		if ((vlr.ll = va_arg(s2, long long int)) >= 0)
			vlr.j = 1;
	}
	else if (detail.h == 1)
	{
		if ((vlr.h = (short int)va_arg(s2, int)) >= 0)
			vlr.j = 1;
	}
	else if (detail.h == 2)
	{
		if ((vlr.hh = (signed char)va_arg(s2, int)) >= 0)
			vlr.j = 1;
	}
	else
	{
		if ((vlr.i = va_arg(s2, int)) >= 0)
			vlr.j = 1;
	}
	d_detail(vlr, str, n, detail);
	return (0);
}
