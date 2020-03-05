/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:25:12 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 16:25:19 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H
# include "../libft/libft.h"
# include "../include/ft_printf.h"
# include <limits.h>

typedef struct	s_float_rep
{
	unsigned long int	mantissa:63;
	unsigned int		check:1;
	unsigned int		exponent:15;
	unsigned int		sign:1;
}				t_float_rep;

typedef union	u_doubletofloatrep
{
	long double	f;
	t_float_rep	fr;
}				t_doubletofloatrep;

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

char			*opmul(char *a, char *b, int *params, int *len_out);
char			*opadd(char *a, char *b, int *params, int *len_out);
char			*oppow(char *a, long b, int *len_out);
void			f_detail(char *str, int n, t_valeur *v, t_detail *d);
long int		ft_atol(const char *str, t_bool use_max_int, int def);
char			*convesion_normalized(t_doubletofloatrep dfr, int *lo);
t_bool			is_bigger(char *num, int index);
t_bool			is_all_nine(char *num, int len);
void			printnumber(char *n, int *p, long int a, t_bool hash);
t_bool			is_nan(t_doubletofloatrep dfr);
t_bool			inf_null(t_doubletofloatrep dfr, t_bool verbose);
void			ft_putchar_seq(char c, int seq);
void			plus_minus(int sign);
int				get_after(char *after);
#endif
