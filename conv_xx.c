/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:45:33 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/25 15:19:10 by ktbatou          ###   ########.fr       */
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

void	details(char *s, char *str, int i, unsigned int j)
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
		if (str[i] == '#' && j != 0)
			detail.hash = 1;
		i++;
	}
	print_X(s, v.num, detail.minus, detail.hash, detail.zero);
}

int		size(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int		conv_xx(char *str, va_list s2, int n)
{
	int nb;
	unsigned int i;
	unsigned int j;
	char	*s;

	i = va_arg(s2, unsigned int);
	j = i;
	nb = size(i);
	s = ft_strnew(nb);
	s[nb--] = '\0';
	while(nb >= 0)
	{
		if ((i % 16) >= 10)
			s[nb--] = ((i % 16) % 10) + 'A';
		else
			s[nb--] = (i % 16) + '0';
		i /= 16;
	}
	details(s, str, n, j);
  	return (0);
}
