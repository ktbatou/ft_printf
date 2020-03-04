#include "src/include/ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>

int     main()
{
    //double d = 11.46;
    ft_printf(" %d\n", ft_printf("%.4000Lf", LDBL_MIN));
    //printf(" %d\n", printf("%.4000Lf", LDBL_MIN));
    return (0);
}   
