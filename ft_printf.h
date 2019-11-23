/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/23 14:41:32 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct s_date
{
	char flags[10];
	int (*flag[10])(char *str, va_list s2, int n);
} t_data;

typedef struct s_detail
{
	int minus;
	int hash;
	int point;
	int plus;
	int zero;
} t_detail;

typedef struct s_valeur
{
	int 	i;
	int 	j;
	int 	f;
	int 	a;
	int 	flag;
	char	*num;
}	t_valeur;


int     percent(char *str, va_list  s2, int n);
int     conv_o(char *str, va_list s2, int n);
char	*ft_utoa(unsigned int n);
int     conv_u(char *str, va_list s2, int n);
int     conv_i(char *str, va_list s2, int n);
int     conv_d(char *str, va_list s2, int n);
int     conv_xx(char *str, va_list s2, int n);
void    print_p(char *s1, char *str, int minus);
int     conv_p(char *str, va_list s2, int n);
int     flag_size(char *str, int n);
void    get_details(char *s1 ,char *str, int i);
void    print_x(char *s1, char *s2, t_detail det);
int     conv_x(char *s1, va_list s2, int n);
int		ft_check(char *str, int i, va_list op);
int		ft_printf(char *str, ...);
int		conv_c(char *s1, va_list s2, int n);
int		conv_s(char *s1, va_list s2, int n);
int 	check_num(char *str);
int		checker(char *str, va_list ap, char *s );
int		get_detail(char *str, int *de);
void    print_num(char *n, char *str, int minus);
void    print_nb(char  *nb, char c, int minus);
