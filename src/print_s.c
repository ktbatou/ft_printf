/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:38:32 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 15:00:06 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus(t_detail d, char *str, int i, int j)
{
	if (d.point == 1)
		ft_nputstr(str, j);
	else
		ft_putstr(str);
	while (i-- > 0)
		ft_putchar(' ');
}

void	normal(t_detail d, char *str, int i, int j)
{
	while (i-- > 0)
		ft_putchar(' ');
	if (d.point == 1)
		ft_nputstr(str, j);
	else
		ft_putstr(str);
}

void	cond_s(t_detail d, char *str, int i, int j)
{
	if (d.minus == 1)
		minus(d, str, i, j);
	else
		normal(d, str, i, j);
}
