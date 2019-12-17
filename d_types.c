/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:49:26 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/17 17:52:05 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		types(va_list s2, t_detail detail, t_valeur *vlr)
{
	if (detail.l == 1)
	{
		if ((vlr->l = va_arg(s2, long int)) >= 0)
			vlr->j = 1;
	}
	else if (detail.l == 2)
	{
		if ((vlr->ll = va_arg(s2, long long int)) >= 0)
			vlr->j = 1;
	}
	else if (detail.h == 1)
	{
		if ((vlr->h = (short int)va_arg(s2, int)) >= 0)
			vlr->j = 1;
	}
	else if (detail.h == 2)
	{
		if ((vlr->hh = (signed char)va_arg(s2, int)) >= 0)
			vlr->j = 1;
	}
	else
	{
		if ((vlr->i = va_arg(s2, int)) >= 0)
			vlr->j = 1;
	}
}

t_detail	flag_detail(char *str, int n)
{
	t_detail flag;

	flag.l = 0;
	flag.h = 0;
	while (str[n] != 'd')
	{
		if (str[n] == 'l')
			flag.l++;
		if (str[n] == 'h')
			flag.h++;
		n++;
	}
	return (flag);
}
