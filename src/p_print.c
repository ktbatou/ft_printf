/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:47:36 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/11 19:07:28 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_normal(t_detail d, t_valeur *v, char *str)
{
	while (v->i-- > 0)
		n_putchar(' ', v);
	n_putstr("0x", v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	return (v->rest);
}

int	p_minus(t_detail d, t_valeur *v, char *str)
{
	n_putstr("0x", v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0)
		ft_nputstr(str, 0);
	else
		n_putstr(str, v);
	while (v->i-- > 0)
		n_putchar(' ', v);
	return (v->rest);
}

int	p_conv(t_detail d, t_valeur *v, char *str)
{
	if (d.minus == 1)
		p_minus(d, v, str);
	else
		p_normal(d, v, str);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
	return (v->rest);
}
