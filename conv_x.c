/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/14 17:45:02 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_size(unsigned int nb)
{
	int	i;

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

int		conv_x(char *str, va_list s2, int n)
{
	unsigned int dec;
	unsigned int i;
	int count;
	char *s;

	dec = va_arg(s2, unsigned int);
	count = x_size(dec);
	s = ft_strnew(count);
	s[count--] = '\0';
	while (count >= 0)
	{
		if ((dec % 16) >= 10)
			s[count--] = ((dec % 16) % 10) + 'a';
		else
			s[count--] = '0' + (dec % 16);
		dec /= 16;
	}
	get_details(str, s, n);
	return (0);
}

int		flag_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n++] != 'x')
		i++;
	return (i);
}

void	get_details(char *s1 ,char *str, int i)
{
	int			n;
	t_detail	detail;
	char		*s;

	n = 0;
	detail.minus = 0;
	detail.hash = 0;
	s = ft_strnew(flag_size(s1, i));
	while (s1[i] != 'x')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] == '#')
			detail.hash = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
			s[n++] = s1[i];
		i++;
	}
	print_x(s, str, detail.minus, detail.hash);
}

void	print_x(char *s1, char *s2, int minus, int hash)
{
	int	i;

	i = atoi(s1);
	if (ft_strlen(s2) < i)
	{
		i -= ft_strlen(s2);
		if (hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (minus == 1)
	{
		if (hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		if (hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
	}
}
