/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:50:32 by ktbatou           #+#    #+#             */
/*   Updated: 2019/10/29 14:06:54 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

int     ft_size(char *s);
void    d(char *str, int nb);
void    ft_check(char *str, int n);
char	c(char s, int n);
void    ft_printf(char *str, ...);
