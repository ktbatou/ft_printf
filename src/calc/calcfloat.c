/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcfloat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:36:53 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 16:36:55 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

char		*convesion_normalized(t_doubletofloatrep dfr, int *lo)
{
	char	*mantissa;
	char	*twopower;
	char	*result[3];
	int		len;

	if (dfr.f == 0)
		return (ft_strdup("0"));
	mantissa = ft_ntoa(dfr.fr.mantissa);
	result[0] = opadd(mantissa, "9223372036854775808", (int[]){0, 19}, lo);
	if ((dfr.fr.exponent - 16383 - 63) < 0)
		twopower = oppow("5", -(dfr.fr.exponent - 16383 - 63), &len);
	else
		twopower = oppow("2", dfr.fr.exponent - 16383 - 63, &len);
	result[1] = result[0];
	result[2] = twopower;
	result[0] = opmul(result[0], twopower, (int[]){*lo, len}, lo);
	free(result[1]);
	free(result[2]);
	free(mantissa);
	return (result[0]);
}

void		writenumber(char *num, int *p, t_bool before, t_bool hash)
{
	while (*num == '0' && *(num + 1) && num++)
		(void)num;
	if (before)
	{
		(p[1] || (!p[1] && hash)) ? ft_putstr("0.") : ft_putstr("0");
		ft_putchar_seq('0', (p[0] < p[1]) ? p[0] : p[1]);
		p[1] -= ((p[0] < p[1]) ? p[0] : p[1]);
		while (*num && p[1]--)
			ft_putchar_seq(*num++, 1);
	}
	else
	{
		p[1] += p[0] + ((p[1]) ? 1 : 0);
		while (*num && p[1]--)
			ft_putchar_seq((p[0]--) ? *num++ : '.', 1);
		(!p[0] && (p[1]-- > 0 || hash)) ? ft_putchar('.') : 0;
	}
	ft_putchar_seq('0', p[1]);
}

t_bool		is_bigger(char *num, int index)
{
	if ((int)num[index] - 48 > 5)
		return (true);
	else if ((int)num[index] - 48 == 5)
	{
		if ((int)num[index - 1] - 48 == 5)
			return (true);
		num = num + index + 1;
		while (*num)
			if (*num++ != '0')
				return (true);
	}
	return (false);
}

void		choser(char *n, int *p, long int a, t_bool hash)
{
	char *c;

	c = NULL;
	if (-p[1] >= p[0])
	{
		p[1] = -p[1] - p[0];
		if (a - p[1] >= 0 && a - p[1] < p[0] && is_bigger(n, a - p[1]))
		{
			c = opadd("1", n,
			(int[]){1, a - p[1] + ((a == p[1]) ? 1 : 0)}, &p[0]);
			(is_all_nine(n, a - p[1])) ? p[1]-- : 0;
		}
		writenumber((c) ? c : n, (int[]){p[1], a}, true, hash);
	}
	else
	{
		p[1] = p[0] + p[1];
		if (a + p[1] < p[0] && is_bigger(n, a + p[1]))
		{
			c = opadd("1", n, (int[]){1, a + p[1]}, &p[0]);
			(is_all_nine(n, a + p[1])) ? p[1]++ : 0;
		}
		writenumber((c) ? c : n, (int[]){p[1], a}, false, hash);
	}
	(c) ? free(c) : 0;
}

void		printnumber(char *n, int *p, long int a, t_bool hash)
{
	while (*n == '0' && *(n + 1) && n++ && p[0]--)
		(void)n;
	if (p[1] > 0)
		writenumber(n, (int[]){p[0], a}, false, hash);
	else
		choser(n, (int[]){p[0], p[1]}, a, hash);
}
