/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimayumi <mimayumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:27:00 by wribeiro          #+#    #+#             */
/*   Updated: 2024/12/23 12:16:54 by mimayumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex(unsigned long long n, int lettercase);
int		count_digits(long n, int base);
int		get_hex_str(void *ptr);
char	*ptr_to_hex(void *ptr, int len);

int	handle_diuxx(const char format, int len, va_list args, int base)
{
	long	num;

	if (format == 'd' || format == 'i')
	{
		num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
	}
	else
	{
		num = va_arg(args, unsigned int);
		if (format == 'x')
			ft_puthex(num, 0);
		else if (format == 'X')
			ft_puthex(num, 1);
		else if (format == 'u')
			ft_putunbr(num);
	}
	len += count_digits(num, base);
	return (len);
}

int	handle_s(int len, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len += ft_strlen(str);
	}
	return (len);
}

int	handle_format(const char format, int len, va_list args)
{
	int	base;

	base = 10;
	if (format == 'x' || format == 'X')
		base = 16;
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len++;
	}
	else if (format == 'p')
		len += get_hex_str(va_arg(args, void *));
	else if (format == 's')
		len = handle_s(len, args);
	else if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'x' || format == 'X')
		len = handle_diuxx(format, len, args, base);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		else
			len = handle_format(format[++i], len, args);
		i++;
	}
	va_end(args);
	return (len);
}
