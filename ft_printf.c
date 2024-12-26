/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimayumi <mimayumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:19:33 by mimayumi          #+#    #+#             */
/*   Updated: 2024/12/23 18:57:27 by mimayumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *args)
{
	int	i;

	i = 0;
	if (args == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	while (args[i])
	{
		ft_putchar(args[i]);
		i++;
	}
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_verify(char character, va_list args)
{
	int	len;

	len = 0;
	if (character == 'c')
		len = ft_putchar(args);
	else if (character == 's')
		len = ft_putstr(args);
	else if (character == 'd' || character == 'i')
		len = ft_putnbr(args);
	else if (character == 'u')
		len = ft_putnbr_u(args);
	else if (character == 'x' || character == 'X')
		len = ft_hexa(args);
	else if (character == 'p')
		len = ft_hexa_p(args);
	else
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_verify(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
