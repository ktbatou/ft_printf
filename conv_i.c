/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:31:50 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/18 15:24:37 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_i(char *num, char *str, int plus, int minus, int zero)
{
	int		i;
	char	c;

	i = ft_atoi(num);
	c = ' ';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (minus == 0 && zero == 1)
		c = '0';
	if (minus == 1)
	{
		if (plus == 1)
			ft_putchar ('+');
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

int		i_size(char	*str, int n)
{
	int i;
	
	i = 0;
	while (str[n++] != 'd')
		i++;
	return (i);
}

void	i_detail(char *s, char *str, int n)
{
	t_valeur	v;
	t_detail	detail;

	v.i = 0;
	detail.minus = 0;
	detail.plus = 0;
	detail.zero = 0;
	v.flag = 0;
	v.num = ft_strnew(i_size(str, n));
	while (str[n] != 'i')
	{
		if (str[n] == '+')
			detail.plus = 1;
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
	print_i(v.num, s, detail.plus, detail.minus, detail.zero);
}

int		conv_i(char	*str, va_list s2, int n)
{
	int		nb;
	char	*num;

	nb = va_arg(s2, int);
	num = ft_itoa(nb);
	i_detail(num, str, 1);
	return (0);
}
