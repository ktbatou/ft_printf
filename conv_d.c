/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/06 18:24:37 by ktbatou          ###   ########.fr       */
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

void	print_d(t_valeur v,  t_valeur vl, t_detail d, t_detail det)
{
	int		i;
	int		j;
	int		n;
	char	*str;
	char	c;

	str = type_conv(vl, det);
	c = ' ';
	n = ft_strlen(str);
	if (v.num)
		i = ft_atoi(v.num);
	if (v.pre)
	{
		j = ft_atoi(v.pre);
		if (j > n)
			n = j;
		if (j == 0)
			n = 0;
		j -= ft_strlen(str);
	}
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (i > n)
		i -= n;
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
	else if (d.plus == 1 && d.zero == 1 && d.point == 0)
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

int		pre_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		i++;
		n++;
	}
	return (i);
}

int		prec(char *str, int n, char **num)
{
	int i;

	i = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		*num[i++] = str[n];
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
	detail.point = 0;
	v.j = 0;
	v.flag = 0;
	v.pre = 0;
	v.num = 0;
	v.i = string_size(str, n);
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
			if (!v.num)
				v.num = ft_strnew(v.i);
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		if (str[n] == '.')
		{
			v.pre = ft_strnew(pre_size(str, n + 1));
			n += prec(str, n + 1, &v.pre);
			detail.point = 1;
		}
		n++;
	}
	print_d(v, valeur, detail, d);
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
