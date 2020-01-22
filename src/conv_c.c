/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:16:30 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/20 19:12:51 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_size(char *str, int i)
{
	int	n;

	n = 0;
	while (str[i++] != 'c')
		n++;
	return (n);
}

int		conv_c(char *s1, va_list s2, int n)
{
	t_valeur	v;
	t_detail	detail;
	char		s;

	v.i = 0;
	v.n = 0;
	detail.minus = 0;
	s = va_arg(s2, int);
	v.num = ft_strnew(ft_size(s1, n));
	while (s1[n] != 'c')
	{
		if (s1[n] == '-')
			detail.minus = 1;
		if (s1[n] >= 48 && s1[n] <= 57)
			v.num[v.i++] = s1[n];
		n++;
	}
	print_nb(v.num, s, detail.minus);
	if (ft_atoi(v.num) > 0)
		v.n = ft_atoi(v.num) - 1;
	return (1 + v.n);
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
	ft_strdel(&nb);
}
