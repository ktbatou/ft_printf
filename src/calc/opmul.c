/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opmul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:18:37 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 16:18:48 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

void	biggerloop(char *result, char *b, char *s, int *params)
{
	int	rindex;
	int	index;
	int	pi;
	int	retenu;

	pi = params[0];
	retenu = 0;
	index = params[1];
	rindex = params[3];
	while (--index >= 0)
		if (((int)b[index] - 48) * ((int)s[pi] - 48) + retenu >= 10)
		{
			result[rindex--] = (((int)b[index] - 48) *
			((int)s[pi] - 48) + retenu) % 10 + '0';
			retenu = (((int)b[index] - 48) * ((int)s[pi] - 48) + retenu) / 10;
		}
		else
		{
			result[rindex--] = (((int)b[index] - 48) *
			((int)s[pi] - 48) + retenu) + '0';
			retenu = 0;
		}
	(retenu) ? result[rindex--] = retenu + '0' : 0;
	while (rindex >= 0)
		result[rindex--] = '0';
}

char	*smallerloop(char *b, char *s, int *p, int *lo)
{
	char	*pr;
	char	*result[2];
	int		index;
	int		fix;
	int		rindex;

	result[0] = ft_strdup("0");
	index = p[1];
	*lo = 1;
	while (--index >= 0)
	{
		fix = (p[1] - index - 1);
		rindex = (p[0] + 1 + fix);
		p[2] = rindex;
		pr = malloc(sizeof(char) * (rindex + 1));
		pr[rindex--] = '\0';
		while (fix--)
			pr[rindex--] = '0';
		biggerloop(pr, b, s, (int[]){index, p[0], p[1], rindex});
		result[1] = result[0];
		result[0] = opadd(result[0], pr, (int[]){*lo, p[2]}, lo);
		free(result[1]);
		free(pr);
	}
	return (result[0]);
}

char	*opmul(char *a, char *b, int *params, int *len_out)
{
	char	*scatcher;
	int		lenb;
	int		lens;
	int		icatcher;

	while (a && *(a + 1) && *a == '0' && a++)
		(params && params[0]) ? params[0]-- : 0;
	while (b && *(b + 1) && *b == '0' && b++)
		(params && params[1]) ? params[1]-- : 0;
	lenb = (params && params[0]) ? params[0] : ft_strlen(a);
	lens = (params && params[1]) ? params[1] : ft_strlen(b);
	if (lens > lenb)
	{
		scatcher = a;
		a = b;
		b = scatcher;
		icatcher = lenb;
		lenb = lens;
		lens = icatcher;
	}
	return (smallerloop(a, b, (int[]){lenb, lens, lens}, len_out));
}
