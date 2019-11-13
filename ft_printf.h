/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/13 14:42:28 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct s_date
{
	char flags[4];
	int (*flag[4])(char *str, va_list s2, int n);
} t_data;

typedef struct s_detail
{
	int minus;
	int hash;
	int point;
	int space;
} t_detail;

typedef struct s_valeur
{
	int i;
	int j;
	int f;
	int a;
}	t_valeur;


int     flag_size(char *str, int n);
void    get_details(char *s1 ,char *str, int i);
void    print_x(char *s1, char *s2, int minus, int hash);
int     conv_x(char *s1, va_list s2, int n);
int		ft_check(char *str, int i, va_list op);
int		percent(char *str, va_list s);
int		ft_printf(char *str, ...);
int		conv_c(char *s1, va_list s2, int n);
int		conv_s(char *s1, va_list s2, int n);
int 	check_num(char *str);
int		checker(char *str, va_list ap, char *s );
int		get_detail(char *str, int *de);
void    print_num(char *n, char *str, int minus);
void    print_nb(char  *nb, char c, int minus);
