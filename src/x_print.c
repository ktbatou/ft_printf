/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:43:25 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/11 18:22:51 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus_x(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.hash == 1)
		n_putstr("0x", v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->a == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	while (v->i-- > 0)
		n_putchar(c, v);
	return (v->rest);
}

int		normal_x(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		n_putchar(c, v);
	if (d.hash == 1)
		n_putstr("0x", v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->a == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	return (v->rest);
}

int		zero_print_x(char *str, t_valeur *v)
{
	n_putstr("0x", v);
	while (v->i-- > 0)
		n_putchar('0', v);
	n_putstr(str, v);
	return (v->rest);
}

int		x_cond(t_detail d, t_valeur *v, char *str, t_unsigned_v vl)
{
	char c;

	c = ' ';
	v->a = vl.signe;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
		v->rest = minus_x(d, v, str, c);
	else if (d.zero == 1 && d.minus == 0 && d.hash == 1 && d.point == 0)
		v->rest = zero_print_x(str, v);
	else
		v->rest = normal_x(d, v, str, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
	return (v->rest);
}
