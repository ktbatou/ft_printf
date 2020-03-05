/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:17:10 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 17:17:15 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc/calc.h"

t_bool		ft_type(char *str)
{
	while (*str != 'f')
	{
		if (*str == 'L')
			return (true);
		str++;
	}
	return (false);
}

int			c_f_choser(char *n, int *p, long int a, t_bool hash)
{
	char	*c;

	c = NULL;
	if (-p[1] >= p[0])
	{
		p[1] = -p[1] - p[0];
		if (a - p[1] >= 0 && a - p[1] < p[0] && is_bigger(n, a - p[1]))
		{
			c = opadd("1", n, (int[]){1, a - p[1]}, &p[0]);
			(is_all_nine(n, a - p[1])) ? p[1]-- : 0;
		}
		(c) ? free(c) : 0;
		return (a + ((a || (!a && hash)) ? 2 : 1));
	}
	else
	{
		p[1] = p[0] + p[1];
		if (a + p[1] < p[0] && is_bigger(n, a + p[1]))
		{
			c = opadd("1", n, (int[]){1, a + p[1]}, &p[0]);
			(is_all_nine(n, a + p[1])) ? p[1]++ : 0;
		}
		(c) ? free(c) : 0;
		return (p[1] + a + ((a || hash) ? 1 : 0));
	}
}

int			calc_float(char *n, int *p, long int a, t_bool hash)
{
	while (*n == '0' && *(n + 1) && n++ && p[0]--)
		(void)n;
	if (p[1] > 0)
		return (p[0] + a + ((a || hash) ? 1 : 0));
	else
		return (c_f_choser(n, (int[]){p[0], p[1]}, a, hash));
	return (0);
}

int			print(char *str, int n, t_doubletofloatrep dfr, int *p)
{
	t_detail	d;
	t_valeur	v;
	char		*result;

	intial(&d, &v);
	(dfr.f >= 0) ? d.signe = 1 : 0;
	f_detail(str, n, &v, &d);
	result = inf_null(dfr, false) ? convesion_normalized(dfr, &p[2]) : NULL;
	(d.space && !d.plus && !dfr.fr.sign && ++p[0]) ? ft_putchar(' ') : 0;
	((dfr.fr.sign || d.plus) && (!d.minus && d.zero &&
	inf_null(dfr, false)) && ++p[0]) ? plus_minus(dfr.fr.sign) : 0;
	((dfr.fr.sign || d.plus) && !(!d.minus && d.zero &&
	inf_null(dfr, false)) && !is_nan(dfr)) ? p[0]++ : 0;
	n = ((dfr.fr.exponent == 32767) ? 3 : calc_float(result, (int[])
	{p[2], dfr.fr.exponent - 16383 - 63}, get_after(v.pre), d.hash)) + p[0];
	p[1] = (v.num) ? ft_atol(v.num, true, 6) - n : p[1] - p[0];
	if (!d.minus)
		ft_putchar_seq((d.zero && inf_null(dfr, false)) ? '0' : ' ', p[1]);
	((dfr.fr.sign || d.plus) && !(!d.minus && d.zero && inf_null(dfr, false))
	&& !is_nan(dfr)) ? plus_minus(dfr.fr.sign) : 0;
	inf_null(dfr, true) ? printnumber(result,
	(int[]){p[2], dfr.fr.exponent - 16383 - 63}, get_after(v.pre), d.hash) : 0;
	(d.minus) ? ft_putchar_seq(' ', p[1]) : 0;
	clean(&v, &result);
	return (((p[1] > 0) ? p[1] : 0) + n);
}

int			conv_f(char *str, va_list s2, int n)
{
	t_doubletofloatrep dfr;

	dfr.fr.exponent = 0;
	dfr.fr.mantissa = 0;
	dfr.fr.sign = 0;
	if (ft_type(str + n))
		dfr.f = va_arg(s2, long double);
	else
		dfr.f = va_arg(s2, double);
	return (print(str, n, dfr, (int[]){0, 0, 0}));
}
