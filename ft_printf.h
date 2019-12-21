/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/21 14:17:56 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_date
{
	char	flags[10];
	int		(*flag[10])(char *str, va_list s2, int n);
}				t_data;

typedef struct	s_detail
{
	int	minus;
	int	hash;
	int	point;
	int	plus;
	int	zero;
	int	space;
	int	l;
	int	h;

}				t_detail;

typedef struct	s_valeur
{
	int				i;
	int				j;
	int				f;
	int				a;
	int				n;
	int				flag;
	char			*num;
	char			*pre;
	short int		h;
	long int		l;
	signed char		hh;
	long long int	ll;
}				t_valeur;

typedef struct	s_unsigned_v
{
	int					signe;
	unsigned int		i;
	unsigned char		hh;
	unsigned short int	h;
	unsigned long int	l;
	unsigned long long	ll;
}				t_unsigned_v;

int				pre_vlr(t_valeur *v, t_valeur vl, int n);
void			intial(t_detail *d, t_valeur *v);
void			cond_u(t_detail d, t_valeur v, char *str);
t_detail		flags(char *str, int n);
void			u_types(t_detail d, t_unsigned_v *v, char **num, va_list s2);
t_detail    	type_flag(char *str, int n);
t_detail		flag_detail(char *str, int n);
char			*type_conv(t_valeur v, t_detail det);
void    		types(va_list s2, t_detail detail , t_valeur *vlr);
void			cond_s(t_detail d, char *str, int i, int j);
void			negative_print(t_detail d, t_valeur v, char *str, char c);
void			cond(t_detail d, t_valeur v, t_valeur vl, char *s);
void			zero_print(t_valeur v, char *str, char c);
void			minus_print(t_detail d, t_valeur v, char *str, char c);
void			normal_print(t_detail d, t_valeur v, char *str, char c);
int				pre_size(char *str, int n);
int				prec(char *str, int n, t_valeur v);
void			ft_nputstr(char const *s, int n);
char			*ft_itoa_base(unsigned long long int n, int base, int a);
char			*ft_untoa(unsigned long long int n);
char			*ft_ntoa(long long int n);
int				percent(char *str, va_list s2, int n);
int				conv_o(char *str, va_list s2, int n);
char			*ft_utoa(unsigned int n);
int				conv_u(char *str, va_list s2, int n);
int				conv_i(char *str, va_list s2, int n);
int				conv_d(char *str, va_list s2, int n);
int				conv_xx(char *str, va_list s2, int n);
int				print_p(t_valeur v, char *str, t_detail d);
int				conv_p(char *str, va_list s2, int n);
int				flag_size(char *str, int n);
int				get_details(char *s1, char *str, int i, t_unsigned_v vl);
int				print_x(t_valeur v, char *s2, t_detail det);
int				conv_x(char *s1, va_list s2, int n);
int				ft_check(char *str, int i, va_list op, t_valeur *v);
int				ft_printf(char *str, ...);
int				conv_c(char *s1, va_list s2, int n);
int				conv_s(char *s1, va_list s2, int n);
int				check_num(char *str);
int				checker(char *str, va_list ap, char *s);
int				get_detail(char *str, int *de);
int				print_num(char *n, char *pre, char *str, t_detail d);
void			print_nb(char *nb, char c, int minus);

#endif
