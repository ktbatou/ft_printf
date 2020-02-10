/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:43:25 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/08 14:59:35 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_x(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.hash == 1)
		ft_putstr("0x");
	if (d.point == 1)
	{
		while (v->j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->a == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
	while (v->i-- > 0)
		ft_putchar(c);
}

void	normal_x(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		ft_putchar(c);
	if (d.hash == 1)
		ft_putstr("0x");
	if (d.point == 1)
	{
		while (v->j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->a == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
}

void	zero_print_x(char *str, t_valeur *v)
{
	ft_putstr("0x");
	while (v->i-- > 0)
		ft_putchar('0');
	ft_putstr(str);
}

void	x_cond(t_detail d, t_valeur *v, char *str, t_unsigned_v vl)
{
	char c;

	c = ' ';
	v->a = vl.signe;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
		minus_x(d, v, str, c);
	else if (d.zero == 1 && d.minus == 0 && d.hash == 1 && d.point == 0)
		zero_print_x(str, v);
	else
		normal_x(d, v, str, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
}
