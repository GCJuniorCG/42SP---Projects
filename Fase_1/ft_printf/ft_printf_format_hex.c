/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:02:07 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/26 22:24:22 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lower_x(unsigned long int num)
{
	char	*str;
	int		len;

	str = ft_itoa_hex(num);
	len = 0;
	while (str[len])
	{
		str[len] = ft_tolower(str[len]);
		len++;
	}
	ft_printf_s(str);
	free(str);
	return (len);
}

int	ft_printf_upper_x(unsigned long int num)
{
	char	*str;
	int		len;

	str = ft_itoa_hex(num);
	len = 0;
	while (str[len])
	{
		str[len] = ft_toupper(str[len]);
		len++;
	}
	ft_printf_s(str);
	free(str);
	return (len);
}
