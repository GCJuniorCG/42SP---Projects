/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:53:07 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/27 19:53:09 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_val;
	unsigned char		*src_val;
	size_t				i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dest_val = (unsigned char *)dest;
	src_val = (unsigned char *)src;
	while (i < n)
	{
		dest_val[i] = src_val[i];
		i++;
	}
	return (dest);
}
