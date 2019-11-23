/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:56 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/23 12:39:40 by ktbatou          ###   ########.fr       */
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
	t_valeur	v;
	t_detail	detail;

	v.j = 0;
	v.flag = 0;
	detail.zero = 0;
	detail.minus = 0;
	detail.hash = 0;
	v.num = ft_strnew(flag_size(s1, i));
	while (s1[i] != 'x')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] == '#')
			detail.hash = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (s1[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = s1[i];
		}
		i++;
	}
	print_x(v.num, str, detail);
}

void	print_x(char *s1, char *s2, t_detail det)
{
	int	i;

	i = atoi(s1);
	if (ft_strlen(s2) < i)
	{
		i -= ft_strlen(s2);
		if (det.hash == 1)
			i -= 2;
	}
	else
		i = 0;
	if (det.zero == 1 && det.minus == 0 && det.hash == 1)
	{
		ft_putstr("0x");
		 while (i-- > 0)
			 ft_putchar('0');
		 ft_putstr(s2);
	}
	else if (det.minus == 1)
	{
		if (det.hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		if (det.hash == 1)
			ft_putstr("0x");
		ft_putstr(s2);
	}
}
