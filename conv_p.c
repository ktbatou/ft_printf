/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:24:58 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/02 17:07:45 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_size(char	*str, int n)
{
	int	i;

	i = 0;
	while (str[n++] != 'p')
		i++;
	return (i);
}

void	get_det(char *s1, char *str, int i)
{
	int			n;
	t_detail	detail;
	char		*s;

	n = 0;
	detail.minus = 0;
	s = ft_strnew(f_size(s1, i));
	while (s1[i] != 'p')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] >= 48 && s[i] <= 57)
			s[n++] = s1[i];
		i++;
	}
	print_p(s, str, detail.minus);
}

void	print_p(char *s1, char *str, int minus)
{
	int		i;

	i = atoi(s1);
	if (i > ft_strlen(str))
			i -= ft_strlen(str) + 2;
	else
		i = 0;
	if (minus == 1)
	{
		ft_putstr("0x");
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putstr(str);
	}
}

int		size_p(unsigned long long int nb)
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

int		conv_p(char *str, va_list s2, int n)
{
	unsigned long long int	adr;
	int 					i;
	char					*s;

	adr = va_arg(s2, unsigned long long int);
	i = size_p(adr);
	s = ft_strnew(i);
	s[i--] = '\0';
	while (i >= 0)
	{
		if ((adr % 16) >= 10)
			s[i--] = ((adr % 16) % 10) + 'a';
		else
			s[i--] = (adr % 16) + '0';
		adr /= 16;
	}
	get_det(str, s, n);
	return (0);
}
