/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:16:51 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/11 15:57:42 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus_print(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.space == 1 && d.plus == 0)
	{
		n_putchar(' ', v);
		v->i--;
	}
	if (d.plus == 1)
		n_putchar('+', v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->signe == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	while (v->i-- > 0)
		n_putchar(c, v);
	return (v->rest);
}

int	normal_print(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.space == 1 && d.plus == 0)
	{
		n_putchar(' ', v);
		v->i--;
	}
	while (v->i-- > 0)
		n_putchar(c, v);
	if (d.plus == 1)
		n_putchar('+', v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && v->signe == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	return (v->rest);
}

int	zero_print(t_valeur *v, char *str, char c)
{
	n_putchar('+', v);
	while (v->i-- > 0)
		n_putchar(c, v);
	n_putstr(str, v);
	return (v->rest);
}

int	cond(t_detail d, t_valeur *v, t_valeur vl, char *s)
{
	char c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if ((vl.j == 0 && d.zero == 1 && d.minus == 0)
			|| (vl.j == 0 && v->j > 0 && d.point == 1))
		v->rest = negative_print(d, v, s, c);
	else if (d.minus == 1)
		v->rest = minus_print(d, v, s, c);
	else if (d.plus == 1 && d.zero == 1 && d.point == 0)
		v->rest = zero_print(v, s, c);
	else
		normal_print(d, v, s, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&s);
	return (v->rest);
}
