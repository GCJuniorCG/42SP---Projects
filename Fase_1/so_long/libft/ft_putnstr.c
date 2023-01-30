/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:30:52 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:30:53 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr(char *s, int n)
{
	int	bw;

	if (!s)
		return (write(1, "(null)", 6));
	bw = 0;
	while (*s && n--)
	{
		bw += ft_putchar(*s);
		s++;
	}
	return (bw);
}
