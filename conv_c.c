/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:16:30 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/09 17:47:52 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_size(char *str, int i)
{
	int	n;

	n = 0;
	while (str[i++] != 'c')
		n++;
	return (n);
}

int	conv_c(char *s1, va_list s2, int n)
{
	int		i;
	int		j;
	char	*num;
	char	s;
	t_detail detail;
	
	i = 0;
	s = va_arg(s2, int);
	detail.minus = 0;
	num = ft_strnew(ft_size(s1, n));
	while(s1[n] != 'c')
	{
		if (s1[n] == '-')
			detail.minus = 1;
		if (s1[n] >= 48 && s1[n] <= 57)
			num[i++] = s1[n];
		n++;
	}
	print_nb(num, s, detail.minus);
	return (1);
}

void	print_nb(char *nb, char c, int minus)
{
	int	i;

	i = atoi(nb) - 1;
	if (minus == 1)
	{
		ft_putchar(c);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
}
