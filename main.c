#include "ft_printf.h"

void    test(int a, ...);
int	main()
{
	char str[100] = "kaoutar";
	int a;
	int i = -156543;

	a = ft_printf("|%-#22o| \n",i);
	//printf("\n|%o| \n",i);
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
