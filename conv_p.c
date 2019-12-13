/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:24:58 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/12 19:52:39 by ktbatou          ###   ########.fr       */
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
	t_valeur	v;

	n = 0;
	detail.minus = 0;
	v.num = 0;
	v.pre = 0;
	while (s1[i] != 'p')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (!v.num)
				v.num = ft_strnew(f_size(s1, i));
			v.num[n++] = s1[i];
		}
		if  (s1[i] == '.')
		{
			v.pre = ft_strnew(pre_size(s1, i + 1));
			n += prec(s1, i + 1, v);
			detail.point =  1;
		}
		i++;
	}
	print_p(v, str, detail);
}

void	print_p(t_valeur v, char *str, t_detail d)
{
	int		i;
	int		j;
	int		n;

	j = 0;
	i = 0;
	n = ft_strlen(str) + 2;
	if (d.point == 1 && ft_atoi(v.pre) > ft_strlen(str))
		n -= 2;
	v.n = n;
	if (v.num)
		i = ft_atoi(v.num);
	if (v.pre)
	{
		j = ft_atoi(v.pre);
		if (j > n)
			n = j;
		if (j == 0)
			n = 0;
		j -= v.n;
	}
	if (i > n)
		i -= n;
	else
		i = 0;
	if (d.minus == 1)
	{
		ft_putstr("0x");
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(str, 0);
		else
			ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		if (d.point == 1)
		{
			while (j-- > 0)
				ft_putchar('0');
		}
		if (d.point == 1 && ft_atoi(v.pre) == 0)
			ft_nputstr(str, 0);
		else
			ft_putstr(str);
	}
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
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
