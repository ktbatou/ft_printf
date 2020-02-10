/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:36:51 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/08 14:49:17 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_o(t_detail d, t_valeur v, char *str, char c)
{
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	if ((d.hash == 1 && (v.n > v.f)) ||
			(d.hash == 1 && v.f == 0))
		ft_putchar('0');
	if (d.point == 1 && ft_atoi(v.pre) == 0 && ft_atoi(str) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
	while (v.i-- > 0)
		ft_putchar(c);
}

void	normal_o(t_detail d, t_valeur v, char *str, char c)
{
	while (v.i-- > 0)
		ft_putchar(c);
	if ((d.hash == 1 && v.n >= v.f) ||
			(d.hash == 1 && v.f == 0))
		ft_putchar('0');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v.pre) == 0 && ft_atoi(str) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
}

void	o_cond(t_detail d, t_valeur v, char *str)
{
	char	c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if ((d.hash == 1 && (v.n > v.f)) || (d.hash == 1 && v.f == 0))
		v.i--;
	if (d.minus == 1)
		minus_o(d, v, str, c);
	else
		normal_o(d, v, str, c);
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
}
