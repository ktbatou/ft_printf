/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:33:54 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/25 17:43:47 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	xx_minus_print(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.hash == 1)
		ft_putstr("0X");
	if (d.point == 1)
	{
		while (v->j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
	while (v->i-- > 0)
		ft_putchar(c);
}

void	xx_zero_print(t_detail d, t_valeur *v, char *str, char c)
{
	ft_putstr("0X");
	while (v->i-- > 0)
		ft_putchar('0');
	ft_putstr(str);
}

void	xx_normal_print(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		ft_putchar(c);
	if (d.hash == 1)
		ft_putstr("0X");
	if (d.point == 1)
	{
		while (v->j-- > 0)
			ft_putchar('0');
	}
	if (d.point == 1 && ft_atoi(v->pre) == 0)
		ft_nputstr(str, 0);
	else
		ft_putstr(str);
}

void	xx_cond(t_detail d, t_valeur *v, char *str)
{
	char	c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		 c = '0';
	if (d.minus == 1)
		xx_minus_print(d, v, str, c);
	else if (d.zero == 1 && d.minus == 0 && d.hash == 1 && d.point == 0)
		xx_zero_print(d, v, str, c);
	else
		xx_normal_print(d, v, str, c);
	ft_strdel(&v->num);
	ft_strdel(&v->pre);
	ft_strdel(&str);
}
