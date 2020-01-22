/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:39:49 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/20 20:53:25 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero(t_detail d, t_valeur v, char *str, char c)
{
	ft_putchar('-');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	while (v.i-- > 0)
		ft_putchar(c);
	ft_putstr(str + 1);
}

void	print_minus(t_detail d, t_valeur v, char *str, char c)
{
	ft_putchar('-');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	ft_putstr(str + 1);
	while (v.i-- > 0)
		ft_putchar(c);
}

void	print_negative(t_detail d, t_valeur v, char *str, char c)
{
	while (v.i-- > 0)
		ft_putchar(c);
	ft_putchar('-');
	if (d.point == 1)
	{
		while (v.j-- > 0)
			ft_putchar('0');
	}
	ft_putstr(str + 1);
}

void	negative_print(t_detail d, t_valeur v, char *str, char c)
{
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		zero(d, v, str, c);
	else if (d.minus == 1)
		print_minus(d, v, str, c);
	else
		print_negative(d, v, str, c);
}
