/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:25:55 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:25:57 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		copied;

	if (str == NULL)
		return (-1);
	len = 0;
	copied = 0;
	va_start(args, str);
	while (str[len] != '\0')
	{
		if (str[len++] != '%')
			continue ;
		write(1, str, --len);
		if (str[len + 1] == '\0')
			return (-1);
		str += (len + 1);
		copied += (len + parse_format(&str, args));
		if (str == NULL)
			return (-1);
		len = 0;
	}
	write(1, str, len);
	va_end(args);
	return (copied + len);
}
