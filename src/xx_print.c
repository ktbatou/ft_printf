/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:33:54 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 14:47:49 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		xx_minus_print(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.hash == 1)
		n_putstr("0X", v);
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

int		xx_zero_print(t_valeur *v, char *str)
{
	n_putstr("0X", v);
	while (v->i-- > 0)
		n_putchar('0', v);
	n_putstr(str, v);
	return (v->rest);
}

int		xx_normal_print(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		n_putchar(c, v);
	if (d.hash == 1)
		n_putstr("0X", v);
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

int		xx_cond(t_detail d, t_valeur *v, char *str, t_unsigned_v vl)
{
	char	c;

	c = ' ';
	v->a = vl.signe;
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
		xx_minus_print(d, v, str, c);
	else if (d.zero == 1 && d.minus == 0 && d.hash == 1 && d.point == 0)
		xx_zero_print(v, str);
	else
		xx_normal_print(d, v, str, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
	return (v->rest);
}
