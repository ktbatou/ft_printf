/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:19 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/16 14:51:03 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision(char *str, int n, char *num)
{
	int i;
 
	i = 0;
	if (str[n] >= 48 && str[n] <= 57)
	{
		while (str[n] >= 48 && str[n] <= 57)
		{
			num[i++] = str[n];
			n++;
		}
	}
	else
		num[i] = '0';
	return (i);
}

static int	ft_size(char *str, int i)
{
	int n;

	n = 0;
	while (str[i++] != 's')
		n++;
	return (n);
}

int			conv_s(char *s1, va_list s2, int n)
{
	t_detail	detail;
	t_valeur	v;
	char        *str;

	v.i = 0;
	detail.minus = 0;
	detail.point = 0;
	str = va_arg(s2, char*);
	if (str == NULL)
		str = "(null)";
	ft_size(s1, n);
	v.num = ft_strnew(ft_size(s1, n));
	v.pre = ft_strnew(2);
	while (s1[n] != 's')
	{
		if (s1[n] == '-')
			detail.minus = 1;
		if (s1[n] >= 48 && s1[n] <= 57)
		 	v.num[v.i++] = s1[n];
		if (s1[n] == '.')
		{
			n += precision(s1, n + 1, v.pre);
			detail.point = 1;
		}
		n++;
	}
	return (print_num(v.num, v.pre, str, detail));
}

int			print_num(char *n, char *pre, char *str, t_detail d)
{
	int	i;
	int j;
	int nn;
	int v;

	v = 0;
	i = atoi(n);
	j = atoi(pre);
	nn = ft_strlen(str);
	if (d.point == 1 && (j < ft_strlen(str)))
		nn = j;
	if (nn < i)
		i -= nn;
	else
		i = 0;
	v = i;
	if (d.minus == 1)
	{
		if (d.point == 1)
			ft_nputstr(str, j);
		else
			ft_putstr(str);
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		if (d.point == 1)
			ft_nputstr(str, j);
		else
			ft_putstr(str);
    }
	ft_strdel(&n);
	ft_strdel(&pre);
	return (v + nn);
}
