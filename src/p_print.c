/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:47:36 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/20 20:21:54 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_normal(t_detail d, t_valeur v, char *str)
{
	while (v.i-- > 0)
		ft_putchar(' ');
	ft_putstr("0x");
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

void	p_minus(t_detail d, t_valeur v, char *str)
{
	ft_putstr("0x");
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
		ft_putchar(' ');
}

void	p_conv(t_detail d, t_valeur v, char *str)
{
	if (d.minus == 1)
		p_minus(d, v, str);
	else
		p_normal(d, v, str);
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&str);
}
