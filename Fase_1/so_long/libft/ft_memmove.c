/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:31:32 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:31:34 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ps;
	unsigned char		*pd;

	if (src == dest || n == 0)
		return (dest);
	if (dest < src)
	{
		ps = (unsigned char *)src;
		pd = (unsigned char *)dest;
		while (n--)
			*pd++ = *ps++;
	}
	else
	{
		ps = (unsigned char *)src + (n - 1);
		pd = (unsigned char *)dest + (n - 1);
		while (n--)
			*pd-- = *ps--;
	}
	return (dest);
}
