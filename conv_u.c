/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/25 11:26:14 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(char *num, char *str, int minus, int plus, int zero)
{
	int		i;
	char	c;

	i = ft_atoi(num);
	c = ' ';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (zero == 1 && minus == 0)
		c = '0';
	if (minus == 1)
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

void	u_detail(char *s, char *str, int n)
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
		if (str[n] == '+')
			detail.plus = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.i++] = str[n];
		}
		n++;
	}
	print_u(v.num, s, detail.minus, detail.plus, detail.zero);
}

int		conv_u(char	*str, va_list s2, int n)
{
	unsigned int	i;
	char			*num;

	i = va_arg(s2, unsigned int);
	num = ft_utoa(i);	
	u_detail(num, str, n);
	return (0);
}
