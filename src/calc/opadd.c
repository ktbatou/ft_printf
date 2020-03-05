/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opadd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:00 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:13 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

void	addsuffix(char *result, char *b, int *params)
{
	int	r_index;
	int	index;
	int	retenu;

	retenu = params[0];
	r_index = params[1];
	index = params[2];
	while (--index >= 0)
		if ((((int)b[index] - 48) + retenu) >= 10)
		{
			result[r_index--] = (((int)b[index] - 48) + retenu - 10) + '0';
			retenu = 1;
		}
		else
		{
			result[r_index--] = ((int)b[index] - 48) + retenu + '0';
			retenu = 0;
		}
	if (retenu)
		result[r_index--] = retenu + '0';
	while (r_index >= 0)
		result[r_index--] = '0';
}

void	addhandler(char *result, char *b, char *s, int *params)
{
	int	r_index;
	int	index;
	int	retenu;

	retenu = 0;
	r_index = params[0] + 1;
	index = params[1];
	result[r_index--] = '\0';
	while (--index >= 0)
		if ((((int)b[index + (params[0] -
		params[1])] - 48) + ((int)s[index] - 48) + retenu) >= 10)
		{
			result[r_index--] = (((int)b[index + (params[0] -
			params[1])] - 48) + ((int)s[index] - 48) + retenu - 10) + '0';
			retenu = 1;
		}
		else
		{
			result[r_index--] = ((int)b[index + (params[0] - params[1])] - 48) +
			((int)s[index] - 48) + retenu + '0';
			retenu = 0;
		}
	addsuffix(result, b, (int[]){retenu, r_index, params[0] - params[1]});
}

char	*opadd(char *a, char *b, int *params, int *len_out)
{
	char	*result;
	char	*scatcher;
	int		len_b;
	int		len_s;
	int		icatcher;

	while (a && *(a + 1) && *a == '0' && a++)
		(params && params[0]) ? params[0]-- : 0;
	while (b && *(b + 1) && *b == '0' && b++)
		(params && params[1]) ? params[1]-- : 0;
	len_b = (params && params[0]) ? params[0] : ft_strlen(a);
	len_s = (params && params[1]) ? params[1] : ft_strlen(b);
	if (len_s > len_b)
	{
		scatcher = a;
		a = b;
		b = scatcher;
		icatcher = len_b;
		len_b = len_s;
		len_s = icatcher;
	}
	result = (char *)malloc(sizeof(char) * (len_b + 2));
	addhandler(result, a, b, (int[]){len_b, len_s});
	*len_out = len_b + 1;
	return (result);
}
