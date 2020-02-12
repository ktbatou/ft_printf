/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:45:33 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/11 18:25:02 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_xx(t_valeur *v, t_detail d, t_detail det, t_unsigned_v val)
{
	char	*str;

	str = xx_conv_flag(det, val);
	v->f = ft_strlen(str);
	v->n = v->f;
	if (v->num)
		v->i = ft_atoi(v->num);
	if (v->pre)
	{
		v->j = ft_atoi(v->pre);
		if (v->j > v->f)
			v->f = v->j;
		v->f = v->j == 0 && val.signe == 0 ? 0 : v->f;
		v->j -= v->n;
	}
	if (v->f < v->i)
	{
		v->i -= v->f;
		v->i -= d.hash == 1 ? 2 : 0;
	}
	else
		v->i = 0;
	v->rest = xx_cond(d, v, str, val);
	return (v->rest);
}

int		flag(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n++] != 'X')
		i++;
	return (i);
}

int		details(char *str, int i, t_unsigned_v val, t_detail d)
{
	t_valeur v;
	t_detail detail;

	intial(&detail, &v);
	while (str[i] != 'X')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			!v.num ? v.num = ft_strnew(flag(str, i)) : v.num;
			if (str[i] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[i];
		}
		if (str[i] == '.' && (detail.point = 1))
		{
			v.pre = ft_strnew(pre_size(str, i + 1));
			i += prec(str, i + 1, v);
		}
		detail.minus = str[i] == '-' ? 1 : detail.minus;
		if (str[i] == '#' && val.signe == 1)
			detail.hash = 1;
		i++;
	}
	return (print_xx(&v, detail, d, val));
}

int		conv_xx(char *str, va_list s2, int n)
{
	t_detail		d;
	t_unsigned_v	v;

	d = xx_flag(str, n);
	v.signe = 0;
	xx_types(&v, d, s2);
	return (details(str, n, v, d));
}
