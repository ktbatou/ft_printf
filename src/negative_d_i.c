/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:39:49 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 14:45:06 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	zero(t_detail d, t_valeur *v, char *str, char c)
{
	n_putchar('-', v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	while (v->i-- > 0)
		n_putchar(c, v);
	n_putstr(str + 1, v);
	return (v->rest);
}

int	print_minus(t_detail d, t_valeur *v, char *str, char c)
{
	n_putchar('-', v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	n_putstr(str + 1, v);
	while (v->i-- > 0)
		n_putchar(c, v);
	return (v->rest);
}

int	print_negative(t_detail d, t_valeur *v, char *str, char c)
{
	while (v->i-- > 0)
		n_putchar(c, v);
	n_putchar('-', v);
	if (d.point == 1)
	{
		while (v->j-- > 0)
			n_putchar('0', v);
	}
	n_putstr(str + 1, v);
	return (v->rest);
}

int	negative_print(t_detail d, t_valeur *v, char *str, char c)
{
	if (d.zero == 1 && d.minus == 0 && d.point == 0)
		v->rest = zero(d, v, str, c);
	else if (d.minus == 1)
		v->rest = print_minus(d, v, str, c);
	else
		v->rest = print_negative(d, v, str, c);
	return (v->rest);
}
