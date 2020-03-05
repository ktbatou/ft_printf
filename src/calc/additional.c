/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:10:08 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 17:10:10 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

t_bool	is_nan(t_doubletofloatrep dfr)
{
	if (dfr.fr.exponent == 32767 && dfr.fr.mantissa)
		return (true);
	return (false);
}

t_bool	inf_null(t_doubletofloatrep dfr, t_bool verbose)
{
	if (dfr.fr.exponent == 32767 && !dfr.fr.mantissa)
	{
		(verbose) ? ft_putstr("inf") : 0;
		return (false);
	}
	else if (dfr.fr.exponent == 32767 && dfr.fr.mantissa)
	{
		(verbose) ? ft_putstr("nan") : 0;
		return (false);
	}
	return (true);
}

void	plus_minus(int sign)
{
	ft_putchar(sign ? '-' : '+');
}

int		get_after(char *after)
{
	return ((after) ? ft_atol(after, true, 6) : 6);
}

t_bool	is_all_nine(char *num, int len)
{
	while (len--)
		if (*num++ != '9')
			return (false);
	return (true);
}
