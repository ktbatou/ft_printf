/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:31:50 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/27 18:41:48 by ktbatou          ###   ########.fr       */
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

void	print_i(char *num, t_valeur t, t_detail d, t_detail det)
{
	int		i;
	char	c;
	char	*str;

	i = ft_atoi(num);
	c = ' ';
	str = flag_conv(t, det);
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (d.space == 1 && i == 0 && d.minus == 0)
		i++;
	if (d.plus  == 1)
		i--;
	if (d.minus == 0 && d.zero == 1)
		c = '0';
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
		ft_putchar ('+');
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
			ft_putchar ('+');
		ft_putstr(str);
	}
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
	v.flag = 0;
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
		n++;
	}
	print_i(v.num, val, detail, d);
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
