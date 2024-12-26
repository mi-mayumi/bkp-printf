
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	x;

	ft_printf("%c %s %d %p %u 100%% %x %X %x %X\n", 'a', "Milena", INT_MAX, (void *)0, 30000000, 255, 255, -255, -255);
	printf("%c %s %d %p %u 100%% %x %X %x %X\n", 'a', "Milena", INT_MAX, (void *)0, 30000000, 255, 255, -255, -255);
	x = ft_printf("\n\n%c %s %d %p %u 100%% %x %X %x %X\n", 'a', "Milena", INT_MAX, (void *)0, 30000000, 255, 255, -255, -255);
	ft_printf("%d\n", x);
	printf("%d\n", x);
	printf("%p\n", &x);
	ft_printf("%p\n", &x);
	printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MIN);
	printf(NULL);
	ft_printf(NULL);
	x = printf(NULL);
	printf("%d\n", x);
	x = ft_printf(NULL);
	printf("%d\n", x);
	printf("%u\n", UINT_MAX);
	ft_printf("%u\n", UINT_MAX);
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	return (0);
}
