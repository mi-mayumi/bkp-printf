/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimayumi <mimayumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:20:33 by wribeiro          #+#    #+#             */
/*   Updated: 2024/12/23 12:12:32 by mimayumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, int lettercase)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (lettercase)
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, lettercase);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	count_digits(long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ptr_to_hex(void *ptr, int len)
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

int	get_hex_str(void *ptr)
{
	char	*hex_str;
	int		len;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 1;
	hex_str = ptr_to_hex(ptr, len);
	if (!hex_str)
		return (-1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_str, 1);
	len = ft_strlen(hex_str) + 2;
	free(hex_str);
	return (len);
}
