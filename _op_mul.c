#include "./libft/libft.h"
#include <stdio.h>

char *_op_add(char *a, char *b);

int _bigger_loop(char *result, char *a, char *b, int _iteration)
{
	int _len_a;
	int _len_b;
	int index;
	int _retenu;

	((_len_a = ft_strlen(a)) && (_len_b = ft_strlen(b)));
	((index = -1) && (_retenu = 0));
	while (++index < ((_len_a > _len_b) ? _len_a : _len_b))
		if (((int)a[((_len_a > _len_b) ? index : _iteration)] - 48) * 
		((int)b[((_len_a > _len_b) ? _iteration : index)] - 48) + _retenu >= 10)
		{
			result[index] = (((int)a[((_len_a > _len_b) ? index : _iteration)] - 48) *
			 ((int)b[((_len_a > _len_b) ? _iteration : index)] - 48) + _retenu) % 10 + '0';
			_retenu = (((int)a[((_len_a > _len_b) ? index : _iteration)] - 48) * 
			((int)b[((_len_a > _len_b) ? _iteration : index)] - 48) + _retenu) / 10;
		}
		else
		{
			result[index] = (((int)a[((_len_a > _len_b) ? index : _iteration)] - 48) * 
			((int)b[((_len_a > _len_b) ? _iteration : index)] - 48) + _retenu) + '0';
			_retenu = 0;
		}
    (_retenu) ? result[index++] = _retenu + '0' : 0;
	result[index] = '\0';
	return index;
}

char *_smaller_loop(char *a, char *b, int _len_a, int _len_b)
{
	char *partial_result[2];
	char *result;
	int index;
	int _catcher;
	int partial_index;

	(_len_a = ft_strlen(a)) && (_len_b = ft_strlen(b));
	((index = -1) && (result = ft_strdup("0")));
	while (++index < ((_len_a > _len_b) ? _len_b : _len_a))
	{
		partial_result[0] = malloc(sizeof(char) * ((_len_a > _len_b) 
		? _len_a + 1 + index : _len_b + 1 + index));
		partial_index = _bigger_loop(partial_result[0], a, b, index);
		ft_strrev(partial_result[0]);
		_catcher = index;
		while(_catcher--)
			partial_result[0][partial_index++] = '0';
		partial_result[0][partial_index] = '\0';
		partial_result[1] = result;
		result = _op_add(result, partial_result[0]);
		ft_strdel(&partial_result[0]);
		ft_strdel(&partial_result[1]);
	}
	return result;
}

char *_op_mul(char *a, char *b)
{
	char *result;
	int len_a;
	int len_b;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	a = ft_strdup(a);
	b = ft_strdup(b);
	ft_strrev(a);
	ft_strrev(b);
	result = _smaller_loop(a, b, len_a, len_b);
	ft_strdel(&a);
	ft_strdel(&b);
	return result;
}