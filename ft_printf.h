/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/07 18:08:44 by ktbatou          ###   ########.fr       */
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
	int hash ;
	int point ;
	int plus ;
	int zero;
	int space;
	int l;
	int h;

} t_detail;

typedef struct s_valeur
{
	int 	i;
	int 	j;
	int 	f;
	int 	a;
	int 	flag;
	char	*num;
	char	*pre;
	long int l;
	long long int ll;
	short int h;
	signed char hh;
}	t_valeur;

typedef struct s_unsigned_v
{

	unsigned int i;
	unsigned long int l;
	unsigned long long ll;
	unsigned short int h;
	unsigned char hh;
	int	signe;
}	t_unsigned_v;

void    print_cond(t_detail d, t_valeur v, char *str, char c);
void    zero_print(t_valeur v, char *str, char c);
void    minus_print(t_detail d, t_valeur v, char *str, char c);
void    normal_print(t_detail d, t_valeur v, char *str, char c);
int     pre_size(char *str, int n);
int     prec(char *str, int n, char **num);
void    ft_nputstr(char const *s, int n); 
char    *ft_itoa_base(unsigned long long int n, int base, int a);
char            *ft_untoa(unsigned long long int n);
char            *ft_ntoa(long long int n);
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
void    get_details(char *s1 ,char *str, int i, t_unsigned_v  vl);
void    print_x(char *s1, char *s2, t_detail det);
int     conv_x(char *s1, va_list s2, int n);
int		ft_check(char *str, int i, va_list op);
int		ft_printf(char *str, ...);
int		conv_c(char *s1, va_list s2, int n);
int		conv_s(char *s1, va_list s2, int n);
int 	check_num(char *str);
int		checker(char *str, va_list ap, char *s );
int		get_detail(char *str, int *de);
void    print_num(char *n, char *pre, char *str, t_detail d);
void    print_nb(char  *nb, char c, int minus);
