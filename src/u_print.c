/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:59:06 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/11 18:37:03 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus_u(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && ft_atoi(str) == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	while (v->i-- > 0)
		n_putchar(c, v);
	return (v->rest);
}

int		u_normal(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		n_putchar(c, v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0 && ft_atoi(str) == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	return (v->rest);
}

int		cond_u(t_detail d, t_valeur *v, char *str)
{
	char c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
		v->rest = minus_u(d, v, str, c);
	else
		v->rest = u_normal(d, v, str, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
	return (v->rest);
}
