/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:30:29 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:30:30 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	int	bw;

	bw = 0;
	if (n > 9)
		bw += ft_putunbr(n / 10);
	bw += ft_putchar((n % 10) + '0');
	return (bw);
}
