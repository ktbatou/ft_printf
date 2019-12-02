/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/28 16:07:14 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(char *str, char *num, t_detail d)
{
	int		i;
	char	c;

	i = ft_atoi(num);
	c = ' ';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (d.zero == 1 && d.minus == 0)
		c = '0';
	if (d.minus == 1)
	{
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
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
	detail.plus = 0;
	detail.zero = 0;
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
		n++;
	}
	print_u(num, v.num, detail);
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
