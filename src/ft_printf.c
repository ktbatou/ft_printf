/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:11:03 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/16 21:57:53 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_data g_struct =
{
	{"csxpXdiuo%"},
	{&conv_c, &conv_s, &conv_x, &conv_p, &conv_xx,
		&conv_d, &conv_i, &conv_u, &conv_o, &percent}
};

int		ft_printf(char *str, ...)
{
	int			format;
	t_valeur	v;
	va_list		ap;

	v.f = 0;
	v.i = 0;
	format = 0;
	v.n = 0;
	va_start(ap, str);
	while (str[v.i])
	{
		if (str[v.i] == '%')
		{
			format = ft_check(str, v.i + 1, ap, &v);
			v.i += (format - v.i) + 1;
			format++;
		}
		if (str[v.i] && str[v.i] != '%')
		{
			ft_putchar(str[v.i++]);
			v.n++;
		}
	}
	va_end(ap);
	return (v.f + v.n);
}

int		ft_check(char *str, int n, va_list op, t_valeur *v)
{
	t_data		data;

	v->a = 0;
	v->i = n;
	data = g_struct;
	while (str[n])
	{
		v->j = 0;
		while (v->j < 10)
		{
			if (data.flags[v->j] == str[n])
			{
				v->f += data.flag[v->j](str, op, v->i);
				v->a = 1;
				break ;
			}
			v->j++;
		}
		if (v->a == 1)
			break ;
		n++;
	}
	return (n);
}
