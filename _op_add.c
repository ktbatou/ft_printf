#include "./libft/libft.h"
#include <stdio.h>

void	_add_suffix(char *result, char *a, int index, int _retenu)
{
	int _len_a;

	_len_a = ft_strlen(a);
	index = index - 1;
	while (++index < _len_a)
        if ((((int)a[index] - 48) + _retenu) >= 10)
        {
            result[index] = (((int)a[index] - 48) + _retenu - 10) + '0';
            _retenu = 1;
        }
        else
        {
            result[index] = ((int)a[index] - 48) + _retenu + '0';
            _retenu = 0;
        }
    if (_retenu)
        result[index++] = _retenu + '0';
    result[index] = '\0';
}

void	_add_handler(char *result, char *a, char *b)
{
	int index;
	int  _len_a;
	int	 _len_b;
	int  _retenu;

	_len_a = ft_strlen(a);
	_len_b = ft_strlen(b);
	_retenu = 0;
	index = -1;
	while (++index < ((_len_a > _len_b) ? _len_b : _len_a))
        if ((((int)a[index] - 48) + ((int)b[index] - 48) + _retenu) >= 10)
        {
            result[index] = (((int)a[index] - 48) + ((int)b[index] - 48) + _retenu - 10) + '0';
            _retenu = 1;
        }
        else
        {
            result[index] = ((int)a[index] - 48) + ((int)b[index] - 48) + _retenu + '0';
            _retenu = 0;
        }
	_add_suffix(result, (_len_a > _len_b) ? a : b, index, _retenu);
}


char *_op_add(char *a, char *b)
{
	char *result;
	int  _len_a;
	int	 _len_b;

    _len_a = ft_strlen(a);
    _len_b = ft_strlen(b);
	result = (char *)malloc(sizeof(char) * ((_len_a > _len_b) ? _len_a + 1 : _len_b + 1));
	a = ft_strdup(a);
	b = ft_strdup(b);
	ft_strrev(a);
	ft_strrev(b);
	_add_handler(result, a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	ft_strrev(result);
	return result;
}