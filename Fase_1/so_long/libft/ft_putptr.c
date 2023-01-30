/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:30:44 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:30:46 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *p)
{
	char			*s;
	int				bw;

	bw = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	bw += write(1, "0x", 2);
	s = ft_ultoa((unsigned long)p, "0123456789abcdef");
	if (!s)
		return (0);
	bw += ft_putstr(s);
	free(s);
	return (bw);
}
