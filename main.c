#include "src/include/ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>

int     main()
{
    //double d = 11.46;
    ft_printf(" %d\n", ft_printf("%15.554f", 878787.7878));
    printf(" %d\n", printf("%15.554f", 878787.7878));
    return (0);
}   
