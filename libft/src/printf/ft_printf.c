/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:28:49 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	check_char(char text);
static int	ft_print_data(char c, va_list *args);

/**
 * @brief Outputs the datas to the file descriptor STDOUT and return the total length of 'nb'.
 * 
 * @param format The string that specifies the formatting model of the data to display.
 * @param ... A variable number of arguments that will be replaced in the specified format.
 * @return Total length of the arguments'.
 */
int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	if ((write(STDOUT_FILENO, 0, 0) == -1))
		return (-1);
	va_start(args, format);
	len = ft_strlen(format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && check_char(format[i + 1]))
			len += ft_print_data(format[++i], &args) - 2;
		else if (format[i] != '%')
			ft_putchar_fd(format[i], STDOUT_FILENO);
		else
			len--;
		i++;
	}
	va_end(args);
	return (len);
}

static int	check_char(char text)
{
	return (text == 'c' || text == 's' || text == 'p' \
			|| text == 'd' || text == 'i' || text == 'u' \
			|| text == 'x' || text == 'X' || text == '%');
}

static int	ft_print_data(char c, va_list *args)
{
	if (c == 'i' || c == 'd')
		return (ft_printnbr(va_arg(*args, int)));
	if (c == 's')
		return (ft_printstr(va_arg(*args, char *)));
	if (c == 'u')
		return (ft_print_unsigned_int(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_printnbr_base(va_arg(*args, int), HEX_BASE_LOWER));
	if (c == 'X')
		return (ft_printnbr_base(va_arg(*args, int), HEX_BASE_UPPER));
	if (c == 'p')
	{
		write(STDOUT_FILENO, "0x", 2);
		return (2 + ft_print_pointer(va_arg(*args, unsigned long), HEX_BASE_LOWER));
	}
	if (c == 'c')
		ft_putchar_fd(va_arg(*args, int), STDOUT_FILENO);
	else if (c == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
