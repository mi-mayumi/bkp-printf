/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:04:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/13 11:27:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list args)
{
	int	temp;
	int	total;
	int	index;

	total = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			index++;
			temp = handle_specifier(format[index], args, total);
			if (temp == -1)
				return (-1);
			total += temp;
		}
		else
		{
			write(1, &format[index], 1);
			total++;
		}
		index++;
	}
	return (total);
}
