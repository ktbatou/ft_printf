#include "ft_printf.h"

void    test(int a, ...);
int	main()
{
	char str[10] = "ktbatou";
	int a;

	a = ft_printf("Im %s i've played for %c times", str, 57);

/*	printf("%d\n", a);
	printf("|%5s|\n", "Kao");
	printf("|%.2s|\n", "Kao");
	printf("|%5s|\n", "Kao");
	printf("|%.0s|\n", "Kao");
	printf("|%-.s|\n", "Kao");
	printf("|%-6s|\n", "Kao");
	printf("|%-.2s|\n", "Kao");
	printf("|%-.0s|\n", "Kao");
	printf("|%d|\n", "Kao");
	printf("|%-s|\n", "Kao");
	printf("|Q%04%Q|\n"); */
}
