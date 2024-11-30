/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimayumi <mimayumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:19:33 by mimayumi          #+#    #+#             */
/*   Updated: 2024/11/30 16:16:59 by mimayumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	verify(va_list args, char character) //vai verificar o caracter depois do % pra saber o tipo do args
{
	if (character == 'c')
		ft_putchar(va_args(args, int));
	else if (character == 's')
		ft_putstr(va_args(args, char *));
	else if (character == 'p')
		//função que irá printar um ponteiro
	else if (character == 'd' || character == 'i')
		ft_putnbr(/*fazer essa função*/);
	else if (character == 'u')
		//função que irá printar unsigned
	else if (character == 'x' || character == 'X')
		//função com condição se encontrar um ou outro
	else
		ft_putchar('%');	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			total += verify(args, format[i]);
		}
		else
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total);
}
