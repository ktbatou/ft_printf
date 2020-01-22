/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:16:51 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/21 15:13:56 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_print(t_detail d, t_valeur v, char *str, char c)
{
	if (d.space == 1 && d.plus == 0)
	{
		ft_putchar(' ');
		v.i--;
	}
	if (d.plus == 1 && (--v.i))
		ft_putchar('+');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	//if (d.point == 1 && ft_atoi(v.pre) == 0)
		//ft_nputstr(str, 0);
	//else
		ft_putstr(str);
	while (v.i-- > 0)
		ft_putchar(c);
}

void	normal_print(t_detail d, t_valeur v, char *str, char c)
{

	if (d.plus == 1)
		v.i--;
	if (d.space == 1 && d.plus == 0)
	{
		ft_putchar(' ');
		v.i--;
	}
	while (v.i-- > 0)
		ft_putchar(c);
	if (d.plus == 1)
		ft_putchar('+');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	//if (d.point == 1 && ft_atoi(v.pre) == 0)
		//ft_nputstr(str, 0);
	//else
		ft_putstr(str);
}

void	zero_print(t_valeur v, char *str, char c)
{
	v.i--;
	ft_putchar('+');
	while (v.i-- > 0)
		ft_putchar(c);
	ft_putstr(str);
}

void	cond(t_detail d, t_valeur v, t_valeur vl, char *s)
{
	char c;

	c = ' ';
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		c = '0';
	if ((vl.j == 0 && d.zero == 1 && d.minus == 0)
			|| (vl.j == 0 && v.j > 0 && d.point == 1))
		negative_print(d, v, s, c);
	else if (d.minus == 1)
		minus_print(d, v, s, c);
	else if (d.plus == 1 && d.zero == 1 && d.point == 0)
		zero_print(v, s, c);
	else
		normal_print(d, v, s, c);
	ft_strdel(&v.num);
	ft_strdel(&v.pre);
	ft_strdel(&s);
}
