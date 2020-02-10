#include "include/ft_printf.h"
#include <limits.h>
char    *ft_sum(char *num1, char *num2);
char		*ft_sumx(char *nbr1, char *nbr2);
char	*ft_multiplication(char *num1, char *num2);
int	main()
{
	char str[100] = "kaoutar";
	int a;
	int i = 200;


	//printf("result = %s\n", ft_multiplication("23578", "235"));
	//while (i-- >= 0)
//	printf("-- %d --",ft_printf("%o\n", 444));
	//	printf("%010x\n",0);
		//printf("%d\n",ft_printf("%%\n"))
		//ft_printf("|%.2d|\n",-11);
		//printf("|%.2d|\n", -11);
	printf("  %d\n",ft_printf("|%#0.22o|", ULLONG_MAX));
	printf("  %d\n",printf("|%#0.22o|", ULLONG_MAX));
	//printf("%%55\n");
	// ft_printf("-- %d --",printf("%"));
	//printf ("\n%d ", printf("%"));
//	printf("\n%20p", &i);
//	printf("\n%9.3d\n", 99);
//	printf("%x\n", 5);
//	printf("%\n", i);
//	printf("|%s|\n", "Kao");
//	printf("|%.2s|\n", "Kaofuu");
//	printf("|%5s|\ni", "Kao");
//	printf("|%.0s|\n", "Kao");
//	printf("|%-.s|\n", "Kao");
//	printf("|%-6s|\n", "Kao");
//	printf("|%-.3s|\n", "Kaoooo");
//	printf("|%-.0s|\n", "Kao");
//	printf("|%d|\n", "Kao");
//	printf("|%-s|\n", "Kao");
//	printf("|Q%04%Q|\n"); */
}
