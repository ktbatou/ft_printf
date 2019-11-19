/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/18 16:54:47 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(char *num, char *str, int  minus, int plus, int zero)
{
	int	i;
	char	c;

	i = atoi(num);
	c = ' ';
	if (zero == 1 && minus == 0)
		c = '0';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (minus == 1)
	{
		if (plus == 1)
		{
			ft_putchar('+');
			i--;
		}
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

int		string_size(char *str, int	n)
{
	int 	i;

	i = 0;
	while (str[n++] != 'd')
		i++;
	return (i);
}

void	d_detail(char *s1, char *str, int	n)
{
	t_valeur	v;
	t_detail	detail;

	v.j = 0;
	detail.minus = 0;
	detail.plus = 0;
	detail.zero = 0;
	v.flag = 0;
	v.num = ft_strnew(string_size(str, n));
	while (str[n] != 'd')
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
			v.num[v.j++] = str[n];
		}
		n++;
	}
	print_d(v.num, s1, detail.minus, detail.plus, detail.zero);
}

int		conv_d(char *str, va_list s2, int n)
{
	int		  num;
	int			i;
	char		*s1;
	
	num = va_arg(s2, int);
	s1 = ft_itoa(num);
	d_detail(s1, str, n);
	return (0);
}
