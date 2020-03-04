#include "calc.h"
#include <stdio.h>

void	_add_suffix(char *result, char *b, int *params)
{
    int r_index;
    int index;
	int  _retenu;

    _retenu = params[0];
    r_index = params[1];
    index = params[2];
	while (--index >= 0)
        if ((((int)b[index] - 48) + _retenu) >= 10)
        {
            result[r_index--] = (((int)b[index] - 48) + _retenu - 10) + '0';
            _retenu = 1;
        }
        else
        {
            result[r_index--] = ((int)b[index] - 48) + _retenu + '0';
            _retenu = 0;
        }
    if (_retenu)
        result[r_index--] = _retenu + '0';
    while(r_index >= 0)
        result[r_index--] = '0';
}

void	_add_handler(char *result, char *b, char *s, int *params)
{
    int r_index;
    int index;
	int  _retenu;

	_retenu = 0;
	r_index = params[0] + 1;
    index = params[1];
    result[r_index--] = '\0';
	while (--index >= 0)
        if ((((int)b[index + (params[0] - params[1])] - 48) + ((int)s[index] - 48) + _retenu) >= 10)
        {
            result[r_index--] = (((int)b[index + (params[0] - params[1])] - 48) + ((int)s[index] - 48) + _retenu - 10) + '0';
            _retenu = 1;
        }
        else
        {
            result[r_index--] = ((int)b[index + (params[0] - params[1])] - 48) + ((int)s[index] - 48) + _retenu + '0';
            _retenu = 0;
		}
	_add_suffix(result, b, (int []){_retenu, r_index, params[0] - params[1]});
}

char *_op_add(char *a, char *b, int *params, int *len_out)
{
	char *result;
    char *_s_catcher;
	int  _len_b;
	int	 _len_s;
    int _i_catcher;

    while (a && *(a + 1) && *a == '0' && a++)
        (params && params[0]) ? params[0]-- : 0;
    while (b && *(b + 1) && *b == '0' && b++)
        (params && params[1]) ? params[1]-- : 0;
    _len_b = (params && params[0]) ? params[0] : ft_strlen(a);
    _len_s = (params && params[0]) ? params[1] : ft_strlen(b);
    if (_len_s > _len_b)
    {
        _s_catcher = a;
        a = b;
        b = _s_catcher;
        _i_catcher = _len_b;
        _len_b = _len_s;
        _len_s = _i_catcher;
    }
	result = (char *)malloc(sizeof(char) * (_len_b + 2));
	_add_handler(result, a, b, (int []){_len_b, _len_s});
    *len_out = _len_b + 1;
	return result;
}