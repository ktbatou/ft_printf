/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oppow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:10:02 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 16:10:05 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

char	*oppow(char *a, long b, int *len_out)
{
	char	*res;
	char	*catcher;
	int		start_free;
	int		len;

	res = ft_strdup("1");
	*len_out = 1;
	start_free = 0;
	len = ft_strlen(a);
	while (b > 0)
	{
		(b & 1) ? catcher = res : 0;
		(b & 1) ? res = opmul(res, a, (int[]){*len_out, len}, len_out) : 0;
		(b & 1) ? free(catcher) : 0;
		if ((b >> 1) <= 0)
			return (res);
		catcher = a;
		a = opmul(a, a, (int[]){len, len}, &len);
		if (start_free)
			free(catcher);
		start_free = 1;
		b = b >> 1;
	}
	return (res);
}
