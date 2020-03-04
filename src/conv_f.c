
#include "./include/ft_printf.h"
#include "calc/calc.h"
#include <limits.h>

typedef struct s_float_rep
{
    unsigned long int   mantissa:63;
    unsigned int        check:1;
    unsigned int        exponent:15;
    unsigned int        sign:1;
}               t_float_rep;

typedef union u_doubletofloatrep
{
    long double f;
    t_float_rep fr;
}             t_doubletofloatrep;

typedef enum e_bool {
    false = 0,
    true = 1
}             t_bool;

void printb(unsigned long int b)
{
    if (b > 1)
        printb(b / 2);
    ft_putnbr(b % 2);

}

char *convesion_normalized(t_doubletofloatrep dfr, int *len_out, long int after)
{
    char *mantissa;
    char *twopower;
    char *result[3];
    int  len;

    if (dfr.f == 0)
        return ft_strdup("0");
    mantissa = ft_ntoa(dfr.fr.mantissa);
    result[0] = _op_add(mantissa, "9223372036854775808", (int []){0, 19}, len_out);
    if ((dfr.fr.exponent - 16383 - 63) < 0)
    {
        (void)after;
        //if (after < -(dfr.fr.exponent - 16383 - 63) && dfr.fr.mantissa == 0)
        //    return ft_strdup("0");
        twopower = _op_pow("5", -(dfr.fr.exponent - 16383 - 63), &len);
        //printf("==> %d\n", -(dfr.fr.exponent - 16383 - 63));
        //ft_putendl(twopower);
    }
    else
        twopower = _op_pow("2", dfr.fr.exponent - 16383 - 63, &len);
    result[1] = result[0];
    result[2] = twopower;
    result[0] = _op_mul(result[0], twopower, (int []){*len_out, len}, len_out);
    free(result[1]);
    free(result[2]);
    free(mantissa);
    return result[0];
}

t_bool ft_type(char *str)
{
    while (*str != 'f')
    {
        if (*str == 'L')
            return true;
        str++;
    }
    return false;
}

int			checker_f(t_detail *d, t_valeur *v, char *s, int n)
{
	int i;

	i = 0;
    if (s[n] == '#')
        d->hash = 1;
	if (s[n] == '+' && d->signe == 1)
		d->plus = 1;
	if (s[n] == '-')
		d->minus = 1;
	if (s[n] == ' ' && d->signe == 1)
		d->space = 1;
	if (s[n] >= '0' && s[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(v->i);
		if (s[n] == '0' && v->flag == 0)
			d->zero = 1;
		v->flag = 1;
		v->num[v->j++] = s[n];
	}
	if (s[n] == '.')
	{
		v->pre = ft_strnew(pre_size(s, n + 1));
		i = pre_size(s, n + 1) > 0 ? prec(s, n + 1, *v) : 0;
		d->point = 1;
	}
	return (i);
}

int			string_size_f(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n] != 'f')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

void        f_detail(char *str, int n, t_valeur *v, t_detail *d)
{
	
	v->i = string_size_f(str, n);
	while (str[n] != 'f')
	{
		n += checker_f(d, v, str, n);
		n++;
	}
}

void    ft_putchar_seq(char c, int seq)
{
    while (seq-- > 0)
        ft_putchar(c);
}

void    _print_number_V2(char *num, int point, t_bool before, int after, t_bool hash)
{
    while (*num == '0' && *(num + 1) && num++);
    if (before)
    {
        (after || (!after && hash)) ? ft_putstr("0.") : ft_putstr("0");
        ft_putchar_seq('0', (point < after) ? point : after);
        after -= ((point < after) ? point : after);
        //printf("after: %d\n", after);
        while (*num && after--)
            ft_putchar_seq(*num++, 1);
    }
    else
    {
        after += point + ((after) ? 1 : 0);
        while (*num && after--)
            ft_putchar_seq((point--) ? *num++ : '.', 1);
        (!point && (after-- > 0 || hash)) ? ft_putchar('.') : 0;
    }
    ft_putchar_seq('0', after);
}

t_bool is_bigger(char *num, int index)
{
    if ((int)num[index] - 48 > 5)
        return true;
    else if ((int)num[index] - 48 == 5)
    {
        if ((int)num[index - 1] - 48 == 5)
            return true;
        num = num + index + 1;
        while (*num)
            if (*num++ != '0')
                return true;
    }
    return false;
}

t_bool is_all_nine(char *num, int len)
{
    while (len--)
        if (*num++ != '9')
            return false;
    return true;
}

void     print_number_V2(char *num, int len, int point, long int after, t_bool hash)
{
    char *_catcher;

    while (*num == '0' && *(num + 1) && num++ && len--);
    if (point > 0)
        _print_number_V2(num, len, false, after, hash);
    else
    {
        if (-point >= len)
        {
            point = -point - len;
            //printf("=> %ld\n", after - point);
            //printf("point: %d, after: %ld, len: %d=> \n", point, after, len);
            if (after - point >= 0 && after - point < len &&  is_bigger(num, after - point))
            {
                _catcher = num;
                num = _op_add("1", num, (int []){1, after - point}, &len);
                (is_all_nine(_catcher, after - point)) ? point-- : 0;
            }
            //point = (after == point) ? point - 1 : point;
            _print_number_V2(num, point, true, after, hash);
        }
        else
        {
            point = len + point;
            if (after + point < len && is_bigger(num, after + point))
            {
                _catcher = num;
                num = _op_add("1", num, (int []){1, after + point}, &len);
                (is_all_nine(_catcher, after + point)) ? point++ : 0;
                //printf("po2: %d, %s\n", point, num);
            }
            _print_number_V2(num, point, false, after, hash);
        }
    }
}

int     calc_float(char *num, int len, int point, long int after, t_bool hash)
{
    char *_catcher;
    
    while (*num == '0' && *(num + 1) && num++ && len--);
    if (point > 0)
        return len + after + ((after || hash) ? 1 : 0);
    else
    {
        if (-point >= len)
        {
            point = -point - len;
            //(after - point < 0) ? point = 0 : 0;
            if (after - point >= 0 && after - point < len &&  is_bigger(num, after - point))
            {
                _catcher = num;
                num = _op_add("1", num, (int []){1, after - point}, &len);
                (is_all_nine(_catcher, after - point)) ? point-- : 0;
            }
            //point = (after == point) ? point - 1 : point;
            return after + ((after || (!after && hash)) ? 2 : 1);
        }
        else
        {

            point = len + point;
            //printf("op: %d, poi: %d, after: %ld, len: %d\n", point - len, point, after, len);
            if (after + point < len && is_bigger(num, after + point))
            {
                _catcher = num;
                num = _op_add("1", num, (int []){1, after + point}, &len);
                (is_all_nine(_catcher, after + point)) ? point++ : 0;
            }
            return point + after + ((after || hash) ? 1 : 0);
        }
    }
    return 0;
}

t_bool is_nan(t_doubletofloatrep dfr)
{
    if (dfr.fr.exponent == 32767 && dfr.fr.mantissa)
        return true;
    return false;
}

t_bool inf_null(t_doubletofloatrep dfr, t_bool verbose)
{
    if (dfr.fr.exponent == 32767 && !dfr.fr.mantissa)
    {
        (verbose) ? ft_putstr("inf") : 0;
        return false;
    }
    else if (dfr.fr.exponent == 32767 && dfr.fr.mantissa)
    {
        (verbose) ? ft_putstr("nan") : 0;
        return false;
    }
    return true;
}

long int	ft_atol(const char *str, t_bool use_max_int, int def)
{
	int	i;
	long int nb;
	int	bolean;

	bolean = 0;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		bolean = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - '0') + (nb * 10);
		i++;
	}
	if (!use_max_int)
		return ((bolean == 1) ? -nb : nb);
    else
        return ((nb > INT_MAX) ? def : nb);

}


int     print(char *str, int n, t_doubletofloatrep dfr)
{
    t_detail d;
    t_valeur v;
    char *result;
    int len_out;
    int len;
    int ch;

    intial(&d, &v);
    (dfr.f >= 0) ? d.signe = 1 : 0;
    f_detail(str, n, &v, &d);
    len_out = 0;
    inf_null(dfr, false) ? result = convesion_normalized(dfr, &len_out, (v.pre) ? ft_atol(v.pre, true, 6) : 6) : NULL;
    //ft_putendl(result);
    //return 0;
    len = 0;
    ch = 0;
    (d.space && !d.plus && !dfr.fr.sign && ++ch) ? ft_putchar(' ') : 0;
    ((dfr.fr.sign || d.plus) && (!d.minus && d.zero && inf_null(dfr, false)) && ++ch) ? ft_putchar(dfr.fr.sign ? '-' : '+') : 0;
    ((dfr.fr.sign || d.plus) && !(!d.minus && d.zero && inf_null(dfr, false)) && !is_nan(dfr)) ? ch++ : 0;
    n = ((dfr.fr.exponent == 32767) ? 3 : calc_float(result, len_out, dfr.fr.exponent - 16383 - 63, (v.pre) ? ft_atol(v.pre, true, 6) : 6, d.hash)) + ch;
    //ft_putendl(result);
    //printf("==> %d\n", n - ch);
    len = (v.num) ? ft_atol(v.num, true, 6) - n : len - ch;
    if (!d.minus)
        ft_putchar_seq((d.zero && inf_null(dfr, false)) ? '0' : ' ', len);
    ((dfr.fr.sign || d.plus) && !(!d.minus && d.zero && inf_null(dfr, false)) && !is_nan(dfr)) ? ft_putchar(dfr.fr.sign ? '-' : '+') : 0;
    inf_null(dfr, true) ? print_number_V2(result, len_out, dfr.fr.exponent - 16383 - 63, (v.pre) ? ft_atol(v.pre, true, 6) : 6, d.hash) : 0;
    if (d.minus)
        ft_putchar_seq(' ', len);
    return ((len > 0) ? len : 0) + n;
}

int		conv_f(char *str, va_list s2, int n)
{
    t_doubletofloatrep dfr;


    dfr.fr.exponent = 0;
    dfr.fr.mantissa = 0;
    dfr.fr.sign = 0;
    if (ft_type(str + n))
        dfr.f = va_arg(s2, long double);
    else
        dfr.f = va_arg(s2, double);
    return print(str, n, dfr);
}