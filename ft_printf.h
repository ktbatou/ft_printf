/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/03 18:38:22 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

int     ft_printf(char *str, ...);
void    conv_c(char *s1, va_list s2);
int conv_s(char *s1, va_list s2);
int     check_num(char *str);
int  checker(char *str, va_list ap, char *s );
