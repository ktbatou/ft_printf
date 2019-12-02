/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:45:33 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/02 16:52:17 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_X(char *str, char *s, int minus, int hash, int zero)
{
	int	i;
	char	c;

	i = atoi(s);
	c = ' ';
	if (ft_strlen(str) < i)
	{
		i -= ft_strlen(str);
		if (hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (zero == 1 && minus == 0)
		c = '0';
	if (zero == 1 && minus == 0 && hash == 1)
	{
		ft_putstr("0X");
		while (i-- > 0)
			ft_putchar('0');
		ft_putstr(str);
	}
	else if (minus == 1)
	{
		if (hash == 1)
			ft_putstr("0X");
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while(i-- > 0)
			ft_putchar(c);
		if (hash == 1)
			ft_putstr("0X");
		ft_putstr(str);
	}
}

int		flag(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n++] != 'X')
		i++;
	return (i);
}

void	details(char *s, char *str, int i, t_unsigned_v val)
{ 
	t_valeur v;
	t_detail detail;

	detail.minus = 0;
	detail.hash = 0;
	detail.zero = 0;
	v.flag = 0;
	v.j = 0;
	v.num = ft_strnew(flag(str, i));
	while (str[i] != 'X')
	{
		if (str[i]  >= '0' && str[i] <= '9')
		{
			if (str[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[i];
		}
		if (str[i] == '-')
			detail.minus = 1;
		if (str[i] == '#' && val.signe == 1)
			detail.hash = 1;
		i++;
	}
	print_X(s, v.num, detail.minus, detail.hash, detail.zero);
}

t_detail 	X_flag(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'X')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return(det);
}

int		conv_xx(char *str, va_list s2, int n)
{
	char	*num;
	t_detail d;
	t_unsigned_v v;

	d = X_flag(str, n);
	v.signe = 0;
	if (d.l == 1)
	{
		if ((v.l = va_arg(s2, unsigned long int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.l, 16, 1);
	}
	else if (d.l == 2)
	{
		if ((v.ll = va_arg(s2, unsigned long long int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.ll, 16, 1);
	}
	else if (d.h == 1)
	{
		if ((v.h = (unsigned short int)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.h, 16, 1);
	}
	else if (d.h == 2)
	{
		if ((v.hh = (unsigned char)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.hh, 16, 1);
	}
	else
	{
		if ((v.i = va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.i, 16, 1);
	}
	details(num, str, n, v);
	return (0);
}
