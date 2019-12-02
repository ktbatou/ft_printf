#include "ft_printf.h"
#include <limits.h>
void    test(int a, ...);
int	main()
{
	char str[100] = "kaoutar";
	int a;
	int i = 2000;

	printf("\n%d\n", ft_printf("%x", 2233));
	printf("%d\n", 	  printf("%#llo\n", 22337203685477ul));
	
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
