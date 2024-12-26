#include "ft_printf.h"

har	*ptr_to_hex(void *ptr, int len)
{
	char				*base;
	char				*str;
	unsigned long long	val;
	unsigned long long	temp;

	base = "0123456789abcdef";
	val = (unsigned long long)ptr;
	temp = val;
	while (temp > 0)
	{
		temp /= 16;
		if (temp <= 0)
			break ;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[val % 16];
		val /= 16;
	}
	return (str);
}

void	ft_hexa(unsigned int args, char c, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (args >= 16)
		ft_hexa(args / 16, c, count);
	ft_putchar(base[args % 16], count);
}

void	ft_hexa_p(unsigned long args, char c, int *count)
{
	static char	base[] = "0123456789abcdef";

	if (args == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	if (c == 'p')
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		c = 'x';
	}
	if (args >= 16)
		ft_hexa_p(args / 16, c, count);
	ft_putchar(base[args % 16], count);
}

void	ft_putnbr(int args, int *count)
{
	if (args == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (args < 0)
	{
		ft_putchar('-', count);
		args = args * (-1);
	}
	if (args >= 10)
		ft_putnbr(args / 10, count);
	ft_putchar((args % 10) + '0', count);
}

void	ft_putnbr_u(unsigned int args, int *count)
{
	if (args >= 10)
		ft_putnbr_u(args / 10, count);
	ft_putchar((args % 10) + '0', count);
}