/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimayumi <mimayumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:26:47 by mimayumi          #+#    #+#             */
/*   Updated: 2024/12/23 19:09:52 by mimayumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int args, char c)
{
	int		len;
	char	*base;
	
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (args >= 16)
		len = ft_hexa(args / 16, c);
	len = ft_putchar(base[args % 16]);
	return (len);
}

int	ft_hexa_p(unsigned long args, char c)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	if (args == 0)
	{
		len = ft_putstr("(nil)");
		return ;
	}
	if (c == 'p')
	{
		len = ft_putstr("0x");
		c = 'x';
	}
	if (args >= 16)
		ft_hexa_p(args / 16, c);
	len = ft_putchar(base[args % 16]);
}

//ARRUMAR A PUTNBR ABAIXO

/*int	ft_putnbr(int args)
{
	int	len;
	
	if (args == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (args < 0)
	{
		ft_putchar('-');
		args = args * (-1);
	}
}*/