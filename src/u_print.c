/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:59:06 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/20 18:20:21 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_u(t_detail d, t_valeur v, char *str, char c)
{
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v.pre) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
	while (v.i-- > 0)
		ft_putchar(c);
}

void	u_normal(t_detail d, t_valeur v, char *str, char c)
{
	while (v.i-- > 0)
		ft_putchar(c);
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v.pre) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
}

void	cond_u(t_detail d, t_valeur v, char *str)
{
	char c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if (d.minus == 1)
		minus_u(d, v, str, c);
	else
		u_normal(d, v, str, c);
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
}
