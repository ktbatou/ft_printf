/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:45:33 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/15 16:13:48 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_X(char *str, char *s, int minus, int hash)
{
	int	i;

	i = atoi(s);
	if (ft_strlen(str) < i)
	{
		i -= ft_strlen(str);
		if (hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (minus == 1)
	{
		if (hash == 1)
			ft_putstr("0X");
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while(i-- > 0)
			ft_putchar(' ');
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

void	details(char *s, char *str, int i)
{ 
	int		n;
	char	*num;
	t_detail detail;

	detail.minus = 0;
	detail.hash = 0;
	n = 0;
	num = ft_strnew(flag(str, i));
	while (str[i] != 'X')
	{
		if (str[i]  >= '0' && str[i] <= '9')
		 	num[n++] = str[i];
		if (str[i] == '-')
			detail.minus = 1;
		if (str[i] == '#')
			detail.hash = 1;
		i++;
	}
	print_X(s, num, detail.minus, detail.hash);
}

int		size(unsigned int nb)
{
	int i;

	i = 0;
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
	char	*s;

	i = va_arg(s2, unsigned int);
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
	details(s, str, n);
  	return (0);
}
