/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/09 15:41:45 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(char *str, t_valeur v, t_detail d)
{
	int		i;
	int 	j;
	char	c;
	int 	n;

	c = ' ';
	n = ft_strlen(str);
	v.n = n;
	if (v.num)
		i = ft_atoi(v.num);
	if (v.pre)
	{
		j = ft_atoi(v.pre);
		if (j > n)
			n = j;
		if (j == 0)
			n = 0;
		j -= v.n;
	}
	if (i > n)
		i -= n;
	else
		i = 0;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
	{
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
	else
	{
		while (i-- > 0)
			ft_putchar(c);
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

int		u_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] != 'u')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

void	u_detail(char *num, char *str, int n)
{
	t_detail detail;
	t_valeur v;

	detail.minus = 0;
	detail.zero = 0;
	detail.point = 0;
	v.num = ft_strnew(u_size(str, n));
	v.flag = 0;
	v.i = 0;
	while (str[n] != 'u')
	{
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.i++] = str[n];
		}
		if  (str[n] == '.')
		{
			v.pre = ft_strnew(pre_size(str, n + 1));
			n += prec(str, n + 1, v);
			detail.point =  1;
		}
		n++;
	}
	print_u(num, v, detail);
}

t_detail 	flags(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'u')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return(det);
}

int		conv_u(char	*str, va_list s2, int n)
{
	t_unsigned_v	v;
	t_detail 		d;
	char			*num;

	d = flags(str, n);
	if (d.l == 1)
	{
		v.l = va_arg(s2, unsigned long int);
		num = ft_untoa(v.l);
	}
	else if (d.l == 2)
	{
		v.ll = va_arg(s2, unsigned long long int);
		num = ft_untoa(v.ll);
	}
	else if (d.h == 1)
	{
		v.h = (unsigned short int)va_arg(s2, unsigned int);
		num = ft_untoa(v.h);
	}
	else if (d.h == 2)
	{
		v.hh = (unsigned char)va_arg(s2, unsigned int);
		num = ft_untoa(v.hh);
	}
	else
	{
		v.i = va_arg(s2, unsigned int);
		num = ft_untoa(v.i);
	}
	u_detail(num, str, n);
	return (0);
}
