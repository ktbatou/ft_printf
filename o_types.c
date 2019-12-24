/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:32:20 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/23 17:10:16 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_detail	flag_det(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'o')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return (det);
}

void		o_types(t_detail *det, t_unsigned_v *v, va_list s2)
{
	if (det->l == 1)
	{
		if ((v->l = va_arg(s2, unsigned long int)) != 0)
			v->signe = 1;
	}
	else if (det->l == 2)
	{
		if ((v->ll = va_arg(s2, unsigned long long int)) != 0)
			v->signe = 1;
	}
	else if (det->h == 1)
	{
		if ((v->h = (unsigned short int)va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
	else if (det->h == 2)
	{
		if ((v->hh = (unsigned char)va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
	else
	{
		if ((v->i = va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
}

char		*conv_flag(t_unsigned_v v, t_detail det)
{
	char	*num;

	if (det.l == 1)
		num = ft_itoa_base(v.l, 8, 0);
	else if (det.l == 2)
		num = ft_itoa_base(v.ll, 8, 0);
	else if (det.h == 1)
		num = ft_itoa_base(v.h, 8, 0);
	else if (det.h == 2)
		num = ft_itoa_base(v.hh, 8, 0);
	else
		num = ft_itoa_base(v.i, 8, 0);
	return (num);
}
