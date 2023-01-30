/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:02:23 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 14:13:15 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printf_c(va_arg(args, int));
	else if (c == 's')
		len = ft_printf_s(va_arg(args, char *));
	else if (c == 'p')
		len = ft_printf_p(va_arg(args, unsigned long int));
	else if (c == 'd' || c == 'i')
		len = ft_printf_d_and_i(va_arg(args, int));
	else if (c == 'u')
		len = ft_printf_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_printf_lower_x(va_arg(args, unsigned int));
	else if (c == 'X')
		len = ft_printf_upper_x(va_arg(args, unsigned int));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_printed;

	i = 0;
	len_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (!str)
			return (-1);
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len_printed += ft_format(str[i + 1], args);
			i += 2;
		}
		else
		{
			len_printed += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len_printed);
}
