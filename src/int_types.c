/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:49:26 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 14:45:38 by ktbatou          ###   ########.fr       */
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

void		get_signe(t_detail detail, t_valeur *vlr)
{
	if (detail.l == 1)
	{
		if (vlr->l != 0)
			vlr->signe = 1;
	}
	else if (detail.l == 2)
	{
		if (vlr->ll != 0)
			vlr->signe = 1;
	}
	else if (detail.h == 1)
	{
		if (vlr->h != 0)
			vlr->signe = 1;
	}
	else if (detail.h == 2)
	{
		if (vlr->hh != 0)
			vlr->signe = 1;
	}
	else
	{
		if (vlr->i != 0)
			vlr->signe = 1;
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

char		*type_conv(t_valeur v, t_detail det)
{
	char	*str;

	if (det.l == 1)
		str = ft_ntoa(v.l);
	else if (det.l == 2)
		str = ft_ntoa(v.ll);
	else if (det.h == 1)
		str = ft_ntoa(v.h);
	else if (det.h == 2)
		str = ft_ntoa(v.hh);
	else
		str = ft_ntoa(v.i);
	return (str);
}

t_detail	type_flag(char *str, int n)
{
	t_detail detail;

	detail.l = 0;
	detail.h = 0;
	while (str[n] != 'i')
	{
		if (str[n] == 'l')
			detail.l++;
		if (str[n] == 'h')
			detail.h++;
		n++;
	}
	return (detail);
}
