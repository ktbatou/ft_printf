/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:14:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/16 12:19:07 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(char *num, char *str, int  minus)
{
	int	i;
	i = atoi(num);
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (minus == 1)
	{
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
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
	int			i;
	int			j;
	t_detail	detail;
	char		*num;

	j = 0;
	i = string_size(str, n);
	detail.minus = 0;
	num = ft_strnew(i);
	while (str[n] != 'd')
	{
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] >= '0' && str[n] <= '9')
			num[j++] = str[n];
		n++;
	}
	print_d(num, s1, detail.minus);
}

int		size_d(int nb)
{
	int	i;

	i = 0;
	while(nb >= 1)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		conv_d(char *str, va_list s2, int n)
{
	int		  num;
	int			i;
	char		*s1;
	
	num = va_arg(s2, int);
	i = size_d(num);
	s1 = ft_itoa(num);
	d_detail(s1, str, n);
	return (0);
}
