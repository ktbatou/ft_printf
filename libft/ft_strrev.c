/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:37:21 by aariss            #+#    #+#             */
/*   Updated: 2018/10/13 23:17:19 by aariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		v;
	int		i;
	char	tmp;

	i = 0;
	v = ft_strlen(str) - 1;
	while (i < v)
	{
		tmp = str[i];
		str[i] = str[v];
		str[v] = tmp;
		i++;
		v--;
	}
	return (str);
}
