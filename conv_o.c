/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:12:16 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/12 19:51:05 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_o(char *str , t_valeur v, t_detail d)
{
	int		i;
	int		j;
	int     n;
	char	c;

	c = ' ';
	n = ft_strlen(str);
	v.n = n;
	i = 0;
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
		i -= n;
	else
		i = 0;
	if ((d.hash == 1 && (v.n > v.j))
			|| (d.hash == 1 && v.j == 0))
		i--;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c  ='0';
	if (d.minus == 1)
	{
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if ((d.hash == 1 && (v.n > v.j)) ||
			   (d.hash == 1 && v.j == 0))
			ft_putchar('0');
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
		if ((d.hash == 1 && v.n >= v.j) ||
				(d.hash == 1 && v.j == 0)) 
			ft_putchar('0');
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
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
}

int		num_size(char *str, int n)
{
	int	 i;

	i = 0;
	while (str[n] != 'o')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return(i);
}

void	detail_o(char *nb, char *str, int n, t_unsigned_v vl)
{
	t_detail detail;
	t_valeur v;

	v.j = 0;
	v.flag = 0;
	detail.minus = 0;
	detail.hash = 0;
	detail.zero = 0;
	detail.point = 0;
	v.num = 0;
	v.pre = 0;
	while (str[n]  != 'o')
	{
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] == '#' && vl.signe == 1)
			detail.hash = 1;
		if (str[n]  >= '0' && str[n] <= '9')
		{
			if (!v.num)
				v.num = ft_strnew(num_size(str, n));
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		if (str[n] == '.')
		{
			v.pre = ft_strnew(pre_size(str, n + 1));
			n += prec(str, n + 1, v);
			detail.point = 1;
		}
		n++;
	}
	print_o(nb, v, detail);
}

t_detail 	flag_det(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'o')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return(det);
}

int		conv_o(char	*str, va_list s2, int n)
{
	char	*num;
	t_detail det;
	t_unsigned_v v;

	det = flag_det(str, n);
	v.signe = 0;
	if (det.l == 1)
	{
		if ((v.l = va_arg(s2, unsigned long int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.l, 8, 0);
	}
	else if (det.l == 2)
	{
		if ((v.ll = va_arg(s2, unsigned long long int)) != 0)
			v.signe = 1;	
		num = ft_itoa_base(v.ll, 8, 0);
	}
	else if (det.h == 1)
	{
		if ((v.h = (unsigned short int)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.h, 8, 0);
	}
	else if (det.h == 2)
	{
		if ((v.hh = (unsigned char)va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.hh, 8, 0);
	}
	else
	{
		if ((v.i = va_arg(s2, unsigned int)) != 0)
			v.signe = 1;
		num = ft_itoa_base(v.i, 8, 0);
	}
	detail_o(num, str, n, v);
	return (0);
}	
