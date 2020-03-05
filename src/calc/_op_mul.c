#include "calc.h"
#include <stdio.h>

void _bigger_loop(char *result, char *b, char *s, int *params)
{
	int r_index;
	int index;
	int _pre_index;
	int _retenu;

	_pre_index = params[0];
	_retenu = 0;
	index = params[1];
	r_index = params[3];
	while (--index >= 0)
		if (((int)b[index] - 48) * ((int)s[_pre_index] - 48) + _retenu >= 10)
		{
			result[r_index--] = (((int)b[index] - 48) * ((int)s[_pre_index] - 48) + _retenu) % 10 + '0';
			_retenu = (((int)b[index] - 48) * ((int)s[_pre_index] - 48) + _retenu) / 10;
		}
		else
		{
			result[r_index--] = (((int)b[index] - 48) * ((int)s[_pre_index] - 48) + _retenu) + '0';
			_retenu = 0;
		}
    (_retenu) ? result[r_index--] = _retenu + '0' : 0;
	while (r_index >= 0)
		result[r_index--] = '0';
}

/*int	 get_number(char *num, int index)
{
	return (int)num[index] - 48;
}*/

# define get_number(num, index) ((int)num[index] - 48)

char *_smaller_loop(char *b, char *s, int *params, int *len_out)
{
	char *partial_result;
	char *result[2];
	int index;
	int _fix;
	int r_index;

	result[0] = ft_strdup("0");
	index = params[1];
	*len_out = 1;
	while (--index >= 0)
	{
		_fix = (params[1] - index - 1);
		r_index = (params[0] + 1 + _fix);
		params[2] = r_index;
		partial_result = malloc(sizeof(char) * (r_index + 1));
		partial_result[r_index--] = '\0';
		while (_fix--)
			partial_result[r_index--] = '0';
		_bigger_loop(partial_result, b, s, (int []){index, params[0], params[1], r_index});
		result[1] = result[0];
		result[0] = _op_add(result[0], partial_result, (int []){*len_out, params[2]}, len_out);
		free(result[1]);
		free(partial_result);
	}
	return result[0];
}

char *_op_mul(char *a, char *b, int *params, int *len_out)
{
	char *_s_catcher;
	int len_b;
	int len_s;
	int _i_catcher;

	while (a && *(a + 1) && *a == '0' && a++)
		(params && params[0]) ? params[0]-- : 0;
    while (b && *(b + 1) && *b == '0' && b++)
		(params && params[1]) ? params[1]-- : 0;
	len_b = (params && params[0]) ? params[0] : ft_strlen(a);
	len_s = (params && params[1]) ? params[1] : ft_strlen(b);
	if (len_s > len_b)
    {
        _s_catcher = a;
        a = b;
        b = _s_catcher;
        _i_catcher = len_b;
        len_b = len_s;
        len_s = _i_catcher;
    }
	return _smaller_loop(a, b, (int []){len_b, len_s, len_s}, len_out);
}