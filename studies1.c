int	handle_specifier(char specifier, va_list args, int total)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == 'd' || specifier == 'i')
		printed = convert_int_to_str(args);
	else if (specifier == 'x' || specifier == 'X')
		printed = convert_hex_to_str(args, specifier);
	else if (specifier == 'u')
		printed = convert_unsigned_to_str(args);
	else if (specifier == '%')
		printed = print_percentage();
	else if (specifier == 'p')
		printed = convert_ptr_to_str(args);
	else
	{
		if (total > 0)
			return (-1);
		write(1, '%', 1);
	}
	return (printed);
}


#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;
	size_t	length;

	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	return (write(1, str, length));
}