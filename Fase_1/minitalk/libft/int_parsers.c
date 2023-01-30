/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:17 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:31:20 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_int(va_list args, t_format *format)
{
	int	nbr;

	nbr = va_arg(args, int);
	if (nbr >= 0)
		nbr = -nbr;
	else
		format->flags |= MINUS_PREFIX;
	return (putnbr_dec_int(nbr, format));
}

int	parse_uint(va_list args, t_format *format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_dec_uint(nbr, format));
}

int	parse_hex_upper(va_list args, t_format *format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	format->flags |= UPPERCASE;
	return (putnbr_hex_uint(nbr, format));
}

int	parse_hex_lower(va_list args, t_format *format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	format->flags |= LOWERCASE;
	return (putnbr_hex_uint(nbr, format));
}
