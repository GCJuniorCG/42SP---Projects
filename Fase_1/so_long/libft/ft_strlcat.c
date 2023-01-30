/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:40 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:29:42 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	if (size < i)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && *src)
		dest[i++] = *(src++);
	dest[i] = '\0';
	return (ft_strlen(src) + i);
}
