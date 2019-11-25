/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/24 18:43:53 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(char *num, int nb, t_detail d)
{
	int	i;
	char	*str;
	char	c;

	i = ft_atoi(num);
	str = ft_itoa(nb);
	c = ' ';
	if (d.zero == 1 && d.minus == 0)
		c = '0';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (d.plus == 1)
		i--;
	if (d.minus == 1)
	{
		if (d.space == 1)
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
		if (d.space == 1)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putchar('+');
		while (i-- > 0)
			ft_putchar(c);
		ft_putstr(str);
	}	
	else
	{
		if (d.space == 1)
		{
			ft_putchar(' ');
			i--;
		}
		while (i-- > 0)
			 ft_putchar(c);
		if (d.plus == 1)
			ft_putchar('+');
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

void	d_detail(int num, char *str, int	n)
{
	t_valeur	v;
	t_detail	detail;

	v.j = 0;
	detail.minus = 0;
	detail.plus = 0;
	detail.zero = 0;
	detail.space = 0;
	v.flag = 0;
	v.num = ft_strnew(string_size(str, n));
	while (str[n] != 'd')
	{
		if (str[n] == '+' && num >= 0)
			detail.plus = 1;
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] == ' ' && num >= 0)
			detail.space = 1;
		if (str[n] >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		n++;
	}
	print_d(v.num, num, detail);
}

int		conv_d(char *str, va_list s2, int n)
{
	int		  num;
	int			i;
	char		*s1;
	
	num = va_arg(s2, int);
//	s1 = ft_itoa(num);
	d_detail(num, str, n);
	return (0);
}
