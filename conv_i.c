/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:31:50 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/24 18:50:36 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_i(char *num, int nb, t_detail d)
{
	int		i;
	char	c;
	char	*str;

	i = ft_atoi(num);
	c = ' ';
	str = ft_itoa(nb);
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

void	i_detail(int nb, char *str, int n)
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
		if (str[n] == '+' && nb >= 0)
			detail.plus = 1;
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] == ' ' && nb >= 0)
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
	print_i(v.num, nb, detail);
}

int		conv_i(char	*str, va_list s2, int n)
{
	int		nb;
	char	*num;

	nb = va_arg(s2, int);
//	num = ft_itoa(nb);
	i_detail(nb, str, n);
	return (0);
}
