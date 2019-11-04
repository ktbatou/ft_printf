#include "ft_printf.h"

struct data
{
	char flags[10];
	void *t;
};

const struct data g_struct =
{
	{1234},
	{&conv_c}
};

data = g_struct;
