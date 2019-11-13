/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:36 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/13 16:30:38 by ktbatou          ###   ########.fr       */
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

int		conv_x(char *s1, va_list s2, int n)
{
	unsigned int dec;
	unsigned int i;
	int count;
	char *str;

	dec = va_arg(s2, unsigned int);
	count = x_size(dec);
	str = ft_strnew(count);
	str[count--] = '\0';
	while (count >= 0)
	{
		if ((dec % 16) >= 10)
		{
			str[count--] = ((dec % 16) % 10) + 'a';
			dec /= 16;
		}
		else
		{
		i = dec % 16;
		str[count--] = '0' + i;
		dec /= 16;
		}
	}
	get_details(s1, str, n);
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
