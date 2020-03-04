#include "calc.h"

char *_op_pow_old(char *a, long b, int *len_out)
{
    char *result[2];
    int _len_a;
    long  conter;

    conter = 1;
    result[0] = ft_strdup(a);
    if (b == 0)
        return ft_strdup("1");
    _len_a = ft_strlen(a);
    while (conter != b)
    {
        result[1] = result[0];
        result[0] = _op_mul(result[0], a, (int []){0, _len_a}, len_out);
        free(result[1]);
        conter++;
    }
    return result[0];
}

char *_op_pow(char *a, long b, int *len_out)
{
    char *res;
    char *_catcher;
    int  start_free;
    int len;

    res = ft_strdup("1");
    *len_out = 1;
    start_free = 0;
    len = ft_strlen(a);
    while (b > 0)
    {
        ft_putendl("ok");
        if (b & 1)
        {
            _catcher = res;
            res = _op_mul(res, a, (int []){*len_out, len}, len_out);
            free(_catcher);
        }
        if ((b >> 1) <= 0)
            return res;
        //if ((b >> 1) & 1)
        //{
            _catcher = a;
            a = _op_mul(a, a, (int []){len, len}, &len);
            if (start_free)
                free(_catcher);
            start_free = 1;
        //}
        b = b >> 1;
    }
    return res;
}