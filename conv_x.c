/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/02 16:33:33 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_detail 	x_flag(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'x')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return(det);
}

int		conv_x(char *str, va_list s2, int n)
{
	char *num;
	t_detail d;
	t_unsigned_v v;

	d = x_flag(str, n);
	v.signe = 0;
	if (d.l == 1)
	{
		if ((v.l = va_arg(s2, unsigned long int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.l, 16, 0);
	}
	else if (d.l == 2)
	{
		if ((v.ll = va_arg(s2, unsigned long long int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.ll, 16, 0);
	}
	else if (d.h == 1)
	{
		if ((v.h = (unsigned short int)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.h, 16, 0);
	}
	else if (d.h == 2)
	{
		if ((v.hh = (unsigned char)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.hh, 16, 0);
	}
	else
	{
		if ((v.i = va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.i, 16, 0);
	}
	get_details(str, num, n, v);
	return (0);
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

void	get_details(char *s1 ,char *str, int i, t_unsigned_v vl)
{
	t_valeur	v;
	t_detail	detail;

	v.j = 0;
	v.flag = 0;
	detail.zero = 0;
	detail.minus = 0;
	detail.hash = 0;
	v.num = ft_strnew(flag_size(s1, i));
	while (s1[i] != 'x')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] == '#' && vl.signe == 1)
			detail.hash = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (s1[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = s1[i];
		}
		i++;
	}
	print_x(v.num, str, detail);
}

void	print_x(char *s1, char *s2, t_detail det)
{
	int	i;
	char	c;

	c = ' ';
	i = atoi(s1);
	if (ft_strlen(s2) < i)
	{
		i -= ft_strlen(s2);
		if (det.hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (det.zero == 1 && det.minus == 0)
		c = '0';
	if (det.zero == 1 && det.minus == 0 && det.hash == 1)
	{
		ft_putstr("0x");
		while (i-- > 0)
			ft_putchar('0');
		ft_putstr(s2);
	}
	else if (det.minus == 1)
	{
		if (det.hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
		if (det.hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
	}
}
