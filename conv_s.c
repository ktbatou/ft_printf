/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:19 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/03 15:11:58 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(char *s1, va_list s2)
{
	char *str;
	int i;
	
	i = 0;
	str = va_arg(s2, char*);
	//return (ft_strlen(ft_putstr(ft_strdup(va_arg(s2, char*)))));
	//va_arg(s2, char*);
	while(str[i])
		ft_putchar(str[i++]);
	return (ft_strlen(str));
}

