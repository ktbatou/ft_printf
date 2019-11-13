#include "ft_printf.h"

void    test(int a, ...);
int	main()
{
	char str[100] = "kaoutar";
	int a;
	int i = 0;

	a = ft_printf("Im %1x ", 54654);

	i = printf("\nIm %o \n", 54654);
//	printf("%x\n", 5);
//	printf("%\n", i);
//	printf("|%s|\n", "Kao");
//	printf("|%.2s|\n", "Kaofuu");
//	printf("|%5s|\n", "Kao");
//	printf("|%.0s|\n", "Kao");
//	printf("|%-.s|\n", "Kao");
//	printf("|%-6s|\n", "Kao");
//	printf("|%-.3s|\n", "Kaoooo");
//	printf("|%-.0s|\n", "Kao");
//	printf("|%d|\n", "Kao");
//	printf("|%-s|\n", "Kao");
//	printf("|Q%04%Q|\n"); */
}
