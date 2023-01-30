/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:01:57 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/26 22:20:59 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_s(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_printf_p(unsigned long int num)
{
	int	len;

	if (num == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_printf_lower_x(num);
	return (len);
}

int	ft_printf_d_and_i(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	len = ft_printf_s(str);
	free(str);
	return (len);
}

int	ft_printf_u(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_itoa_u(num);
	len = ft_printf_s(str);
	free(str);
	return (len);
}
