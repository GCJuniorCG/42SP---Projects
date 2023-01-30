/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:31:03 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:31:05 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putlhex(unsigned long d)
{
	char	*base;
	int		bw;

	bw = 0;
	base = "0123456789abcdef";
	if (d < 16)
		bw += write(1, base + d, 1);
	else if (d >= 16)
	{
		bw += ft_putlhex(d / 16);
		bw += ft_putlhex(d % 16);
	}
	return (bw);
}

static int	ft_putuhex(unsigned long d)
{
	char	*base;
	int		bw;

	bw = 0;
	base = "0123456789ABCDEF";
	if (d < 16)
		bw += write(1, base + d, 1);
	else if (d >= 16)
	{
		bw += ft_putuhex(d / 16);
		bw += ft_putuhex(d % 16);
	}
	return (bw);
}

int	ft_putnbr_hex(unsigned long n, int c)
{
	if (c == 'x')
		return (ft_putlhex(n));
	else if (c == 'X')
		return (ft_putuhex(n));
	return (0);
}
