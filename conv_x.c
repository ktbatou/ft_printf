/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/12 19:55:50 by ktbatou          ###   ########.fr       */
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
	detail.point = 0;
	v.num = 0;
	v.pre = 0;
	while (s1[i] != 'x')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] == '#' && vl.signe == 1)
			detail.hash = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (!v.num)
				v.num = ft_strnew(flag_size(s1, i));
			if (s1[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1; 
			v.num[v.j++] = s1[i];
		}
		if (s1[i] == '.')
		{
			v.pre = ft_strnew(pre_size(s1, i + 1));
			i += prec(s1, i + 1, v);
			detail.point = 1;
		}
		i++;
	}
	print_x(v, str, detail);
}

void	print_x(t_valeur v, char *s2, t_detail d)
{
	int		i;
	int		j;
	int		n;
	char	c;

	c = ' ';
	n = ft_strlen(s2);
	v.n = n;
	i = 0;
	j = 0;
	v.j = 0;
	if (v.num)
		i = ft_atoi(v.num);
	if (v.pre)
	{
		j = ft_atoi(v.pre);
		v.j = j;
		if (j > n)
			n = j;
		if (j == 0)
			n = 0;
		j -= v.n;
	}
	if (i > n)
	{
		i -= n;
		if (d.hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.zero == 1 && d.minus == 0 && d.hash == 1 && d.point == 0)
	{
		ft_putstr("0x");
		while (i-- > 0)
			ft_putchar('0');
		ft_putstr(s2);
	}
	else if (d.minus == 1)
	{
		if (d.hash == 1)
			ft_putstr("0x");
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(s2, 0);
		else
			ft_putstr(s2);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
		if (d.hash == 1)
			ft_putstr("0x");
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(s2, 0);
		else
			ft_putstr(s2);
	}
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&s2);
}
