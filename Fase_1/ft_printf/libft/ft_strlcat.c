/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:09:42 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/27 00:09:43 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	result;

	size_dest = ft_strlen(dest);
	if (size_dest > size)
		return (ft_strlen(src) + size);
	result = size_dest + ft_strlen(src);
	while (*src && size_dest + 1 < size)
	{
		dest[size_dest] = *src++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (result);
}
