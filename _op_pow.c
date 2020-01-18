#include "libft/libft.h"
#include <stdio.h>

char *_op_mul(char *a, char *b);
char *_op_add(char *a, char *b);

char *_op_pow(char *a, char *b)
{
    char *result;
    char *conter;
    char *_catcher;

    conter = ft_strdup("1");
    result = a;
    while (ft_strcmp(conter, b))
    {
        if (ft_strcmp(conter, "1"))
            _catcher = result;
        result = _op_mul(result, a);
        if (ft_strcmp(conter, "1"))
            free(_catcher);
        _catcher = conter;
        conter = _op_add(conter, "1");
        free(_catcher);
    }
    free(conter);
    return result;
}

int main() 
{
    char *a = _op_pow("12", "142");
	ft_putendl(a);
    printf("result = %s \n", a);
    //free(a);
    ft_strdel(&a);
    //printf("result = %s\n", );
}
