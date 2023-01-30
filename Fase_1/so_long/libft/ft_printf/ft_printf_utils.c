/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:37:14 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:37:16 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*__getstr(char spec, va_list ap)
{
	char	*s;

	if (spec == 'p')
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
	if (spec == 'x')
		s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
	if (spec == 'X')
		s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (s);
}
